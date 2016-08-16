/*

	boj problem #

2805

1654

2110

2343

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
struct Line {
    int x1, y1, x2, y2;
};
int dist(int x1, int y1, int x2, int y2) {
    return max(abs(x2-x1), abs(y2-y1));
}
bool check(vector<Line> &a, int len) {
    int n = a.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int xs[] = {a[i].x1, a[i].x2};
            int ys[] = {a[j].y1, a[j].y2};
            for (int l1=0; l1<2; l1++) {
                for (int l2=0; l2<2; l2++) {
                    int x = xs[l1]+len;
                    int y = ys[l2]+len;
                    bool ok = true;
                    for (int k=0; k<n; k++) {
                        int dist1 = dist(x, y, a[k].x1, a[k].y1);
                        int dist2 = dist(x, y, a[k].x2, a[k].y2);
                        int d = min(dist1, dist2);
                        if (d > len) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        return true;
                    }
                }
            }

        }
    }
    return false;
}
int main() {
    int t;
    scanf("%d",&t);
    for (int tc=1; tc<=t; tc++) {
        int n;
        scanf("%d",&n);
        vector<Line> a(n);
        for (int i=0; i<n; i++) {
            scanf("%d %d %d %d",&a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
            a[i].x1 *= 2;
            a[i].y1 *= 2;
            a[i].x2 *= 2;
            a[i].y2 *= 2;
        }
        int left = 0;
        int right = 100000000;
        int ans = right;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (check(a, mid)) {
                right = mid-1;
                ans = min(ans, mid);
            } else {
                left = mid+1;
            }
        }
        printf("Case #%d\n",tc);
        if (ans%2 == 0) {
            printf("%d\n",ans/2);
        } else {
            printf("%d.5\n",ans/2);
        }
    }
    return 0;
}
