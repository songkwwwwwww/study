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


const int MAX_N = 30000;


int main(){
    freopen("6168.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    vi a(N + 1);
    // [1, i] 까지 숫자 2의 개수
    vi check_two(N + 3);
    // [i, N] 까지 숫자 1의 개수    
    vi check_one(N + 3);
    for(int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
        check_two[i] = check_two[i - 1] + (a[i] == 2);
    }
    int ans = N;
    for(int i = N; i >= 1; i--){
        check_one[i] = check_one[i + 1] + (a[i] == 1);
    }
    for(int i = 0; i <= N; i++){    
        ans = min(ans, check_two[i] + check_one[i + 1]);
    }
    printf("%d\n", ans);
}