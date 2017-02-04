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

int d[1 << MAX_N][MAX_K];


/*
inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}*/

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
    cin >> N;
    vector<string> num(N);
    vi num_mod(N);
    vi len(N);
    for(int i = 0; i < N; i++){
	cin >> num[i];
	len[i] = num[i].size();
    }
    cin >> K;

    for(int i = 0; i < N; i++){
	for(int j = 0; j < len[i]; j++){
	    num_mod[i] = num_mod[i] * 10 + (num[i][j] - '0');
	    num_mod[i] %= K;
	}
    }
    vi ten(51);
    ten[0] = 1;
    for(int i = 1; i <= 50; i++){
	ten[i] = ten[i - 1] * 10;
	ten[i] %= K;
    }

    d[0][0] = 1;
    for(int i = 0; i < (1 << N); i++){
	for(int j = 0; j < K; j++){
	    for(int k = 0; k < N; k++){
		if((i & (1 << k)) == 0){
		    int next = j * ten[len[k]];
		    next %= K;
		    next += num_mod[k];
		    next %= K;
		    d[i | (1 << k)][next] += d[i][j];
		}
	    }
	}
    }
    ll a = d[(1 << N) - 1][0];
    ll b = 1;
    // 모든 경우의 수, 즉 N! 을 계산
    for(int i = 2; i <= N; i++){
	b *= (ll)i;
    }
    ll g = gcd(a, b);
    cout << a / g << "/" << b / g << endl;
}
