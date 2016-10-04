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


const int MAX_N = 100000;
const int MAX_M = 100000;

int main(){
    freopen("7571.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, M;
    scanf("%d %d", &N, &M);
    vi px, py;
    px.reserve(M);
    py.reserve(M);
    for(int x, y, i = 0; i < M; i++){
        scanf("%d %d", &x, &y);
        px.push_back(x);
        py.push_back(y);
    }
    sort(px.begin(), px.end());
    sort(py.begin(), py.end());
    int m_x = px[M / 2];
    int m_y = py[M / 2];
    int sum = 0;
    for(int i = 0; i < M; i++){
        sum += ( abs(px[i] - m_x) + abs(py[i] - m_y) );
    }
    printf("%d\n", sum);
}