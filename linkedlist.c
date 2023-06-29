#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int x;
    struct Node* next;

}Node;
void display(Node** root){
    Node* curr = *root;
    if(curr==NULL){
        printf("NULL");
        return;
    }

    while(root!=NULL){
        if(curr->next==NULL)
        {
            printf("%d",curr->x);
            return;
        }
        printf("%d -> ",curr->x);
        curr = curr->next;
    }


}

int displayBefore(Node** root,char name[],int print){
    Node* list = *root;
    char dash[] = "------------------------";

    int sizeDash = strlen(dash)*2;  
    int sizeName = strlen(name);
    int total = sizeDash+sizeName;

    if(print){
        printf("%s%s%s\nBefore: ", dash,name,dash);
        display(&list);
    }

    return total;

}
void displayAfteR(Node** root,int count){
    Node* curr = *root;
    char character = '-';
    char duplicated[count + 1];

    memset(duplicated, character, count);
    duplicated[count] = '\0';
    printf("\nAfter:  ");
    display(&curr);
    printf("\n%s\n", duplicated);
}

void insertEnd(Node** list,int value){

    Node* new_node= malloc(sizeof(Node));
    new_node->x = value;
    new_node->next = NULL;

    if(*list==NULL){
        *list = new_node;
        return;
    }

    Node* curr = *list;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = new_node;

}

int listSize(Node**root){
    if(*root==NULL){
        return 0;
    }
    int i = 0;
    Node* curr = *root;
    while (curr!=NULL)
    {
        i+=1;
        curr= curr->next;
    }   

    return i;        
    
}

void sortAsc(Node** root){
    char name[] = "Ascending Bubble Sort";
    Node * list = *root;
    int size = listSize(&list);
    displayBefore(&list,name,1);

    for(int i = 1; i < size ; i++){
        Node* curr = *root;

        while(curr!=NULL){
            if(curr->next!=NULL&&curr!=NULL){
                if(curr->x > curr->next->x){
                    int temp;
                    temp = curr->x;
                    curr->x = curr->next->x;
                    curr->next->x = temp;
                }
            }

            curr= curr->next;
        }
    }
    int sizeStr = displayBefore(&list,name,0);

    displayAfteR(&list,sizeStr);



}

void sortDesc(Node** root){
    Node* list = *root;
    int size = listSize(&list);

    
    displayBefore(&list,"Descending Bubble Sort",1);
    int sizeStr = displayBefore(&list,"Descending Bubble Sort",0);

    for(int i = 1; i < size; i ++ ){
        Node* curr = *root;

        while(curr!=NULL){
            if(curr->next!=NULL){
                if(curr->x < curr->next->x){
                    int temp;
                    if(curr->x < curr->next->x){
                        temp = curr->x;
                        curr->x = curr->next->x;
                        curr->next->x = temp;
                    }    
                    
                }
            }
            curr = curr->next;
        }

    }

    displayAfteR(&list,sizeStr);



}

void insertFirst(Node** root,int value){

    Node* new_node = malloc(sizeof(Node));
    new_node ->x = value;
    new_node->next = *root;

    *root = new_node;
}

int findIndex(Node** root, int index){
    Node* curr = *root;
    int i = 0;
    while(curr!=NULL){
        i++;

        if(curr->x==index){
            printf("\nIndex is at: %d",i);
            return i;
        }
        curr= curr->next;


    }

    printf("\nNo index is found");
    return -1;

}

void deleteFirst(Node**root){
    if(*root==NULL){
        printf("Nothing to delete");
        return;
    }

    Node* curr = *root;
    *root = curr->next;


}

void deleteEnd(Node**root){
    Node* curr = *root;
    if(*root==NULL){
        printf("Nothing to delete\n");
        return;
    }
    if(curr->next==NULL){
        *root=NULL;
        return;
    }
    while (curr!=NULL)
    {
        if(curr->next->next==NULL){
            curr->next=NULL;
            return;
        }
        curr= curr->next;
    }
    
 
}




int main(){
    Node* list = NULL;
    insertEnd(&list, 26);
    insertEnd(&list, 49);
    insertEnd(&list, 72);
    insertEnd(&list, 3);
    insertEnd(&list, 87);
    insertEnd(&list, 11);
    insertEnd(&list, 65);
    insertEnd(&list, 38);
    insertEnd(&list, 92);
    insertEnd(&list, 5);
    int size = listSize(&list);   


    sortDesc(&list);
    

    return 0;
}