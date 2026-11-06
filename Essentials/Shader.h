#pragma once

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>

#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(const char* filename);

class Shader {
public:
	GLuint ID = 0;
	GLuint vertexShader, fragmentShader;

	void CompileShader(std::string vexPath, std::string fragPath);

	void Activate();
	void Disable();

	void checkShader(GLuint shader, const std::string& type);
	void checkProgram(GLuint program);

	void SetUniform1i(const char* name, int unit);
	void SetUniformMat4fv(const char* name, const glm::mat4& matrix);


	void Destroy();


};

