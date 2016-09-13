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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
입력
첫 번째 줄에는 석판의 크기 N(1≤N≤20)이 들어온다. 
다음 줄부터 N줄에 걸쳐서 석판의 상태가 입력으로 들어온다. 
여기서 1은 불순물을 의미하며, 2는 보석 결정체, 0은 불순물과 보석결정체가 존재하지 않는 곳을 의미한다. 
이 때, 보석 결정체의 수는 15개를 넘지 않으며, 각 줄에 주어지는 석판의 정보는 공백 하나로 구분한다.

출력
각각의 석판 안에 불순물이 없으면서 단 하나의 보석 결정체만이 있도록 주어진 석판을 나눌 때, 
모두 몇 가지의 경우가 존재하는지를 출력하시오. 
이 때 가능한 경우가 존재하지 않으면 -1을 출력한다.
*/

const int MAX_N = 20;
int N;
int a[MAX_N][MAX_N];

int main(){
    freopen("2339.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    

}