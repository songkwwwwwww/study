#include <stdio.h>


/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y){
    unsigned s = x + y;
    // overflow occurs
    if(s < x)
	return 0;
    //
    else
	return 1;
}

int main(){
    unsigned a = 0xffffffff;
    unsigned b = 0xabcd0123;

    int ans = uadd_ok(a, b);
    // if overflow doesn't occur
    if(ans){
	printf("overflow doesn't occur!\n");
    }
    else{
	printf("overflow occur!\n");
    }
}
