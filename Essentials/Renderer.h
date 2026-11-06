#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "VAO.h"
#include "IBO.h"
#include "Shader.h"

class Renderer
{
private:
	unsigned int ID;
public:
	void Clear(float r = 0.07f, float g = 0.13f, float b = 0.17f, float a = 1.0f);
	void Draw(VAO& vao, IBO& ibo, Shader& shader);


};

