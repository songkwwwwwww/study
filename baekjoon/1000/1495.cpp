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
첫째 줄에 곡의 개수 N, 시작 볼륨 S, M이 주어진다. 
(1 ≤ N ≤ 100, 1 ≤ M ≤ 1000, 0 ≤ S ≤ M) 

둘째 줄에는 각 곡이 시작하기 전에 줄 수 있는 볼륨의 차이가 주어진다. 
이 값은 1보다 크거나 같고, M보다 작거나 같다.

출력
첫째 줄에 가능한 마지막 곡의 볼륨 중 최대값을 출력한다. 
만약 마지막 곡을 연주할 수 없다면 (중간에 볼륨 조절을 할 수 없다면) -1을 출력한다.
*/


const int MAX_N = 100;
const int MAX_M = 1000;
int N, S, M;
int v[MAX_N + 1];
int d[MAX_M + 1][MAX_N + 1];


int solve(int volume, int index){
    if(volume < 0 || volume > M) return -1;
    if(index == N) return volume;

    int& ret = d[volume][index];
    if(ret != -2) return ret;

    return ret = max(solve(volume + v[index], index + 1), solve(volume - v[index], index + 1));
}

int main(){
    freopen("1495.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d %d", &N, &S, &M);
    
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i]);
    
    //memset(d, -1, sizeof(d));
    for (int i = 0; i < 1001; i++){
        for (int j = 0; j < 101; j++){
            d[i][j] = -2; 
        }
    }
    printf("%d\n", solve(S, 0));
    return 0;
}