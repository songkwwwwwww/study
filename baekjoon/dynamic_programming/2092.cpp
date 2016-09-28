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
1부터 T(1≤T≤200)까지의 범위에 있는 수들이 총 A개 있다. 
이들 중 K개를 골라서 집합을 만들 때, 가능한 집합의 개수를 세려 한다. 
단, K의 범위는 1≤S≤K≤B≤A로 한다. 즉, 두 정수 S, B를 입력받아서 K=S일 경우, …, K=B일 경우의 집합의 개수를 모두 더하려고 한다.

예를 들어 T=3, 수들이 1, 1, 2, 2, 3인 경우를 생각해 보면, 각기 다음의 경우가 있다.
우리가 일반적으로 이야기하는 집합은 같은 원소를 허용하지 않는다. 
이 문제에서의 집합은 같은 원소가 없다는 사실 보다는, 
집합의 각 원소들의 순서를 바꾸어도 같은 집합이라는 사실에 주목하여 풀도록 한다.
즉, {1, 1, 2}는 하나의 집합이고, {1, 2, 1}은 이와 같은 집합이다.

입력
첫째 줄에 네 정수 T, A, S, B가 주어진다. 다음 A개의 줄에는 차례로 각각의 수들이 주어진다. (A<=4000)

출력
첫째 줄에 답을 1,000,000으로 나눈 나머지를 출력한다.
*/


const int MAX_A = 4000;
const int MAX_T = 200;

const int MOD = 1000000;
int T, A, S, B;
int check_num[MAX_T + 1];

int d[MAX_A + 1][MAX_T + 1];
/*
    선택할 수 있는 원소의 수가 count개이고
    현재 수가 num일 때 
    집합의 개수를 반환
*/
int solve(int count, int num){
    // base case
    if(count == 0) return 1;
    else if(num == 0) return 0;

    int& ret = d[count][num];
    if(ret != -1) return ret;

    ret = 0;

    // 현재 num 은 그냥 건너뛰는 경우.
    ret = (ret + solve(count, num - 1)) % MOD;

    // 현재 num 을 사용할 경우
    for(int i = 1; i <= min(check_num[num], count); i++){
        ret = (ret + solve(count - i, num - 1)) % MOD;
    }

    return ret;
}

int main(){
    freopen("2092.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d %d %d", &T, &A, &S, &B);
    for(int i = 0; i < A; i++){
        int num;
        scanf("%d", &num);
        check_num[num]++;
    }
    memset(d, -1, sizeof(d));
    int ans = 0;
    for(int i = min(S, B); i <= max(S, B); i++){
        ans += solve(i, T);
        ans %= MOD;
    }
    printf("%d\n", ans);
}