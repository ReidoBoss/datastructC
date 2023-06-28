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
    new_node->next= NULL;

    if(*root ==NULL){
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
void deleteEnd(Node** root){
    Node* node = malloc(sizeof(Node));
    node->next =NULL;

    Node* curr = *root;

    while(curr!=NULL){
        if(curr->next->next == NULL){
            curr->next =NULL;
            return;
        }          
        curr= curr->next;
    }

}

void display(Node** root){

    Node* curr = *root;

    if(*root==NULL){
        printf("NULL");
        return;
    }    

    while(curr!=NULL){
        printf("%d -> ",curr->x);
        curr = curr->next;
        if(curr==NULL){
            printf("NULL");
        }
    }
    printf("\n");


}

int main(){


    Node* list = NULL;
    insertEnd(&list,24);
    insertEnd(&list,244);
    insertEnd(&list,2445);
    insertEnd(&list,24245);
    insertEnd(&list,8569);

    deleteEnd(&list);
    display(&list);





    return 0;
}