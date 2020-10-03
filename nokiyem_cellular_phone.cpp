#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	int code;
	int price;
	struct data *left, *right;
}*root;

struct data *init(int code, int price){
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->code=code;
	node->price=price;
	node->left=node->right=NULL;
	return node;
}

struct data *push(struct data *node, int code, int price){
	if(node==NULL){
		return node=init(code, price);
	}
	else if(code<node->code){
		node->left=push(node->left, code, price);
	}
	else if(code>node->code){
		node->right=push(node->right, code, price);
	}
}

void add(){
	int code;
	int price;
	do{
		system("clear");
		printf("Input phone code N[1-9][0-9][0-9][0-9]: N");
		scanf("%d",&code); getchar();
	}while(code<1000||code>9999);
	do{
		system("clear");
		printf("Input phone price [$50..$999]: $");
		scanf("%d",&price); getchar();
	}while(price<50||price>999);
	root=push(root,code,price);
}

struct data *pop(struct data *node,int code){
	int temp;
	if(node==NULL){
		printf("--- Phone Code is Not Found ---");
		return node;
	}
	else if(code<node->code){
		node->left=pop(node->left,code);
	}
	else if(code>node->code){
		node->right=pop(node->right,code);
	}
	else{
		printf("Phone Code		: [N%d]\nPhone Price		: [$ %d]\n",node->code,node->price);
		printf("Input New Phone Price [$50..$999]: ");
		do{
			system("clear");
			scanf("%d",&temp);	
		}while(temp<50||temp>999);
		node->price=temp;
		return node;
	}
}

void up(){
	int code;
	printf("Input phone code N[1-9][0-9][0-9][0-9]: N");
	do{
		system("clear");
		scanf("%d",&code);
	}while(code<1000||code>9999);
	root=pop(root,code);
}

void preOrder(struct data *node){
	if(node !=NULL){
		printf("- N%d [ $ %d ]\n",node->code, node->price);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void inOrder(struct data *node){
	if(node !=NULL){
		inOrder(node->left);
		printf("- N%d [ $ %d ]\n",node->code, node->price);
		inOrder(node->right);
	}
}

void postOrder(struct data *node){
	if(node !=NULL){
		postOrder(node->left);
		postOrder(node->right);
		printf("- N%d [ $ %d ]\n",node->code, node->price);
	}
}

void order(){
	printf("PreOrder :\n");
	preOrder(root);
	printf("\n");
	printf("InOrder :\n");
	inOrder(root);
	printf("\n");
	printf("PostOrder :\n");
	postOrder(root);
	printf("\n");
}

void menu(){
	printf("NOKIYEM CELLULAR PHONE\n");
	for(int i=0;i<strlen("NOKIYEM CELLULAR PHONE");i++){
		printf("x");
	}
	printf("\n1. Add New Phone\n2. Update Phone Price\n3. InOrder, PreOrder, PostOrder\n4. Exit\n\n");
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
				add();
				printf("--- Add New Phone Success ---\n");
				count++;
				getchar();
				break;
			case 2:
				if(count==0){
					printf("--- Phone Code is Not Found ---");
				}
				else{
					up();	
				} 
				getchar();

				break;
			case 3:
				if(count==0){
					printf("--- There is No Phone in The Tree ---");
				}
				else order();
				getchar();
				break;
		}

	}while(opt!=4);


	return 0;
}