#include <iostream>
#include <stdlib.h>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Grafo{
private:
   int V;
   list<pair<int, int> > *adj;
public:
   Grafo(int V){
      this->V = V;
      adj = new list<pair<int, int> >[V];
   }
   void AgregarArista(int v1, int v2, int peso){
      adj[v1].push_back(make_pair(v2,peso));
   }
   int ADijkstra(int orig, int dest){
      int dist[V];
      int visitados[V];
      priority_queue < pair<int, int>,
      vector<pair<int, int> >, greater<pair<int, int> > > pq;
      for(int i = 0; i < V; i++){
         dist[i]=100;
         visitados[i] = false;
      }
      dist[orig] = 0;
      pq.push(make_pair(dist[orig], orig));
      while(!pq.empty()){
         pair<int, int> p = pq.top();
         int u = p.second; 
         pq.pop();
         if(visitados[u] == false){
            visitados[u] = true;
            list<pair<int, int> >::iterator it;
            for(it = adj[u].begin(); it != adj[u].end(); it++){
               int v = it->first;
               int custo_aresta = it->second;
               if(dist[v] > (dist[u] + custo_aresta)){
                  dist[v] = dist[u] + custo_aresta;
                  pq.push(make_pair(dist[v], v));
               }
            }
         }
      }
      return dist[dest];
   }
};

int main(){
   vector<int> M;
   system("cls");
   int nc;
   int ng;
   int inicio;
   int final;
   int peso;
   cout<<endl;
   cout<<"INGRESAR NUMERO DE GRAFOS (NODO)        : ";
   cin>>ng;
   Grafo Grafo1(ng);
   cout<<"INGRESAR NUMERO DE ARISTAS (CONEXIONES) : ";
   cin>>nc; 
   cout<<"------------------------------------"<<endl;
   cout<<"  ___                      ___ "<<endl;
   cout<<" | 0 |------------------->| 1 |"<<endl;
   cout<<"  ---                      --- "<<endl;
   cout<<endl;
   cout<<" inicio     costo         final"<<endl;
   cout<<endl;
   cout<<"------------------------------------"<<endl;
   cout<<endl;
   for(int i=0;i<nc;i++){

      cout<<"Ingresar inicio  : ";
      cin>>inicio;
      cout<<"Ingresar final   : ";
      cin>>final;
      cout<<"Ingresar peso    : ";
      cin>>peso;
      Grafo1.AgregarArista(inicio,final,peso);
      M.push_back(inicio);
      M.push_back(final);
      cout<<"------------------------------------"<<endl;
   }
      system("cls");
      cout<<endl;
      int i;
      int f;
      cout<<"EJECUTAR ALGORITMO DIJKSTRA"<<endl;
      cout<<endl;
      cout<<"Ingrese inicio : ";
      cin>>i;
      cout<<"Ingrese final  : ";
      cin>>f;
      cout<<"-------------------------------------------"<<endl;
      cout<<"COSTO DEL CAMINO MAS CORTO: "<<Grafo1.ADijkstra(i,f) << endl;
      cout<<"-------------------------------------------"<<endl;
      cout<<endl;
      cout<<"MATRIX DE ADYACENCIA"<<endl;
      cout<<endl;
         int iter=0;
         for (int i=0;i<ng;i++){
            for (int j=0;j<ng;j++){
               if(M[iter]=i and j==M[iter+1]){
                  cout<<"1 ";
                  iter+=1;
               }
               else{
                  cout<<"0 ";
               }
            }
            cout<<endl;
         }        
   

   return 0;
}