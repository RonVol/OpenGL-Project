#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Camera
{
public:
	Camera();
	~Camera(){};



	const glm::vec3& GetPosition() const{ return m_Position; };
	void SetPosition(glm::vec3 pos) { m_Position = pos; };

	const glm::vec3& GetDirection() const { return m_Direction; };
	void SetDirection(float x, float y, float z) { m_Direction = glm::vec3(x, y, z); };

	const glm::vec3& GetUp() const { return m_Up; };
	void SetUp(float x, float y, float z) { m_Up = glm::vec3(x, y, z); };

	const glm::vec3& GetRight() const { return m_Right; };
	void SetRight(float x, float y, float z) { m_Right = glm::vec3(x, y, z); };

	float GetSpeed() const { return m_Speed; };

	const glm::mat4& GetLookAtMat() { m_LookAt = glm::lookAt(m_Position, m_Position + m_Direction, m_Up); return m_LookAt; };

	void ProcessMouseMovement();

	static float offsetX;
	static float offsetY;
private:
	glm::vec3 m_Position;
	glm::vec3 m_Direction; // the direction the camera is pointing at
	glm::vec3 m_Up;
	glm::vec3 m_WorldUp;
	glm::vec3 m_Right;
	glm::mat4 m_LookAt;
	float m_Speed = 2.5f;
	float m_yaw = -90.0f;
	float m_pitch = 0.0f;
	float m_sensitivty = 0.1f;
	void updateCameraVectors();



};

