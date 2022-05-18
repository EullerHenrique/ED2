#include <stdio.h>
int main(){
    int *a = NULL;
    int b = 0;
    int c = 0;
    int d = 2;

    a = &b;
    *a = d;
   

    printf("%d",b);
}