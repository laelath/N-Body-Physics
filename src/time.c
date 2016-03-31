#include <GLFW/glfw3.h>

#include "time.h"

double timeTick()
{
	double seconds = glfwGetTime();
	glfwSetTime(0.0);
	return seconds;
}
