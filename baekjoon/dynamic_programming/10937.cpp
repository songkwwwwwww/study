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


#define current (1 << n) 
#define right (1 << (n-1)) 
#define down (1) 
#define MOD (1 << (n+1))


int p[4][4] = {100,70,40,0,70,50,30,0,40,30,20,0,0,0,0,0}; 
int n, m[12][12], d[12][12][1<<13];


//    현재 a, b 열을 탐색하는 상태에서
//    bit_state의 값으로 다음 n개의 칸이 채워져 있을 때까지의 최대 이득

int solve(int x, int y, int s){
    // base case
    if(x == n) return 0;
    if(y == n) return solve(x + 1, 0, s);
    
    int& ret = d[x][y][s];
    if(ret != -1) return ret;
    ret = 0;
    // (a, b) 위치가 체크되어 있지 않다면
    if( !(s & current) ){
        // 오른 쪽 위치를 선택할 수 있는지 확인하고 가능하면 놓는다.
        if( y + 1 < n && !(s & right) )
            ret = max(ret, solve(x, y + 2, (s << 2) % MOD) + p[m[x][y]][m[x][y + 1]] );
        
        // 아래 쪽 위치를 선택할 수 있는지 확인하고 가능하면 놓는다.
        if( x + 1 < n && !(s & down))
            ret = max(ret, solve(x, y + 1, ((s|down)<<1) % MOD) + p[m[x][y]][m[x + 1][y]]);
        
        // 오른 쪽과 아래 쪽 어디에도 놓지 않고 건너 뛰는 경우
        ret = max(ret, solve(x, y + 1, (s << 1) % MOD));
    }
    // (a, b) 위치가 체크되어 있다면 놓을 수 없다. 건너뛴다.
    else{
        ret = max(ret, solve(x, y + 1, (s << 1) % MOD));        
    }
    return ret;
}

int main(){
    freopen("10937.txt", "r", stdin);
    scanf("%d", &n);
    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %1c", &c);
            m[i][j] = (c == 'F' ? 3 : c -'A');  
        }
    }
    
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, 0, 0));
}