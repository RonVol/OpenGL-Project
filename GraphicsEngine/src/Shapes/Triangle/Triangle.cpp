#include "Triangle.h"


Triangle::Triangle(const std::string& name="Triangle1") :m_base(1), m_height(1) {
	float vertices[] = {
		0.0f,0.5f,0.0f,     0.0f,0.5f,
		0.5f,-0.5f,0.0f,    0.5f,-0.5f,
		-0.5f,-0.5f,0.0f    -0.5f,-0.5f
	};

	m_shader = new Shader("../GraphicsEngine/src/Shapes/Triangle/TriangleShader.shader");

	m_VA = new VertexArray;
	(*m_VA).BindVA();
	m_VB = new VertexBuffer(vertices, sizeof(vertices));
	m_VBL = new VertexBufferLayout;
	(*m_VBL).PushFloat(3, 5, false);
	(*m_VBL).PushFloat(2, 5, false);
	(*m_VA).AddVertexBuffer(*m_VB, *m_VBL);

	m_texture1 = new Texture("resources/pexels1.jpg");
	(*m_shader).Use();
	(*m_shader).SetUniform1i("texture1", 0);
	(*m_texture1).BindTexture(0);
	m_name = name;

	m_model = glm::mat4(1.0f);
	m_view = glm::mat4(1.0f);
	m_proj = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
	(*m_shader).SetUniformMatrix4f("model", m_model);
	(*m_shader).SetUniformMatrix4f("view", m_view);
	(*m_shader).SetUniformMatrix4f("projection", m_proj);

}

void Triangle::Draw() {
	m_VA->BindVA();
	m_shader->Use();
	m_texture1->BindTexture(0);
	m_view = GetViewMat();
	m_shader->SetUniformMatrix4f("view", m_view);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}