#ifndef grafom_hpp
#define grafom_hpp
#include <stdexcept>
#include <list>
#include "grafo.hpp"


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
        std::list<Edge>& bordaIncidente(int v){ 
            std::list<Edge> *lst =  new std::list<Edge>();
            for(int i = 0; i < N; ++i){
                if(matriz[v][i] != 0){
                    lst->push_back(Edge(i,matriz[v][i]));
                }
            }
            return *lst;
        }

        // Retorna uma lista contendo os vizinhos do vértice v
        std::list<int>& vizinho(int v){
            std::list<int> *lst = new std::list<int>();
            for(int i = 0;i < N; ++i){
                if(matriz[v][i] != 0){
                    lst->push_back(i);
                }
            }
            return *lst;
        }

        void setPesoBorda(int v1 , int v2 , int wgt){
            if(wgt <= 0 ) throw std::runtime_error("Peso negativo ou igual a zero");
            if( !isEdge(v1,v2))
                ++M;
            matriz[v1][v2] = wgt;
        }

        // Adicionar uma borda
        void addEdge(int v1 , int v2){
            setPesoBorda(v1 , v2 , 1);
        }
        
        // Excluir uma borda
        void delEdge(int v1, int v2){
            if(isEdge(v1, v2)){
                M--;
                matriz[v1][v2] = 0;
            }
        }
        // Determine se uma aresta está no grafo
        bool isEdge(int v1 , int v2){
            return (matriz[v1][v2] > 0);
        }

        int peso( int v1 ,int v2 ){
            verificarVertice(v1);
            verificarVertice(v2);
            if(isEdge(v1,v2))
                return matriz[v1][v2];
            else return 0;
        }
        int getMark(int v){
            verificarVertice(v);
            return mark[v];
        }

        void setMark(int v, int val){
            verificarVertice(v);
            mark[v] = val;
        }
};

#endif // !grafom_hpp