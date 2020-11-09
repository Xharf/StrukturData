#include <bits/stdc++.h>
using namespace std;

typedef struct node *typeptr;
struct node{
	int info;
	typeptr next;	
	typeptr prev;
};

typeptr first, end;

int listKosong()
{ 
	if(first==NULL)
		return(true);
	else
		return(false); 
}

void buatListBaru()
{
	typeptr list;
	list=NULL;
	first=list;
	end=list;
}

void sisipNode(int new_info)
{ 
	typeptr new_node, helper,helper2;
	new_node=(node *) malloc(sizeof(node));
	new_node->info=new_info;
	new_node->next=NULL;
	new_node->prev=NULL;
	if (listKosong()){
		first=new_node;
		end=new_node; 
	}
	else if (new_info <= first->info){
		first->prev=new_node;
		new_node->next=first;
		first=new_node; 
	}
	else{
		helper=first;	
		while (helper->next!=NULL && new_info > helper->next->info)
			helper=helper->next;
		
		helper2=helper->next;
		new_node->prev=helper;
		new_node->next=helper->next; // Sisip di tengah atau di belakang
		helper->next=new_node;
		
		if (new_info>end->info){
			end=new_node;
		} else{
			helper2->prev = new_node; 
		}
	}
}

void bacaMundur()
{	
	typeptr helper;
	helper = end;
	int i=0;
	while (helper!= NULL)
	{
		if(i==2){
			helper = helper->prev;
			i=0;
			continue;
		}
		cout << ' ' << helper->info << ' ';
		helper = helper->prev;
		i++;
	}	
}

int main(){
	buatListBaru();
	sisipNode(50);
	sisipNode(25);
	sisipNode(150);
	sisipNode(75);
	sisipNode(100);
	sisipNode(125);
	
	bacaMundur();
}
