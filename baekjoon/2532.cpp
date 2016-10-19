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


const int MAX_N = 500000;
const int MAX_L = 1000000000;
const int MAX_R = 1000000000;
int N;

struct point{
    int n, l, r;
    bool operator < (const point& rhs)const{
        if(l == rhs.l){
            return r > rhs.r; 
        }
        else{
            return l < rhs.l;
        }
    }
};
point p[MAX_N + 3];


int main(){
    freopen("2532.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d %d", &p[i].n, &p[i].l, &p[i].r);
    sort(p, p + N);
    
    int n = 1;
    for(int i = 1; i < N; i++){
        if(!(p[i - 1].l == p[i].l && p[i - 1].r == p[i].r)){
            p[n] = p[i];
            n++;
        }
    }
    N = n;
    vi d(N + 1, INF);
    for(int i = N - 1; i >= 0; i--){
        *upper_bound(d.begin(), d.end(), p[i].r) = p[i].r;
    }
    int ans = find(d.begin(), d.end(), INF) - d.begin();
    printf("%d\n", ans);
}