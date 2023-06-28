#include <stdio.h>
#include <stdlib.h>

typedef struct  Node
{
    int x; 
    struct Node* next;
}Node;

void display (Node* root){

    if (root==NULL)
    {
        printf("NULL");
        return;
    }
    

    while (root!=NULL){
        printf("%d -> ",root->x );
        root = root->next;

        if(root==NULL){
            printf("NULL");
            return;
        }
    }

}

void insertEnd (Node** root, int value){

    Node* new_node = malloc(sizeof(Node));
    new_node->x= value;
    new_node->next = NULL;  

    if(*root == NULL){

        *root = new_node;

        return;
    }

    Node* curr = *root;
    while (curr->next!=NULL)
    {
        curr = curr->next;
    }
    
    curr->next = new_node;
    

}


int main(){

    Node* root=NULL;
    insertEnd(&root,24);
    insertEnd(&root,245);
    insertEnd(&root,298);


    display(root);



    return 0;
}