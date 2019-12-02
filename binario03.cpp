#include <iostream>
#include <conio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct nodo{
	int dato;
	nodo *left;
	nodo *right;
};
nodo *crearnodo(int);

void insertarnodo(nodo *&,int);
void mostrararbol(nodo *,int);

nodo *arbol = NULL;

int main(int argc, char** argv) {
	int dato, contador=0;
	do{
		cout<<"inserar un nuevo nodo"<<endl;
	cout<<"digite un numero"<<endl;
	cin>>dato;
	insertarnodo(arbol,dato);
	
	cout<<"mostramos el arbol\n\n"<<endl;
	mostrararbol(arbol, contador);
	cout<<"\n";
	
	}while(dato=-1);
	
	
	
	getch();
	
	return 0;
}
nodo *crearnodo(int n){
	nodo *nuevo_nodo = new nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->left=NULL;
	nuevo_nodo->right=NULL;
	
	return nuevo_nodo;
	
}
void insertarnodo(nodo *&arbol,int n){
	if(arbol==NULL){
		nodo *nuevo_nodo=crearnodo(n);
		arbol=nuevo_nodo;
		
	}else {
		int valorraiz=arbol->dato;
		if(n<valorraiz){
			insertarnodo(arbol->left,n);
		}else{
			insertarnodo(arbol->right,n);
		}
	}
}

void mostrararbol(nodo *arbol,int cont){
	if(arbol==NULL){
		return;
		
	}else{
		mostrararbol(arbol->right,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrararbol(arbol->left,cont+1);
	}
}
