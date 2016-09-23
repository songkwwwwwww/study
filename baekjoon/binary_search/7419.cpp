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

typedef vector<double> vd; 

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 10000;
const int MAX_K = 10000;

int N, K;
vd len;

bool check(double m){
    int count = 0;
    for(int i = 0; i < N; i++){
        count += (int)(len[i] / m);
    }
    return count >= K;
}

int main(){
    freopen("7419.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &K);
    len = vd(N);
    for(int i = 0; i < N; i++){
        scanf("%lf", &len[i]);
    }
    double r = 100000, l = 0, m;
    while(abs(r - l) > 1e-6){
    //for(int i = 0; i < 100; i++){
        m = (l + r) / 2.0;
        if(check(m)){
            l = m;
        }
        else{
            r = m;
        }
    }
    //printf("%.2f\n", floor(r * 100)/100);
    printf("%.2f\n", l);
}