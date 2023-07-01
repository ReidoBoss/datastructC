#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int x;
    struct Node* next;
}Node;
void display(Node** root){

    Node* curr = *root;
    if(curr==NULL){
        printf("NULL\n");
        return;
    }
    while(curr!=NULL){
        if(curr->next==NULL){
            printf("%d\n",curr->x);
            return;
        }
        printf("%d -> ",curr->x);
        curr = curr->next;
    }
}

void before(Node** root){
    Node* list = *root;
    printf("Before:\t ");
    display(&list);
    
}
void after(Node** root){
    Node* list = *root;
    printf("After:\t ");
    display(&list);
}

int listSize(Node** root){
    Node* curr = *root;
    int i= 0;
    while(curr!=NULL){
        i++;
        curr = curr->next;
    }
    return i;
}
int findIndex(Node** root, int value){
    Node* curr = *root;
    int i=0;
    while (curr!=NULL)
    {   

        i++;
        if(curr->x == value){
            return i;
        }
        curr = curr->next;

    }
    return 0;
}

void sortAsc(Node** root){
    Node* list = *root;
    int size = listSize(&list);
    int temp;
    printf("Ascending Sort:\n");
    before(&list);
    for (int i = 1;i <size ;i++){
        Node* curr = *root;
        while(curr!=NULL){
            if(curr->next==NULL){

            }
            else{
                if(curr->x > curr->next->x){
                    temp = curr->x;
                    curr->x = curr->next->x;
                    curr->next->x = temp;
                }
            }
            curr= curr->next;
        }
    }
    after(&list);
}
void sortDesc(Node** root){
    printf("Descending Sort:\n");
    Node* list = *root;
    int size = listSize(&list);
    before(&list);
    for(int i = 0; i < size; i ++){
        Node* curr = *root;
        while(curr!=NULL){
            if(curr->next==NULL){                
            }
            else{
                if(curr->x < curr->next->x){
                    int temp;
                    temp = curr->x;
                    curr->x = curr->next->x;
                    curr->next->x = temp;
                }
            }
            curr = curr->next;
        }
    }
    after(&list);
}

void deleteFirst(Node** root){
    Node* list = *root;
    if(list ==NULL){
        printf("Nothing to delete\n");
        return;
    }

    *root = list->next;
}
void deleteEnd(Node** root){
    Node* list = *root;
    printf("Delete End:\n");
    before(&list);
    if(list==NULL){
        printf("nothing to delete\n");
        return;
    }
    while(list!=NULL){
        if(list->next->next==NULL){
            list->next=NULL;

            Node* curr = *root;
            after(&curr);
            return;
        }
        list = list->next;
    }

}

void insertEnd(Node**root, int value){
    Node* new_node = malloc(sizeof(Node));
    new_node->x = value;
    new_node->next = NULL;
    
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
void insertFirst(Node** root, int value){
    Node* new_node = malloc(sizeof(Node));
    new_node->x = value;
    new_node->next = *root;

    *root = new_node;
}

void removeElement(Node** root, int value){
    Node* curr = *root;
    Node* prev = NULL;

    while(curr!=NULL){

        if(curr->x == value){
            if (prev==NULL)
            {
                *root = curr->next;
                return;
            }
            prev->next = curr->next;
            return;
        }

        prev = curr;
        curr = curr->next;
    }
    

}

void addAfter(Node**root, int current ,int value){
    Node* new_node = malloc(sizeof(Node));
    new_node->x = value;
    
    Node* curr = *root;
    while (curr!=NULL)
    {
        if(curr->x == current){
            new_node->next = curr->next;
            curr->next = new_node;
            return;
        }
        curr = curr->next;
    }
    
   printf("Nothing to be replaced\n"); 
}
void addBefore(Node** root, int current, int value){
    Node* new_node = malloc(sizeof(Node));
    new_node ->x = value;

    Node* curr = *root;
    Node* prev = NULL;
    while(curr!=NULL){
        if(current == curr->x){
            if(prev==NULL){
                new_node->next = *root;
                return;
            }
            new_node->next = prev->next;
            prev->next = new_node;
        }
        prev= curr;
        curr = curr->next;
    }
}

void reverse(Node**root){
    Node* list = *root;
    int size = listSize(&list);
    int arr[size];
    printf("Reverse List: \n");
    before(&list);
    
    for(int i = 0 ; i < size; i ++){
        arr[i]= list ->x;
        list = list->next;
    }

    Node* curr = *root;
    int i = size-1;
    while (curr!=NULL)
    {   
        curr->x = arr[i];
        i--;
        curr=curr->next;
    }
    
    Node* display = *root;
    after(&display);

}




int main(){

    Node* list = NULL;

    insertEnd(&list,1);
    insertEnd(&list,2);
    insertEnd(&list,3);
    insertEnd(&list,4);
    insertEnd(&list,5);
    insertEnd(&list,6);
    insertEnd(&list,7);
    insertEnd(&list,8);
    display(&list);

    addBefore(&list,4,32);
    display(&list);

    return 0;
}
