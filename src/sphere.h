#ifndef SPHERE_H
#define SPHERE_H

const float sphere_model[] = {
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, -1.0f,
	-1.0f, 0.0f, 0.0f,
	0.0f, -1.0f, 0.0f };

const unsigned int sphere_indices[] = {
	0, 1, 2,
	0, 2, 3,
	0, 3, 4,
	0, 4, 1,
	5, 1, 4,
	5, 4, 3,
	5, 3, 2,
	5, 2, 1 };

const unsigned sphere_num_indices = sizeof(sphere_indices)/sizeof(unsigned int);

#endif
