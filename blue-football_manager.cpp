#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	char name[50];
	int value;
	struct data *left, *right;
}*root;


struct data *push(struct data *node ,char name[], int number){
	char choose[10];
	if(node==NULL){
		node=(struct data*)(malloc(sizeof(struct data)));
		strcpy(node->name, name);
		node->value=number;
		node->left=node->right=NULL;
	}

	else{
		printf("kiri atau kanan:");
		scanf("%s",choose); getchar();
		if(strcmp(choose,"kiri")==0){
			node->left= push(node->left, name, number);
		}
		else if(strcmp(choose,"kanan")==0){
			node->right= push(node->right, name, number);
		}
	}
	return node;
}

void insert(){
	char name[50];
	int number;
	do{
		printf("input name:");
		scanf("%[^\n]",name); getchar();
	}while(strlen(name)<3||strlen(name)>20);
	do{
		printf("input number:");
		scanf("%d",&number); getchar();
	}while(number<1||number>99);
	root = push(root,name,number);
}

void inOrder(struct data *curr){
	if(curr!=NULL){
		inOrder(curr->left);
		printf("- %s %d",curr->name,curr->value);
		inOrder(curr->right);
	}

}

struct data *deletebyname(struct data *curr,char nama[]){
	
		if(curr->left != NULL && strcmp(curr->left->	name,nama)!=0){
		curr->left = deletebyname(curr->left,nama);
		}
		else
		{
			free(curr);
			curr = NULL;
		}
		if(curr->right != NULL && strcmp(curr->right->name,nama)!=0){
		curr->right = deletebyname(curr->right,nama);
		}
		else if((curr->name,nama) == 0)
		{
			free(curr);
			curr = NULL;
		}
		
	
	return curr;

}



void menu(){
	printf("1. View All Player\n2. Add Player\n3. Remove Player\n4. Inorder, Preorder, Postorder\n5. Exit and Remove All\n");
}



int main(){
	int opt;
	char inputnama[50];
	do{
		menu();
		scanf("%d",&opt); getchar();
		switch (opt){
			case 1:
				inOrder(root); getchar();
				break;
			case 2:
				insert();
				break;
			case 3:
				scanf("%[^\n]",inputnama);
				deletebyname(root,inputnama);
				break;
			case 4:
				break;
		}
	}while(opt!=5);
	
	return 0;
}