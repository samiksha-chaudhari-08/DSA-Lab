/*
Problem Statement: A book consists of chapters, chapters consist of sections and sections consist of subsections.
Construct a tree and print the nodes. Find the time and space requirements of your method.
*/

#include<iostream>
using namespace std;

struct Node 
{	  
	string label;
	int ch_count;
	
	struct Node* child[10];
}*root;

class Tree{
	public:
		Tree()
		{
			root = nullptr ; 
		}
		
		string lbel;
		int count;
		
		void create()
		{
			root = new Node;
			cout<<"Enter Name of Book \t: ";
			cin>>root->label;
			
			cout<<"Enter Number of Chapters\t :";
			cin>>root->ch_count;
			
			for(int i = 0; i < root->ch_count; i++)
			{
				root->child[i] = new Node ;
				cout<<"Enter Name of chapter : "<<i+1<<"\t";
				cin>>root->child[i]->label;
				cout<<"Enter Number of sections : \t";
				cin>>root->child[i]->ch_count;
				
				for(int j = 0; j < root->child[i]->ch_count;j++)
				{	root->child[i]->child[j] = new Node;
					cout<<"Enter section name : "<<i+1<<"-"<<j+1<<" -";
					cin>>root->child[i]->child[j]->label;
					cout<<"Enter Number of subsections :";
					cin>>root->child[i]->child[j]->ch_count;
					
					for (int k = 0; k < root->child[i]->child[j]->ch_count ; k++)
					{
						root->child[i]->child[j]->child[k] = new Node;
						cout<<"Enter Sub-section name : "<<i+1<<"-"<<j+1<<"-"<<k+1<<" : ";
						cin>>root->child[i]->child[j]->child[k]->label;
						
					}					
				}
			}
		}
		
void display(Node * r){
	cout<<endl<<"Name of Book:\t";
	cout<<root->label<<endl;
	cout<<endl<<"Number of chapters :\t";
	cout<<root->ch_count<<endl;
	for (int i=0;i<root->ch_count;i++){
		cout<<endl<<"Name of chapter:"<<i+1; 
		cout<<endl<<root->child[i]->label<<endl;
		cout<<"Number of sections :\t";
		cout<<root->child[i]->ch_count<<endl;
		
		for(int j=0;j<root->child[i]->ch_count; j++)
		{
			cout<<"Section name : "<<root->child[i]->child[j]->label<<endl;
			cout<<"Number of Subsections : "<<root->child[i]->child[j]->ch_count<<endl;
			for (int k = 0; k < root->child[i]->child[j]->ch_count ; k++)
					{
						cout<<"Sub-section name : "<<i+1<<"-"<<j+1<<"-"<<k+1<<" : ";
						cout<<root->child[i]->child[j]->child[k]->label<<endl;
						
					}		
		}
		
	}
}
};
int main()
{
	Tree t;
    while(1)
    {	
    	cout<<"\n====Main Menu===="<<endl;
    	cout<<"1.Add Book :"<<endl;
    	cout<<"2.Display Book : "<<endl;
    	cout<<"3.Exit "<<endl;
    	cout<<"Choose an option (1-3):\t";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:
				t.create();
				break;
			case 2:
				t.display(root);
				break;
			case 3:
				cout<<"The End ";
				exit(0);
				break;
			default:
				cout<<"Invalid Choice !!";
		}
    }
}



