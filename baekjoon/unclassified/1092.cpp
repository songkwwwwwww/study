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

*/


const int MAX_N = 50;
const int MAX_M = 10000;

int main(){
    freopen("1092.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, M;
    
    scanf("%d", &N);
    vi crane(N); 
    for(int i = 0; i < N; i++)
        scanf("%d", &crane[i]);

    scanf("%d", &M);
    vi box(M);
    for(int i = 0; i < M; i++)
        scanf("%d", &box[i]);
    
    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());
    

    int ans = 0;
    while(true){
        bool empty = true, proc = false;
        int p = N - 1;
        for(int i = M - 1; i >= 0; i--){
            if(box[i] == 0) continue;
            empty = false;
            if(crane[p] >= box[i]){
                box[i] = 0;
                p--;
                proc = true;
                if(p == -1)
                    break;
            }
        }
        if(empty == true)
            break;
        else if(proc == false){
            ans = -1;
            break;
        }
        ans++;
    }
    printf("%d\n", ans);
}