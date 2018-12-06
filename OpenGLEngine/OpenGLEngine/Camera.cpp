#include "Camera.h"

void Camera::UpdateCameraVectors()
{
	vec3 front;
	front.x = cos(radians(Yaw)) * cos(radians(Pitch));
	front.y = sin(radians(Pitch));
	front.z = sin(radians(Yaw)) * cos(radians(Pitch));
	Front = normalize(front);

	Right = normalize(cross(Front, WorldUp));
	Up = normalize(cross(Right, Front));
}
void Camera::KeyboardUpdate(Camera_Movement direction, float deltaTime)
{
	float velocity = MovementSpeed * deltaTime;
	if (direction == FORWARD)
	{
		Position += Front * velocity;
	}
	if (direction == BACKWARD)
	{
		Position -= Front * velocity;
	}
	if (direction == LEFT)
	{
		Position -= Right * velocity;
	}
	if (direction == RIGHT)
	{
		Position += Right * velocity;
	}
}
void Camera::MouseUpdate(float Xoffset, float Yoffset, GLboolean ConstrainPitch)
{
	Xoffset *= MouseSensitivity;
	Yoffset *= MouseSensitivity;

	Yaw += Xoffset;
	Pitch += Yoffset;

	if (ConstrainPitch)
	{
		if (Pitch > 89.0f)
		{
			Pitch = 89.0f;
		}
		if (Pitch < -89.0f)
		{
			Pitch = -89.0f;
		}
	}
}
void Camera::ProcessMouseScroll(float yoffset)
{
	if (Zoom >= 1.0f && Zoom <= 45.0f)
		Zoom -= yoffset;
	if (Zoom <= 1.0f)
		Zoom = 1.0f;
	if (Zoom >= 45.0f)
		Zoom = 45.0f;
}

void Camera::Update(Shader shader, unsigned int ScreenWidth, unsigned int ScreenHeight)
{
	glm::mat4 projection = glm::perspective(glm::radians(Zoom), (float)ScreenWidth / (float)ScreenHeight, 0.1f, 100.0f);
	glm::mat4 view = GetViewMatrix();

	shader.SetVec3f("viewPos", Position);
	shader.SetMatrix4fv("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	shader.SetMatrix4fv("view", view);
}