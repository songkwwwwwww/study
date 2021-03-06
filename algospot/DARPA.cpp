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


const int MAX_N = 100;
const int MAX_M = 200;
int N, M;
double locations[MAX_M];

// m 간격으로 N개 이상 설치 가능한가?
bool check(double m){
    double last = -1;
    int installed = 0;
    for(int i = 0; i < M; i++){
        if(last <= locations[i]){
            installed++;
            last = locations[i] + m;
        }
    }
    return installed >= N;
}

int main(){
    freopen("DARPA.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        for(int i = 0; i < M; i++)
            scanf("%lf", &locations[i]);
        
        double l = 0, r = 240, m;
        for(int i = 0; i < 100; i++){
            m = (l + r) / 2.0;
            if(check(m))
                l = m;
            else
                r = m;
        }
        printf("%.2lf\n", l);
    }
}