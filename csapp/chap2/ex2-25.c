#include <stdio.h>


float sum_elements(float a[], unsigned length){
    int i;
    float result = 0;

    for(i = 0; i < length; i++){
	result += a[i];
    }
    return result;
}

int main(){
    float arr[5] = {5.1, -1.5, 3.4, 10.3, -2.3};
    float ans = sum_elements(arr, 0);
    //float ans = sum_elements(arr, 5);
    printf("%lf\n", ans);
}
