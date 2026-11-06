
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include <fstream>
#include <sstream>
#include <iostream>


// Importing Buffer Objects
#include "Essentials/VAO.h"
#include "Essentials/VBO.h"
#include "Essentials/IBO.h"


// Importing Important classes
#include "Essentials/Renderer.h"
#include "Essentials/Texture.h"
#include "Essentials/Shader.h"
#include "Essentials/Camera.h"



struct UVs
{
	float u, v, width, height;
	UVs()
		: u{ 0.0f }, v{ 0.0f }, width{ 0.0f }, height{ 0.0f }
	{

	}
};




int width = 1280;
int height = 720;


int main() {
	
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, "V12 Final", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create window\n";
		return -1;
	}
	glfwMakeContextCurrent(window);

	// gladLoadGL();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, width, height);

	// Making temporary UVs
	/*UVs uvs{};

	auto generateUVs = [&](float startX, float startY, float spriteWidth, float spriteHeight)
		{
			uvs.width = spriteWidth / texture->GetWidth();
			uvs.height = spriteHeight / texture->GetHeight();

			uvs.u = startX * uvs.width;
			uvs.v = startY * uvs.height;
		};

	generateUVs(1, 62, 16, 16);*/

	//float vertices[] =
	//{
	//	10.f, 26.f, 0.0f,  	// TL
	//	10.f, 10.f, 0.0f,   // TR
	//	26.f, 10.f, 0.0f,  	// BR
	//	26.f, 26.f, 0.0f 	// BL
	//};


	float vertices[] = {
		// x, y, z			   //U, V
		 100.0f,  100.0f, 0.0f, 0.0f, 0.0f,	// Top-Left
		 200.0f, 100.0f, 0.0f, 0.0f, 1.0f,	// Bottom-Left
		 200.0f, 200.0f, 0.0f,  1.0f, 1.0f,	// Bottom-Right
		 100.0f,  200.0f, 0.0f,	 1.0f, 0.0f		// Top-Right
	};

	// Hence, textured quads can be in the format
	// x, y, z,		u, v
	// I hope


	/*GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 3
	};*/
	GLuint indices[] =
	{
		0, 1, 2,
		2, 3, 0,
	};

	std::string vPath = "Essentials/BasicShader.vert";
	std::string fPath = "Essentials/BasicShader.frag";

	Shader shader;
	shader.CompileShader(vPath, fPath);

	Texture texture("wall.jpg");
	texture.Bind();


	VAO vao;
	vao.Bind();
	VBO vbo(vertices, sizeof(vertices));
	IBO ibo(indices, sizeof(indices));

	vao.LinkAttrib(0, 3, 5 * sizeof(float), (void*)0);
	vao.LinkAttrib(1, 2, 5 * sizeof(float), (void*)(3 * sizeof(float)));

	vao.Unbind();
	vbo.Unbind();
	ibo.Unbind();



	/*glm::mat4 projection = glm::ortho(0.0f, float(width), 0.0f, float(height), -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(100, 0, 0));*/

	// Create camera
	Camera camera2d(1280.0f, 720.0f);
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(100, 0, 0));
	
	Renderer renderer;
	float LastFrame = float(glfwGetTime());
	float CurrentFrame = 0.0f;
	float dt = 0.0f;
	while (!glfwWindowShouldClose(window))
	{
		CurrentFrame = glfwGetTime();
		dt = CurrentFrame - LastFrame;
		if (dt > 1.0f / 60.0f)
		{
			renderer.Clear();
			shader.Activate();
			
			shader.SetUniform1i("u_Texture", 0);

			// Matrix shit
			glm::mat4 mvp = camera2d.GetCameraMatrix() * model;
			// glm::mat4 projection = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
			// glm::mat4 mvp = projection * model;
			shader.SetUniformMat4fv("u_mvp", mvp);

			// Draw stuff
			renderer.Draw(vao, ibo, shader);

			camera2d.Update();
			shader.Disable();
			LastFrame = CurrentFrame;
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//Clean up
	shader.Destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
