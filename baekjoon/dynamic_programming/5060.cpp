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
입력
첫째 줄에 테스트 케이스의 개수 t가 주어진다. (1 ≤ t ≤ 50)

각 테스트 케이스는 두 줄로 이루어져 있다. 
첫째 줄에는 집의 수 h와 저장할 수 있는 집 위치의 수 c가 주어진다. (2 ≤ h ≤ 200, 2 ≤ c ≤ h) 
둘째 줄에는 각각의 집의 위치가 주어진다. 위치는 구간 [0, 1000000]에 포함된다. 

출력
각 테스트 케이스에 대해서, h개의 집 중 오차의 평균이 최소가 되도록 c개의 집의 위치를 저장했을 때,
 그 오차의 평균을 출력한다. 출력은 소수점 넷째자리까지 하며, 오차는 ±0.001까지 허용한다.
*/


const int MAX_H = 200;
const int MAX_C = 200;
int H, C; // 집의 수 H, 저장할 수 있는 집의 수 C
int x[MAX_H];
double d[MAX_H][MAX_C];

/*
번지가 i인 집의 위치 xi와 j인 집의 위치 xj를 저장했고, 그 사이의 집은 저장하지 않았을 때, 
번지가 k (i < k < j)인 집의 위치를 선형 보간법으로 계산하면 xi + (xj-xi) * (k-i)/(j-i)가 된다.
*/
inline double calc_interpolate(int i, int k, int j){
    return x[i] + 1.0 * (x[j] - x[i]) * (k - i)/(j - i);
}

/*
    현재까지 saved의 집을 저장했고
    이제 pos번 째 집부터 저장 여부를 결정해야할 때
    나올수 있는 가장 작은 위치 오차의 합
*/
double solve(int index, saved){
    
}


int main(){
    freopen("5060.txt", "r", stdin);
    //setbuf(stdout, NULL);

}