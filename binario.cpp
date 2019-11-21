#include <iostream>
#include <vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct node{
	int data;
	struct node*  left;//izquierda
	struct node*  right;//derecha
};

int main(int argc, char** argv) {
	

	vector <node> tree;
	struct node ing;


	struct node temp;
	temp.left=NULL;
	temp.right=NULL;
	
	tree.push_back(temp);

	for(int i = 0; i < 8; i++) {
		cout <<"digite numeros ";
		cin  >>ing.data;
		
		if (ing.data>tree[i].data) {
			
			tree[i].right=&temp;
			
		}else{
			
			tree[i].left=&temp;
		}
		
		
		
		tree.push_back(ing);
	}
	
	for (auto item:tree) {
		
		
		cout <<endl<<"data = "<<item.data;
		cout <<endl<<"left = "<<item.left;
		cout <<endl<<"right = "<<item.right;
		
	}

	
	return 0;
}
