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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
첫째 줄에 N(1≤N≤1,500)이 주어진다. 
다음 N개의 줄에는 각 줄마다 N개의 수가 주어진다. 
주어진 수는 표의 조건을 만족한다. 
즉, 모든 수는 자신의 한 칸 위에 있는 수보다는 크다.

출력
첫째 줄에 N번째 큰 수를 출력한다.
*/

int N;

int main(){
    freopen("2075.txt", "r", stdin);
    scanf("%d", &N);
}