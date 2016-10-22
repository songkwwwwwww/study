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


const int MAX_N = 100;


int main(){
    freopen("10163.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    vvi m(101, vi(101));
    for(int i = 1; i <= N; i++){
        int x, y, h, w;
        scanf("%d %d %d %d", &x, &y, &h, &w);
        for(int j = x; j < x + h; j++){
            for(int k = y; k < y + w; k++){
                m[j][k] = i;
            }
        }
    }
    
    vi ans(N + 1);
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            ans[m[i][j]]++;
        }
    }
    for(int i = 1; i<= N; i++){
        printf("%d\n", ans[i]);
    }
}