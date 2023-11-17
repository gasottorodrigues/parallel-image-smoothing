#ifndef SMOOTHING_H
#define SMOOTHING_H

#include "pixel.h"
#include "img_matrix.h"
#include <stdio.h>
#include <stdlib.h>

Pixel ** sequential_avg_filter(Pixel ** img, unsigned int width, unsigned int height,unsigned int kernel_size);

#endif