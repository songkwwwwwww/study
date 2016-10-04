#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <stack>
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

#include <map>
#include <utility> // std::pair

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*

*/

int a[5001];
int d[5001][5001];
int main(){
    freopen("1695.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    //vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int t = 2; t <= n; t++){
        for(int i = 1, j = t; j <= n; i++, j++){
            if(a[i] == a[j])
                d[i][j] = d[i+1][j-1];
            else // S[i] != S[j]
                d[i][j] = 1 + MIN(d[i+1][j], d[i][j-1]);
            }
    }
    printf("%d\n", d[1][n]);
   
}
