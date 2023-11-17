#include "../smoothing_filters.h"

Pixel ** sequential_avg_filter(Pixel ** img, unsigned int width, unsigned int height, unsigned int kernel_size){
    Pixel ** filtered_img = alloc_image(width,height);

    int red, green, blue;
    int pixels_counter;

    for(int lin = 0;lin<height;lin++){
        for(int col=0;col<width;col++){
            red = 0;
            green = 0;
            blue=0;
            pixels_counter = 0;

            for(int x = -1*(int)(kernel_size/2); x <= (int)(kernel_size/2); x++){
                for(int y = -1*(int)(kernel_size/2); y <= (int)(kernel_size/2); y++){
                    if (col + x >= 0 && col + x < width && lin + y >= 0 && lin + y < width) {
                            red += img[lin+y][col+x].red;
                            green += img[lin+y][col+x].green;
                            blue += img[lin+y][col+x].blue;
                            pixels_counter ++;
                        }
                }
            }

            //printf("Pixel (%d,%d). Cores pre divisao: (%d,%d,%d). Total de Pixels: %d\n",lin,col,red,green,blue,pixels_counter);

            filtered_img[lin][col].red =  red/pixels_counter;
            filtered_img[lin][col].green = green/pixels_counter;
            filtered_img[lin][col].blue = blue/pixels_counter;
        }
    }

    return filtered_img;
}