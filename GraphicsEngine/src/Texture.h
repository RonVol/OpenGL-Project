#pragma once
#include <iostream>

class Texture
{
public:
	Texture() :m_ID(0),m_filePath(""),m_Width(0),m_Height(0),m_NumOfChannels(0) {};
	Texture(const std::string& filePath);
	~Texture();
	uint32_t GetID() { return m_ID; };

	void BindTexture(uint32_t slot) const;
	void UnbindTexture() const;
private:
	uint32_t m_ID;
	std::string m_filePath;
	
	int m_Width;
	int m_Height;
	int m_NumOfChannels;

};

