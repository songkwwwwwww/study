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
양의 정수 n이 주어졌을 때, n의 배수 중에서 0과 1로만 이루어진 m을 찾는 프로그램을 작성하시오. 
n은 200을 넘지 않고, m은 0보다 큰 양의 정수이며, 100자리를 넘지 않아야 한다.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 
각 줄에는 n (1 ≤ n ≤ 200)이 주어진다. 
입력의 마지막 줄에는 0이 주어진다.

출력
입력으로 주어지는 각각의 n마다 m을 출력한다. 
m의 길이는 100을 넘지 않으며, 가능한 경우가 여러가지라면 아무거나 출력한다.
*/


const int MAX_N = 200;
const int MAX_M = 100;
int N, M;

int main(){
    freopen("4994.txt", "r", stdin);
    //setbuf(stdout, NULL);
    while(scanf("%d", &N) && N != 0){
        ll ans;
        queue<long long> q;
        q.push(1);
        while(!q.empty()){
            ll here = q.front(); q.pop();
            if(here % N == 0){
                ans = here;
                break;
            }
            q.push(here * 10);
            q.push(here * 10 + 1);            
        }
        printf("%lld\n", ans);
    }
}