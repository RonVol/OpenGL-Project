#pragma once
#include <iostream>
#include <glad/glad.h>
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void AddVertexBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void BindVA() const;
	void UnbindVA() const;
	uint32_t GetID()const { return m_ID; };

private:
	uint32_t m_ID;
};

