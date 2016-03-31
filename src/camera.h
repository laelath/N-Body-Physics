#ifndef CAMERA_H
#define CAMERA_H

//#include "object.h"
#include "world.h"

struct Camera {
	double distance;
	double angles[2];
	//struct GravityObject *parent;
	World *world;
	unsigned int parent;
};

typedef struct Camera Camera;

//void makeCamera(struct Camera *camera, double anglex, double angley, double distance, struct GravityObject *parent);
void makeCamera(Camera *camera, double anglex, double angley, double distance, World *world, unsigned int parent);

void updateCamera(Camera *camera, double dx, double dy, double dz);
//void changeCameraParent(struct Camera *camera, struct GravityObject *goNew);
void changeCameraParent(Camera *camera, double distance, World *world, unsigned int new_parent);
void getCameraMatrix(Camera *camera, double mt[4][4]);

#endif
