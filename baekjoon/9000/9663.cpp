#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

int a[14][14];
int N; // 1 <= N < 15;
int ans = 0;
// can i put down queen there
bool check(int r, int c){
    for(int i = 0; i < r; i++){
        if(a[i][c])
            return false;
    }

    int x = r - 1;
    int y = c - 1;
    while(x >= 0 && y >= 0){
        if(a[x][y]) return false;
        x--;
        y--;
    }

    x = r - 1;
    y = c + 1;
    while(x >= 0 && y < N){
        if(a[x][y]) return false;
        x--;
        y++;
    }
    return true;
}

int go(int r){
    if(r == N) ans++;
    for(int c = 0; c < N; c++){
        a[r][c] = true;
        if(check(r, c)) go(r + 1);
        a[r][c] = false;
    }
}


int main(){
    freopen("9663.txt", "r", stdin);
    scanf("%d", &N);
    go(0);
    printf("%d\n", ans);
}