#include <stdio.h>
#include <math.h>
#include <string.h>

#include "camera.h"

#include "vector.h"

/*void makeCamera(struct Camera *camera, double anglex, double angley, double distance, struct GravityObject *parent)
{
	camera->distance = distance;
	camera->angles[0] = anglex;
	camera->angles[1] = angley;
	//vec2dSetEqual(angles, camera->angles);
	camera->parent = parent;
}*/

void makeCamera(Camera *camera, double anglex, double angley, double distance, World *world, unsigned int parent)
{
	if (!isEntity(world, parent, COMPONENT_POSITION)) 
	{
		printf("Tried to create a camera with a parent that doesn't have a position\n");
		return;
	}
	camera->distance = distance;
	camera->angles[0] = anglex;
	camera->angles[1] = angley;
	camera->world = world;
	camera->parent = parent;
}

void updateCamera(Camera *camera, double dx, double dy, double dz)
{
	camera->distance -= dz * camera->distance * 0.05;
	camera->angles[0] += dy;
	if (camera->angles[0] > M_PI * 0.5) camera->angles[0] = M_PI * 0.5;
	if (camera->angles[0] < -M_PI * 0.5) camera->angles[0] = -M_PI * 0.5;
	camera->angles[1] += dx;
}

/*void changeCameraParent(struct Camera *camera, struct GravityObject *goNew)
{
	camera->distance = 10 * goNew->radius;
	camera->angles[0] = 0;
	camera->angles[1] = 0;
	camera->parent = goNew;
}*/

void changeCameraParent(Camera *camera, double distance, World *world, unsigned int new_parent)
{
	if (!isEntity(world, new_parent, COMPONENT_POSITION)) 
	{
		printf("Tried to change camera parent to object that doesn't have a position\n");
		return;
	}
	camera->distance = distance;
	camera->angles[0] = 0;
	camera->angles[1] = 0;
	camera->parent = new_parent;
}

void getCameraMatrix(Camera *camera, double mt[4][4])
{
	mat4dSetIdentity(mt);
	
	double position[3];
	vec3dMltScl(camera->world->position[camera->parent].position, -1, position);
	mat4dTranslate(position, mt);
	
	double axisy[3] = {0,1,0};
	mat4dRotate(camera->angles[1], axisy, mt);
	
	double axisx[3] = {1,0,0};
	mat4dRotate(camera->angles[0], axisx, mt);
	
	double distance[3] = {0,0,-camera->distance};
	mat4dTranslate(distance, mt);
}
