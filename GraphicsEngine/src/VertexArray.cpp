#include "VertexArray.h"
#include <vector>

VertexArray::VertexArray() {
	glGenVertexArrays(1, &m_ID);
	std::cout << "created vertex array!!" << std::endl;
	
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_ID);
	std::cout << "DES vertex array!!" << std::endl;
}
void VertexArray::AddVertexBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {

	BindVA();
	vb.BindVB();
	
	const std::vector<VertexBufferAttribute>& attbs = layout.GetAttributes();
	uint32_t i, offset = 0;
	for (i = 0; i < attbs.size();i++) {
		const VertexBufferAttribute& att = attbs[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, att.ComponentsPerVertex, att.type, att.ShouldNormalize, att.stride, (const void*)offset);
		offset += att.ComponentsPerVertex * VertexBufferAttribute::GetTypeSize(att.type);
	}
	
}

void VertexArray::BindVA() const{
	glBindVertexArray(m_ID);
}

void VertexArray::UnbindVA() const{
	glBindVertexArray(0);
}