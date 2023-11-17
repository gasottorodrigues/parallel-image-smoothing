#ifndef SCREEN_H
#define SCREEN_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} pixel_t;

pixel_t** generate_image(unsigned int width,unsigned int height);
void print_image(pixel_t** img,unsigned int width, unsigned int height);

#endif