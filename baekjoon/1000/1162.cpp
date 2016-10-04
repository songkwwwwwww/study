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

const int INF = 987654321;
const int MAX_V = 20000;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
첫 줄에는 도시의 수 N(1 ≤ N ≤ 10,000)과 도로의 수 M(1 ≤ M ≤ 50,000)과 포장할 도로의 수 K(1 ≤ K ≤ 20)가 
공백으로 구분되어 주어진다. M개의 줄에 대해 도로를 연결짓는 두 도시와 도로를 통과하는데 걸리는 시간이 주어진다. 
도로들은 양방향 도로이다.

출력
첫 줄에 K개 이하의 도로를 포장하여 얻을 수 있는 최소 시간을 출력한다.
*/

int V, E, K;

int main(){
    freopen("1162.txt", "r", stdin);

}