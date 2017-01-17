#include <stdio.h>


/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y){
    int s = x + y;

    // if overflow occur
    if( (x > 0 && y > 0 && s <= 0) 
	    || (x < 0 && y < 0 && s >= 0) ){
	return 0;
    }
    else{
	return 1;
    }

}

int main(){
    
    int a = 0x7fffffff, b = 0x7fffffff;
    int c = 0x80000000, d = 0x80000000;

    if( !tadd_ok(a, b) )
	printf("if a + b, overflow occur!\n");


    if( !tadd_ok(c, d) )
	printf("if c + d, overflow occur!\n");
}
