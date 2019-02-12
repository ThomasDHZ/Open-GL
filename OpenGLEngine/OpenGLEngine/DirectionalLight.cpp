#include "DirectionalLight.h"

DirectionalLight::DirectionalLight()
{

}
DirectionalLight::DirectionalLight(vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular)
{
	Direction = direction;
	Ambient = ambient;
	Diffuse = diffuse;
	Specular = specular;
}
DirectionalLight::~DirectionalLight()
{

}

void DirectionalLight::Update(Shader shader)
{
	shader.SetVec3("dirLights[" + std::to_string(Index) + "].direction", Direction);
	shader.SetVec3("dirLights[" + std::to_string(Index) + "].ambient", Ambient);
	shader.SetVec3("dirLights[" + std::to_string(Index) + "].diffuse", Diffuse);
	shader.SetVec3("dirLights[" + std::to_string(Index) + "].specular", Specular);

	shader.SetVec3("dirLight.direction", Direction);
	shader.SetVec3("dirLight.ambient", Ambient);
	shader.SetVec3("dirLight.diffuse", Diffuse);
	shader.SetVec3("dirLight.specular", Specular);
}

void DirectionalLight::SetDirection(vec3 direction)
{
	Direction = direction;
}

void DirectionalLight::SetDirection(float x, float y, float z)
{
	Direction = vec3(x, y, z);
}

void DirectionalLight::SetAmbient(vec3 ambient)
{
	Ambient = ambient;
}

void DirectionalLight::SetAmbient(float x, float y, float z)
{
	Ambient = vec3(x, y, z);
}

void DirectionalLight::SetDiffuse(vec3 diffuse)
{
	Diffuse = diffuse;
}

void DirectionalLight::SetDiffuse(float x, float y, float z)
{
	Diffuse = vec3(x, y, z);
}

void DirectionalLight::SetSpecular(vec3 specular)
{
	Specular = specular;
}

void DirectionalLight::SetSpecular(float x, float y, float z)
{
	Specular = vec3(x, y, z);
}

void DirectionalLight::SetIndex(int index)
{
	Index = index;
}