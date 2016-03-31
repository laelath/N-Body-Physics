#include <stdio.h>
#include <stdlib.h>

#include <GL/gl3w.h>

#include "shader.h"

#define VERTEX_CODE "#version 330 core\n\nlayout(location = 0) in vec3 vertex_position;\nuniform mat4 mvp;\n\nvoid main()\n{\n\tgl_Position = mvp * vec4(vertex_position, 1);\n}"
#define FRAGMENT_CODE "#version 330 core\n\nuniform vec3 in_color;\n\nout vec3 color;\n\nvoid main()\n{\n\tcolor = in_color;\n}"


/*char * getFile(char * path)
{
	char * text;
	FILE * file = fopen(path, "rb");
	if (file)
	{
		fseek(file, 0, SEEK_END);
		int fsize = ftell(file);
		rewind(file);
		
		text = malloc(fsize + 1);
		fread(text, 1, fsize, file);
		fclose(file);
		
		text[fsize] = 0;
	} else {
		printf("Cannot open file: %s\n", path);
	}
	return text;
}*/

int compileShader(const char * shaderSource, GLuint shaderID)
{
	glShaderSource(shaderID, 1, &shaderSource, NULL);
	glCompileShader(shaderID);
	
	GLint result = GL_FALSE;
	
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int infoLogLength;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		char * shaderErrorMessage = malloc(infoLogLength + 1);
		shaderErrorMessage[infoLogLength] = 0;
		glGetShaderInfoLog(shaderID, infoLogLength, NULL, shaderErrorMessage);
		printf("%s\n", shaderErrorMessage);
		free(shaderErrorMessage);
		return -1;
	}
	return 0;
}

GLuint loadShadersvf(char * vertex_shader_path, char * fragment_shader_path)
{
	printf("loading shader: %s\n", vertex_shader_path);
	char * vertexShaderCode = VERTEX_CODE; //getFile(vertex_shader_path);
	printf("loading shader: %s\n", fragment_shader_path);
	char * fragmentShaderCode = FRAGMENT_CODE; //getFile(fragment_shader_path);
	
	if (!vertexShaderCode || !fragmentShaderCode) return 0;
	
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	
	printf("Compiling shader: %s\n", vertex_shader_path);
	int vstatus = compileShader(vertexShaderCode, vertexShaderID);
	//free(vertexShaderCode);
	
	printf("Compiling shader: %s\n", fragment_shader_path);
	int fstatus  = compileShader(fragmentShaderCode, fragmentShaderID);
	//free(fragmentShaderCode);
	
	if (vstatus || fstatus)
	{
		printf("Error compiling shaders\n");
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		return 0;
	}
	
	printf("Linking program\n");
	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	
	GLint result = GL_FALSE;
	
	glGetProgramiv(programID, GL_LINK_STATUS, &result);
	if (result == GL_FALSE)
	{
		int infoLogLength;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
		char * programErrorMessage = malloc(infoLogLength + 1);
		programErrorMessage[infoLogLength] = 0;
		glGetProgramInfoLog(programID, infoLogLength, NULL, programErrorMessage);
		printf("%s\n", programErrorMessage);
		free(programErrorMessage);
	}
	
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);
	
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	
	return programID;
}
