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

const int MOD = 1000000007;
const int MAX_N = 100;

int cache[MAX_N + 1];

/*
    2 * n 크기의 타일을 2 * 1 혹은 1 * 2 타일로 매꾸는 방법의 수를 반환한다.
*/
int tiling(int n){
    // base case
    if(n <= 1) return 1;
    int& ret = cache[n];
    if(ret != -1) return ret;
    return ret = (tiling(n - 1) + tiling(n - 2)) % MOD;    
}

//int asym_cache[MAX_N + 1];
int asymtiling(int n){
    if(n % 2 == 1){ // n이 홀수
        return (tiling(n) - tiling(n/2) + MOD) % MOD;
    }
    else{ // n이 짝수
        int total_tiling = tiling(n);
        total_tiling = (total_tiling - tiling(n / 2) + MOD) % MOD;
        total_tiling = (total_tiling - tiling(n / 2 - 1) + MOD) % MOD;
        return total_tiling;
    }
}

int main(){
    freopen("ASYMTILING.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    memset(cache, -1, sizeof(cache));
    for(int tc = 1; tc <= TC; tc++){
        int n; // ( 1 <= n <= 100)
        
        scanf("%d", &n);
        cout << asymtiling(n) << endl;
    }
}