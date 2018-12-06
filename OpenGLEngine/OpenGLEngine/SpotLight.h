#pragma once

#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include "Shader.h"
#include "Camera.h"
#include <glm/glm.hpp>


using namespace glm;

class SpotLight
{
private:
	vec3 Position;
	vec3 Direction;
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;

	float Constant;
	float Linear;
	float Quadratic;

	float CutOff;
	float OuterCutOff;

	int Index;

public:
	SpotLight();
	SpotLight(vec3 position, vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular, float cutoff, float outercutoff);
	SpotLight(vec3 position, vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic, float cutoff, float outercutoff);
	~SpotLight();

	void Update(Shader shader);

	void SetPosition(vec3 position);
	void SetPosition(float x, float y, float z);
	void SetDirection(vec3 direction);
	void SetDirection(float x, float y, float z);
	void SetAmbient(vec3 ambient);
	void SetAmbient(float x, float y, float z);
	void SetDiffuse(vec3 diffuse);
	void SetDiffuse(float x, float y, float z);
	void SetSpecular(vec3 specular);
	void SetSpecular(float x, float y, float z);

	void SetConstant(float constant);
	void SetLinear(float linear);
	void SetQuadratic(float quadratic);
	void SetCutOff(float cutoff);
	void SetOuterCutOff(float outercutoff);

	void SetIndex(int index);

	vec3 GetPosition()
	{
		return Position;
	}
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
	float GetCutOff()
	{
		return CutOff;
	}
	float GetOuterCutOff()
	{
		return OuterCutOff;
	}
};

#endif