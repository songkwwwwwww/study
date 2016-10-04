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
입력의 첫째 줄에는 회원의 수가 있다. 단, 회원의 수는 50명을 넘지 않는다.
 둘째 줄 이후로는 한 줄에 두 개의 회원번호가 있는데, 이것은 두 회원이 서로 친구임을 나타낸다. 
 회원번호는 1부터 회원의 수만큼 붙어 있다. 마지막 줄에는 -1이 두 개 들어있다.

출력
첫째 줄에는 회장 후보의 점수와 후보의 수를 출력하고, 두 번째 줄에는 회장 후보를 오름차순으로 모두 출력한다.
*/


const int MAX_N = 50;


int main(){
    freopen("2660.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    vvi adj(N, vi(N, INF));
    while(true){
        int u, v;
        scanf("%d %d", &u, &v);
        if(u == -1 && v == -1)
            break;
        adj[v - 1][u - 1] = adj[u - 1][v - 1] = 1;
    }
    for(int i = 0; i < N; i++) adj[i][i] = 0;

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    vi score(N);
    int min_val = INF, count = 0;;
    for(int i = 0; i < N; i++){
        int max_val = -INF;
        for(int j = 0; j < N; j++){
            max_val = max(max_val, adj[i][j]);
        }
        if(min_val > max_val){
            min_val = max_val;
            count = 1;
        }
        else if(min_val == max_val)
            count++;
        score[i] = max_val;
    }
    
    printf("%d %d\n", min_val, count);
    for(int i = 0; i < N; i++){
        if(score[i] == min_val)
            printf("%d ", i + 1);
    }
    printf("\n");
}