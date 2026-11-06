#include "Camera.h"

Camera::Camera()
	: Camera::Camera(960, 540)
{
}

Camera::Camera(float width, float height)
	: m_Width{width}, m_Height{height}, m_Scale{1.0f}
	, m_Position{ glm::vec2{0} }, m_CameraMatrix{1.0f}, m_ProjectionMatrix{1.0f}
	, m_Rotation{0.0f}, m_NeedUpdate{true}, m_viewMatrix{1.0f}
{
	m_ProjectionMatrix = glm::ortho(
		0.0f,							// Left 
		m_Width,	// Right
		0.0f,							// Bottom
		m_Height,	// Top
		-1.0f,							// Near
		1.0f							// Far
	);
	Update();
}

void Camera::SetProjection(float left, float right, float bottom, float top, float near = -1.0f, float far = 1.0f)
{
	m_ProjectionMatrix = glm::ortho(left, right, bottom, top, near, far);
	m_NeedUpdate = true;
	Update();
}

void Camera::Update()
{
	if (!m_NeedUpdate)
		return;

	// Translate, rotate and scale update
	m_viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(m_Position, 1.0f));
	m_viewMatrix = glm::rotate(m_viewMatrix, glm::radians(m_Rotation), glm::vec3(0, 0, 1));
	m_viewMatrix = glm::scale(m_viewMatrix, glm::vec3(m_Scale, m_Scale, 1.0f));

	m_CameraMatrix = m_ProjectionMatrix * m_viewMatrix;
	m_NeedUpdate = false;
}
