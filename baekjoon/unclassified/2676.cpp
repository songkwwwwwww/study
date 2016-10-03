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
라스칼의 삼각형은 파스칼의 삼각형과 비슷하다.
라스칼의 삼각형에서 가장 윗 줄은 0번 줄이다. i번째 줄에는 i+1개의 숫자가 들어있고, 차례대로 0번부터 i번이다. 
R(i,j)는 i번 줄의 j번째 숫자이다.
R(n,m) = 0 (n<0 or m<0 or m>n)
각 줄의 첫번째와 마지막 숫자는 1이다.
R(n,0) = R(n,n) = 1
나머지 값을 채우는 방법은 (서쪽값 * 동쪽값 + 1) / 북쪽값 이다.
이것을 수식으로 표현해보면 R(n+1,m+1) = (R(n,m) * R(n,m+1) + 1) / R(n-1,m) 이다.
라스칼의 삼각형에서 R(n,m)을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T(1 <= T <= 1,000)이 주어진다. 
각 테스트 케이스는 2개의 숫자 n과 m으로 이루어져 있다. (0 <= m <= n <= 50,000)

출력
각 테스트 케이스에 대해서 한 줄에 하나씩 R(n,m)을 출력한다.
*/


const int MAX_N = 8;
const int MAX_M = 8;


int main(){
    freopen("2676.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%d\n", 1 + (n - m) * m);
    }
}