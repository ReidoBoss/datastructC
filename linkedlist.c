#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int x;
    struct Node* next;

}Node;

void display(Node* list){

    if(list==NULL){
        printf("NULL");
        return;
    }

    while(list !=NULL){
        printf("%d -> ",list->x);
        list = list->next;
        if(list==NULL){
            printf("NULL");
        }
    }

}

void insertEnd(Node** root, int value){
    
    Node* new_node = malloc(sizeof(Node));
    new_node->x = value;
    new_node->next = NULL;

    if(*root == NULL){
        *root = new_node;
        return;
    }

    Node* curr = *root;
    while ( curr->next !=NULL)
    {
        curr = curr->next;

    }
    curr->next = new_node;


}


int main(){

    Node* list=NULL;
    
    insertEnd(&list,24);
    insertEnd(&list,23);
    insertEnd(&list,143);



    display(list);


    


    return 0;
}