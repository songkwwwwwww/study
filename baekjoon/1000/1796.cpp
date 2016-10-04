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


const int MAX_N = 1000;
char str[MAX_N + 1];

int d[26][MAX_N + 1];

int min_pos[26];
int max_pos[26];
bool check_alpha[26];

int solve(int index, int pos){
    // base case
    if(index == 26) return 0;
    if(!check_alpha[index]) return solve(index + 1, pos);

    int& ret = d[index][pos];
    if(ret != -1) return ret;

    ret = INF;
    //if(min_pos[index] == max_pos[index])
    
    // min_pos[index] 를 먼저 처리하고 max_pos[index]를 처리
    ret = min(ret, solve(index + 1, max_pos[index]) 
        + abs(pos - min_pos[index]) + abs(min_pos[index] - max_pos[index]) );
    
    // max_pos[index] 를 먼저 처리하고 min_pos[index]를 처리    
    ret = min(ret, solve(index + 1, min_pos[index]) 
        + abs(pos - max_pos[index]) + abs(max_pos[index] - min_pos[index]));

    return ret; 
}

int main(){
    freopen("1796.txt", "r", stdin);
    //setbuf(stdout, NULL);
    for(int i = 0; i < 26; i++){
        min_pos[i] = INF;
        max_pos[i] = -INF;
    }

    scanf("%s", str);
    int len;
    for(len = 0; str[len] != '\0'; len++){
        char c = str[len];
        min_pos[c - 'a'] = min(min_pos[c - 'a'], len);
        max_pos[c - 'a'] = max(max_pos[c - 'a'], len);
        check_alpha[c - 'a'] = true;
    }
    memset(d, -1, sizeof(d));
    int result = solve(0, 0);
    printf("%d\n", result + len);
}