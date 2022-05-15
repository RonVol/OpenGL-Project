#pragma once
#include "Shapes/Shape.h"
#include "Camera.h"
#include <vector>


//make a singletone
class Renderer
{
public:
	Renderer(){};
	~Renderer(){};
	void Draw(Camera* cam) const;
	void PushShape(Shape* shape);

private:
	std::vector<Shape*> m_shapes;

};

