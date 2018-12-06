#include "Include.h"
#include "Shader.h"
#include "Mesh.h"
#include "Vertex.h"
#include "Texture.h"
#include "Camera.h"
#include "stb_image.h"
#include "LightManager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Camera camera(vec3(0.0f, 0.0f, 3.0f));
float LastX = SCR_WIDTH / 2.0f;
float LastY = SCR_WIDTH / 2.0f;
bool FirstMouse = true;

float DeltaTime = 0.0f;
float LastFrame = 0.0f;


	glm::vec3 cubePositions[] = 
	{
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


int main()
{
	Material Emerald;
	Emerald.Name = "Emerald";
	Emerald.Ambient = vec3(0.0215f, 0.1745f, 0.0215f);
	Emerald.Diffuse = vec3(0.07568f, 0.61424f, 0.07568f);
	Emerald.Specular = vec3(0.633f, 0.727811f, 0.633f);
	Emerald.Shininess = float(0.6f);

	Material Jade;
	Jade.Name = "Jade";
	Jade.Ambient = vec3(0.135f, 0.2225f, 0.1575f);
	Jade.Diffuse = vec3(0.54f, 0.89f, 0.63f);
	Jade.Specular = vec3(0.316228f, 0.316228f, 0.316228f);
	Jade.Shininess = float(0.1f);

	Material Obsidian;
	Obsidian.Name = "Obsidian";
	Obsidian.Ambient = vec3(0.05375f, 0.05f, 0.06625f);
	Obsidian.Diffuse = vec3(0.18275f, 0.17f, 0.22525f);
	Obsidian.Specular = vec3(0.332741f, 0.328634f, 0.346435f);
	Obsidian.Shininess = float(0.3f);

	Material Pearl;
	Pearl.Name = "Pearl";
	Pearl.Ambient = vec3(0.25f, 0.20725f, 0.20725f);
	Pearl.Diffuse = vec3(1.0f, 0.829f, 0.829f);
	Pearl.Specular = vec3(0.296648f, 0.296648f, 0.296648f);
	Pearl.Shininess = float(0.088f);

	Material Ruby;
	Ruby.Name = "Ruby";
	Ruby.Ambient = vec3(0.1745f, 0.01175f, 0.01175f);
	Ruby.Diffuse = vec3(0.61424f, 0.04136f, 0.04136f);
	Ruby.Specular = vec3(0.727811f, 0.626959f, 0.626959f);
	Ruby.Shininess = float(0.6f);

	Material Turquoise;
	Turquoise.Name = "Turquoise";
	Turquoise.Ambient = vec3(0.1f, 0.18725f, 0.1745f);
	Turquoise.Diffuse = vec3(0.396f, 0.74151f, 0.69102f);
	Turquoise.Specular = vec3(0.297254f, 0.30829f, 0.306678f);
	Turquoise.Shininess = float(0.1f);

	Material Brass;
	Brass.Name = "Brass";
	Brass.Ambient = vec3(0.329412f, 0.223529f, 0.027451f);
	Brass.Diffuse = vec3(0.780392f, 0.568627f, 0.113725f);
	Brass.Specular = vec3(0.992157f, 0.941176f, 0.807843f);
	Brass.Shininess = float(0.21794872f);

	Material Bronze;
	Bronze.Name = "Bronze";
	Bronze.Ambient = vec3(0.2125f, 0.1275f, 0.054f);
	Bronze.Diffuse = vec3(0.714f, 0.4284f, 0.18144f);
	Bronze.Specular = vec3(0.393548f, 0.271906f, 0.166721f);
	Bronze.Shininess = float(0.2f);

	Material Chrome;
	Chrome.Name = "Chrome";
	Chrome.Ambient = vec3(0.25f, 0.25f, 0.25f);
	Chrome.Diffuse = vec3(0.4f, 0.4f, 0.4f);
	Chrome.Specular = vec3(0.774597f, 0.774597f, 0.774597f);
	Chrome.Shininess = float(0.6f);

	Material Copper;
	Copper.Name = "Copper";
	Copper.Ambient = vec3(0.19125f, 0.0735f, 0.0225f);
	Copper.Diffuse = vec3(0.7038f, 0.27048f, 0.0828f);
	Copper.Specular = vec3(0.256777f, 0.137622f, 0.086014f);
	Copper.Shininess = float(0.1f);

	Material Gold;
	Gold.Name = "Gold";
	Gold.Ambient = vec3(0.24725f, 0.1995f, 0.0745f);
	Gold.Diffuse = vec3(0.75164f, 0.60648f, 0.22648f);
	Gold.Specular = vec3(0.628281f, 0.555802f, 0.366065f);
	Gold.Shininess = float(0.4f);

	Material Silver;
	Silver.Name = "Silver";
	Silver.Ambient = vec3(0.19225f, 0.19225f, 0.19225f);
	Silver.Diffuse = vec3(0.50754f, 0.50754f, 0.50754f);
	Silver.Specular = vec3(0.508273f, 0.508273f, 0.508273f);
	Silver.Shininess = float(0.4f);


	Material material[11];

	material[0] = Emerald;
	material[1] = Jade;
	material[2] = Obsidian;
	material[3] = Pearl;
	material[4] = Ruby;
	material[5] = Turquoise;
	material[6] = Brass;
	material[7] = Bronze;
	material[8] = Chrome;
	material[9] = Copper;
	material[10] = Gold;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

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

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);

	Shader lightingShader("..//Resources//Shaders//Shader");
	Shader lampShader("LightShader");
	Mesh mesh(lightingShader, "..//Resources//Textures//container2.png", "..//Resources//Textures//container2_specular.png", float(0.6f));
	Mesh mesh2(lightingShader, "..//Resources//Textures//bricks.jpg", "..//Resources//Textures//container2_specular.png", float(0.6f));
	DirectionalLight Dlight(vec3(1.2f, 1.0f, 2.0f),vec3(0.2f, 0.2f, 0.2f),vec3(0.5f, 0.5f, 0.5f),vec3(1.0f, 1.0f, 1.0f));
	PointLight PLight(vec3(-1.2f, 1.0f, 2.0f), vec3(0.2f, 0.2f, 0.2f), vec3(0.2f, 0.2f, 0.2f), vec3(1.0f, 1.0f, 1.0f));
	SpotLight SLight(camera.Position, camera.Front, vec3(0.1f, 0.1f, 0.1f), vec3(0.8f, 0.8f, 0.8f), vec3(0.8f, 0.8f, 0.8f), 2.0f, 0.09f, 0.032f, 12.5f, 17.5f);

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		DeltaTime = currentFrame - LastFrame;
		LastFrame = currentFrame;

		processInput(window);

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		lightingShader.Bind();

		SLight.SetPosition(camera.Position);
		SLight.Update(lightingShader);

		camera.Update(lightingShader, SCR_WIDTH, SCR_HEIGHT);

		for (unsigned int i = 0; i < 10; i++)
		{
			mesh.SetMaterial(material[i]);
			mesh.SetPosition(cubePositions[i]);
			mesh.SetRotationX(20.0f * i);
			mesh.SetRotationY(20.0f * i);
			mesh.SetRotationZ(20.0f * i);
			mesh.SetScale(vec3(1.0f));
			mesh.Update(lightingShader);
		}

		mesh2.SetMaterial(material[0]);
		mesh2.SetPosition(vec3(1.5f, 0.0f, 0.0f));
		mesh2.SetRotationX(20.0f);
		mesh2.SetRotationY(20.0f);
		mesh2.SetRotationZ(20.0f);
		mesh2.SetScale(vec3(1.0f));
		mesh2.Update(lightingShader);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);


	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.KeyboardUpdate(FORWARD, DeltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.KeyboardUpdate(BACKWARD, DeltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.KeyboardUpdate(LEFT, DeltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.KeyboardUpdate(RIGHT, DeltaTime);
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (FirstMouse)
	{
		LastX = xpos;
		LastY = ypos;
		FirstMouse = false;
	}

	float xoffset = xpos - LastX;
	float yoffset = LastY - ypos; 

	LastX = xpos;
	LastY = ypos;

	camera.MouseUpdate(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}