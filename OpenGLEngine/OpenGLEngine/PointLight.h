#pragma once

#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Shader.h"
#include <glm/glm.hpp>


using namespace glm;

class PointLight
{
private:
	vec3 Position;
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;

	float Constant;
	float Linear;
	float Quadratic; 

	int Index;

public:
	PointLight();
	PointLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular);
	PointLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic);
	~PointLight();

	void Update(Shader shader);

	void SetPosition(vec3 position);
	void SetPosition(float x, float y, float z);
	void SetAmbient(vec3 ambient);
	void SetAmbient(float x, float y, float z);
	void SetDiffuse(vec3 diffuse);
	void SetDiffuse(float x, float y, float z);
	void SetSpecular(vec3 specular);
	void SetSpecular(float x, float y, float z);

	void SetConstant(float constant);
	void SetLinear(float linear);
	void SetQuadratic(float quadratic);

	void SetIndex(int index);

	vec3 GetPosition()
	{
		return Position;
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
	float GetConstant()
	{
		return Constant;
	}
	float GetLinear()
	{
		return Linear;
	}
	float GetQuadratic()
	{
		return Quadratic;
	}
};

#endif