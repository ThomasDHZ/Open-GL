#pragma once

#ifndef LIGHT_H
#define LIGHT_H

#include "Shader.h"
#include "Mesh.h"
#include <glm/glm.hpp>

using namespace glm;

class Light
{
	private:	
		bool LightDebugFlag;

		vec3 LightPosition;
		vec3 LightColor;

		Mesh DebugMesh;

	public:
		Light();
		Light(vec3 lightPosition);
		Light(Shader shader, vec3 lightPosition);
		Light(vec3 lightPosition, vec3 lightColor);
		~Light();
		
		void SetLightPosition(vec3 lightPosition);
		void SetLightColor(vec3 lightColor);
		void SetLightDebugFlag(bool DebugFlag);
		void Update(Shader shader);



		vec3 GetLightPosition()
		{
			return LightPosition;
		}

		vec3 GetLightColor()
		{
			return LightColor;
		}
};

#endif