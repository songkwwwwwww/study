#include <stdio.h>

int main(){
    freopen("3053.txt", "r", stdin);
    double r;
    scanf("%lf", &r);
    double pi = 3.14159265358979323846;
    printf("%.6lf\n", pi * r * r);
    printf("%.6lf\n", 2.0 * r * r);
}
