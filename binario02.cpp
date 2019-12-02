#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};

main()
{
	
	int i=0,vector[10];
	
	FILE *p;
	fstream in;
	in.open("archivo.txt",ios::in);
	
	i=0;
	in>>vector[i];
	while(!in.eof())
	{
		i++;
		in>>vector[i];
	}
	for(i=0;i<7;i++)
	{
		/*vector<node> tree;
		struct node vector[i];
		vector[i].left=NULL;
		vector[i].right=NULL;
		
		tree.push_back(vector[i]);*/
		cout<<vector[i];
	}
	fclose(p);
	getch();
	
	
}
