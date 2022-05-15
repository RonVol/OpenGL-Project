#pragma once

#include <string>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Camera.h"


class Display
{
public:
	Display() : m_window(nullptr),m_camera(nullptr), m_width(0), m_height(0), m_title(""), m_deltaTime(0), m_lastFrameTime(0) {};
	~Display();

	//init GLFW and GLAD
	bool Init(uint32_t width, uint32_t height, const std::string& title);
	//check if window should close
	bool ShouldWindowClose();
	//process inputs every frame
	void ProcessInput();
	//things to do at start of each frame(clear screen..)
	void StartFrame();
	//things to do at end of each frame(swap buffers, poll events..)
	void EndFrame();
	//show fps
	void GetFPS();
	//print hardware related information
	void PrintInfo();

	Camera* GetCamera() const { return m_camera; };

	GLFWwindow* GetWindow()const { return m_window; };
	static float m_mouseLastX;
	static float m_mouseLastY;
	static bool m_firstMouseClick;
private:
	GLFWwindow* m_window;
	Camera* m_camera;
	uint32_t m_width;
	uint32_t m_height;
	std::string m_title;
	//input related
	//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	float m_deltaTime;
	float m_lastFrameTime;
	
	
	

};

