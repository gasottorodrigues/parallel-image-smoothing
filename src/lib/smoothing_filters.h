#ifndef SMOOTHING_H
#define SMOOTHING_H

#include "pixel.h"
#include "img_matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

Pixel ** sequential_avg_filter(Pixel ** img, unsigned int width, unsigned int height,unsigned int kernel_size);
Pixel ** parallel_avg_filter(Pixel ** img, unsigned int width, unsigned int height, unsigned int kernel_size, unsigned int num_threads);
Pixel ** parallel_avg_filter_v2(Pixel ** img, unsigned int width, unsigned int height, unsigned int kernel_size, unsigned int num_threads);
#endif