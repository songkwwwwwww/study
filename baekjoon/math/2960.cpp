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
//#include <unordered_map>

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

const int INF = 987654321;
const int MAX_V = 20000;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*

*/



int solve(int N, int K){
    vector<bool> is_prime(N + 1, true);
    int ans, count = 0;
    for(int i = 2; i <= N; i++){
        if(is_prime[i] == false) continue;
        for(int j = i ; j <= N; j += i){
            if(is_prime[j] == false) continue;

            is_prime[j] = false;
            count++;
            if(count == K) return j;
        }
    }
    return -1;
}
int main(){
    freopen("2960.txt", "r", stdin);
    int N, K;
    scanf("%d %d", &N, &K);
    printf("%d\n", solve(N, K));
}