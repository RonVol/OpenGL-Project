#pragma once
#include <vector>
#include <glad/glad.h>

struct VertexBufferAttribute 
{
	uint32_t type{};
	uint32_t ComponentsPerVertex{};
	GLboolean ShouldNormalize{};
	uint32_t stride{};

	static uint32_t GetTypeSize(uint32_t type) {
		//might add more
		switch(type)
		{
			case GL_FLOAT:return sizeof(float);

		}
		return 0;
	}

};

class VertexBufferLayout {
public:
	VertexBufferLayout(){ std::cout << "created vertex buffer Layout!!!" << std::endl; };
	~VertexBufferLayout(){ std::cout << "DES vertex Layout!!" << std::endl; };

	void PushFloat(uint32_t ComponentsPerVertex, uint32_t untillNextVertex, GLboolean shouldNormalize)
	{
		VertexBufferAttribute a;
		a.ComponentsPerVertex = ComponentsPerVertex;
		a.ShouldNormalize = shouldNormalize;
		a.type = GL_FLOAT;
		a.stride = untillNextVertex * sizeof(float);

		m_Attributes.push_back(a);
		//m_Stride = ComponentsPerVertex * sizeof(float);
	};
	
	//inline uint32_t GetStride() const{ return m_Stride; };
	inline const std::vector<VertexBufferAttribute>& GetAttributes() const { return m_Attributes; };

private:
	std::vector<VertexBufferAttribute> m_Attributes;
	//uint32_t m_Stride;
};
