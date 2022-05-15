#include "Camera.h"
float Camera::offsetX;
float Camera::offsetY;
Camera::Camera()
{
	m_Position = glm::vec3(0.0f, 0.0f, 3.0f);
	m_Direction = glm::vec3(0.0f, 0.0f, -1.0f);
	m_Up = glm::vec3(0.0f, 1.0f, 0.0f);
    m_WorldUp = m_Up;
	m_Right = glm::vec3(1.0f, 0.0f, 0.0f);
	m_LookAt = glm::lookAt(m_Position, m_Position + m_Direction, m_Up);
    updateCameraVectors();
}

void Camera::updateCameraVectors() {
    glm::vec3 front;
    m_Direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_Direction.y = sin(glm::radians(m_pitch));
    m_Direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_Direction = glm::normalize(m_Direction);
    // also re-calculate the Right and Up vector
    m_Right = glm::normalize(glm::cross(m_Direction, m_WorldUp)); 
    // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    m_Up = glm::normalize(glm::cross(m_Right, m_Direction));
}

void Camera::ProcessMouseMovement() {
    Camera::offsetX *= m_sensitivty;
    Camera::offsetY *= m_sensitivty;

    m_yaw += Camera::offsetX;
    m_pitch += Camera::offsetY;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (true)
    {
        if (m_pitch > 89.0f)
            m_pitch = 89.0f;
        if (m_pitch < -89.0f)
            m_pitch = -89.0f;
    }

    // update Direction, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}