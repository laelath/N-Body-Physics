#ifndef PLANET_H
#define PLANET_H

#include "world.h"

#define PLANET_MASK (COMPONENT_POSITION | COMPONENT_VELOCITY | COMPONENT_MASS | COMPONENT_RADIUS | COMPONENT_NAME | COMPONENT_COLOR)
#define STAR_MASK (COMPONENT_POSITION | COMPONENT_VELOCITY | COMPONENT_MASS | COMPONENT_RADIUS | COMPONENT_NAME | COMPONENT_LUMINOSITY)

#define AU 1.496 * pow(10, 11)

unsigned int createPlanet(World *world, char *name, double x, double y, double z, double dx, double dy, double dz, double mass, double radius, double r, double g, double b);
unsigned int createStar(World *world, char *name, double x, double y, double z, double dx, double dy, double dz, double mass, double radius, double luminosity);

void move(World *world, unsigned int entity, double delta);
void attract(World *world, unsigned int entity, double delta);

void setTimeStep(double dtime);
double getTimeStep();

#endif
