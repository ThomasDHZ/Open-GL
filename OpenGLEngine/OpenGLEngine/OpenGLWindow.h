#pragma once

#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include "Include.h"

using namespace std;

class OpenGLWindow
{
	private:
		unsigned int WindowWidth;
		unsigned int WindowHeight;

		bool CloseWindow;

		GLFWwindow* GLwindow;

	public:
		OpenGLWindow(unsigned int Width, unsigned int Height);
		~OpenGLWindow();

		void ClearWindow(float Red, float Green, float Blue);
		void SwapBuffers();
		void Update();
		void UpdateInput();


		bool IsClosed()
		{
			return CloseWindow;
		}
};

#endif

