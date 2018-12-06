#pragma once

#ifndef MESH_H
#define MESH_H

#include "Include.h"
#include "Vertex.h"
#include "Shader.h"
#include "OBJloader.h"
#include "Texture.h"


struct Material
{
	string Name;
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;
	float Shininess;
};

class Mesh
{
private:

	//generic vertex attribute 
	enum
	{
		PositionAttribute,
		NormalAttribute,
		AttributeCount
	};

	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;

	mat4 ModelMatrix;

	vec3 Position;
	vec3 Rotation;
	vec3 Scale;

	Texture texture;
	Material material;

public:
	Mesh();
	Mesh(Shader shader, string DiffuseMap, string SpecularMap, float Shinyiness);
	~Mesh();

	void Update(Shader shader);
	void SetMaterial(Material mat);
	void SetTexture(Texture NewTexture);
	void SetMeshColor(vec3 Color);
	void SetMeshColor(float Red, float Green, float Blue);
	void SetPosition(vec3 position);
	void SetRotation(vec3 rotation);
	void SetRotationX(float x);
	void SetRotationY(float y);
	void SetRotationZ(float z);
	void SetScale(vec3 scale);
	void SetModelMatrix(mat4 Matrix);
	Texture GetTexture()
	{
		return texture;
	}
	mat4 GetModelMatrix()
	{
		return ModelMatrix;
	}
	vec3 GetModelPosition()
	{
		return Position;
	}
};

#endif
