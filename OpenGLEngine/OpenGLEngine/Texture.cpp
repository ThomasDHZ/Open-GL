#include "Texture.h"
#include <cassert>
#include "stb_image.h"
Texture::Texture()
{

}
Texture::Texture(Shader shader)
{
	shader.Bind();
}
Texture::Texture(Shader shader, string DiffuseMapPath, string SpecularMapPath, float shininess)
{
	DiffuseMap = LoadTexture(DiffuseMapPath.c_str());
	SpecularMap = LoadTexture(SpecularMapPath.c_str());
	Shininess = shininess;
	shader.Bind();
}

Texture::~Texture()
{

}
void Texture::Update(Shader shader)
{
	shader.SetInt("material.diffuse", 0);
	shader.SetInt("material.specular", 1);
	shader.SetFloat("material.shininess", Shininess);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, DiffuseMap);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, SpecularMap);
}

void Texture::SetDiffuseMap(string DiffuseMapPath)
{
	DiffuseMap = LoadTexture(DiffuseMapPath.c_str());
}

void Texture::SetSpecularMap(string SpecularMapPath)
{
	SpecularMap = LoadTexture(SpecularMapPath.c_str());
}

void Texture::SetShininess(float shininess)
{
	Shininess = shininess;
}

void Texture::RemoveDiffuseMap()
{
	glDeleteTextures(1, &DiffuseMap);
}

void Texture::RemoveSpecularMap()
{
	glDeleteTextures(1, &SpecularMap);
}

void Texture::RemoveAllTextures()
{
	glDeleteTextures(1, &DiffuseMap);
	glDeleteTextures(1, &SpecularMap);
}

unsigned int Texture::LoadTexture(char const * path)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}