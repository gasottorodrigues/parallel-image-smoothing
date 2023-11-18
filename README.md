# parallel-image-smoothing

Foram desenvolvidas 3 versões de um mesmo algoritmo simples de suavização de imagem, em que as cores de um pixel é determinada pela média de seus vizinhos.
A primeira versão, totalmente sequencial, foi tomada como base para as outras duas versões paralelas em OpenMP. O importante desse projeto era analisar o ganho
de desempenho dos algoritmos desenvolvidos em relação a versão sequencial.

# Como executar

É necessário ter o Make e o GCC instalados previamente na sua máquina. Após clonar o repositório, basta executar as seguintes linhas no terminal aberto na pasta do
projeto:

```bash
make compile
./program
```

e o programa será executado conforme os valores default configurados na main. Para alterar as dimensões da imagem, tamanho do kernel e número de threads, basta alterar os valores presentes a partir da linha 9 no arquivo main.c.