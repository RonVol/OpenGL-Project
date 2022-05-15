#include "Renderer.h"


void Renderer::Draw(Camera* cam) const
{
	cam->ProcessMouseMovement();
	int i;
	for (i=0;i<m_shapes.size();i++)
	{
		m_shapes[i]->SetViewMat(cam->GetLookAtMat());
		m_shapes[i]->Draw();
	}
	
}

void Renderer::PushShape(Shape* shape) {
	m_shapes.push_back(shape);
}