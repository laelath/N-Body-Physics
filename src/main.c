#include <stdio.h>
#include <math.h>

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "sphere.h"

#include "time.h"
#include "input.h"
#include "shader.h"
#include "vector.h"
#include "world.h"
#include "planet.h"
#include "camera.h"

#define GL_VERSION_MAJOR 3
#define GL_VERSION_MINOR 3

int main()
{
	GLFWwindow* window;
	
	if (!glfwInit()) 
	{
		printf("Error initializing GLFW\n");
		return -1;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	glfwWindowHint(GLFW_SAMPLES, 8);
	
	window = glfwCreateWindow(1920, 1080, "Test Window", glfwGetPrimaryMonitor(), NULL);
	
	if (!window)
	{
		printf("Error creating GLFW window\n");
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);
	
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetScrollCallback(window, scroll_callback);
	
	if (gl3wInit())
	{
		printf("Error initializing OpenGL\n");
		glfwTerminate();
		return -1;
	}
	
	printf("OpenGL %s GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));
	
	if (!gl3wIsSupported(GL_VERSION_MAJOR, GL_VERSION_MINOR))
	{
		printf("OpenGL %i.%i is not supported\n", GL_VERSION_MAJOR, GL_VERSION_MINOR);
		glfwTerminate();
		return -1;
	}
	
	glViewport(0, 0, 1920, 1080);
	
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	
	GLuint programID = loadShadersvf("shaders/simple.vsh", "shaders/simple.fsh");
	
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sphere_model), sphere_model, GL_STATIC_DRAW);
	
	GLuint ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sphere_indices), sphere_indices, GL_STATIC_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_buffer_data), index_buffer_data, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDisableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
	
	double timesteps[] = {1, 60, 60 * 60, 60 * 60 * 24, 60 * 60 * 24 * 7, 60 * 60 * 24 * 30, 60 * 60 * 24 * 365};
	int timestepCounter = 0;
	
	
	World world;
	world.num_functions = 0;
	//Add the functions for gravitational attraction to the world's object list, and have it execute when updateWorld() is called
	addFunction(&world, attract, COMPONENT_POSITION | COMPONENT_VELOCITY);
	addFunction(&world, move, COMPONENT_POSITION | COMPONENT_VELOCITY);
	
	unsigned int bodies[11];
	
	//Create all the planets with the correct masses, sizes, and velocities
	bodies[0] = createStar(&world, "Sun", 0, 0, 0, 0, 0, 0, 1.989 * pow(10, 30), 6.963 * pow(10,8), 1);
	
	bodies[1] = createPlanet(&world, "Mercury", -0.35790 * AU, -0.04240 * AU, -0.11618 * AU,
		-0.00000004 * AU, 0.00000003 * AU, 0.00000031 * AU, 3.285 * pow(10,23), 2.44 * pow(10,6), 0.4549, 0.4509, 0.4705);
	
	bodies[2] = createPlanet(&world, "Venus", -0.46075 * AU, -0.03422 * AU, -0.56289 * AU,
		-0.00000017 * AU, -0.00000001 * AU, 0.00000014 * AU, 4.867 * pow(10, 24), 6.052 * pow(10,6), 0.4627, 0.568, 0.380);
	
	bodies[3] = createPlanet(&world, "Earth", 0.99542 * AU, 0, 0.01938 * AU,
		0.00000001 * AU, 0, -0.00000019 * AU, 5.972 * pow(10, 24), 6.371 * pow(10,6), 0, 0.4, 0.6);
	
	bodies[4] = createPlanet(&world, "Moon", 0.99708 * AU, -0.00016 * AU, 0.02141 * AU,
		0.00000001 * AU + 722.66, 0, -0.00000019 * AU - 722.66, 7.348 * pow(10, 22), 1.737 * pow(10,6), 0.4, 0.4, 0.4);
	
	bodies[5] = createPlanet(&world, "Mars", 1.38763 * AU, 0.01755 * AU, -0.79510 * AU,
		-0.00000009 * AU, -0.00000001 * AU, -0.00000013 * AU, 6.39 * pow(10, 23), 3.39 * pow(10,6), 0.8157, 0.5294, 0.3922);
	
	bodies[6] = createPlanet(&world, "Jupiter", 5.32462 * AU, 0.11488 * AU, 1.04223 * AU,
		0.00000002 * AU, 0, -0.00000008 * AU, 1.898 * pow(10,27), 69.911 * pow(10,6), 0.8824, 0.7961, 0.7412);
	
	bodies[7] = createPlanet(&world, "Saturn", 3.30063 * AU, 0.29595 * AU, -9.47771 * AU,
		-0.00000006 * AU, 0, -0.00000002 * AU, 5.683 * pow(10,26), 58.232 * pow(10,6), 0.7843, 0.6392, 0.4314);
	
	bodies[8] = createPlanet(&world, "Uranus", -18.76415 * AU, -0.21783 * AU, 6.83528 * AU,
		0.00000002 * AU, 0, 0.00000004 * AU, 8.681 * pow(10,25), 25.362 * pow(10,6), 0.8314, 0.9804, 0.9922);
	
	bodies[9] = createPlanet(&world, "Neptune", -28.07048 * AU, -0.42924 * AU, -10.42730 * AU,
		-0.00000002 * AU, 0, 0.0000003 * AU, 1.024 * pow(10,26), 24.622 * pow(10,6), 0.2, 0.2902, 0.7451);
	
	bodies[10] = createPlanet(&world, "Pluto", -8.88081 * AU, 0.86973 * AU, -31.76914 * AU,
		-0.00000003 * AU, -0.00000001 * AU, 0.0000001 / 41.0 * AU, 1.309 * pow(10,22), 1.186 * pow(10, 6), 0.7137, 0.6824, 0.6314);
	
	
	double mat4d_projection[4][4] = MATRIX_IDENTITY_4;
	mat4dProjection(M_PI / 2.0, 16.0/9.0, pow(10,6), pow(10,13), mat4d_projection);
	
	
	unsigned int parent = 3;
	
	Camera camera;
	makeCamera(&camera, 0, 0, pow(10, 9), &world, bodies[parent]);
	
	double mat4d_camera[4][4] = MATRIX_IDENTITY_4;
	float mat4_camera[4][4];

	
	
	double sensitivity = 0.005;
	
	printf("Starting main loop\n");
	
	while (!glfwWindowShouldClose(window))
	{
		clearInput();
		glfwPollEvents();
		
		//rotate or zoom out the camera depending on camera movement and scrolling
		double dx, dy, dz;
		getMouseDelta(&dx, &dy, &dz);
		updateCamera(&camera, dx * sensitivity, dy * sensitivity, dz);
		
		if (getClicked())
		{
			if(++parent > 10) parent = 0;
			changeCameraParent(&camera, pow(10, 9), &world, bodies[parent]);
		}
		
		timestepCounter += getTimeStepChange();
		if (timestepCounter > 6) timestepCounter = 0;
		else if (timestepCounter < 0) timestepCounter = 6;
		setTimeStep(timesteps[timestepCounter]);
		
		//get the time since the last frame to do proper delta-timing for the gravitational attraction and movement
		double delta = timeTick();
		updateWorld(&world, delta);
		
		getCameraMatrix(&camera, mat4d_camera);
		
		double modelView[4][4];
		mat4dMlt(mat4d_projection, mat4d_camera, modelView);
		
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glUseProgram(programID);
		
		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
		
		//For each of the objects in the world, loop through them and render them if they have a position and radius,
		//rendering works by rendering the same sphere over and over, with a different translation and scale
		//because all objects in this program are spheres
		for (int i = 0; i < WORLD_MAX_ENTITIES; ++i)
		{
			if (isEntity(&world, i, COMPONENT_POSITION | COMPONENT_RADIUS))
			{
				/*double pos[4] = {world.position[i].position[0], world.position[i].position[1], world.position[i].position[2], 1};
				vec4dMltMat(mat4d_camera, pos, pos);
				double distance = vec3dLength(pos);
				printf("%i: %f\n", i, distance);
				
				double mat4d_model[4][4] = MATRIX_IDENTITY_4;
				
				double radius = world.radius[i].radius;
				
				double scaleFactor = distance * (1 / pow(radius,2));
				printf("Scale factor: %f\n", scaleFactor);
				
				if (scaleFactor > pow(10,-3))
				{
					printf("Has been scaled\n");
					radius = radius / scaleFactor;
				}
				printf("Radius: %f\n", radius);*/
				
				double mat4d_model[4][4] = MATRIX_IDENTITY_4;
				
				double radius = world.radius[i].radius;
				
				double scale[3] = {radius, radius, radius};
				mat4dGenScale(scale, mat4d_model);
				mat4dTranslate(world.position[i].position, mat4d_model);
				
				double modelViewProjection[4][4];
				mat4dMlt(modelView, mat4d_model, modelViewProjection);
				
				float modelViewProjectionf[4][4];
				doubleToSingle(modelViewProjection[0], modelViewProjectionf[0], 16);
				
				double color[3] = {1,1,1};
				
				if (isEntity(&world, i, COMPONENT_COLOR))
				{
					vec3dSetEqual(world.color[i].color, color);
				}
				
				float colorf[3];
				doubleToSingle(color, colorf, 3);
				
				GLint colorLoc = glGetUniformLocation(programID, "in_color");
				glUniform3fv(colorLoc, 1, colorf);
				
				GLint mvpLoc = glGetUniformLocation(programID, "mvp");
				glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, modelViewProjectionf[0]);
				
				glDrawElements(GL_TRIANGLES, sphere_num_indices, GL_UNSIGNED_INT, 0);
			}
		}
		
		glDisableVertexAttribArray(0);
		
		glBindVertexArray(0);
		
		
		glfwSwapBuffers(window);
	}
	
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
