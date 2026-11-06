#pragma once

#include <glad/glad.h>

class IBO
{
private:
	unsigned int m_ID;
	unsigned int m_Count;
public:
	IBO(const unsigned int* data, GLsizeiptr size);
	~IBO();

	void Bind();
	void Unbind();

	unsigned int GetCount();

};
