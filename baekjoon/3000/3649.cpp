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


const int MAX_N = 1000000;
const int MAX_L = 100000000;
int X, N, L;
int len[MAX_N + 1];

bool solve(int n){
    int l = 0, r = N - 1, m;
    while(l <= r){
        m = (l + r) / 2;
        if(len[m] == n){
            return true;
        }
        else if(len[m] < n){
            l = m + 1;
        }
        else{ // len[m] > n
            r = m - 1;
        }
    }
    return false;
}

int main(){
    freopen("3649.txt", "r", stdin);
    //setbuf(stdout, NULL);
    while(scanf("%d", &X) == 1){
        X *= 10000000;
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d", &len[i]);
        }
        if(N)
            sort(len, len + N);
        bool flag = false;
        int a, b;
        for(int i = 0; i < N; i++){
            // 현재 막대와 다음 막대로 막을 수 있으면
            if(len[i] + len[i + 1] == X){
                a = len[i];
                b = len[i + 1];
                flag = true;
                break;
            }
            else if(solve(X - len[i])){
                a = len[i];
                b = X - len[i];
                flag = true;
                break;
            }
        }
        if(!flag)
            printf("danger\n");
        else
            printf("yes %d %d\n", a, b);
    } // end of while
}