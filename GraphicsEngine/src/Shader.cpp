#include "Shader.h"
#include <fstream>
#include <string>
#include <sstream>
Shader::Shader(const std::string& filePath):m_ID(0) {

	std::ifstream stream(filePath);
	if (!stream.is_open())
	{
		std::cout << "FAILED TO OPEN SHADER FILE :: "<< filePath << std::endl;
	}
	
	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT =1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if(line.find("#Define Vertex Shader") != std::string::npos)
		{
			type = ShaderType::VERTEX;
		}
		else if (line.find("#Define Fragment Shader") != std::string::npos)
		{
			type = ShaderType::FRAGMENT;
		}
		else 
		{
			ss[(int)type] << line << '\n';
		}
		
	}
	m_VertexCode = ss[0].str();
	m_FragmentCode = ss[1].str();
	CreateShader();
}

void Shader::CreateShader() 
{
	uint32_t vs, fs;
	const char* vss = m_VertexCode.c_str();
	const char* fss = m_FragmentCode.c_str();

	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vss, NULL);
	glCompileShader(vs);
	//**Check compilation errors
	int  success;
	char info[512];
	glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vs, 512, NULL, info);
		std::cout << "VERTEX SHADER COMPILATION ERROR ! :: " << info << std::endl;
	}


	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fss, NULL);
	glCompileShader(fs);
	//**Check compilation errors
	glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fs, 512, NULL, info);
		std::cout << "FRAGMENT SHADER COMPILATION ERROR ! :: " << info << std::endl;
	}

	m_ID = glCreateProgram();
	glAttachShader(m_ID, vs);
	glAttachShader(m_ID, fs);
	glLinkProgram(m_ID);
	//**check linking errors
	glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_ID, 512, NULL, info);
		std::cout << "SHADER LINKING ERROR ! :: " << info << std::endl;
	}

	glDeleteShader(vs);
	glDeleteShader(fs);

}

uint32_t Shader::getUniformLocation(const GLchar* name) {

	int loc = glGetUniformLocation(m_ID, name);
	if (loc == -1)
		std::cout << "UNIFORM NOT FOUND ! :: " << name << std::endl;		
	return loc;
};

void Shader::Use() const{
	glUseProgram(m_ID);
}

void Shader::SetUniform1bool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_ID, name.c_str()), (int)value);
}
void Shader::SetUniform1i(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
}
void Shader::SetUniform1f(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
}

void Shader::SetUniformMatrix4f(const std::string& name, glm::mat4 mat) const 
{
	glUniformMatrix4fv(glGetUniformLocation(m_ID,name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}