#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
int main() {
    freopen("10816.txt","r", stdin);
    int n;
    scanf("%d",&n);

    multiset<int> s;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        s.insert(x);
    }

    int m;
    scanf("%d",&m);

    for (int i=0; i<m; i++) {
        int x;
        scanf("%d",&x);
        printf("%lu ", s.count(x));
    }

    printf("\n");

    return 0;
}