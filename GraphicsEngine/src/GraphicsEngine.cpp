

#include "GraphicsEngine.h"
#include "Renderer.h"
#include "Display.h"
#include "Camera.h"
#include "Shapes/Shape.h"
#include "Shapes/Quad/Quad.h"
#include "Shapes/Triangle/Triangle.h"

namespace GraphicsEngine {
	void Run() {
		int WindowWidth = 800;
		int WindowHeight = 600;
		Display d;
		if (!d.Init(WindowWidth, WindowHeight, "My Project")) {
			//
		}
		d.PrintInfo();
		////glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		Triangle tri("triangle222");
		Quad quad("Quad111");
		quad.Rotate(45.0f, glm::vec3(1.0f, 0.0f, 1.0f));
		Renderer ren;
		ren.PushShape(&tri);
		ren.PushShape(&quad);

		while (!d.ShouldWindowClose()) {
			
			d.StartFrame();
			d.ProcessInput();
			quad.Rotate(glfwGetTime()/100, glm::vec3(1.0f, 1.0f, 1.0f));
			ren.Draw(d.GetCamera());

			d.EndFrame();
		}

	
	

	}
}