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

const int MAX_N = 100000;

int N;
ll h[MAX_N + 1];
//ll psum[MAX_N + 1];

ll solve(int left, int right){
    // base case
    if(left == right) return h[left] * h[left];
    
    ll mid = (left + right) / 2;
    ll ans = max( solve(left, mid), solve(mid + 1, right) );

    ll low = mid, high = mid + 1;

    ll min_height = min(h[low], h[high]);
    ll sum = h[low] + h[high];
    
    ans = max(ans, min_height * sum);

    while(left < low || high < right){
        if(high < right && (low == left || h[low - 1] < h[high + 1]) ){
            high++;
            min_height = min(min_height, h[high]);
            sum += h[high];
        }
        else{
            low--;
            min_height = min(min_height, h[low]);
            sum += h[low];
        }
        ans = max(ans, min_height * sum );
    }
    return ans;
}

int main(){
    freopen("2104.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld", &h[i]);
        //psum[i + 1] += h[i] + psum[i];
    }
    printf("%lld\n", solve(0, N - 1));
}