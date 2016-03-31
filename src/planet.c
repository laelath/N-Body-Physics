#include <stdio.h>
#include <string.h>
#include <math.h>

#include "planet.h"
#include "vector.h"

#define GRAV_CONSTANT 0.0000000000667408

double timestep = 60 * 60 * 24; //Seconds per second

unsigned int createPlanet(World *world, char *name, double x, double y, double z, double dx, double dy, double dz, double mass, double radius, double r, double g, double b)
{
	unsigned int entity = createEntity(world);
	
	world->mask[entity] = PLANET_MASK;
	
	strcpy(world->name[entity].name, name);
	
	world->position[entity].position[0] = x;
	world->position[entity].position[1] = y;
	world->position[entity].position[2] = z;
	
	world->velocity[entity].velocity[0] = dx;
	world->velocity[entity].velocity[1] = dy;
	world->velocity[entity].velocity[2] = dz;
	
	world->mass[entity].mass = mass;
	
	world->radius[entity].radius = radius;
	
	world->color[entity].color[0] = r;
	world->color[entity].color[1] = g;
	world->color[entity].color[2] = b;
	
	return entity;
}

unsigned int createStar(World *world, char *name, double x, double y, double z, double dx, double dy, double dz, double mass, double radius, double luminosity)
{
	unsigned int entity = createEntity(world);
	
	world->mask[entity] = STAR_MASK;
	
	strcpy(world->name[entity].name, name);
	
	world->position[entity].position[0] = x;
	world->position[entity].position[1] = y;
	world->position[entity].position[2] = z;
	
	world->velocity[entity].velocity[0] = dx;
	world->velocity[entity].velocity[1] = dy;
	world->velocity[entity].velocity[2] = dz;
	
	world->mass[entity].mass = mass;
	
	world->radius[entity].radius = radius;
	
	world->luminosity[entity].luminosity = luminosity;
	
	return entity;
}

void move(World* world, unsigned int entity, double delta)
{
	double movement[3];
	vec3dMltScl(world->velocity[entity].velocity, delta * timestep, movement);
	vec3dAdd(world->position[entity].position, movement, world->position[entity].position);
}

void attract(World *world, unsigned int entity, double delta)
{
	int mask = COMPONENT_POSITION | COMPONENT_MASS;
	for (int i = 0; i < WORLD_MAX_ENTITIES; ++i)
	{
		if (isEntity(world, i, mask) && i != entity)
		{
			double distance = vec3dDistance(world->position[entity].position, world->position[i].position);
			double acceleration = GRAV_CONSTANT * world->mass[i].mass / pow(distance, 3);
			//printf("attracted by %s with distance of %f, and acceleration of %f\n", world->name[i].name, distance, acceleration);
			double direction[3];
			vec3dSub(world->position[i].position, world->position[entity].position, direction);
			vec3dMltScl(direction, acceleration * delta * timestep, direction);
			vec3dAdd(world->velocity[entity].velocity, direction, world->velocity[entity].velocity);
		}
	}
}

void setTimeStep(double dtime)
{
	timestep = dtime;
}

double getTimeStep()
{
	return timestep;
}
