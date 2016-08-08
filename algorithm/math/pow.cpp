#include <iostream>

/*
	compute a^n

	O(logn)
*/

double pow(double a, int n){
	if( n == 0 ) return 1;
	if( n == 1 ) return a;
	double t  = pow(a, n/2);
	return t * t * pow(a, n % 2);
}

double pow2(double a, int n){
	double ret = 1;
	while(n){
		if(n%2 == 1) ret *= a;
		a *= a; n /= 2;		
	}
	return ret;
}

int main(){
	double arr[10]={1, 2, 3, 4, 5
			, 6, 7, 8, 9, 10};

	for(int i = 0; i < 10; i++){
		std::cout << pow(arr[i], 2) << std::endl;
	}
}
