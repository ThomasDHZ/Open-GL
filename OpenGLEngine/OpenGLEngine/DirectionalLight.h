#pragma once

#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "Shader.h"
#include <glm/glm.hpp>


using namespace glm;

class DirectionalLight
{
	private:
		vec3 Direction;
		vec3 Ambient;
		vec3 Diffuse;
		vec3 Specular;

		int Index;

	public:
		DirectionalLight();
		DirectionalLight(vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular);
		~DirectionalLight();

		void Update(Shader shader);

		void SetDirection(vec3 direction);
		void SetDirection(float x, float y, float z);
		void SetAmbient(vec3 ambient);
		void SetAmbient(float x, float y, float z);
		void SetDiffuse(vec3 diffuse);
		void SetDiffuse(float x, float y, float z);
		void SetSpecular(vec3 specular);
		void SetSpecular(float x, float y, float z);

		void SetIndex(int index);

		vec3 GetDirection()
		{
			return Direction;
		}
		vec3 GetAmbient()
		{
			return Ambient;
		}
		vec3 GetDiffuse()
		{
			return Diffuse;
		}
		vec3 GetSpecular()
		{
			return Specular;
		}
};

#endif