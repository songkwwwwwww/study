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
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

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


const int MAX_N = 8;
const int MAX_M = 8;


int main(){
    freopen("11566.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N, M;
    scanf("%d", &N);
    vi a; a.resize(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    scanf("%d", &M);
    vi b; b.resize(M);
    for(int i = 0; i < M; i++)
        scanf("%d", &b[i]);
    
    int depth = 0;
    vi ans; ans.reserve( (M - N) / (N - 1) + 1);
    while((N - 1) * depth + N <= M){
        for(int i = 0; i + (N - 1) * depth + N <= M; i++){
            bool flag = true;
            for(int j = 0, k = 0; j < N; j++, k++){
                if(a[j] != b[i + k]){
                    flag = false;
                    break;
                }
                k += depth;
            }
            if(flag){
                ans.push_back(depth);
                break;
            }
        }
        depth++;
    }
    if(ans.size() == 0){
        printf("-1\n");
    }
    else{
        printf("%d %d\n", ans[0], ans[ans.size() - 1]);
    }
}   