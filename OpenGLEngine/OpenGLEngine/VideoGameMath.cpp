#include "VideoGameMath.h"

float VideoGameMath::ObjectDistance(vec3 Object1, vec3 Object2)
{
	float Distance = 0.0f;
	float DistanceX = pow((Object2.x - Object1.x), 2);
	float DistanceY = pow((Object2.y - Object1.y), 2);
	float DistanceZ = pow((Object2.z - Object1.z), 2);
	Distance = pow(DistanceX + DistanceY + DistanceZ, .5);

	return Distance;
}

