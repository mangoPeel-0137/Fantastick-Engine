#pragma once

#include <glad/glad.h>
#include <stb_image/stb_image.h>
#include <string>

class Texture {
private:

	GLuint m_ID;
	std::string m_filePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP; // BPP - Beats per pixel


public:
	Texture(const std::string& path);
	~Texture();




	void Bind(GLuint slot = 0);
	void Unbind(GLuint slot = 0);

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }

};

