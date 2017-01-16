#include "show_bytes_test.h"

void show_bytes(byte_pointer start, size_t len){
    int i;
    for(i = 0; i < len; i++)
	printf(" %.2x", start[i]);
    printf("\n");
    printf("\n");
}

void show_int(int x){
    printf("show int\n");
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
    printf("show float\n");
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
    printf("show pointer\n");
    show_bytes((byte_pointer) &x, sizeof(void *));
}


void test_show_bytes(int val){
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    printf("val = %d\n", val);
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void exec_ex_2_5(){
    int a = 0x12345678;
    byte_pointer ap = (byte_pointer) &a;
    show_bytes(ap, 1);
    show_bytes(ap, 2);
    show_bytes(ap, 3);
}

void exec_ex_2_6(){
    int a = 2607352; // = 0x0027C8F8
    float b = 3510593.0;
    double c = 3510593.0;

    show_bytes( (byte_pointer) &a, sizeof(int));
    show_bytes( (byte_pointer) &b, sizeof(float));
}
/*
int main(){
//    int n = 10;
//    test_show_bytes(n);
    //exec_ex_2_5();
    exec_ex_2_6();
}
*/
