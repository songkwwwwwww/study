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
 determine M, the minimum number of machine operations required to get all the cows facing forward using that value of K.

입력
Line 1: A single integer: N
Lines 2..N+1: Line i+1 contains a single character, F or B, indicating whether cow i is facing forward or backward.
 

출력
Line 1: Two space-separated integers: K and M
*/


const int MAX_N = 5000;
const int MAX_K = 5000;
int N;
vi dir;
vi f;

int calc(int K){
    int res = 0, sum = 0;
    f = vi(N);

    for(int i = 0; i <= N - K; i++){
        // dir[i] + sum이 홀수이면
        // 뒤집어야 한다.
        if( (dir[i] + sum) & 1 ){
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if(i - K + 1 >= 0){
            sum -= f[i - K + 1];
        }
    }

    // 나머지 소들을 확인한다.
    // 나머지 소들은 K보다 작으므로, 이 소들에 대해서는 뒤집을 수 없다
    for(int i = N - K + 1; i < N; i++){
        if( (dir[i] + sum) & 1 ){
            return -1;
        }
        if(i - K + 1 >= 0){
            sum -= f[i - K + 1];
        }
    }
    return res;
}

int solve(){
    int K = 1, M = N;
    for(int k = 1; k <= N; k++){
        int m = calc(k);
        if(m >= 0 && M > m ){
            K = k;
            M = m;
        }
    }
    printf("%d %d\n", K, M);
}

int main(){
    freopen("6233.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    dir = vi(N);
    for(int i = 0; i < N; i++){
        char c;
        scanf(" %c", &c);
        if(c == 'F')
            dir[i] = 0;
        else
            dir[i] = 1;
    }
    solve();
}