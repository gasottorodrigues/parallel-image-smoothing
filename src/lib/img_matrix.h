#ifndef IMG_MATRIX_H
#define IMG_MATRIX_H

#include "pixel.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Pixel** alloc_image(unsigned int width, unsigned int height);
void free_image(Pixel ** img, unsigned int height);

Pixel** random_pixels(unsigned int width, unsigned int height);
void print_pixels(Pixel** img, unsigned int width, unsigned int height);

#endif