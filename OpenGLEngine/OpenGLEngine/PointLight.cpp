#include "PointLight.h"

PointLight::PointLight()
{

}

PointLight::PointLight(string Lightname, vec3 position, vec3 ambient, vec3 diffuse, vec3 specular)
{
	LightName = Lightname;
	Position = position;
	Ambient = ambient;
	Diffuse = diffuse;
	Specular = specular;

	Constant = 1.0f;
	Linear = 0.09f;
	Quadratic = 0.032;
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

void PointLight::Update(Shader shader, Camera camera)
{
	CameraDistance = VideoGameMath::ObjectDistance(camera.GetCameraPosition(), GetPosition());

	if (Index <= 125)
	{
		shader.SetVec3("pointLights[" + std::to_string(Index) + "].position", Position);
		shader.SetVec3("pointLights[" + std::to_string(Index) + "].ambient", Ambient);
		shader.SetVec3("pointLights[" + std::to_string(Index) + "].diffuse", Diffuse);
		shader.SetVec3("pointLights[" + std::to_string(Index) + "].specular", Specular);
		shader.SetFloat("pointLights[" + std::to_string(Index) + "].constant", Constant);
		shader.SetFloat("pointLights[" + std::to_string(Index) + "].linear", Linear);
		shader.SetFloat("pointLights[" + std::to_string(Index) + "].quadratic", Quadratic);
	}
}

void PointLight::UpdateCameraDistance(Camera camera)
{
	CameraDistance = VideoGameMath::ObjectDistance(camera.GetCameraPosition(), GetPosition());
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

void PointLight::OutOfRange(Shader shader)
{
	shader.SetVec3("pointLights[" + std::to_string(Index) + "].position", vec3(0.0f));
	shader.SetVec3("pointLights[" + std::to_string(Index) + "].ambient", vec3(0.0f));
	shader.SetVec3("pointLights[" + std::to_string(Index) + "].diffuse", vec3(0.0f));
	shader.SetVec3("pointLights[" + std::to_string(Index) + "].specular", vec3(0.0f));
	shader.SetFloat("pointLights[" + std::to_string(Index) + "].constant", 0.0f);
	shader.SetFloat("pointLights[" + std::to_string(Index) + "].linear", 0.0f);
	shader.SetFloat("pointLights[" + std::to_string(Index) + "].quadratic", 0.0f);
}