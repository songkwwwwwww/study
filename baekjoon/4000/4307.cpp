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
첫째 줄에 테스트 케이스의 개수가 주어진다. 
각 테스트 케이스의 첫째 줄에는 막대의 길이와 개미의 수 n이 주어진다. 
다음 n개 줄에는 숫자가 하나씩 주어지며, 이 숫자는 개미의 초기 위치를 나타낸다. 
개미의 위치는 1000000보다 작거나 같으며, 공백으로 구분되어져 있다.

출력
각 테스트 케이스에 대해서, 두 숫자를 출력한다. 
첫 번째 숫자는 개미가 모두 땅으로 떨어지는 가능한 시간 중 가장 빠른 시간, 
두 번째 숫자는 가장 늦은 시간이다.
*/



const int MAX_L = 1000000;

int N, L;


int main(){
    freopen("4307.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &L, &N);
        vi a(N); // location of ants
        int min_t = 0;
        int max_t = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", &a[i]);
            min_t = max(min_t, min(a[i], L - a[i]));
            max_t = max(max_t, max(a[i], L - a[i]));
        }
        printf("%d %d\n", min_t, max_t);
    }
}