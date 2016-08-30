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