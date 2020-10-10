#include <iostream>
#include "../include/grafo.hpp"
#include "../include/grafoM.hpp"
using namespace std;


void DFS(GrafoM* g);
void DFS_VISIT(GrafoM* g , int v ,int *d , int *f , int& tempo);

#define BRACO 0
#define CINZA 1
#define PRETO 2


void DFS(GrafoM* g){
    
    int d[g->n()]; //tempo de descoberta
    int f[g->n()];// tempo de finalização
    int tempo = 0;//variavel para o tempo 

    for(int v = 0; v < g->n(); ++v)
        g->setMark(v,BRACO);
    
    for(int v = 0; v < g->n(); ++v )
        if(g->getMark(v) == BRACO)
            DFS_VISIT(g , v , d , f , tempo );
}
//Função Recursiva DFS_VISIT
//Recebe como Entrada: o Grafo g, o vertice v Atual
//o vetor d[] de tempo de descoberta dos vertices
//o vetor f[] de tempo de finalização
//ponteiro para variavel interia tempo
void DFS_VISIT(GrafoM* g , int v ,int *d , int *f , int& tempo){
    tempo++;
    d[v] =  tempo;
    g->setMark(v,CINZA);

    cout << "Vértice " << v << " Visitou" << endl;

    for(int &w :g->vizinho(v))
        if(g->getMark(w) == BRACO)
            DFS_VISIT(g , w , d , f , tempo);

    g->setMark(v,PRETO);
    tempo++;
    f[v] = tempo;    
}

int main(int argc, char const *argv[]){
    
    // Criando um caminho com 8 vértices
    int N = 8;
    GrafoM *grafo = new GrafoM(N); 

    // Adicionando bordas
    for( int i = 0; i<=N-2; ++i ){
        grafo->addEdge(i,i+1);
        grafo->addEdge(i+1,i);
    }

        DFS(grafo);
    // Imprimindo os vizinhos de cada vértice
    for(int i = 0; i <= N-1; ++i){
        cout << "Vizinhos do " << i << ": " ;
        for(int vizinho : grafo->vizinho(i))
            cout << vizinho << " ";
        cout << endl;
    }
    
    return 0;
}
