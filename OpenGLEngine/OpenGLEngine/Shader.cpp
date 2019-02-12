#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath)
{
	string vertexCode;
	string fragmentCode;
	string geometryCode;
	ifstream vShaderFile;
	ifstream fShaderFile;
	ifstream gShaderFile;

	vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	gShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	try
	{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

		if (geometryPath != nullptr)
		{
			gShaderFile.open(geometryPath);
			stringstream gShaderStream;
			gShaderStream << gShaderFile.rdbuf();
			gShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}
	catch (ifstream::failure e)
	{
		cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char * fShaderCode = fragmentCode.c_str();
	unsigned int vertex, fragment;

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	CheckCompileErrors(vertex, "VERTEX");

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	CheckCompileErrors(fragment, "FRAGMENT");

	unsigned int geometry;
	if (geometryPath != nullptr)
	{
		const char * gShaderCode = geometryCode.c_str();
		geometry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometry, 1, &gShaderCode, NULL);
		glCompileShader(geometry);
		CheckCompileErrors(geometry, "GEOMETRY");
	}

	ShaderID = glCreateProgram();
	glAttachShader(ShaderID, vertex);
	glAttachShader(ShaderID, fragment);
	if (geometryPath != nullptr)
		glAttachShader(ShaderID, geometry);
	glLinkProgram(ShaderID);
	CheckCompileErrors(ShaderID, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);
	if (geometryPath != nullptr)
		glDeleteShader(geometry);

}
void Shader::Use()
{
	glUseProgram(ShaderID);
}

void Shader::Update()
{
	Use();

}

void Shader::SetBool(const string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ShaderID, name.c_str()), (int)value);
}

void Shader::SetInt(const string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ShaderID, name.c_str()), value);
}

void Shader::SetFloat(const string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ShaderID, name.c_str()), value);
}

void Shader::SetVec2(const string &name, const glm::vec2 &value) const
{
	glUniform2fv(glGetUniformLocation(ShaderID, name.c_str()), 1, &value[0]);
}
void Shader::SetVec2(const string &name, float x, float y) const
{
	glUniform2f(glGetUniformLocation(ShaderID, name.c_str()), x, y);
}

void Shader::SetVec3(const string &name, const glm::vec3 &value) const
{
	glUniform3fv(glGetUniformLocation(ShaderID, name.c_str()), 1, &value[0]);
}
void Shader::SetVec3(const string &name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(ShaderID, name.c_str()), x, y, z);
}

void Shader::SetVec4(const string &name, const glm::vec4 &value) const
{
	glUniform4fv(glGetUniformLocation(ShaderID, name.c_str()), 1, &value[0]);
}
void Shader::SetVec4(const string &name, float x, float y, float z, float w)
{
	glUniform4f(glGetUniformLocation(ShaderID, name.c_str()), x, y, z, w);
}

void Shader::SetMat2(const string &name, const glm::mat2 &mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(ShaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat3(const string &name, const glm::mat3 &mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(ShaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat4(const string &name, const glm::mat4 &mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(ShaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::CheckCompileErrors(GLuint shader, string type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << endl;
		}
	}
}