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


const int MAX_N = 30;
const int MAX_W = 500;
const int MAX_TOTAL_W = MAX_N * MAX_W;

inline int get_abs(int x){
    return x >= 0 ? x : -x;
}

inline bool is_range(int x){
    if(0 <= x && x <= MAX_TOTAL_W)
        return true;
    else
        return false;
}

int main(){
    freopen("2629.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vi a(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    vb check(MAX_TOTAL_W + 1), temp(MAX_TOTAL_W);
   
    check[0] = temp[0] = true;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= MAX_TOTAL_W; j++){
            if(check[j]){
                int left = get_abs(j - a[i]);
                int right = get_abs(j + a[i]);
                if(is_range(left)) temp[left] = true;
                if(is_range(right)) temp[right] = true;   
            }
        }
        for(int j = 0; j <= MAX_TOTAL_W; j++)
            check[j] = temp[j];        
    }
    int q;
    scanf("%d", &q);
    for(int num, i = 0; i < q; i++){
        scanf("%d", &num);
        if(check[num]) printf("Y ");
        else printf("N ");
    }
    printf("\n");
}