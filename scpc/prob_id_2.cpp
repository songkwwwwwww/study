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


const int MAX_N = 300000;

bool cmp(int a, int b){
    if( a > b)
        return true;
    else
        return false;
}

int a[MAX_N];

int main(){
    freopen("prob_id_2.txt", "r", stdin);
    setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        int N;
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d", &a[i]);
        }
        sort(a, a + N);
        int max_val = 0, cnt = 0;
        for(int i = 0; i < N; i++){
            if(a[i] + N - i > max_val)
                max_val = a[i] + N - i;
        }
        for(int i = N - 1; i >= 0; i--){
            if(max_val <= a[i] + N)
                cnt++;
            else
                break;
        }
        printf("Case #%d\n%d\n", tc, cnt);
    }
}