#include <stdio.h>

void inplace_swap(int* x, int* y){
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse_array(int a[], int cnt){
    int first, last;
    for(first = 0, last = cnt - 1; first < last; first++, last--){
	inplace_swap(&a[first], &a[last]);
//	swap(&a[first], &a[last]);
    }
}

void print_array(int a[], int cnt){

    for(int i = 0; i < cnt; i++){
	printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9};

    printf("before A : \n");
    print_array(a, 5);
    reverse_array(a, 5);
    printf("after A\n");
    print_array(a, 5);


    printf("\n");

    printf("before B : \n");
    print_array(b, 4);
    reverse_array(b, 4);
    printf("after B\n");
    print_array(b, 4);
}
