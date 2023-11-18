#include "lib/img_matrix.h"
#include "lib/smoothing_filters.h"


// Altere aqui os valores de dimensoes, kernel_size e num_threads desejados
// > Recomenda-se um numero ímpar para o kernel_size (isso mantem o pixel em análise centralizado)
// > Recomenda-se dimensoes maiores que 5000 para um tempo significativo de execução
// > kernel_size pode causar maior variação de desempenho que a dimensão da imagem em si.
#define WIDTH 5000
#define HEIGHT 5000
#define KERNEL_SIZE 5
#define NUM_THREADS 8

int main(int argc, char* argv[]){
    printf("Avaliacao de desempenho sequencial x paralelo.\n");
    printf(">codigo em analise: filtro de suavizacao por media.\n");
    printf(">numero de threads definidas: %d.\n\n",NUM_THREADS);

    printf("[SYS] Gerando imagem. Dimensoes %d x %d.\n",WIDTH, HEIGHT);
    Pixel ** img = random_pixels(WIDTH,HEIGHT);
    Pixel ** filtered;
    printf("[SYS] Imagem gerada com sucesso.\n");

    printf("[SYS] Iniciando suavizacao sequencial.\n");
    long int seq_time = omp_get_wtime();
    filtered = sequential_avg_filter(img,WIDTH,HEIGHT,KERNEL_SIZE);
    seq_time = omp_get_wtime() - seq_time;
    printf("[SYS] suavizacao sequencial concluida.\n");

    free_image(filtered,HEIGHT);

    printf("[SYS] Iniciando suavizacao paralela.\n");
    long int par_time = omp_get_wtime();
    filtered = parallel_avg_filter(img,WIDTH,HEIGHT,KERNEL_SIZE,NUM_THREADS);
    par_time = omp_get_wtime() - par_time;
    printf("[SYS] suavizacao paralela concluida.\n");

    free_image(filtered,HEIGHT);

    printf("[SYS] Iniciando suavizacao paralela v2.\n");
    long int par2_time = omp_get_wtime();
    filtered = parallel_avg_filter_v2(img,WIDTH,HEIGHT,KERNEL_SIZE,NUM_THREADS);
    par2_time = omp_get_wtime() - par2_time;
    printf("[SYS] suavizacao paralela v2 concluida.\n\n");

    free_image(filtered,HEIGHT);
    free_image(img,HEIGHT);

    double su1 = (double)((seq_time * 1.0)/par_time);
    double su2 = (double)((seq_time * 1.0)/par2_time);
    double ef1 = su1/NUM_THREADS;
    double ef2 = su2/NUM_THREADS;

    printf("> Resultados\n");
    printf("Pixels na matriz: %d\n",WIDTH*HEIGHT);
    printf("Algoritmo Sequencial: %lds\n\n",seq_time);
    printf("Algoritmo Paralelo 1: %lds\n",par_time);
    printf("Speed-Up: %.2f\n",su1);
    printf("Eficiencia: %.2f\n\n", ef1);
    printf("Algoritmo Paralelo 2: %lds\n",par2_time);
    printf("Speed-Up: %.2f\n",su2);
    printf("Eficiencia: %.2f\n", ef2);
    

    return 0;
}
