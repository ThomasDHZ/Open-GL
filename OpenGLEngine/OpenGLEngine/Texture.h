#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include "Include.h"
#include "Shader.h"
#include <vector>

using namespace std;

class Texture
{
	private:
		unsigned int DiffuseMap;
		unsigned int SpecularMap;
		float Shininess;
	public:
		Texture();
		Texture(Shader shader);
		Texture(Shader shader, string DiffuseMapPath, string SpecularMapPath, float shininess);
		~Texture();
		
		void SetDiffuseMap(string DiffuseMapPath);
		void SetSpecularMap(string SpecularMapPath);
		void SetShininess(float Shininess);
		void RemoveDiffuseMap();
		void RemoveSpecularMap();
		void RemoveAllTextures();

		void Update(Shader shader);
		unsigned int LoadTexture(char const * path);
};
#endif