#pragma once

#ifndef SHADER_H
#define SHADER_H


#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


class Shader
{
public:
	unsigned int ShaderID;
	Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
	void Use();
	void Update();
	void SetBool(const string &name, bool value) const;
	void SetInt(const string &name, int value) const;
	void SetFloat(const string &name, float value) const;
	void SetVec2(const string &name, const glm::vec2 &value) const;
	void SetVec2(const string &name, float x, float y) const;
	void SetVec3(const string &name, const glm::vec3 &value) const;
	void SetVec3(const string &name, float x, float y, float z) const;
	void SetVec4(const string &name, const glm::vec4 &value) const;
	void SetVec4(const string &name, float x, float y, float z, float w);
	void SetMat2(const string &name, const glm::mat2 &mat) const;
	void SetMat3(const string &name, const glm::mat3 &mat) const;
	void SetMat4(const string &name, const glm::mat4 &mat) const;

private:
	void CheckCompileErrors(GLuint shader, std::string type);
};

#endif