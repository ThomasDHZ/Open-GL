#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "Shader.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

enum Camera_Movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera
{
	private:
		void UpdateCameraVectors();
	public:
		vec3 Position;
		vec3 Front;
		vec3 Up;
		vec3 Right;
		vec3 WorldUp;

		float Yaw;
		float Pitch;
		float MovementSpeed;
		float MouseSensitivity;
		float Zoom;

		Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
		{
			Position = position;
			WorldUp = up;
			Yaw = yaw;
			Pitch = pitch;
			UpdateCameraVectors();
		}
		Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
		{
			Position = glm::vec3(posX, posY, posZ);
			WorldUp = glm::vec3(upX, upY, upZ);
			Yaw = yaw;
			Pitch = pitch;
			UpdateCameraVectors();
		}

		void KeyboardUpdate(Camera_Movement direction, float deltaTime);
		void MouseUpdate(float Xoffset, float Yoffset, GLboolean ConstrainPitch = true);
		void ProcessMouseScroll(float yoffset);
		void Update(Shader shader, unsigned int ScreenWidth, unsigned int ScreenHeight);

		mat4 GetViewMatrix()
		{
			return lookAt(Position, Position + Front, Up);
		}
};

#endif