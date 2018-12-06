#include "Light.h"

Light::Light()
{
	LightDebugFlag = false;
}

Light::Light(vec3 lightPosition)
{
	LightDebugFlag = false;
	LightPosition = lightPosition;
	LightColor = vec3(1.0f, 1.0f, 1.0f);
}

Light::Light(Shader shader, vec3 lightPosition)
{
	LightDebugFlag = true;

	//DebugMesh = Mesh(shader);
	//DebugMesh.SetPosition(lightPosition);

	LightPosition = lightPosition;
	LightColor = vec3(1.0f, 1.0f, 1.0f);

	DebugMesh.SetPosition(LightPosition);
	DebugMesh.SetScale(vec3(0.2f));
}

Light::Light(vec3 lightPosition, vec3 lightColor)
{
	LightDebugFlag = false;
	LightPosition = lightPosition;
	LightColor = lightColor;
}

Light::~Light()
{

}

void Light::SetLightPosition(vec3 lightPosition)
{
	LightPosition = lightPosition;
}

void Light::SetLightColor(vec3 lightColor)
{
	LightColor = lightColor;
}

void Light::SetLightDebugFlag(bool DebugFlag)
{
	LightDebugFlag = DebugFlag;

	if (LightDebugFlag == true)
	{
		mat4 NewModelMatrix(1.0f);
		DebugMesh.SetModelMatrix(NewModelMatrix);
		DebugMesh.SetPosition(LightPosition);
		DebugMesh.SetScale(vec3(0.2f));
	}
}

void Light::Update(Shader shader)
{
	if (LightDebugFlag)
	{
		DebugMesh.SetPosition(LightPosition);
		//DebugMesh.Update(LightDebugShader, shader);
	}

	glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
	glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f);
	glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f);
	shader.SetVec3f("light.position", LightPosition);
	shader.SetVec3f("light.ambient", ambientColor);
	shader.SetVec3f("light.diffuse", diffuseColor);
	shader.SetVec3f("light.specular", 1.0f, 1.0f, 1.0f);
}
