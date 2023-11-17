#include "lib/screen/screen.h"

int main(int argc, char* argv[]){
    pixel_t** img = generate_image(10,10);
    print_image(img,10,10);
    return 0;
}
