#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm> // min
#include <cmath> // abs, sqrt

using namespace std;
typedef long long ll;

int main(){
    freopen("2022.txt", "r", stdin);
    double x, y, c;
    while(scanf("%lf %lf %lf",&x,&y,&c) == 3){
        double l = 0, r, m;
        r = min(x, y);
        while(abs(r-l) > 1e-6){
            m = (l + r) / 2.0;
            double d = m;
            double h1 = sqrt(x * x - d * d);
            double h2 = sqrt(y * y - d * d);
            double h = h1 * h2 / (h1 + h2);
            if(h > c)
                l = m;
            else // h < c
                r = m;
        }
        printf("%.3lf\n", l);
    }
}