#ifndef grafo_hpp
#define grafo_hpp
#include <iostream>
#include <list>

class Edge{
    private:
        int vertice;
        int peso;
    public:
        Edge() {vertice = -1; peso = -1;}
        explicit Edge(int v ,int w ){vertice = v ; peso = w;}
        int getVertice() const { return vertice; }
        int getPeso()const { return peso;}
        void setVertice(int v) { vertice = v; }
        void setPeso(int w) { peso = w; }
};


class Grafo{
    public:
        Grafo(){}
        virtual ~Grafo(){}
        // retorna o número de vértices e arestas, respectivamente
        virtual int n() = 0;
        virtual int m() = 0;
        // Retorna uma lista contendo os vizinhos do vértice v
        virtual std::list<int>& vizinho(int v) = 0;
        // retorna uma lista contendo arestas incidentes de v
        virtual std::list<Edge>& bordaIncidente(int v) = 0;
        
        // v1, v2: os vértices
        // wgt: o peso da borda
        virtual void setPesoBorda( int v1, int v2, int wgt ) = 0;

        // Adicionar uma borda
        virtual void addEdge(int v1 , int v2) = 0;

        // Excluir uma borda
        virtual void delEdge(int v1, int v2) = 0;

        // Determine se uma aresta está no gráfico
        virtual bool isEdge(int v1 , int v2) = 0;
        
        // Retorna o peso de uma borda 
        // Retorna o peso da borda em ou 
        // 0 se a borda não existe
        virtual int peso(int v1 , int v2) = 0;
        // Obtenha e defina o valor do Mark para um vértice 
        // v: o vértice 
        // val: o valor a ser definido
        virtual int getMark(int v ) = 0;
        virtual void setMark( int v , int val) = 0;
};

#endif // !grafo_hpp    