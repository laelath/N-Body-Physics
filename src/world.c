#include <stdio.h>

#include "world.h"

unsigned int createEntity(World *world)
{
	for (unsigned int i = 0; i < WORLD_MAX_ENTITIES; ++i)
	{
		if (world->mask[i] == COMPONENT_NONE)
		{
			return i;
		}
	}
	
	printf("Tried to create entity when the world was full\n");
	return WORLD_MAX_ENTITIES;
}

void destroyEntity(World *world, unsigned int entity)
{
	world->mask[entity] = COMPONENT_NONE;
}

bool isEntity(World *world, unsigned int entity, int mask)
{
	return (world->mask[entity] & mask) == mask;
}

void addFunction(World *world, void (*function) (World *world, unsigned int entity, double delta), int mask)
{
	if (world->num_functions < WORLD_MAX_FUNCTIONS)
	{
		world->functions[world->num_functions] = function;
		world->function_masks[world->num_functions] = mask;
		world->num_functions++;
	}
	else
	{
		printf("%u\n", world->num_functions);
		printf("Tried to add a function when the function list was full\n");
	}
}

void updateWorld(World *world, double delta)
{
	for (int i = 0; i < world->num_functions; ++i)
	{
		for (int j = 0; j < WORLD_MAX_ENTITIES; ++j)
		{
			//if ((world->mask[j] & world->function_masks[i]) == world->function_masks[i])
			if (isEntity(world, j, world->function_masks[i]))
			{
				world->functions[i](world, j, delta);
			}
		}
	}
}
