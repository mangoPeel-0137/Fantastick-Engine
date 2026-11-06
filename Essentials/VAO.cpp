#include "VAO.h"


VAO::VAO()
{
	glGenVertexArrays(1, &m_ID);
}

VAO::~VAO()
{
	glDeleteBuffers(1, &m_ID);
}

void VAO::Bind()
{
	glBindVertexArray(m_ID);
}

void VAO::LinkAttrib(unsigned int layout, int size, GLsizeiptr stride, const void* offset)
{
	// Vertices Link Attrib
	glVertexAttribPointer(
		layout,										// Attribute 0 -- The layout position in the shader
		size,										// Size		   -- Number of components per vertex
		GL_FLOAT,								// Type		   -- Data type of the above components
		GL_FALSE,								// Normalized  -- Specifies if fixed-point data values should be normalized
		stride,									// Stride	   -- Specifies the byte offset b/w consecutive attributes
		offset								// Pointer	   -- Specifies the offset of the first component
	);
	// stride = 5 * sizeof(float)
	glEnableVertexAttribArray(layout);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

