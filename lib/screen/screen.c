#include "screen.h"

pixel_t generate_pixel(){
    pixel_t new_pixel;

    new_pixel.red = rand()%256;
    new_pixel.blue = rand()%256;
    new_pixel.green = rand()%256;
    new_pixel.alpha = rand()%101;

    return new_pixel;
}

pixel_t** generate_image(unsigned int width,unsigned int height){
    srand((unsigned int)time(NULL));
    pixel_t** new_image = (pixel_t**)malloc(height*sizeof(pixel_t*));

    for(int lin=0;lin<height;lin++){
        new_image[lin] = (pixel_t*)malloc(width*sizeof(pixel_t));
    }

    for(int lin=0;lin<height;lin++){
        for(int col=0;col<width;col++){
            new_image[lin][col] = generate_pixel();
        }
    }
    return new_image;
}

void print_image(pixel_t** img,unsigned int width, unsigned int height){
     for(int lin=0;lin<height;lin++){
        for(int col=0;col<width;col++){
            printf("(%d,%d,%d,%d) ",img[lin][col].red,img[lin][col].green,img[lin][col].blue,img[lin][col].alpha);
        }
        printf("\n");
    }
}