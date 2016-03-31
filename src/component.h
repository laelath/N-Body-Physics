#ifndef COMPONENT_H
#define COMPONENT_H

typedef struct {
	double position[3];
} Position;

typedef struct {
	double velocity[3];
} Velocity;

typedef struct {
	double mass;
} Mass;

typedef struct {
	double radius;
} Radius;

typedef struct {
	char name[10];
} Name;

typedef struct {
	double color[3];
} Color;

typedef struct {
	double luminosity;
} Luminosity;


typedef enum {
	COMPONENT_NONE = 0,
	COMPONENT_POSITION = 1 << 0,
	COMPONENT_VELOCITY = 1 << 1,
	COMPONENT_MASS = 1 << 2,
	COMPONENT_RADIUS = 1 << 3,
	COMPONENT_NAME = 1 << 4,
	COMPONENT_COLOR = 1 << 5,
	COMPONENT_LUMINOSITY = 1 << 6
} Component;

#endif
