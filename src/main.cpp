#include <iostream>
#include "../include/grafo.hpp"
#include "../include/grafoM.hpp"
using namespace std;

int main(int argc, char const *argv[]){
    
    // Criando um caminho com 8 vértices
    int N = 8;
    Grafo *grafo = new GrafoM(N); 

    // Adicionando bordas
    for( int i = 0; i<=N-2; ++i ){
        grafo->addEdge(i,i+1);
        grafo->addEdge(i+1,i);
    }
    // Imprimindo os vizinhos de cada vértice
    for(int i = 0; i <= N-1; ++i){
        cout << "Vizinhos do " << i << ": " ;
        for(int vizinho : grafo->vizinho(i))
            cout << vizinho << " ";
        cout << endl;
    }
    
    return 0;
}
