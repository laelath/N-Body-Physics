#include <stdbool.h>

#include "input.h"

double deltax, deltay, deltaz;
double x, y;
bool clicked;
bool right_down;
int timestep;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	else if (key == GLFW_KEY_COMMA && action == GLFW_PRESS)
	{
		timestep++;
	}
	else if (key == GLFW_KEY_PERIOD && action == GLFW_PRESS)
	{
		timestep--;
	}
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		if (action == GLFW_PRESS) right_down = true;
		else right_down = false;
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS) clicked = true;
	}
}

void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{
	if (right_down)
	{
		deltax += xpos - x;
		deltay += ypos - y;
	}
	x = xpos;
	y = ypos;
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	deltaz += yoffset;
}

void clearInput()
{
	clicked = false;
	deltax = 0;
	deltay = 0;
	deltaz = 0;
	
	timestep = 0;
}

void getMouseDelta(double *dx, double *dy, double *dz)
{
	*dx = deltax;
	*dy = deltay;
	*dz = deltaz;
}

bool getClicked()
{
	return clicked;
}

int getTimeStepChange()
{
	return timestep;
}
