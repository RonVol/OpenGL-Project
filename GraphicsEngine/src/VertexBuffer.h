#pragma once

#include <iostream>
class VertexBuffer
{
public:
	VertexBuffer(const void* data, uint32_t size);
	~VertexBuffer();

	void BindVB() const;
	void UnbindVB() const;
	uint32_t GetID()const { return m_ID; };
private:
	uint32_t m_ID;

};

