#pragma once

#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include "Light.h"
#include "Shader.h"
#include <glm/glm.hpp>
#include <vector>

using namespace std;
using namespace glm;

class LightManager
{
	private:
		vec4 AmbientLight;
		vector<Light> LightList;
	public:
		LightManager();
		~LightManager();
		void AddLight(Light light);
		void SetAmbientLight(vec4 ambientLight);
		void SetAmbientLight(float x, float y, float z, float w);
		void UpdateLight(int LightID, Light NewLightPos);
		void UpdateLightPosition(int LightID, vec3 NewPosition);
		void UpdateLightPosition(int LightID, float x, float y, float z);
		void UpdateLightColor(int LightID, vec3 NewColor);
		void UpdateLightColor(int LightID, float x, float y, float z);
		void Update(Shader shader);

		vec4 GetAmbientLight()
		{
			return AmbientLight;
		}
		vector<Light> GetLightList()
		{
			return LightList;
		}
		Light GetLight(int LightID)
		{
			return LightList[LightID];
		}
};

#endif