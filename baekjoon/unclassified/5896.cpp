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
농부 존은 새 소들이 필요하다! 그래서 농부 존은 소 시장에 가서 새 소들을 사려고 한다.

농부 존은 돈이 많이 없기 때문에 소들을 최대한 효율적으로 사야 한다. 그래서 농부 존은 M원과 K개의 소 쿠폰을 가지고 소 시장에 나온 N마리의 소들을 최대한 많이 사려고 한다.

소 쿠폰은 소 한 마리당 한 번만 쓸 수 있고, 쓰고 나면 사라진다. i번째 소는 Pi원이고, 쿠폰을 썼을 때는 Ci원이 될 때, 농부 존이 최대로 살 수 있는 소의 마릿수를 출력하라.

입력
첫 번째 줄에 소 시장에 나온 소들의 마릿수 N(1 ≤ N ≤ 50,000), 농부 존이 가지고 있는 쿠폰의 개수 K(1 ≤ K ≤ N), 농부 존이 가지고 있는 돈 M(1 ≤ M ≤ 1014)이 주어진다.

다음 줄부터 Pi (1 ≤ Pi ≤ 109), Ci (1 ≤ Ci ≤ Pi)가 주어진다.

출력
농부 존이 최대로 살 수 있는 소 마릿수를 출력하라.
*/


const int MAX_N = 8;
const int MAX_M = 8;

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

int main(){
    freopen("5896.txt", "r", stdin);
    //setbuf(stdout, NULL);

}