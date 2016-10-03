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
양의 정수 N이 주어졌을 때, 이 수를 소인수분해 한 결과를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 수가 주어진다. 각 테스트 케이스마다 양의 정수 N (2 ≤ N ≤ 100,000)이 주어진다.

출력
각 테스트 케이스마다 각 인수와 그 인수가 곱해진 횟수를 한 줄씩 출력한다. 출력 순서는 인수가 증가하는 순으로 한다.
*/


const int MAX_N = 100000;

map<int, int> solve(int n){
    map<int, int> m;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            m[i]++;
            n /= i;
        }
    }
    if(n != 1) m[n] = 1;
    return m;
}

int main(){
    freopen("2312.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        int N;
        scanf("%d", &N);
        map<int, int> m = solve(N);
        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
            printf("%d %d\n", it->first, it->second);
        }
    }
}