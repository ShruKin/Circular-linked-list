#include <stdio.h>

void foo(int a){
    a = 3;
}

int main(){
    int b = foo(3);
}