#include <stdio.h>

void swap (int x, int y){
    int temp;

    printf("Before: %d, %d\n",x,y);
    temp = x;
    x=y;
    y = temp;
    printf("After: %d, %d",x,y);

}

int main(){

    swap(1,23);

    return 0;
}