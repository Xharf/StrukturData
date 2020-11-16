#include <bits/stdc++.h>
using namespace std;

typedef struct node *typeptr;

struct node{
	int info;
	typeptr next;	
};

typeptr first, last;

int listKosong()
{ 
	if(first==NULL)
		return(true);
	else
		return(false); 
}

void listBaru()
{
	typeptr list;
	list=NULL;
	first=list;
	last=list;
}

void sisipNode(int new_info)
{ 
	typeptr new_node, helper;
	new_node=(node *) malloc(sizeof(node));
	new_node->info=new_info;
	new_node->next=NULL;
	if (listKosong()){
		first=new_node;
		last=new_node; 
	}
	else if (new_info <= first->info){
		new_node->next=first;
		first=new_node; 
	}
	else{
		helper=first;	
		while (helper->next!=NULL && new_info > helper->next->info)
			helper=helper->next;
		
		new_node->next=helper->next; // Sisip di tengah atau di belakang
		helper->next=new_node;
		
		if (new_info>last->info){
			last=new_node;
		}
	}
}

int lebihKecilDari(int number){
typeptr helper;
	helper = first;
	int i=0;

	while(helper!=last && helper->info<number)
	{
		i++;
		helper = helper->next;
	}
	return i;
}


int main(){
	listBaru();
	sisipNode(30);
	sisipNode(60);
	sisipNode(90);
	sisipNode(120);
	sisipNode(150);
	sisipNode(180);

	cout << "lebih kecil dari 130 ada : " <<  lebihKecilDari(130);
}

