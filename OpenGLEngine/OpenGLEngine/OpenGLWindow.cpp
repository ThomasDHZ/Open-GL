#include "OpenGLWindow.h"

OpenGLWindow::OpenGLWindow(unsigned int Width, unsigned int Height)
{
	CloseWindow = false;
	WindowWidth = Width;
	WindowHeight = Height;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif



	GLwindow = glfwCreateWindow(WindowWidth, WindowHeight, "LearnOpenGL", NULL, NULL);
	if (GLwindow == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

	}

	glfwMakeContextCurrent(GLwindow);
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//glfwSetCursorPosCallback(window, mouse_callback);
	//glfwSetScrollCallback(window, scroll_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}


	glEnable(GL_DEPTH_TEST);
}

OpenGLWindow::~OpenGLWindow()
{
	glfwTerminate();
}

void OpenGLWindow::ClearWindow(float Red, float Green, float Blue)
{
	glClearColor(Red, Green, Blue, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLWindow::SwapBuffers()
{
	glfwSwapBuffers(GLwindow);
	glfwPollEvents();
}
void OpenGLWindow::Update()
{
	UpdateInput();
}
void OpenGLWindow::UpdateInput()
{

}