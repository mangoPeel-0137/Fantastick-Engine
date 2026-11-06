#include "IBO.h"

IBO::IBO(const unsigned int* data, GLsizeiptr size)
{
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);

	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,				// The target buffer type
		size, // * sizeof(unsigned int),		// Size in bytes of the buffer object's new data store
		data,									// Pointer of the data that will be coped to the data store
		GL_STATIC_DRAW							// The expected usage pattern of the data store
	);
	m_Count = size;
}

IBO::~IBO()
{
	glDeleteBuffers(1, &m_ID);
}

void IBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void IBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IBO::GetCount()
{
	return m_Count;
}
