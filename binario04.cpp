
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct nodo{
    int valor;
    nodo* derecha;
    nodo* izquierda;
}; 
nodo *BST=NULL;
nodo *NuevoNodo(int val){
    nodo *nodon = new nodo();
    nodon->derecha= NULL;
    nodon->izquierda= NULL;
    nodon->valor=val;
    return nodon; 
} 
void Poner(nodo *&BST,int datotemp){
    if(BST==NULL){
        nodo *temporal= NuevoNodo(datotemp);
        BST=temporal;
    }
    else{
        int root=BST->valor;
        if (root>datotemp){
            Poner(BST->izquierda,datotemp);            
        }
        else{
            Poner(BST->derecha,datotemp);
        }
    }
}
void inorder(struct nodo *BST) { 
    if (BST != NULL){ 
        inorder(BST->izquierda); 
        cout<<"------------------------------------"<<endl;
        cout<<"valor               "<<BST->valor<<endl;
        cout<<"direccion del valor "<<&BST->valor<<endl;
        cout<<"derecho             "<<BST->derecha<<endl;
        cout<<"izquierdo           "<<BST->izquierda<<endl;
		inorder(BST->derecha); 
    } 
} 
int main() {   
    string texto;
    ifstream archivo;
 	archivo.open("BST.txt",ios::in);
 	while(!archivo.eof()){
    getline(archivo,texto);
    int n;
    istringstream(texto)>>n;
    Poner(BST,n);
	} 
	archivo.close();
    //     20
    //  10    30
    //5   15
    inorder(BST);
    return 0; 
}
