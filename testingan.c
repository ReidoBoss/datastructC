#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int x;
    struct Node* next;

}Node;

void insertEnd(Node** root, int value){
    Node* new_node = malloc(sizeof(Node));
    new_node->x = value;
    new_node ->next = NULL;

    
    if(*root==NULL){
        *root = new_node;
        return;
    }

    Node* curr = *root;
    while(curr->next!=NULL){
        curr = curr->next;
    }

    curr->next = new_node;
    


}

void display(Node* root){

    if (root==NULL)
    {
        printf("NULL");
        return;
    }
    

    while(root!=NULL){
        printf("%d -> ",root->x);
        root = root->next;

        if(root==NULL){
            printf("NULL");
        }
    }    

}


int main(){

    Node* root=NULL;
    insertEnd(&root,24);
    insertEnd(&root,69);
    insertEnd(&root,239);
    insertEnd(&root,2324);


    display(root);


    return 0;
}