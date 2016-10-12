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
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 200000;
const int MAX_C = MAX_N;
const int MAX_X = 1000000000;

int N, C;
int x[MAX_N + 3];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

int main(){
    freopen("2110.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++)
        scanf("%d", &x[i]);
    
    sort(x, x + N);

    int l = 0, r = MAX_X, m, ans;
    while(l <= r){
        // 가장 인접한 두 공유기 사이의 거리 m
        m = (l + r) / 2;

        int cnt = 1;
        int last = 0;

        for(int i = 1; i < N && cnt <= C; i++){
            if(x[last] + m <= x[i]){ 
            // now, x[last] + m > x[i]
                last = i;
                cnt++;
            }
        }
        /*
        for(int i = 1; cnt <= C && i < N; i++)
            if(a[i] - last >= m){
                cnt++;
                last = a[i];
            }
        */
        if(cnt >= C){
            ans = m;
            l = m + 1;
        }
        else{ // cnt < C
            r = m - 1;
        }
    }
    printf("%d\n", ans);

}

/*
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;


int main(){
    freopen("2110.txt", "r", stdin);

    // N : 집의 개수, C : 공유기의 개수
    // 2 <= N <= 20,0000
    // 2 <= C <= N
    // x_i 집의 좌표의 범위 : 1<= x_i <= 10,0000,0000
    int N, C; 
    int a[200000];

    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    sort(a, a + N);    

 
    int l = 1, r = a[N-1] - a[0], m;
    while(l <= r){
        m = (l + r) / 2;
        int cnt = 1;
        int last = a[0];
        for(int i = 1; cnt <= C && i < N; i++)
            if(a[i] - last >= m){
                cnt++;
                last = a[i];
            }
                
        if(cnt < C)
            r = m - 1;
        else // cnt >= C
            l = m + 1;
    }
    printf("%d\n", l - 1);
}
*/