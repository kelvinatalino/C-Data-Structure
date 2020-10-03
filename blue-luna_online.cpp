#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct data{
	char name[50];
	char job[50];
	int lvl;
	int dmg;
	struct data *left, *right;
}*root;

struct data *init(char name[],char job[],int lvl,int dmg){
	struct data *node= (struct data*)malloc(sizeof(struct data));
	strcpy(node->name,name);
	strcpy(node->job,job);
	node->lvl=lvl;
	node->dmg=dmg;
	node->left=node->right=NULL;
}

struct data *push(struct data *node, char name[],char job[],int lvl,int dmg){
	if(node==NULL){
		return node=init(name, job, lvl, dmg);
	}
	else if(dmg<node->dmg){
		node->left=push(node->left, name, job, lvl, dmg);
	}
	else if(dmg>node->dmg){
		node->right=push(node->right, name, job, lvl, dmg);
	}
}

void add(){
	char name[50];
	char job[50];
	int dmg;
	int lvl;
	do{
		printf("Input character's name [3..20][non space char]:");
		scanf("%s",name); getchar();
	}while(strlen(name)<3||strlen(name)>20);
	do{
		printf("Input character's job [fighter/rogue/mage]:");
		scanf("%s",job); getchar();
	}while(strcmp(job,"fighter")!=0 && strcmp(job,"rogue")!=0 && strcmp(job,"mage")!=0);
	do{
		printf("Input character's level [1..105]:");
		scanf("%d",&lvl); getchar();
	}while(lvl<1||lvl>105);

	if(strcmp(job,"fighter")==0){
		dmg= lvl+rand() %50;
	}
	else if(strcmp(job,"rogue")==0){
		dmg= lvl+rand() %25;
	}
	else if(strcmp(job,"mage")==0){
		dmg= lvl+rand() %75;
	}
	root=push(root, name, job, lvl, dmg);
}

void preOrderView(struct data *node){
	if(node!=NULL){
		printf("* %-15s | %-10s| lvl.%-5d | damage : %-10d\n",node->name, node->job, node->lvl, node->dmg);
		preOrderView(node->left);
		preOrderView(node->right);
	}
}

void view(){
	printf("Character List :\n\n");
	preOrderView(root);
}

void preOrder(struct data *node){
	if(node!=NULL){
		printf("%d ",node->dmg);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void inOrder(struct data *node){
	if(node!=NULL){
		inOrder(node->left);
		printf("%d ",node->dmg);
		inOrder(node->right);
	}
}

void postOrder(struct data *node){
	if(node!=NULL){
		postOrder(node->left);
		postOrder(node->right);
		printf("%d ",node->dmg);
	}
}

void Order(){
	printf("PreOrder : ");
	preOrder(root);
	printf("\n");
	printf("InOrder : ");
	inOrder(root);
	printf("\n");
	printf("PostOrder : ");
	postOrder(root);
	printf("\n");
}

struct data *popAll(struct data *node){
	while(node!=NULL){
		popAll(node->left);
		popAll(node->right);
		free(node);
	}
	return NULL;
}

void menu(){
	printf("BLUE - LUNA ONLINE\n");
	for(int i=0;i<strlen("BLUE - LUNA ONLINE");i++){
		printf("o");	
	}
	printf("\n\n");
	printf("1. View All Characters\n2. Add New Character\n3. Inorder, Preorder, Postorder Character’s Damage\n4. Exit and Popall\n\n");
	printf("Input choice :");
}

int main(){
	int count=0;
	int opt;
	do{
		system("clear");
		menu();
		scanf("%d",&opt); getchar();
		switch(opt){
			case 1: 
				if(count==0){
					printf("--- There is No Character in The Tree ---\n");
				}
				else view();
				getchar();
				break;
			case 2:
				add();
				count++;
				break;
			case 3:
				if(count==0){
					printf("--- There is No Character in The Tree ---\n");
				}
				else Order();
				getchar();
				count--;
				break;
		}
	}while(opt!=4);
	root=popAll(root);
	// view();
	return 0;
}