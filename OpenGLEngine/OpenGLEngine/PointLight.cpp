#include "PointLight.h"

PointLight::PointLight()
{

}

PointLight::PointLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular)
{
	Position = position;
	Ambient = ambient;
	Diffuse = diffuse;
	Specular = specular;

	Constant = 1.0f;
	Linear = 0.09f;
	Quadratic = 0.032;
}

PointLight::PointLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic)
{
	Position = position;
	Ambient = ambient;
	Diffuse = diffuse;
	Specular = specular;

	Constant = constant;
	Linear = linear;
	Quadratic = quadratic;
}

PointLight::~PointLight()
{

}

void PointLight::Update(Shader shader)
{
	shader.SetVec3f("light.position", Position);
	shader.SetVec3f("light.ambient", Ambient);
	shader.SetVec3f("light.diffuse", Diffuse);
	shader.SetVec3f("light.specular", Specular);
	shader.SetFloat("light.constant", Constant);
	shader.SetFloat("light.linear", Linear);
	shader.SetFloat("light.quadratic", Quadratic);
}

void PointLight::SetPosition(vec3 position)
{
	Position = position;
}

void PointLight::SetPosition(float x, float y, float z)
{
	Position = vec3(x, y, z);
}

void PointLight::SetAmbient(vec3 ambient)
{
	Ambient = ambient;
}

void PointLight::SetAmbient(float x, float y, float z)
{
	Ambient = vec3(x, y, z);
}

void PointLight::SetDiffuse(vec3 diffuse)
{
	Diffuse = diffuse;
}

void PointLight::SetDiffuse(float x, float y, float z)
{
	Diffuse = vec3(x, y, z);
}

void PointLight::SetSpecular(vec3 specular)
{
	Specular = specular;
}

void PointLight::SetSpecular(float x, float y, float z)
{
	Specular = vec3(x, y, z);
}

void PointLight::SetConstant(float constant)
{
	Constant = constant;
}

void PointLight::SetLinear(float linear)
{
	Linear = linear;
}

void PointLight::SetQuadratic(float quadratic)
{
	Quadratic = quadratic;
}

void PointLight::SetIndex(int index)
{
	Index = index;
}