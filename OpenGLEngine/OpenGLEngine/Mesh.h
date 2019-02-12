#pragma once
#include "Vertex.h"
#include "Texture.h"
#include "Shader.h"

class Mesh
{

private:

	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;

	mat4 ModelMatrix;
	vec3 Position;
	vec3 Rotation;
	vec3 Scale;
	int VertexCount; 

	Texture ModelTexture;

public:

	Mesh(Vertex vertex, Shader shader, string DiffuseMapPath, string SpecularMapPath);
	~Mesh();
	void Update(Shader shader);
	void DeleteBuffers();

	mat4 GetModelMatrix();
	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);
	void SetPosition(vec3 position);
	void SetRotation(vec3 rotation);
	void SetScale(vec3 scale);
	void SetRotationX(float x);
	void SetRotationY(float y);
	void SetRotationZ(float z);
};

