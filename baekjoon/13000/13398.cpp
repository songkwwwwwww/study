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


const int MAX_N = 100000;
int N;
int a[MAX_N + 3];
int dl[MAX_N + 3];
int dr[MAX_N + 3];

int main(){
    freopen("13398.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    int ans = -0x7fffffff;        
    for(int i = 1; i <= N; i++){
        dl[i] = max(dl[i - 1] + a[i], a[i]);
        ans = max(ans, dl[i]);
    }
    for(int i = N; i >= 1; i--){
        dr[i] = max(dr[i + 1] + a[i], a[i]);
    }
    for(int i = 1; i <= N; i++){
        ans = max(ans, dl[i - 1] + dr[i + 1]);
    }
    printf("%d\n", ans);
}