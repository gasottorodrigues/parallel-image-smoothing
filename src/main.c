#include "lib/img_matrix.h"
#include "lib/smoothing_filters.h"

#define WIDTH 5
#define HEIGHT 5
#define KERNEL_SIZE 3

int main(int argc, char* argv[]){
    Pixel** img = random_pixels(WIDTH,HEIGHT);
    printf("IMAGEM ORIGINAL\n");
    print_pixels(img,WIDTH,HEIGHT);

    Pixel ** filtered_img = sequential_avg_filter(img,WIDTH,HEIGHT,KERNEL_SIZE);
    printf("IMAGEM FILTRADA\n");
    print_pixels(filtered_img,WIDTH,HEIGHT);

    return 0;
}
