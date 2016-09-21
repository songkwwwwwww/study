/*
참조:
	Stanford Univ.
	Course : Introduction to Programming Contests
	Chap2 Mathematics


	compute a^n
	O(log(a + b)) 
*/

int gcd(int a, int b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}





int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int extgcd(int a, int b, int& x, int& y){
    int d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else{
        x = 1;
        y = 0;
    }
    return d;
}