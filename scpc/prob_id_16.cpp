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


const int MAX_N = 100000;
int N;
ll a[MAX_N];
ll diff[MAX_N];

ll gcd(ll a, ll b){
    while(b > 0){
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    freopen("prob_id_16.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d", &N);
        ll ans = 0, prev = 0;
        bool zero = false;
        for(int n, i = 0; i < N; i++){
            scanf("%lld", &a[i]);
            diff[i] = a[i] - prev;
            if(diff[i] == 0)
                zero = true;
            prev = a[i];
        }

        if(zero){
            if(a[0] == a[N - 1])
                ans = 1;
        }
        else{
            ll g = diff[1];
            for(int i = 2; i < N; i++){
                g = gcd(g, diff[i]);
            }

            bool flag = false;
            for(ll i = 1; i * i <= g; i++){
                if(g % i == 0){
                    ans++;
                    if(i * i == g) 
                        flag = true;
                }
            }
            if(flag)
                ans = 2 * ans - 1;
            else
                ans = 2 * ans;
        }

        
        printf("Case #%d\n", tc);
        printf("%lld\n", ans);
    }
}