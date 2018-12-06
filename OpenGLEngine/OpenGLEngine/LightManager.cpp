#include "LightManager.h"

LightManager::LightManager()
{
	AmbientLight = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}

LightManager::~LightManager()
{

}

void LightManager::AddLight(Light Light)
{
	LightList.push_back(Light);
}

void LightManager::SetAmbientLight(vec4 ambientLight)
{
	AmbientLight = ambientLight;
}

void LightManager::SetAmbientLight(float x, float y, float z, float w)
{
	AmbientLight = vec4(x, y, z, w);
}

void LightManager::UpdateLight(int LightID, Light NewLightPos)
{
	LightList[LightID] = NewLightPos;
}
void LightManager::UpdateLightPosition(int LightID, vec3 NewPosition)
{
	LightList[LightID].SetLightPosition(NewPosition);
}
void LightManager::UpdateLightPosition(int LightID, float x, float y, float z)
{
	LightList[LightID].SetLightPosition(vec3(x,y,z));
}
void LightManager::UpdateLightColor(int LightID, vec3 NewColor)
{
	LightList[LightID].SetLightPosition(NewColor);
}
void LightManager::UpdateLightColor(int LightID, float x, float y, float z)
{
	LightList[LightID].SetLightColor(vec3(x, y, z));
}

void LightManager::Update(Shader shader)
{
	shader.SetVec4f("AmbientLight", AmbientLight.x, AmbientLight.y, AmbientLight.z, AmbientLight.w);
	for (Light Lights : LightList)
	{
		Lights.Update(shader);
	}
}