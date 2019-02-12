#pragma once

#ifndef Vertex_H
#define Vertex_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

enum VertexMap
{
	vPosition,
	vNormalMapping,
	vTextureCoordinates,
	vTangant,
	vBitangant,
	vColor
};

struct Vertex
{
	vec3 Position = vec3(0.0f,0.0f,0.0f);
	vec3 NormalMapping = vec3(0.0f, 0.0f, 0.0f);
	vec2 TextureCoordinates = vec2(0.0f, 0.0f);
	vec3 Tangant = vec3(0.0f, 0.0f, 0.0f);
	vec3 Bitangant = vec3(0.0f, 0.0f, 0.0f);
	vec3 Color = vec3(0.0f, 0.0f, 0.0f);
};

#endif