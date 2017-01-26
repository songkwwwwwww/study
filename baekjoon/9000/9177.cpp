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


const int MAX_L = 200;
char a[MAX_L + 1], b[MAX_L + 1], c[MAX_L * 2 + 1];
bool check[MAX_L + 1][MAX_L + 1];
bool d[MAX_L + 1][MAX_L + 1];
int len_a, len_b, len_c;

bool solve(int index_a, int index_b, int index_c){
    // base case
    if(index_c == len_c)
        return true;

    bool& ret = d[index_a][index_b];
    if(check[index_a][index_b]) return ret;
    check[index_a][index_b] = true;


    ret = 0;
    // a를 쓸 수 있으면 a를 사용
    if(index_a < len_a && a[index_a] == c[index_c])
        ret |= solve(index_a + 1, index_b, index_c + 1);

    // b를 쓸 수 있으면 b를 사용
    if(index_b < len_b && b[index_b] == c[index_c])
        ret |= solve(index_a, index_b + 1, index_c + 1);

    return ret;
}

int main(){
    freopen("9177.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%s %s %s", a, b, c);
        for(len_a = 0; a[len_a]; len_a++);
        for(len_b = 0; b[len_b]; len_b++);
        for(len_c = 0; c[len_c]; len_c++);
        memset(check, false, sizeof(check));
        memset(d, false, sizeof(d));
        bool ans = solve(0, 0, 0);
        if(ans)
            printf("Data set %d: yes\n", tc);
        else
            printf("Data set %d: no\n", tc);        
    }
}