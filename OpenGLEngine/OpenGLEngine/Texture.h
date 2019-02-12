#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include "FileSystem.h"
#include "Shader.h"

#include <iostream>


class Texture
{
public:
	unsigned int DiffuseMap;
	unsigned int SpecularMap;
	unsigned int texture1;
	unsigned int texture2;

	Texture(Shader shader, string DiffuseMapPath, string SpecularMapPath);
	Texture();
	~Texture();

	void Update(Shader shader);
private:
	unsigned int LoadTexture(char const * path);
};

