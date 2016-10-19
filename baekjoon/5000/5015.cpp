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


const int MAX_LEN = 100;
const int MAX_N = 100;
int N;
string w, s;
int d[MAX_LEN + 1][MAX_LEN + 1];

int solve(int w_index, int s_index){
    // 둘 다 사용한 경우에는 성공
    if(w_index == w.size() && s_index == s.size())
        return 1;
    
    int& ret = d[w_index][s_index];
    if(ret != -1) return ret;

    if(w[w_index] == '?' || w[w_index] == s[s_index])
        return ret = solve(w_index + 1, s_index + 1);
    
    else if(w[w_index] == '*')
        if(solve(w_index + 1, s_index) || solve(w_index, s_index + 1))
            return ret = 1;

    return ret = 0;
}

int main(){
    freopen("5015.txt", "r", stdin);
    //setbuf(stdout, NULL);
    char str[MAX_LEN + 1];
    scanf("%s", str);
    w = string(str);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        memset(d, -1, sizeof(d));
        scanf("%s", str);
        s = string(str);
        if(solve(0, 0)) printf("%s\n", str);
    }
}