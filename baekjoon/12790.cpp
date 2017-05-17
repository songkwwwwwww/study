#include <stdio.h>


int main(){
    freopen("12790.txt", "r", stdin);

    int a, b, c, d, e, f, g, h, TC;
    scanf("%d", &TC);

    for(int tc = 1; tc <= TC; tc++){

	
	scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
	a = (a + e < 1) ? 1 : a + e;
	b = (b + f < 1) ? 1 : b + f;
	c = (c + g < 0) ? 0 : c + g;
	d = d + h;
	int power = a + 5 * b + 2 * c + 2 * d;
	printf("%d\n", power);
    }
}
