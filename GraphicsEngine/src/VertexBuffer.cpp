#include "VertexBuffer.h"
#include <glad/glad.h>

VertexBuffer::VertexBuffer(const void* data, uint32_t size) {
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	std::cout << "created vertex Buffer!!" << std::endl;
}

VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &m_ID);
	std::cout << "DES vertex Buffer!!" << std::endl;
}

void VertexBuffer::BindVB() const{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VertexBuffer::UnbindVB() const{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}