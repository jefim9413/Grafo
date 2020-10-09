#ifndef grafom_hpp
#define grafom_hpp
#include <stdexcept>
#include <list>
#include "C:\Users\Jefferson Marques\Documents\EDA\include\grafo.hpp"


//Implementação de um grafo como uma matriz de adjacência
class GrafoM:public Grafo{
    private:
        int N;
        int M;
        int **matriz;
        int *mark;
        // Verifique se um vértice v é válido (0 <= v <= N-1)
        void verificarVertice(int v){
            if(v < 0 || v > N-1)
                throw std::runtime_error("Intervalo de valor de vertice invalido");
        }
    public:
        //Construtor
        GrafoM(int n){
            if( n <= 0 ) throw std::runtime_error("Tamanho Invalido");
            N = n;
            M = 0;
            // Alocar memória para matriz de mark
            mark = new int[n];
            // Alocar memória para uma matriz n x n
            matriz = new int*[n];
            for(int i = 0;i <= n-1;++i){
                matriz[i] =  new int[n];
            }
            // Inicializa a matriz com 0's
            for(int i = 0;i <= n-1; ++i)
                for(int j = 0 ;j<= n-1;++j)
                    matriz[i][j] = 0;

        }
        // Destruidor
        ~GrafoM(){
            delete[] mark;
            for(int i = 0; i < N; i++)
                delete[] matriz[i];
            delete[] matriz;    
        }
        // Retorna: o número de vértices e arestas respectivamente
        int n(){return N;}
        int m(){return M;}
        // Retorna uma lista contendo as bordas incidentes de v
};

#endif // !grafom_hpp