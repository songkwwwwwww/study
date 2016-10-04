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


const int MAX_N = 8;
const int MAX_M = 8;

bool is_prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

ll pow(ll a, ll n, ll mod){
    ll res = 1;
    while(n){
        if(n & 1) res = res * a % mod;
        a = a * a % mod;
        n /= 2;
    }
    return res;
}

int main(){
    freopen("4233.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int p, a;
    while(scanf("%d %d", &p, &a) == 2 && p != 0 && a != 0){
        if(is_prime(p)){
            printf("no\n");
        }
        else{ // 
            if(pow(a, p, p) == a) printf("yes\n");
            else printf("no\n");
        }
    }
}