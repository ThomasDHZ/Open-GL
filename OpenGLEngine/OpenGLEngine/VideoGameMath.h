#pragma once

#ifndef VIDEOGAMEMATH_H
#define VIDEOGAMEMATH_H

#include <glm/glm.hpp>

using namespace glm;

static class VideoGameMath
{
public:
	static float ObjectDistance(vec3 Object1, vec3 Object2);
};

#endif