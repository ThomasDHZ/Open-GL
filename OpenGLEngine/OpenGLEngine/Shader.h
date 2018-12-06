#pragma once

#ifndef SHADER_H
#define SHADER_H

#include "Include.h"

using namespace std;
using namespace glm;

class Shader
{
	private:
		static const unsigned int NUM_SHADER = 2;

		GLuint m_program;
		GLuint m_shaders[NUM_SHADER];

		mat4 ModelMatrix;
		string LoadShader(const string& fileName);
		GLuint CreateShader(const string& text, GLenum ShaderType);
		void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);

	public:
		Shader(const string& fileNam);
		void Bind();
		void Update();
		GLuint GetShaderProgram()
		{
			return m_program;
		}
		GLuint GetShaderUniformLocation(GLchar *Variable)
		{
			return glGetUniformLocation(m_program, Variable);
		
		}
		GLuint GetShaderAttributeLocation(GLchar *Variable)
		{
			return glGetAttribLocation(m_program, Variable);
		}
		void SetInt(const GLchar* IDLocation, int value);
		void SetFloat (const GLchar* IDLocation, float value);
		void SetVec3f(const GLchar* IDLocation, GLfloat x, GLfloat y, GLfloat z);
		void SetVec3f(const GLchar* IDLocation, vec3 xyz);
		void SetVec4f(const GLchar* IDLocation, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
		void SetMatrix4fv(const GLchar* IDLocation, mat4 &Matrix);

		virtual ~Shader();

};

#endif