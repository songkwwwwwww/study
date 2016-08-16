/*
	boj problem #

2745
11005

2085

1112

5692

3565

*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main() {
    freopen("prob_id_13.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    for (int tc=1; tc <= t; tc++) {
        int n;
        scanf("%d",&n);

        int ans = -1;
        for (int b=2; b*b <= n; b++) {
            int num = n%b;
            int x = n;
            bool ok = true;
            while (x > 0) {
                if (x%b != num) {
                    ok = false;
                    break;
                }
                x /= b;
            }
            if (ok) {
                ans = b;
                break;
            }
        }
        if (ans == -1) {
            for (int i=1; i*i <= n; i++) {
                if (n%i != 0) {
                    continue;
                }
                int x = i;
                int base = n/x - 1;
                if (base > x) {
                    ans = base;
                }
            }
        }
        if (ans == -1) {
            ans = n+1;
        }
        printf("Case #%d\n",tc);
        printf("%d\n",ans);
    }

    return 0;
}

