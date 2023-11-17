#include "../img_matrix.h"

Pixel generate_pixel(){
    Pixel new_pixel;

    new_pixel.red = rand()%256;
    new_pixel.blue = rand()%256;
    new_pixel.green = rand()%256;

    return new_pixel;
}


Pixel** alloc_image(unsigned int width, unsigned int height){
    Pixel** new_image = (Pixel**) malloc(height*sizeof(Pixel*));

    for(int lin=0;lin<height;lin++){
        new_image[lin] = (Pixel*) malloc(width*sizeof(Pixel));
    }

    return new_image;
}

void free_image(Pixel ** img, unsigned int height){
    for(int lin=0;lin<height;lin++){
        free(img[lin]);
    }

    free(img);
}

Pixel** random_pixels(unsigned int width, unsigned int height){
    Pixel** random_img = alloc_image(width,height);
    
    srand(3);

    for(int lin=0;lin<height;lin++){
        for(int col=0;col<width;col++){
            random_img[lin][col] = generate_pixel();
        }
    }

    return random_img;
}

void print_pixels(Pixel** img, unsigned int width, unsigned int height){
     for(int lin=0;lin<height;lin++){
        for(int col=0;col<width;col++){
            printf("(%d,%d,%d) ",img[lin][col].red,img[lin][col].green,img[lin][col].blue);
        }
        printf("\n");
    }
}