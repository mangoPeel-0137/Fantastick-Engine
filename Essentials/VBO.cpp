#include "VBO.h"
#include "VAO.h"

VBO::VBO(float* data, unsigned int size)
{
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);

	glBufferData(
		GL_ARRAY_BUFFER,						// The target buffer type
		size * 3 * sizeof(float),	// Size in bytes of the buffer object's new data store
		data,								// Pointer of the data that will be coped to the data store
		GL_STATIC_DRAW							// The expected usage pattern of the data store
	);
}

VBO::~VBO()
{
	glDeleteBuffers(1, &m_ID);
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
