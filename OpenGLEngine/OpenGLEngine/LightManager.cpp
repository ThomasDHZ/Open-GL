#include "LightManager.h"
#include "windows.h"

LightManager::LightManager()
{

}

LightManager::~LightManager()
{

}

void LightManager::Update(Shader shader)
{
	for (DirectionalLight DLights : DirectionalLightList)
	{
		DLights.Update(shader);
	}
	for (PointLight PLights : PointLightList)
	{
		PLights.Update(shader);
	}
	for (SpotLight SLights : SpotLightList)
	{
		SLights.Update(shader);
	}
}

void LightManager::AddDirectionalLight(DirectionalLight light)
{
	light.SetIndex(DirectionalLightList.size());
	DirectionalLightList.push_back(light);
}

void LightManager::AddPointLightLight(PointLight light)
{
	light.SetIndex(PointLightList.size());
	PointLightList.push_back(light);
}

void LightManager::AddSpotLight(SpotLight light)
{
	light.SetIndex(SpotLightList.size());
	SpotLightList.push_back(light);
}

void LightManager::RemoveDirectionalLight(int index)
{
	int size = DirectionalLightList.size();
	if (size > index)
	{
		DirectionalLightList.erase(DirectionalLightList.begin() + index);
		for (int x = 0; x <= DirectionalLightList.size() - 1; x++)
		{
			DirectionalLightList[x].SetIndex(x);
		}
	}
	else
	{
		MessageBox(nullptr, TEXT("DirectionalLight index doesn't exist"), TEXT("Index out of range error."), MB_OK);
		cout << "DirectionalLightLight[" + to_string(index) + "] doesn't exist." << endl;
	}
}

void LightManager::RemovePointLight(int index)
{
	int size = PointLightList.size();
	if (size > index)
	{
		PointLightList.erase(PointLightList.begin() + index);
		for (int x = 0; x <= PointLightList.size() - 1; x++)
		{
			PointLightList[x].SetIndex(x);
		}
	}
	else
	{
		MessageBox(nullptr, TEXT("PointLight index doesn't exist"), TEXT("Index out of range error."), MB_OK);
		cout << "PointLight[" + to_string(index) + "] doesn't exist." << endl;
	}
}

void LightManager::RemoveSpotLight(int index)
{
	int size = SpotLightList.size();
	if (size > index)
	{
		SpotLightList.erase(SpotLightList.begin() + index);
		for (int x = 0; x <= SpotLightList.size() - 1; x++)
		{
			SpotLightList[x].SetIndex(x);
		}
	}
	else
	{
		MessageBox(nullptr, TEXT("SpotLight index doesn't exist"), TEXT("Index out of range error."), MB_OK);
		cout << "SpotLight[" + to_string(index) + "] doesn't exist." << endl;
	}
}

void LightManager::Clear()
{
	DirectionalLightList.clear();
	PointLightList.clear();
	SpotLightList.clear();
}
