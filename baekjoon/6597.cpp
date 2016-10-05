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

string pre, in;


// post_order 로 출력
void solve(int pre_start, int pre_end, int in_start, int in_end){
    if(pre_start > pre_end || in_start > in_end) return ;

    char root = pre[pre_start];
    int l = 0;
    while(in[in_start + l] != root)
        l++;
    
    // visit l-subt
    solve(pre_start + 1, pre_start + l, in_start, in_start + l - 1);
    // visit r-subt
    solve(pre_start + l + 1, pre_end, in_start + l + 1, in_end);    
    printf("%c", root);
}

int main(){
    freopen("6597.txt", "r", stdin);
    //setbuf(stdout, NULL);
    while(cin >> pre >> in){
        solve(0, (int)pre.size() - 1, 0, (int)in.size() - 1);
        printf("\n");
    }
}