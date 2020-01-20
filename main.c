#include <stdio.h>
#include <stdlib.h>
#include "functii.h"
#include <time.h>
int main()
{
    FILE *out_file=fopen("dataout.txt", "w");
    struct a_graph *graph; // se declara graful
    clock_t start,finish;
    double duration;
    start=clock();
    generate(); // Se genereaza un numar random de noduri si muchii
    graph = calloc(1, sizeof(struct a_graph)); // se aloca memorie pt graf
    init_graph_file(graph); // se citeste grafu
    graph_bfs(graph,0); // se parcurge plecand de la nodul 0
    while(PozZero(graph->no_nodes-1) != 0)    // Daca in vectorul global apare o valoare de 0, inseamna ca s-a gasit
                                                // o alta componenta conexa
        graph_bfs(graph,PozZero(graph->no_nodes)); // Se parcurge graful de la nodul corespunzator pozitiei  de unde s-a gasit
                                                       // cifra 0 in vector
    finish=clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("duration: %.3fs ", duration);
    fclose(out_file);
    return 0;

}
