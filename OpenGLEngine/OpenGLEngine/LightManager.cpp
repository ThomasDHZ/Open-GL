#include "LightManager.h"
#include "windows.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

LightManager::LightManager()
{

}

LightManager::~LightManager()
{

}

void LightManager::SortSpotLight(Camera camera)
{
	for (int x = 0; x <= SpotLightList.size() - 1; x++)
	{
		SpotLightList[x].UpdateCameraDistance(camera);
	}

	std::sort(SpotLightList.begin(), SpotLightList.end());

	for (int x = 0; x <= SpotLightList.size() - 1; x++)
	{
		SpotLightList[x].SetIndex(x);
	}
	system("CLS");
	cout << flush;
	cout << "Unused Lights:" << endl << endl;
	for (int x = MAXPOINTLIGHTS; x <= SpotLightList.size() - 1; x++)
	{
		cout << "Pos X: " << SpotLightList[x].GetPosition().x << " Pos Y: " << SpotLightList[x].GetPosition().y << " Pos Z: " << SpotLightList[x].GetPosition().z << " Distance: " << SpotLightList[x].GetCameraDistance() << endl;
	}
}

void LightManager::SortPointLight(Shader shader, Camera camera)
{
	int UsedLights = 0;
	int UnusedLights = 0;
	int EmetyLightSpaces = 0;

	for (int x = 0; x <= PointLightList.size() - 1; x++)
	{
		PointLightList[x].UpdateCameraDistance(camera);
	}

	std::sort(PointLightList.begin(), PointLightList.end());

	for (int x = 0; x <= PointLightList.size() - 1; x++)
	{
		PointLightList[x].SetIndex(x);
		UsedLights++;
	}

	for (int x = PointLightList.size() - 1; x <= MAXPOINTLIGHTS - 1; x++)
	{
		shader.SetVec3("pointLights[" + std::to_string(x) + "].ambient", vec3(0.0f, 0.0f, 0.0f));
		EmetyLightSpaces++;
	}
	/*
	system("CLS");
	cout << flush;
	cout << "Unused Lights:" << endl << endl;
	for (int x = MAXPOINTLIGHTS; x <= PointLightList.size() - 1; x++)
	{
		cout << "Pos X: " << PointLightList[x].GetPosition().x << " Pos Y: " << PointLightList[x].GetPosition().y << " Pos Z: " << PointLightList[x].GetPosition().z << " Distance: " << PointLightList[x].GetCameraDistance() << endl;
	}
	cout << "UsedLights: " << UsedLights << endl;
	cout << "UnusedLights: " << UnusedLights << endl;
	cout << "EmetyLightSpaces: " << EmetyLightSpaces << endl;*/
}

void LightManager::Update(Shader shader, Camera camera)
{
	for (DirectionalLight DLights : DirectionalLightList)
	{
		DLights.Update(shader);
	}
	for (int x = 0; x <= PointLightList.size() - 1; x++)
	{
		PointLightList[x].Update(shader, camera);
	}
	for (SpotLight SLights : SpotLightList)
	{
		SLights.Update(shader);
	}

	SortPointLight(shader, camera);
}

void LightManager::AddDirectionalLight(DirectionalLight light)
{
	int size = DirectionalLightList.size();
	if (size < MAXDIRECTIONALLIGHT)
	{
		light.SetIndex(DirectionalLightList.size());
		DirectionalLightList.push_back(light);
	}
	else
	{
		MessageBox(nullptr, TEXT("Can't add anymore Directional Lights"), TEXT("Can't add anymore Directional Lights"), MB_OK);
		cout << "Can't add more than" << MAXDIRECTIONALLIGHT << " Directional Lights" << endl;
	}
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
