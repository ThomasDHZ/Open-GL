#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "FileSystem.h"
#include "shader.h"
#include "Vertex.h"
#include "Camera.h"
#include "Mesh.h"
#include "Texture.h"
#include "DirectionalLight.h"
#include "LightManager.h"
#include "SpotLight.h"
#include "PointLight.h"

#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

float deltaTime = 0.0f;	
float lastFrame = 0.0f;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	Shader shader("BaseVertexShader.vs", "BaseFragmentShader.fs");
	Shader lightshader("Lamp.vs", "Lamp.fs");
	Shader depthshader("DepthTestingShader.vs", "DepthTestingShader.fs");

	Vertex vertices[] =
	{
			 { vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f, -0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(0.5f,  0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f,  0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) },
			 { vec3(-0.5f,  0.5f, -0.5f), vec3(0.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f) }
	};

	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	glm::vec3 cubePositions2[] = {
	glm::vec3(0.0f + 5.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f + 5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f + 5.0f),
	glm::vec3(-3.8f, -2.0f, -12.3f + 5.0f),
	glm::vec3(2.4f, -0.4f + 5.0f, -3.5f),
	glm::vec3(-1.7f + 5.0f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f + 5.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f + 5.0f),
	glm::vec3(1.5f,  0.2f + 5.0f, -1.5f),
	glm::vec3(-1.3f + 5.0f,  1.0f, -1.5f)
	};

	glm::vec3 cubePositions3[] = {
glm::vec3(0.0f + 5.0f,  0.0f-5.0f,  0.0f),
glm::vec3(2.0f,  5.0f + 5.0f, -15.0f - 5.0f),
glm::vec3(-1.5f - 5.0f, -2.2f, -2.5f + 5.0f),
glm::vec3(-3.8f, -2.0f - 5.0f, -12.3f + 5.0f),
glm::vec3(2.4f, -0.4f + 5.0f, -3.5f - 5.0f),
glm::vec3(-1.7f + 5.0f,  3.0f - 5.0f, -7.5f),
glm::vec3(1.3f, -2.0f - 5.0f + 5.0f, -2.5f),
glm::vec3(1.5f - 5.0f,  2.0f, -2.5f + 5.0f),
glm::vec3(1.5f,  0.2f + 5.0f - 5.0f, -1.5f),
glm::vec3(-1.3f + 5.0f,  1.0f, -1.5f - 5.0f)
	};

	glm::vec3 pointLightPositions[] = 
	{
		glm::vec3(0.7f,  0.2f,  2.0f),
		glm::vec3(2.3f, -3.3f, -4.0f),
		glm::vec3(-4.0f,  2.0f, -12.0f),
		glm::vec3(0.0f,  0.0f, -3.0f)
	};

	Mesh mesh = Mesh(Vertex(), shader, "resources/textures/container2.png", "resources/textures/container2_specular.png");
	Mesh mesh2 = Mesh(Vertex(), lightshader, "resources/textures/container2.png", "resources/textures/container2_specular.png");
	Mesh mesh3 = Mesh(Vertex(), depthshader, "resources/textures/container2.png", "resources/textures/container2_specular.png");

	LightManager lightmanager;

	float X;
	float Y;
	float Z;
	float AX;
	float AY;
	float AZ;
	float DX;
	float DY;
	float DZ;

	//lightmanager.AddDirectionalLight(DirectionalLight(vec3(-0.2f, -1.0f, -0.3f), vec3(0.05f, 0.05f, 0.05f), vec3(0.4f, 0.4f, 0.4f), vec3(0.5f, 0.5f, 0.5f)));

	for (int x = 0; x <= 100; x++)
	{
		X = rand() % 50 + 1;
		Y = rand() % 50 + 1;
		Z = rand() % 50 + 1;
		AX = (rand() % 100 + 1) * .01;
		AY = (rand() % 100 + 1) * .01;
		AZ = (rand() % 100 + 1) * .01;
		DX = (rand() % 100 + 1) * .01;
		DY = (rand() % 100 + 1) * .01;
		DZ = (rand() % 100 + 1) * .01;

		lightmanager.AddPointLightLight(PointLight(vec3(X, Y, Z), vec3(AX, AY, AZ), vec3(DX, DY, DZ), vec3(AX, AY, AZ), 1.0f, 0.09, 0.032));
		int sdf = 34;
	}

	lightmanager.AddDirectionalLight(DirectionalLight(vec3(-1.0f, -1.0f, -0.3f), vec3(0.05f, 0.05f, 0.05f), vec3(0.4f, 0.4f, 0.4f), vec3(0.5f, 0.5f, 0.5f)));
	lightmanager.AddSpotLight(SpotLight(vec3(camera.Position), vec3(camera.Front), vec3(0.0f, 0.0f, 0.0f), vec3(1.0f, 1.0f, 1.0f), vec3(1.0f, 1.0f, 1.0f), glm::cos(glm::radians(12.5f)), glm::cos(glm::radians(15.0f))));


	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		processInput(window);

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();

		shader.Use();
		//lightmanager.Update(shader, camera);


		shader.SetVec3("viewPos", camera.Position);
		shader.SetFloat("material.shininess", 32.0f);




		lightmanager.Update(shader, camera);

		// spotLight
		shader.SetVec3("spotLight.position", camera.Position);
		shader.SetVec3("spotLight.direction", camera.Front);
		shader.SetVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
		shader.SetVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
		shader.SetVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
		shader.SetFloat("spotLight.constant", 1.0f);
		shader.SetFloat("spotLight.linear", 0.09);
		shader.SetFloat("spotLight.quadratic", 0.032);
		shader.SetFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
		shader.SetFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

		shader.SetMat4("projection", projection);
		shader.SetMat4("view", view);

		for (unsigned int i = 0; i < 10; i++)
		{
			mesh.SetPosition(cubePositions[i]);
			mesh.Update(shader);
		}

		lightshader.Use();
		lightshader.SetVec3("viewPos", camera.Position);
		lightshader.SetMat4("projection", projection);
		lightshader.SetMat4("view", view);
		for (unsigned int i = 0; i < 10; i++)
		{
			mesh2.SetPosition(cubePositions2[i]);
			mesh2.SetScale(vec3(.25f));
			mesh2.Update(lightshader);
		}

		depthshader.Use();
		depthshader.SetVec3("viewPos", camera.Position);
		depthshader.SetMat4("projection", projection);
		depthshader.SetMat4("view", view);
		for (unsigned int i = 0; i < 10; i++)
		{
			mesh3.SetPosition(cubePositions3[i]);
			mesh3.SetScale(vec3(.25f));
			mesh3.Update(depthshader);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	mesh.DeleteBuffers();

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}