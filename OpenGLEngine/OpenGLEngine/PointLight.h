#pragma once

#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Shader.h"
#include "Camera.h"
#include "VideoGameMath.h"
#include <glm/glm.hpp>


using namespace glm;
using namespace std;

class PointLight
{
private:
	string LightName;

	vec3 Position;
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;

	float Constant;
	float Linear;
	float Quadratic;

	int Index;

	float CameraDistance;

public:
	PointLight();
	PointLight(string Lightname, vec3 position, vec3 ambient, vec3 diffuse, vec3 specular);
	PointLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular);
	PointLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic);
	~PointLight();

	void Update(Shader shader, Camera camera);
	void UpdateCameraDistance(Camera camera);

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

	void OutOfRange(Shader shader);

	void SetIndex(int index);

	bool operator< (const PointLight &OtherPointLight) const
	{
		return CameraDistance < OtherPointLight.CameraDistance;
	}
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
	int GetIndex()
	{
		return Index;
	}
	float GetCameraDistance()
	{
		return CameraDistance;
	}
};

#endif