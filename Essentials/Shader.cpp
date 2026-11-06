#include "Shader.h"

std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

void Shader::checkShader(GLuint shader, const std::string& type) {
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char infoLog[1024];
		glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
		std::cout << "ERROR: Shader compilation failed\n";
		std::cerr << "ERROR: " << type << " compilation failed:\n" << infoLog << "\n";
	}
	std::cout << "Shader " << type << " successfully compiled\n";
}

void Shader::checkProgram(GLuint program) {
	GLint success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		char infoLog[1024];
		glGetProgramInfoLog(program, sizeof(infoLog), nullptr, infoLog);
		std::cout << "ERROR: Program linking failed:\n";
		std::cerr << "ERROR: Program linking failed:\n" << infoLog << "\n";;
	}
	std::cout << "Program linking success\n";
}

void Shader::SetUniform1i(const char* name, int unit)
{
	GLuint loc = glGetUniformLocation(ID, name);
	glUniform1i(loc, unit);
}

void Shader::SetUniformMat4fv(const char* name, const glm::mat4& matrix)
{
	unsigned int projLoc = glGetUniformLocation(ID, name);
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, &matrix[0][0]);
}


void Shader::CompileShader(std::string vexPath, std::string fragPath)
{
	std::string vCode = get_file_contents(vexPath.c_str());
	std::string fCode = get_file_contents(fragPath.c_str());

	const char* vSrc = vCode.c_str();
	const char* fSrc = fCode.c_str();

	// Creating vertex shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vSrc, nullptr);
	glCompileShader(vertexShader);

	// Creating fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fSrc, nullptr);
	glCompileShader(fragmentShader);



	// Creating shader program
	ID = glCreateProgram();

	// Linking shader program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);


	//// Error checking code 
	//auto checkShader = [](GLuint shader, const std::string& type) {
	//	GLint success;
	//	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	//	if (!success) {
	//		char infoLog[1024];
	//		glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
	//		std::cerr << "ERROR: " << type << " compilation failed:\n" << infoLog << "\n";
	//	}
	//	};

	//auto checkProgram = [](GLuint program) {
	//	GLint success;
	//	glGetProgramiv(program, GL_LINK_STATUS, &success);
	//	if (!success) {
	//		char infoLog[1024];
	//		glGetProgramInfoLog(program, sizeof(infoLog), nullptr, infoLog);
	//		std::cerr << "ERROR: Program linking failed:\n" << infoLog << "\n";
	//	}
	//	};


	//// Check vertex compilation
	//checkShader(vertexShader, "VERTEX");

	//// Check fragment compilation
	//checkShader(fragmentShader, "FRAGMENT");

	//// Check program linking (call after glLinkProgram)
	//checkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Disable()
{
	glUseProgram(0);
}

void Shader::Destroy()
{
	glDeleteProgram(ID);
}
