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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
입력
첫째 줄에 N(1 ≤ N ≤ 3^7, N은 3^k 꼴)이 주어진다. 
다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

출력
첫째 줄에 -1로만 채워진 종이의 개수를, 
둘째 줄에 0으로만 채워진 종이의 개수를, 
셋째 줄에 1로만 채워진 종이의 개수를 출력한다.
*/

int N;
int a[3000][3000];
// -1, 0, 1
int cnt[3];

inline bool same(int x, int y, int n){
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(a[x][y] != a[i][j])
                return false;
        }
    }
    return true;
}

int solve(int x, int y, int n){
    if(same(x, y, n)){
        cnt[a[x][y] + 1]++;
    }
    else{
        int m = n / 3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                solve(x + i * m, y + j * m, m);
            }
        }
    }
}

int main(){
    freopen("1780.txt", "r", stdin);
    scanf("%d\n", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    
    solve(0, 0, N);
    for(int i = 0; i < 3; i++)
        printf("%d\n", cnt[i]);
}

/*
#include <stdio.h>

using namespace std;

int N; // 1 <= N <= 3^7, N=3^k

// index 0 = # of -1 
// index 1 = # of 0 
// index 2 = # of 1
int cnt[3];

int a[3000][3000];

bool same(int x, int y, int n){
    int val = a[x][y];
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(val != a[i][j]) return false;
        }
    }
    return true;
}

int solve(int x, int y, int n){
    if(same(x, y, n)){
        cnt[a[x][y] + 1]++;
        return 0;
    }

    int m = n/3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            solve(x + i*m, y + j*m, m);
}

int main(){
    freopen("1780.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    solve(0, 0, N);
    printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);
    return 0;
}
*/