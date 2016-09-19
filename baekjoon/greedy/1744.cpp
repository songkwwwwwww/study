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

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 10000;
int N;
int a[MAX_N + 1];
int d[MAX_N + 1];

bool cmp(int a, int b){
    return a > b ? true : false;
}

int solve(int n){
    if(n >= N) return 0;
    
    int& ret = d[n];
    if(ret != -1) return ret;

    ret = -INF;
    ret = max(ret, a[n] + solve(n + 1));
    if(n < N - 2)
        ret = max(ret, a[n] * a[n + 1] + solve(n + 2));
    return ret;    
}

int main(){
    freopen("1744.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    //sort(a, a + N, cmp);
    sort(a, a + N);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0));
}


/*
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    freopen("1744.txt", "r", stdin);
    int N, num; // N <= 10000
    scanf("%d", &N);

    vector<int> plus;
    plus.reserve(N/2);
    vector<int> minus;
    minus.reserve(N/2);

    int zero = 0;
    int one = 0;

    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        if(num == 0){
            zero++;
        }    
        else if(num == 1){
            one++;
        }
        else if(num > 0){
            plus.push_back(num);
        }
        else{
            minus.push_back(num); // num < 0
        }    
    }
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());

    if(plus.size() % 2 == 1) plus.push_back(1);
    
    if(minus.size() % 2 == 1){
        minus.push_back(zero > 0 ? 0 : 1);
    }
    
    int ans = one;
    for (int i=0; i<plus.size(); i+=2) {
        ans += plus[i] * plus[i+1];
    }
    for (int i=0; i<minus.size(); i+=2) {
        ans += minus[i] * minus[i+1];
    }
    printf("%d\n", ans);
    return 0;
}
*/