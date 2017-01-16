#include <stdio.h>
#include "show_bytes_test.h"

int main(){
    int x = 0x87654321;

    int answer_a = 0x00000021;
    int answer_b = 0x789ABC21;
    int answer_c = 0x876543FF;

    int my_a = x & 0xFF;
    int my_b = (~x & (~(0xFF)) | (x & (0xFF))) ;
    int my_c = x | 0xff;

    printf("@ Question-A\n");
    printf("My_Answer_A : \n");
    show_bytes( (byte_pointer)&my_a, sizeof(int) );
    printf("Answer_A : \n");
    show_bytes( (byte_pointer)&answer_a, sizeof(int) );

    printf("@ Question-B\n");
    printf("My_Answer_B : \n");
    show_bytes( (byte_pointer)&my_b, sizeof(int) );
    printf("Answer_B : \n");
    show_bytes( (byte_pointer)&answer_b, sizeof(int) );



    printf("@ Question-C\n");
    printf("My_Answer_C : \n");
    show_bytes( (byte_pointer)&my_c, sizeof(int) );
    printf("Answer_C : \n");
    show_bytes( (byte_pointer)&answer_c, sizeof(int) );


    
}
