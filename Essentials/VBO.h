#pragma once


#include <glad/glad.h>

class VBO
{
private:
	unsigned int m_ID;

public:
	VBO(float* data, unsigned int size);
	~VBO();
	void Bind();
	void Unbind();
};

