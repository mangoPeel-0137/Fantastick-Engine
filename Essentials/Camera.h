#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>




class Camera
{
private:
	glm::mat4 m_ProjectionMatrix; // Projection matrix
	glm::mat4 m_viewMatrix;		// View matrix
	glm::mat4 m_CameraMatrix; // view * projection = camera matrix


	glm::vec2 m_Position;
	float m_Rotation;
	float m_Scale;

	float m_Width;
	float m_Height;
	float aspectRatio = m_Width / m_Height;
	bool m_NeedUpdate;



public:
	Camera();
	Camera(float width, float height);



	// Camera var setters
	void SetProjection(float left, float right, float bottom, float top, float near, float far);
	inline void SetPosition(glm::vec2 newPosition) { m_Position = newPosition; m_NeedUpdate = true; }
	inline void SetScale(float scale) { m_Scale = scale; m_NeedUpdate = true; }
	inline void SetRotation(float rotation) { m_Rotation = rotation; m_NeedUpdate = true; }


	// Camera var getters
	inline glm::vec2 GetPosition() const { return m_Position; }
	inline float GetScale() const { return m_Scale; }
	inline float GetRotation() const { return m_Rotation; }

	// Camera Matrix getters
	inline glm::mat4 GetCameraMatrix() const { return m_CameraMatrix; }
	inline glm::mat4 GetProjectionMatrix() const { return m_ProjectionMatrix; }
	inline glm::mat4 GetViewMatrix() const { return m_viewMatrix; }



	void Update();


};


