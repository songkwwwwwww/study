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
10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 
이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N (10 < N < 100,000)과 S (0 < S < 100,000,000)가 주어진다. 
둘째 줄에는 수열이 주어진다. 
수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.

출력
첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 
만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.
*/


const int MAX_N = 100000;
const int MAX_S = 100000000;

int main(){
    freopen("1806.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, S;
    scanf("%d %d", &N, &S);
    vi a(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    int sum = 0, s = 0, e = 0, res = INF;
    while(true){
        while(e < N && sum < S){
            sum += a[e++];
        }
        if(sum < S)
            break;

        res = min(res, e - s);
        sum -= a[s++];
    }
    if(res > N)
        res = 0;
    
    printf("%d\n", res);
}