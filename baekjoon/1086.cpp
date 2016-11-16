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


const int MAX_N = 15;
const int MAX_K = 100;
int N, K;
int a[MAX_N + 1];
int len[MAX_N + 1];
int d[1 << MAX_N][MAX_K + 1];
int ten[50 + 1];
// 
int solve(int state, int r){
    // base case
    if( state == ((1 << N) - 1) ){
        if(r == 0) return 1;
        else return 0;
    }

    int& ret = d[state][r];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < N; i++){
        if( !(state & (1 << i)) ){
            //int n_r = (r * ten[len[i]] + a[i]) % K;
            int n_r = r * ten[len[i]];
            n_r %= K;
            n_r += a[i];
            n_r %= K;
            
            ret += solve( state | (1 << i), n_r);
        }
    }
    return ret;
}

ll gcd(ll a, ll b){
    while(b){
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    freopen("1086.txt", "r", stdin);
    //setbuf(stdout, NULL);    
    scanf("%d", &N);
    vector<string> num(N);
    for(int i = 0; i < N; i++){
        cin >> num[i];
        len[i] = num[i].size();
    }
    scanf("%d", &K);
    for(int i = 0; i < N; i++){
        a[i] = 0;
        for(int j = 0; j < num[i].size(); j++){
            a[i] = a[i] * 10 + (num[i][j] - '0');
            a[i] %= K;
        }
    }
    ten[0] = 1;
    for(int i = 1; i <= 50; i++){
        ten[i] = ten[i - 1] * 10;
        ten[i] %= K;
    }
    memset(d, -1, sizeof(d));
    ll a = solve(0, 0);
    ll b = 1;
    for(int i = 2; i <= N; i++){
        b = b * i;
    } 
    ll g = gcd(a, b);
    printf("%lld/%lld\n", a / g, b / g);
}