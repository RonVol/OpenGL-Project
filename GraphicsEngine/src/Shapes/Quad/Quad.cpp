#include "Quad.h"


Quad::Quad(const std::string& name="Quad1") :m_texture2(nullptr){
	float vertices[] = {
		// positions        //texture
	  0.5f, 0.5f, -0.5f,   1.0f,1.0f,
	  0.5f,-0.5f, -0.5f,   1.0f,0.0f,
	 -0.5f,-0.5f, -0.5f,   0.0f,0.0f,
	 -0.5f, 0.5f, -0.5f ,  0.0f,1.0f,

	  0.5f, 0.5f, 0.5f,    1.0f,1.0f,
	  0.5f,-0.5f, 0.5f,    1.0f,0.0f,
	 -0.5f,-0.5f, 0.5f,    0.0f,0.0f,
	 -0.5f, 0.5f, 0.5f ,   0.0f,1.0f,

	  0.5f, 0.5f,-0.5f,    1.0f,1.0f,
	  0.5f,-0.5f,-0.5f,    0.0f,1.0f,
	  0.5f, 0.5f, 0.5f,    1.0f,0.0f,
	  0.5f,-0.5f, 0.5f ,   0.0f,0.0f,

	  -0.5f, 0.5f,-0.5f,    1.0f,1.0f,
	  -0.5f,-0.5f,-0.5f,    0.0f,1.0f,
	  -0.5f, 0.5f, 0.5f,    1.0f,0.0f,
	  -0.5f,-0.5f, 0.5f ,   0.0f,0.0f,

	  -0.5f, 0.5f,-0.5f,    0.0f,0.0f,
	  -0.5f, 0.5f, 0.5f,    1.0f,0.0f,
	   0.0f, 1.0f, -0.5f,    0.0f,1.0f,
	   0.0f, 1.0f, 0.5f ,   1.0f,1.0f,

	   0.5f, 0.5f,-0.5f,    0.0f,0.0f,
	   0.5f, 0.5f, 0.5f,    1.0f,0.0f,
	   0.0f, 1.0f, -0.5f,    0.0f,1.0f,
	   0.0f, 1.0f, 0.5f ,   1.0f,1.0f,
	};

	uint32_t elements[] = {
		0,1,2,
		0,2,3,

		4,5,6,
		4,6,7,

		8,9,10,
		9,10,11,

		12,13,14,
		13,14,15,

		16,18,19,
		16,17,19,

		20,22,23,
		20,21,23
	};

	m_shader = new Shader("../GraphicsEngine/src/Shapes/Quad/QuadShader.shader");

	m_VA = new VertexArray;
	(*m_VA).BindVA();
	m_VB = new VertexBuffer(vertices, sizeof(vertices));
	m_VBL = new VertexBufferLayout;
	(*m_VBL).PushFloat(3, 5, false);
	(*m_VBL).PushFloat(2, 5, false);	
	(*m_VA).AddVertexBuffer(*m_VB, *m_VBL);
	m_EB = new ElementBuffer(elements, 36);



	m_texture1 = new Texture("resources/container.jpg");
	m_texture2 = new Texture("resources/awesomeface.png");
	(*m_shader).Use();
	(*m_shader).SetUniform1i("texture1", 0);
	(*m_shader).SetUniform1i("texture2", 1);
	(*m_texture1).BindTexture(0);
	(*m_texture2).BindTexture(1);
	
	m_name = name;

	m_model = glm::mat4(1.0f);
	m_view = glm::mat4(1.0f);
	m_proj = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
	
	(*m_shader).SetUniformMatrix4f("model", m_model);
	(*m_shader).SetUniformMatrix4f("view", m_view);
	(*m_shader).SetUniformMatrix4f("projection", m_proj);

}

void Quad::Rotate(float degrees,const glm::vec3& direction) {
	//m_model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	//m_view = glm::mat4(1.0f);
	//m_proj = glm::mat4(1.0f);

	//// note that we're translating the scene in the reverse direction of where we want to move
	//m_view = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -3.0f));
	//m_proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	//m_model = glm::rotate(m_model, time * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

	//(*m_shader).SetUniformMatrix4f("model", m_model);
	//(*m_shader).SetUniformMatrix4f("view", m_view);
	//(*m_shader).SetUniformMatrix4f("projection", m_proj);
	m_model = glm::rotate(m_model, glm::radians(degrees), direction);	
	m_shader->SetUniformMatrix4f("model", m_model);
}

void Quad::Draw(){

	m_VA->BindVA();
	m_EB->BindEB();
	m_shader->Use();
	m_texture1->BindTexture(0);
	m_texture2->BindTexture(1);
	m_shader->SetUniformMatrix4f("view", m_view);
	glDrawElements(GL_TRIANGLES,m_EB->GetElementCount(), GL_UNSIGNED_INT, 0);
}

Quad::~Quad() {
	delete m_texture2;
	delete m_EB;
}