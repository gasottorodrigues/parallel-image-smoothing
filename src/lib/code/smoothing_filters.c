#include "../smoothing_filters.h"

Pixel ** sequential_avg_filter(Pixel ** img, unsigned int width, unsigned int height, unsigned int kernel_size){
    /** [SEQUENCIAL] Filtro de Suavização por Média: Esse filtro consiste em tornar o píxel em análise o valor da
     * média dos pixels próximos a ele, com ele incluso. O limiar de proximidade é definido pelo 'kernel_size' Ex: se 
     * 'kernel_size' = 3, então será considerado um quadrado de 3x3, com o pixel em análise ao centro. As médias calcula-
     * das para cada pixel são adicionadas em uma nova matriz de pixels. Cada cor primária tem sua média calculada individual-
     * mente para cada pixel.
    */
    Pixel ** filtered_img = alloc_image(width,height);

    int red, green, blue;
    int pixels_counter;

    for(int lin = 0;lin<height;lin++){
        for(int col=0;col<width;col++){
            // Percorre cada pixel
            red = 0;
            green = 0;
            blue=0;
            pixels_counter = 0;

            // Determina a área do kernel
            for(int x = -1*(int)(kernel_size/2); x <= (int)(kernel_size/2); x++){
                for(int y = -1*(int)(kernel_size/2); y <= (int)(kernel_size/2); y++){
                    // Verifica se o kernel não ultrapassa as bordas da matriz
                    if (col + x >= 0 && col + x < width && lin + y >= 0 && lin + y < width) {
                            red += img[lin+y][col+x].red;
                            green += img[lin+y][col+x].green;
                            blue += img[lin+y][col+x].blue;
                            pixels_counter ++;
                        }
                }
            }

            filtered_img[lin][col].red =  red/pixels_counter;
            filtered_img[lin][col].green = green/pixels_counter;
            filtered_img[lin][col].blue = blue/pixels_counter;
        }
    }
    // Apaga o registro da imagem anterior
    free_image(img,height);
    return filtered_img;
}