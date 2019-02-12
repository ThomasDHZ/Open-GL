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
	const unsigned int MAXPOINTLIGHTS = 123; //If updated, must be updated in shader too.
	const unsigned int MAXDIRECTIONALLIGHT = 3; //If updated, must be updated in shader too.

	vector<DirectionalLight> DirectionalLightList;
	vector<PointLight> PointLightList;
	vector<SpotLight> SpotLightList;

	void SortSpotLight(Camera camera);
	void SortPointLight(Shader shader, Camera camera);

	bool SortByCameraDistance(PointLight PointLight1, PointLight PointLight2)
	{
		return (PointLight1.GetCameraDistance() < PointLight2.GetCameraDistance());
	}

	float ObjectDistance(vec3 Object1, vec3 Object2)
	{
		float Distance = 0.0f;
		float DistanceX = pow((Object2.x - Object1.x), 2);
		float DistanceY = pow((Object2.y - Object1.y), 2);
		float DistanceZ = pow((Object2.z - Object1.z), 2);
		Distance = pow(DistanceX + DistanceY + DistanceZ, .5);

		return Distance;
	}
public:
	LightManager();
	~LightManager();

	void Update(Shader shader, Camera camera);
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