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
첫째 게임을 먼저 시작할 플레이어의 번호가 입력된다. 플레이어의 번호는 1 또는 2이다.

다음 9개의 줄에 게임이 끝날 때까지 번갈아가며 어느 위치에 그렸는지 좌표가 입력된다. 
좌표는 가로 행, 세로 열의 순으로 입력된다. 가장 왼쪽 위는 (1, 1), 가장 오른쪽 아래는 (3, 3)이다.

이미 입력된 좌표가 주어지는 경우는 없으며, 항상 게임이 끝나는 입력만 주어진다.

출력
승자가 결정되는 즉시 이긴 플레이어의 번호를 출력한다. 플레이어의 번호는 1 또는 2이다. 무승부라면 0을 출력한다.
*/


const int MAX_N = 8;
const int MAX_M = 8;


int main(){
    freopen("12759.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int n;
    scanf("%d", &n);

    int x, y, turn = 0;
    vvi map(3, vi(3));
    int p[2] = {1, -1};
    int winner = 2;
    
    while(scanf("%d %d", &x, &y) == 2){
        x--; y--;
        map[x][y] = p[turn];

        // check row
        int sum = 0;
        for(int i = 0; i < 3; i++)
            sum += map[x][i];
        if(sum == p[turn] * 3){
            winner = turn;
            break;
        }

        // check col
        sum = 0;
        for(int i = 0; i < 3; i++)
            sum += map[i][y];
        if(sum == p[turn] * 3){
            winner = turn;
            break;
        }

        // checl dig /
        sum = 0;
        if(x + y == 2 && (map[2][0] + map[1][1] + map[0][2] == (p[turn] * 3) ) ){
            winner = turn;
            break;
        }

        // checl dig \ .
        sum = 0;
        if(x == y && (map[0][0] + map[1][1] + map[2][2] == (p[turn] * 3) ) ){
            winner = turn;                
            break;
        }
        turn = turn ^ 1;
    }
    if(winner == 2){
        printf("0\n");
    }
    else{
        printf("%d\n", n == 1 ? winner + 1 : 2 - winner);
    }
}