#pragma once

#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Shader.h"
#include <glm/glm.hpp>
#include <vector>

using namespace std;
using namespace glm;

class LightManager
{
private:
	vec4 AmbientLight;
	vector<DirectionalLight> DirectionalLightList;
	vector<PointLight> PointLightList;
	vector<SpotLight> SpotLightList;

public:
	LightManager();
	~LightManager();

	void Update(Shader shader);
	void AddDirectionalLight(DirectionalLight light);
	void AddPointLightLight(PointLight light);
	void AddSpotLight(SpotLight light);
	void RemoveDirectionalLight(int index);
	void RemovePointLight(int index);
	void RemoveSpotLight(int index);
	void Clear();

	vector<DirectionalLight> GetDirectionalLightList()
	{
		return DirectionalLightList;
	}
	vector<PointLight> GetPointLightList()
	{
		return PointLightList;
	}
	vector<SpotLight> GetSpotLight()
	{
		return SpotLightList;
	}
	DirectionalLight GetDirectionalLight(int index)
	{
		return DirectionalLightList[index];
	}
	PointLight GetPointLight(int index)
	{
		return PointLightList[index];
	}
	SpotLight GetSpotLightList(int index)
	{
		return SpotLightList[index];
	}
};

#endif