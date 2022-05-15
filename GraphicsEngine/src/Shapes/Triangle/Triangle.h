#pragma once
#include "../Shape.h"
class Triangle : public Shape
{

public:
	Triangle(const std::string& name);
	~Triangle(){};
	bool isIndexed() const { return false; };
	void Draw();
private:
	uint32_t m_base;
	uint32_t m_height;
};

