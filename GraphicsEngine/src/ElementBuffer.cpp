#include "ElementBuffer.h"
#include <glad/glad.h>

ElementBuffer::ElementBuffer(const void* data, uint32_t eleCount) : m_ElementCount(0) {
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, eleCount * sizeof(uint32_t), data, GL_STATIC_DRAW);

	m_ElementCount = eleCount;
	std::cout << "created element buffer!!" << std::endl;
}

ElementBuffer::~ElementBuffer() {
	glDeleteBuffers(1, &m_ID);
	std::cout << "DES element buffer!!" << std::endl;
}

void ElementBuffer::BindEB() const{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void ElementBuffer::UnbindEB()const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

uint32_t ElementBuffer::GetElementCount() const{
	return m_ElementCount;
}