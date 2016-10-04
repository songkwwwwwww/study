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

*/


const int MAX_N = 100;
const int MAX_K = 100000;

int main(){
    freopen("2014.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int K, N;
    scanf("%d %d", &K, &N);
    vi a; a.reserve(K);
    queue<ll> q[K];
    for(int n, i = 0; i < K; i++){
        scanf("%d", &n);
        a.push_back(n);
        q[i].push(n);
    }

    int ans, count = 0;
    while(true){
        ll x = 0x7fffffff;
        int index = 0;
        for(int i = 0; i < K; i++){
            if(x > q[i].front()){
                index = i;
                x = q[i].front();
            }
        }
        if(++count == N){
            ans = x;
            break;
        }
        q[index].pop();
        for(int i = index; i < K; i++){
            q[i].push(a[i] * x);
        }
    }
    printf("%d\n", ans);
}