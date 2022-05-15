#include "Shape.h"

Shape::~Shape() {
	delete m_shader;
	delete m_texture1;
	delete m_VBL;
	delete m_VB;
	delete m_VA;
}

void Shape::LoadTexture(const std::string& filePath) {

}