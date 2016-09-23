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

const int MAX_LEN = 2000000000;

const int MAX_N = 100000;
const int MAX_C = 100000;

int N, C;
vi barn;

bool check(int m){
    int last = 0;
    for(int i = 1; i < C; i++){
        int cur = last + 1;
        while(cur < N && barn[cur] - barn[last] < m)
            cur++;
        if(cur == N) return false;
        last = cur;
    }
    return true;
}

int main(){
    freopen("2456.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &C);
    barn = vi(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &barn[i]);
    sort(barn.begin(), barn.end());

    int l = 0, r = MAX_LEN, m, ans;
    while(r - l > 1){
        m = (l + r) / 2;
        if(check(m)) l = m;
        else r = m;
    }
    printf("%d\n", l);
}