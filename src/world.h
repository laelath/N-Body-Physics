#ifndef WORLD_H
#define WORLD_H

#include <stdbool.h>

#include "component.h"

#define WORLD_MAX_ENTITIES 100
#define WORLD_MAX_FUNCTIONS 25

struct World {
	int mask[WORLD_MAX_ENTITIES];
	
	Position position[WORLD_MAX_ENTITIES];
	Velocity velocity[WORLD_MAX_ENTITIES];
	Mass mass[WORLD_MAX_ENTITIES];
	Radius radius[WORLD_MAX_ENTITIES];
	Name name[WORLD_MAX_ENTITIES];
	Color color[WORLD_MAX_ENTITIES];
	Luminosity luminosity[WORLD_MAX_ENTITIES];
	
	unsigned int num_functions;
	int function_masks[WORLD_MAX_FUNCTIONS];
	void (*functions[WORLD_MAX_FUNCTIONS]) (struct World *world, unsigned int entity, double delta);
};

typedef struct World World;

unsigned int createEntity(World *world);
void destroyEntity(World *world, unsigned int entity);

bool isEntity(World *world, unsigned int entity, int mask);

void addFunction(World *world, void (*function) (World *world, unsigned int entity, double delta), int mask);
void updateWorld(World *world, double delta);

#endif
