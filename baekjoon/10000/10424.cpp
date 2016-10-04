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
첫째 줄에는 알고리즘을 수강하는 학생의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 
둘째 줄에는 알고리즘 기말고사의 성적대로 1등부터 N등까지 중간고사의 성적을 번호로 하여 한 줄로 주어진다.

출력
첫째 줄부터  중간고사 등수를 기준으로 1등부터 N등의 기말고사 성적 만족도를 한 줄씩 출력한다.
*/


const int MAX_N = 100000;
int N;

int main(){
    freopen("10424.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    vi result(N + 1);
    for(int i = 1; i <= N; i++){
        int n;
        scanf("%d", &n);
        result[n] = n - i;
    }
    for(int i = 1; i <= N; i++)
        printf("%d\n", result[i]);
}