#include <bits/stdc++.h>
using namespace std;

typedef struct node *typeptr;

struct node{
		int info;
		typeptr next;
};
typeptr head;

void listBaru(){
	head=(node *) malloc(sizeof(node));
	head->next=head;
}

bool listKosong(){
	if(head->next==head){
		return true;
	} else
		return false;
}

void sisipNode(int new_info)
{ 
	typeptr new_node, helper;
	new_node=(node *) malloc(sizeof(node));
	new_node->info=new_info;
	new_node->next=NULL;
	
	if (listKosong()){
		new_node->next=head;
		head->next=new_node;
		head->info=1;
	}
	else if (new_info <= head->next->info){
		// sisip didepan, pertama setelah head.
		new_node->next=head->next;
		head->next=new_node;
		head->info++; 
	}
	else{
		helper=head->next;
		while (helper->next != head &&
			new_info > helper->next->info)
				helper=helper->next;
				
		// sisip tengah atau akhir sama saja.
		new_node->next=helper->next; 
		helper->next=new_node;
		head->info++;
	}
}

void cetakLebihBesarDari(int number){
	typeptr helper;
	helper = head->next;
	
	while(helper!=head)
	{
		if(helper->info >=number){
			cout << ' ' << helper->info << ' ';
		}
		helper = helper->next;
	}
}

int main(){
	listBaru();
	sisipNode(5);
	sisipNode(125);
	sisipNode(150);
	sisipNode(175);
	sisipNode(200);
	sisipNode(225);
	sisipNode(250);
	cetakLebihBesarDari(150);
}


