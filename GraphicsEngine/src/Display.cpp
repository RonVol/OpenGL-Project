#include "Display.h"
float Display::m_mouseLastX;
float Display::m_mouseLastY;
bool Display::m_firstMouseClick;
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);

}
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{

	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (Display::m_firstMouseClick)
	{
		Display::m_mouseLastX = xpos;
		Display::m_mouseLastY = ypos;
		Display::m_firstMouseClick = false;
	}
	
	float xoffset = xpos - Display::m_mouseLastX;
	float yoffset = Display::m_mouseLastY - ypos; // reversed since y-coordinates go from bottom to top

	Display::m_mouseLastX = xpos;
	Display::m_mouseLastY = ypos;

	Camera::offsetX = xoffset;
	Camera::offsetY = yoffset;
}
bool Display::Init(uint32_t width, uint32_t height, const std::string& title)
{
	m_width = width;
	m_height = height;
	m_title = title;
	glfwInit();
	//Version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Anti-Aliasing
	glfwWindowHint(GLFW_SAMPLES, 4);
	//V-SYNC
	glfwSwapInterval(1);
	
	//Create window and set as context
	m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}
	
	//Set window as context
	glfwMakeContextCurrent(m_window);
	//Load GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return false;
	}
	//Z-Buffer(Depth testing)
	glEnable(GL_DEPTH_TEST);

	//callbacks and inputs
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(m_window, mouse_callback);


	// set color for glClear(Default background color)
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	m_camera = new Camera;

	Display::m_mouseLastX = m_width / 2;
	Display::m_mouseLastY = m_height / 2;

	return true;
}

bool Display::ShouldWindowClose() 
{
	return glfwWindowShouldClose(m_window);
}

void Display::ProcessInput()
{
	//esc to close window
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window, true);

	Camera* cam = m_camera;
	//calculate delta time - to make camera movement consistent
	float currentFrame = static_cast<float>(glfwGetTime());
	m_deltaTime = currentFrame - m_lastFrameTime;
	m_lastFrameTime = currentFrame;
	float CameraSpeed = cam->GetSpeed() * m_deltaTime;
	//W to go forward
	if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
		cam->SetPosition(cam->GetPosition() + (CameraSpeed * cam->GetDirection()));
	//S to go backwards
	if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
		cam->SetPosition(cam->GetPosition() - (CameraSpeed * cam->GetDirection()));
	//D to go right
	if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
		cam->SetPosition(cam->GetPosition() + (CameraSpeed * cam->GetRight()));
	//A to go left
	if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
		cam->SetPosition(cam->GetPosition() - (CameraSpeed *cam->GetRight()));	
	//space to go up
	if (glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS)
		cam->SetPosition(cam->GetPosition() + (CameraSpeed * cam->GetUp()));
	//left ctrl to go down
	if (glfwGetKey(m_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		cam->SetPosition(cam->GetPosition() - (CameraSpeed * cam->GetUp()));

	//std::cout<<"Camera cords:" << cam->GetPosition().x << ", " << cam->GetPosition().y << ", " << cam->GetPosition().z << std::endl;


	

	
	

}

void Display::StartFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Display::EndFrame() 
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}
void Display::GetFPS()
{
	static double previous_seconds = glfwGetTime();
	static int frame_count;
	double current_seconds = glfwGetTime();
	double elapsed_seconds = current_seconds - previous_seconds;
	if (elapsed_seconds > 0.25) {
		previous_seconds = current_seconds;
		double fps = (double)frame_count / elapsed_seconds;
		char tmp[128];
		sprintf_s(tmp, "FPS: %.2f", fps);
		
		glfwSetWindowTitle(m_window, tmp);
		frame_count = 0;
	}
	frame_count++;
}

void Display::PrintInfo() {

		GLenum params[] = {
		  GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
		  GL_MAX_CUBE_MAP_TEXTURE_SIZE,
		  GL_MAX_DRAW_BUFFERS,
		  GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
		  GL_MAX_TEXTURE_IMAGE_UNITS,
		  GL_MAX_TEXTURE_SIZE,
		  GL_MAX_VARYING_FLOATS,
		  GL_MAX_VERTEX_ATTRIBS,
		  GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
		  GL_MAX_VERTEX_UNIFORM_COMPONENTS,
		  GL_MAX_VIEWPORT_DIMS,
		  GL_STEREO,
		};
		const char* names[] = {
		  "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS",
		  "GL_MAX_CUBE_MAP_TEXTURE_SIZE",
		  "GL_MAX_DRAW_BUFFERS",
		  "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS",
		  "GL_MAX_TEXTURE_IMAGE_UNITS",
		  "GL_MAX_TEXTURE_SIZE",
		  "GL_MAX_VARYING_FLOATS",
		  "GL_MAX_VERTEX_ATTRIBS",
		  "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS",
		  "GL_MAX_VERTEX_UNIFORM_COMPONENTS",
		  "GL_MAX_VIEWPORT_DIMS",
		  "GL_STEREO",
		};
		std::cout << "***Info***" << std::endl;
		//char msg[256];
		for (int i = 0; i < 10; i++) {
			int v = 0;
			glGetIntegerv(params[i], &v);
			std::cout << names[i] <<"   " << v << std::endl;
		}
		int v[2];
		v[0] = v[1] = 0;
		glGetIntegerv(params[10], v);
		std::cout << names[10] << "   " << v[0] << "   " <<v[1] << std::endl;
		unsigned char s = 0;
		glGetBooleanv(params[11], &s);
		std::cout << names[11] << "   " << s << std::endl;
		std::cout << "***Info***" << std::endl;
}

Display::~Display() 
{
	delete m_camera;
	glfwDestroyWindow(m_window);
	glfwTerminate();
}
