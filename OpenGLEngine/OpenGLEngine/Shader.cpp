#include "Shader.h"

Shader::Shader(const string& fileName)
{
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

	for (unsigned int x = 0; x < NUM_SHADER; x++)
	{
		glAttachShader(m_program, m_shaders[x]);
	}

	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Shader Failed to Link: ");
	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Shader Failed to validate: ");
}

Shader::~Shader()
{
	for (unsigned int x = 0; x < NUM_SHADER; x++)
	{
		glDetachShader(m_program, m_shaders[x]);
		glDeleteShader(m_shaders[x]);
	}

	glDeleteProgram(m_program);
}

string Shader::LoadShader(const string& fileName)
{
	ifstream file;
	file.open((fileName).c_str());

	string output;
	string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		cerr << "Unable to load shader: " << fileName << endl;
	}

	return output;
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		cerr << errorMessage << ": '" << error << "'" << endl;
	}
}

GLuint Shader::CreateShader(const string& text, GLenum ShaderType)
{
	GLuint shader = glCreateShader(ShaderType);

	if (shader == 0)
	{
		cerr << "Error: Shader creation failed" << endl;
	}

	const GLchar* ShaderSourceStrings[1];
	GLint ShaderSourceStringLengths[1];

	ShaderSourceStrings[0] = text.c_str();
	ShaderSourceStringLengths[0] = text.length();

	glShaderSource(shader, 1, ShaderSourceStrings, ShaderSourceStringLengths);
	glCompileShader(shader);
	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Compiler failed: ");

	return shader;
}

void Shader::Bind()
{
	glUseProgram(m_program);
}
void Shader::Update()
{
	glUseProgram(m_program);
}
void Shader::SetInt(const GLchar* IDLocation, int value)
{
	glUniform1i(glGetUniformLocation(m_program, IDLocation), value);
}
void Shader::SetFloat(const GLchar* IDLocation, float value)
{
	glUniform1f(glGetUniformLocation(m_program, IDLocation), value);
}
void Shader::SetVec3f(const GLchar* IDLocation, GLfloat x, GLfloat y, GLfloat z)
{
	glUniform3f(glGetUniformLocation(m_program, IDLocation), x, y, z);
}
void Shader::SetVec3f(const GLchar* IDLocation, vec3 xyz)
{
	glUniform3f(glGetUniformLocation(m_program, IDLocation), xyz.x, xyz.y, xyz.z);
}
void Shader::SetVec4f(const GLchar* IDLocation, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	glUniform4f(glGetUniformLocation(m_program, IDLocation), x, y, z, w);
}
void Shader::SetMatrix4fv(const GLchar* IDLocation, mat4 &Matrix)
{
	glUniformMatrix4fv(glGetUniformLocation(m_program, IDLocation), 1, GL_FALSE, &Matrix[0][0]);
}
