#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Shader
{
public:
	Shader(const std::string& filePath);
	~Shader(){};
	
	void Use() const;
	uint32_t GetID() const{ return m_ID; };
	uint32_t getUniformLocation(const GLchar* name);

	void SetUniform1bool(const std::string& name, bool value) const;
	void SetUniform1i(const std::string& name, int value) const;
	void SetUniform1f(const std::string& name, float value) const;
	void SetUniformMatrix4f(const std::string& name, glm::mat4 mat) const;
	
	
private:
	void CreateShader();
	uint32_t m_ID;
	std::string m_VertexCode;
	std::string m_FragmentCode;
	
	
	
};

