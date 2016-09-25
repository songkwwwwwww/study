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
문제
n(1≤n≤50,000)개의 점들이 있을 때, 최대 L1-metric 거리를 찾으라.

두 점의 좌표가 (a, b), (c, d)일 때, 이 두 점의 L1-metric 거리는 |a-c|+|b-d|이다.

입력
첫째 줄에 n이 주어진다. 다음 n개의 줄에는 각 점의 x, y좌표가 주어진다. 
각 좌표의 범위는 -1,000,000이상 1,000,000이하이다.

출력
  첫째 줄에 최대 거리를 출력한다.
*/


const int MAX_N = 50000;

struct point{
    int x, y;
    point(){}
    point(int nx, int ny):x(nx), y(ny) {}
};

int main(){
    freopen("2381.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    // |c - a| + |d - b|
    // if a <= c and b <= d, then (c - a) + (d - b) = (c + d) - (a + b)
    // if a <= c and b > d,  then (c - a) - (d - b) = (c - d) - (a - b)
    vector<point> v;
    v.reserve(N);
    int max1 = -INF, max2 = -INF
        , min1 = INF, min2 = INF;

    for(int x, y, i = 0; i < N; i++){
        scanf("%d %d", &x, &y);
        max1 = max(max1, x + y);
        min1 = min(min1, x + y);

        max2 = max(max2, x - y);
        min2 = min(min2, x - y);
    }
    printf("%d\n", max1 - min1 > max2 - min2 ? max1 - min1 : max2 - min2);
}