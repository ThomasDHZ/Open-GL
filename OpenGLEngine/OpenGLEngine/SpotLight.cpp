#include "SpotLight.h"
#include "VideoGameMath.h"

SpotLight::SpotLight()
{

}

SpotLight::SpotLight(vec3 position, vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular, float cutoff, float outercutoff)
{
	Position = position;
	Direction = direction;
	Ambient = ambient;
	Diffuse = diffuse;
	Specular = specular;

	Constant = 1.0f;
	Linear = 0.09f;
	Quadratic = 0.032;
	CutOff = cutoff;
	OuterCutOff = outercutoff;
}

SpotLight::SpotLight(vec3 position, vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic, float cutoff, float outercutoff)
{
	Position = position;
	Direction = direction;
	Ambient = ambient;
	Diffuse = diffuse;
	Specular = specular;

	Constant = constant;
	Linear = linear;
	Quadratic = quadratic;
	CutOff = cutoff;
	OuterCutOff = outercutoff;
	int asdf = 34;
}

SpotLight::~SpotLight()
{

}

void SpotLight::Update(Shader shader)
{
	shader.SetVec3("spotLight.position", Position);
	shader.SetVec3("spotLight.direction", Direction);
	shader.SetVec3("spotLight.ambient", Ambient);
	shader.SetVec3("spotLight.diffuse", Diffuse);
	shader.SetVec3("spotLight.specular", Specular);

	shader.SetFloat("spotLight.constant", Constant);
	shader.SetFloat("spotLight.linear", Linear);
	shader.SetFloat("spotLight.quadratic", Quadratic);
	shader.SetFloat("spotLight.cutOff", cos(radians(CutOff)));
	shader.SetFloat("spotLight.outerCutOff", cos(radians(OuterCutOff)));

	/*shader.setVec3("spotLights[" + std::to_string(Index) + "].position", Position);
	shader.setVec3("spotLights[" + std::to_string(Index) + "].direction", Direction);
	shader.setVec3("spotLights[" + std::to_string(Index) + "].ambient", Ambient);
	shader.setVec3("spotLights[" + std::to_string(Index) + "].diffuse", Diffuse);
	shader.setVec3("spotLights[" + std::to_string(Index) + "].specular", Specular);

	shader.setFloat("spotLights[" + std::to_string(Index) + "].constant", Constant);
	shader.setFloat("spotLights[" + std::to_string(Index) + "].linear", Linear);
	shader.setFloat("spotLights[" + std::to_string(Index) + "].quadratic", Quadratic);
	shader.setFloat("spotLights[" + std::to_string(Index) + "].cutOff", cos(radians(CutOff)));
	shader.setFloat("spotLights[" + std::to_string(Index) + "].outerCutOff", cos(radians(OuterCutOff)));*/
}

void SpotLight::UpdateCameraDistance(Camera camera)
{
	CameraDistance = VideoGameMath::ObjectDistance(camera.GetCameraPosition(), GetPosition());
}

void SpotLight::SetPosition(vec3 position)
{
	Position = position;
}

void SpotLight::SetPosition(float x, float y, float z)
{
	Position = vec3(x, y, z);
}

void SpotLight::SetDirection(vec3 direction)
{
	Direction = direction;
}

void SpotLight::SetDirection(float x, float y, float z)
{
	Direction = vec3(x, y, z);
}

void SpotLight::SetAmbient(vec3 ambient)
{
	Ambient = ambient;
}

void SpotLight::SetAmbient(float x, float y, float z)
{
	Ambient = vec3(x, y, z);
}

void SpotLight::SetDiffuse(vec3 diffuse)
{
	Diffuse = diffuse;
}

void SpotLight::SetDiffuse(float x, float y, float z)
{
	Diffuse = vec3(x, y, z);
}

void SpotLight::SetSpecular(vec3 specular)
{
	Specular = specular;
}

void SpotLight::SetSpecular(float x, float y, float z)
{
	Specular = vec3(x, y, z);
}

void SpotLight::SetConstant(float constant)
{
	Constant = constant;
}

void SpotLight::SetLinear(float linear)
{
	Linear = linear;
}

void SpotLight::SetQuadratic(float quadratic)
{
	Quadratic = quadratic;
}

void SpotLight::SetCutOff(float cutoff)
{
	CutOff = cutoff;
}

void SpotLight::SetOuterCutOff(float outercutoff)
{
	OuterCutOff = outercutoff;
}

void SpotLight::SetIndex(int index)
{
	Index = index;
}