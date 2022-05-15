#pragma once
#include "VertexArray.h"
#include "ElementBuffer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
class Shape
{
public:
	Shape():m_position(glm::vec3(0.0f)),m_shader(nullptr),m_texture1(nullptr),m_VA(nullptr),m_VB(nullptr),m_VBL(nullptr),m_EB(nullptr),m_name("Shape"),
	      m_model(glm::mat4(1.0f)), m_view(glm::mat4(1.0f)), m_proj(glm::mat4(1.0f)){};
	virtual ~Shape();
	virtual void LoadTexture(const std::string& filePath);
	virtual const VertexArray& GetVA()const { return *m_VA; };
	virtual const VertexBuffer& GetVB()const { return *m_VB; };
	virtual const Shader& GetShader()const { return *m_shader; };
	virtual const ElementBuffer& GetEB()const { return *m_EB; };
	virtual const glm::mat4& GetViewMat() const { return m_view; };
	virtual void SetViewMat(const glm::mat4& view) { m_view = view;}
	virtual bool isIndexed() const { return false; };
	virtual void Draw() = 0;
	virtual const glm::mat4& GetMVP() { m_mvp = m_proj * m_view * m_model; return m_mvp; };

	glm::mat4 m_model, m_view, m_proj, m_mvp;
protected:
	std::string m_name;
	glm::vec3 m_position;
	Shader* m_shader;
	Texture* m_texture1;
	VertexArray* m_VA;
	VertexBuffer* m_VB;
	VertexBufferLayout* m_VBL;
	ElementBuffer* m_EB;
	


};

