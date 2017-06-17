#include <stdio.h>

const int MOD = 40;

int a, b, c, d, e;

int main(){
    freopen("4327.txt", "r", stdin);
    while(scanf("%d %d %d %d", &a, &b, &c, &d) && (a || b || c || d)){
	// 1) turn the dial clockwise 2 full turns
	e = 40 * 2;
	// 2) stop at the first number of the combination
	e += ((a - b + MOD) % MOD);
	// 3) turn the dial counter-clockwise 1 full turn
	e += 40;
	// 4) continue turning counter-clockwise until the 2nd number is reached
	e += ((c - b + MOD) % MOD);
	// 5) turn the dial clockwise again until the 3rd number is reached
	e += ((c - d + MOD) % MOD);
	// 6) pull the shank and the lock will open.
	printf("%d\n", e * 9);
    }
}
