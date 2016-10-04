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

int main(){
    freopen("2565.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    vector<pii> v; v.reserve(N);
    for(int a, b, i = 0; i < N; i++){
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    vi a(N);
    for(int i = 0; i < N; i++){
        a[i] = v[i].second;
    }
    vi d(N, INF);
    for(int i = 0; i < N; i++){
        *lower_bound(d.begin(), d.end(), a[i]) = a[i];
    }
    printf("%d\n", N - (int)(lower_bound(d.begin(), d.end(), INF) - d.begin() ) );
}