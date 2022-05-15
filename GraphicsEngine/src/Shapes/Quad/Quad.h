#pragma once
#include <iostream>
#include "Shader.h"

#include "../Shape.h"
class Quad : public Shape
{
public:
	Quad(const std::string& name);
	~Quad();
	const ElementBuffer& GetEB()const { return *m_EB; };
	void Rotate(float degrees, const glm::vec3& direction);
	virtual bool isIndexed() const{ return true; };
	void Draw();
private:
	Texture *m_texture2;
	

};

