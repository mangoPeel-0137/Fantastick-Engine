#pragma once

#include <glad/glad.h>
#include "VBO.h"

class VAO
{
private:
	unsigned int m_ID;
public:
	VAO();
	~VAO();

	void Bind();
	void LinkAttrib(unsigned int layout, int size, GLsizeiptr stride, const void* offset);
	void Unbind();

};
