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


const int MAX_N = 1000;

struct d{
    int g, s, b;
};


int main(){
    freopen("8979.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, K;
    scanf("%d %d", &N, &K);
    vector<d> v; v.reserve(N);
    for(int index, g, s, b, i = 0; i < N; i++){
        scanf("%d %d %d %d", &index, &g, &s, &b);
        v.push_back((d){g, s, b});
    }
    K--;
    int ans = 1;
    for(int i = 0; i < N; i++){
        if(i == K) continue;
        
        if(v[i].g > v[K].g || ( v[i].g == v[K].g && v[i].s > v[K].s ) 
            || (v[i].g == v[K].g && v[i].s == v[K].s && v[i].b > v[K].b)){
            
            ans++;
        }
    }
    printf("%d\n", ans);
}