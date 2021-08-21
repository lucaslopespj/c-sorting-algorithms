# Algoritmos de Ordenação em C
<a href="https://github.com/lucaslopespj/c-sorting-algorithms#readme">English</a>

## Sobre esse repositório

Ele contém uma biblioteca que implementa os mais importantes algoritmos de ordenação em linguagem C. Coloque seus números em um arquivo de entrada e tenha-os ordenados em um arquivo de saída com estatísticas de medição de tempo.

## Sobre os arquivos
Há 7 arquivos: main.c, sorting.h, sorting.c, fileHandling.h, fileHandling.c, timeData.h e timeData.c

Todos os arquivos **.h** (arquivos de interface) contém uma explicação de como usar todas as suas funções. O arquivo **main.c** é o programa exemplo que usa todas as funções dos arquivos **.h**. Todos os outros arquivos **.c** têm as implementações da funções cujas assinaturas estão nos respectivos arquivos de interface.


## Usando o exemplo
Você deve primeiramente compilar os arquivos para usá-los. Você precisará de um programa Compilador C para fazer isso. Por exemplo, eu estou usando o GCC.

Você também precisa compilar com C99 (veja abaixo).

Para compilar os arquivos:

```bash
gcc main.c sorting.c fileHandling.c timeData.c -o program -std=c99 -ansi -pedantic -O2 -lm 
```

Depois disso você pode executar o programa num terminal GNU/Linux. Você também precisa dizer a quantidade de números aleatórios a serem ordenados e a sua quantidade máxima de dígitos [1, 7].

A próxima linha mostra como ordenar 500.000 números aleatórios com no máximo 7 dígitos cada um.
```
./program 500000 7
```

## O que faz o arquivo main.c?
Basicamente ele pega uma quantidade de **v_size** números aleatórios, coloca todos eles em um arquivo **input.txt**. Depois disso o programa roda todos os _algoritmos de ordenação_ ordenando todos os números do arquivo de entrada e computando o tempo de cada um.
Depois que todos os algoritmos terem sido executados, o programa coloca todos os números ordenados no arquivo **output.txt** e imprime estatísticas de tempo na tela.

Por exemplo, para 500.000 números, irá imprimir algo assim:

    +----------------------------------------- STATISTICS ------------------------------------------+

         You have sorted 500000 random numbers.
         The 'input.txt' file contains all random numbers.
         The 'output.txt' file contains all sorted numbers.

         Time of each algorithm:
             Insertion Sort:  33 s  72 ms  195 µs
             Selection Sort:  4 min,  35 s  974 ms  877 µs
             Bubble Sort:  5 min,  52 s  500 ms  483 µs
             Merge Sort:  74 ms  531 µs
             Quick Sort:  51 ms  73 µs
             Heap Sort:  69 ms  478 µs

         Running time of all sorting algorithms :  11 min,  1 s  742 ms  640 µs


         Time to get the random numbers:  611 ms  514 µs
         Writing time of the 'input.txt' file:  35 ms  617 µs
         Writing time of the 'output.txt' file:  45 ms  625 µs
         Mean reading time of the 'input.txt' file:  397 ms  840 µs

    +------------------------------------------------------------------------------------------------+



O tempo é dividido em: _dias, horas, min (minutos), s (segundos), ms (milisegundos), e µs (microsegundos)._

> Obs: o tempo para ordenar os números pode variar de  um processador para outro.

#### Dica:
Você também pode usar as funções nos arquivos **.h** para escrever outros programas. Seus próprios programas! Não se esqueça de me contar se tentar isso!


## Algoritmos de Ordenação
Você pode usar os seguintes algoritmos para ordenar seus números

---
- **Insertion Sort** 
    - Melhor caso: n
    - Caso médio: n²
    - Pior caso: n²
---
- **Selection Sort**
    - Melhor caso: n²
    - Caso médio: n²
    - Pior caso: n²
---
- **Bubble Sort**
    - Melhor caso: n
    - Caso médio: n²
    - Pior caso: n²
---
- **Merge Sort**
    - Melhor caso: n log n
    - Caso médio: n log n
    - Pior caso: n log n
---
- **Quick Sort**
    - Melhor caso: n log n
    - Caso médio: n log n
    - Pior caso: n²
---
- **Heap Sort**
    - Melhor caso: n log n
    - Caso médio: n log n
    - Pior caso: n log n
---