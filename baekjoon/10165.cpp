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


const int MAX_N = 1000000000;
const int MAX_M = 500000;
int N, M;

struct bus{
    int s, e, idx;
    bool operator < (const bus& rhs) const{
        if(s == rhs.s)
            return e > rhs.e;
        else
            return s < rhs.s;
    }
};

int main(){
    freopen("10165.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    vector<bus> v; v.reserve(M);
    for(int a, b, i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        if(a > b) swap(a, b);
        v.push_back((bus){a, b, i + 1});
    }
    sort(v.begin(), v.end());
    vb flag(M, true);
    vb ans(M + 1, true);
    for(int i = 0; i < M; i++){
        if(flag[i]){
            for(int j = i + 1; j < M; j++){
                if(v[i].s <= v[j].s && v[j].e <= v[i].e){
                    flag[j] = false;
                    ans[ v[j].idx ] = false;
                }
            }
        }
    }
    for(int i = 1; i <= M; i++){
        if(ans[i])
            printf("%d ", i);
    }
    printf("\n");
}