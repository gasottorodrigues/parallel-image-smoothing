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
                    if (col + x >= 0 && col + x < width && lin + y >= 0 && lin + y < height) {
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

    
    return filtered_img;
}

Pixel ** parallel_avg_filter(Pixel ** img, unsigned int width, unsigned int height, unsigned int kernel_size, unsigned int num_threads){
    /** Versao paralela do algoritmo sequencial simplesmente implementando um parallel for para percorrer a matriz da imagem.
     * O Funcionamento é exatamente o mesmo do algoritmo sequencial, apenas foi acrescentado a #pragma parallel for para aninhar
     * os dois loopins que percorrer a matriz da imagem original.
     * */
    Pixel ** filtered_img = alloc_image(width,height);

    int red, green, blue;
    int pixels_counter;

    #pragma omp parallel for collapse(2) num_threads(num_threads) shared(filtered_img,kernel_size,width,height,img) private(red,green,blue,pixels_counter)
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
                    if (col + x >= 0 && col + x < width && lin + y >= 0 && lin + y < height) {
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
    return filtered_img;
}

Pixel ** parallel_avg_filter_v2(Pixel ** img, unsigned int width, unsigned int height, unsigned int kernel_size, unsigned int num_threads){
    /** Versão paralela mais otimizada. A matriz é subdivida "manualmente" pelas linhas, e distribuída cada agrupamento de linhas a uma thread,
     * balanceando a carga delas quase igualmente e evitando concorrencia para acesso a memória entre elas. O restante da lógica é a mesma. 
    */
    Pixel ** filtered_img = alloc_image(width,height);

    #pragma omp parallel num_threads(num_threads) shared(width,height,kernel_size)
    {
        int tid = omp_get_thread_num();
        int num_tasks = height / num_threads;
        int start_row = tid * num_tasks;
        int end_row = (tid == num_threads - 1) ? height : start_row + num_tasks;
        int half_kernel = (kernel_size / 2);

        for (int lin = start_row; lin < end_row; lin++) {
            for (int col = 0; col < width; col++) {
                int red = 0, green = 0, blue = 0, pixels_counter = 0;
                
                    for (int x = -half_kernel; x <= half_kernel; x++) {
                        for (int y = -half_kernel; y <= half_kernel; y++) {
                            int neighbor_row = lin + y;
                            int neighbor_col = col + x;

                            if (neighbor_row >= 0 && neighbor_row < height && neighbor_col >= 0 && neighbor_col < width) {
                                red += img[neighbor_row][neighbor_col].red;
                                green += img[neighbor_row][neighbor_col].green;
                                blue += img[neighbor_row][neighbor_col].blue;
                                pixels_counter++;
                            }
                        }
                 }

                filtered_img[lin][col].red = red / pixels_counter;
                filtered_img[lin][col].green = green / pixels_counter;
                filtered_img[lin][col].blue = blue / pixels_counter;
            }
        }

    }

    return filtered_img;
}