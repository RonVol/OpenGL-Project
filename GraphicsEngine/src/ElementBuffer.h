#pragma once

#include <iostream>
class ElementBuffer
{
public:
	ElementBuffer(const void* data, uint32_t eleCount);
	~ElementBuffer();

	uint32_t GetElementCount() const;
	void BindEB() const;
	void UnbindEB() const;
	uint32_t GetID()const { return m_ID; };
private:
	uint32_t m_ID;
	uint32_t m_ElementCount;

};

