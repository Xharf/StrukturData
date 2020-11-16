#include <bits/stdc++.h>
using namespace std;

typedef struct node *typeptr;

struct node{
		char nim[6];
		char nama[100];
		int nilai;
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

void sisipNode(string nim,string nama, int nilai)
{ 
	typeptr new_node, helper;
	new_node=(node *) malloc(sizeof(node));
	strncpy(new_node->nim,nim.c_str(),6);
	strncpy(new_node->nama,nama.c_str(),100);
	new_node->nilai = nilai;
	new_node->next=NULL;
	
	if (listKosong()){
		new_node->next=head;
		head->next=new_node;
		head->nilai=1;
	}
	else if (nilai <= head->next->nilai){
		// sisip didepan, pertama setelah head.
		new_node->next=head->next;
		head->next=new_node;
		head->nilai++; 
	}
	else{
		helper=head->next;
		while (helper->next != head &&
			nilai > helper->next->nilai)
				helper=helper->next;
				
		// sisip tengah atau akhir sama saja.
		new_node->next=helper->next; 
		helper->next=new_node;
		head->nilai++;
	}
}

void jmlhnilai(){
	typeptr helper;
	helper = head->next;
	float total;
	while(helper!=head)
	{
		total += helper->nilai;
		helper = helper->next;
	}
	
	cout << "\nRata-rata Nilai = "
		<< total/(1.0*head->nilai);
}

void cetaklist(){
	typeptr helper;
	helper = head->next;
	
	while(helper!=head)
	{
		cout << helper->nim << ' '
			<< helper->nama << ' '
			<< helper->nilai << endl;
		helper = helper->next;
	}
	cout <<endl;
}

int main(){
	listBaru();
	printf("Data Nilai (NIM, Nama, Nilai) : \n");
	sisipNode("12718", "akbar", 70);
	sisipNode("12719", "doni", 75);
	sisipNode("12720", "monic", 75);
	sisipNode("12721", "dela", 80);
	cetaklist();
	jmlhnilai();
	getchar();
	
	return 0;
}

