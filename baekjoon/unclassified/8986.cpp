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
//#include <unordered_map> // c++11

#include <utility> // std::pair

#include <functional> // greater, less
#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

typedef pair<int, int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
입력
입력의 첫 줄은 전봇대의 수 N (1 ≤ N ≤ 100,000)이 주어진다. 
두 번째 줄에는 전봇대의 위치를 나타내는 N개의 서로 다른 x-좌표 xi(i = 0, ..., N-1)가 빈칸을 사이에 두고 오름차순으로 주어진다.
 xi는 정수이고, 1 ≤ xi ≤ 10 0000 0000 이다.

출력
출력은 단 한 줄이며, 모든 이웃한 전봇대들의 거리가 같도록 전봇대들의 이동거리 합의 최솟값을 출력한다.
*/


const int MAX_N = 100000;
int N;
int a[MAX_N];

int main(){
    freopen("8986.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    
    ll l = 0, r = 0x7fffffff, m;
    ll ans= 0x7fffffffffffffff;
    while(l <= r){
        m = (l + r) / 2;
        
     
        ll x1 = 0, x2 = 0;
        for(int i = 0; i < N; i++){
            x1 += abs(a[i] - m * i);
            x2 += abs(a[i] - (m + 1) * i);
        }
        ans = min(ans, min(x1, x2));
        if(x1 < x2){
            r = m - 1;
        }
        else{
            l = m + 2;
        }
    }
    printf("%lld\n", ans);
}

/*
koosaga님 코드

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long lint;
 
lint d[100005];
int n;
lint trial(lint piv){
    lint res = 0;
    for (int i=0; i<n; i++) {
        res += max(d[i] - piv * i, piv * i - d[i]);
    }
    return res;
}
 
int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%lld",&d[i]);
    }
    int s = 0, e = 1e9;
    while (s != e) {
        int m = (s+e)>>1;
        if(trial(m) > trial(m+1)) s = m+1;
        else e = m;
    }
    printf("%lld",trial(s));
}

*/