#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* left;
struct node* right;
};

void Inorder(struct node* root){
if(root!=NULL){
Inorder(root->left);
printf("%d,",root->data);
Inorder(root->right);
}

}
void Postorder(struct node* root){
if(root!=NULL){
Postorder(root->left);
Postorder(root->right);
printf("%d,",root->data);
}
}
void Preorder(struct node* root){
if(root!=NULL){
printf("%d,",root->data);
Preorder(root->left);
Preorder(root->right);
}

}
struct node* createNode(){

int n;

printf("Enter Element Of Node\n");
scanf("%d",&n);

struct node* newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = n;
if(n==0)
return 0;
printf("Enter Data For Left of %d Node\n",n);
    newnode->left = createNode();
printf("Enter Data For Right of %d Node\n",n);
newnode->right=createNode();
 
return newnode;
}

int main(){
struct node* root;
root= createNode();

printf("Inorder Traversal\n");
Inorder(root);
printf("Preorder Traversal\n");
Preorder(root);
printf("Postorder Traversal\n");
Postorder(root);
return 0;

}