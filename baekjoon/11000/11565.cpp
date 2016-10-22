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


const int MAX_LEN = 1000;

int main(){
    freopen("11565.txt", "r", stdin);
    //setbuf(stdout, NULL);
    char a[MAX_LEN + 1];
    char b[MAX_LEN + 1];
    int a_cnt = 0;
    scanf("%s", a);
    for(int i = 0; a[i]; i++)
        if(a[i] == '1')
            a_cnt++;
    
    int b_cnt = 0;
    scanf("%s", b);
    for(int i = 0; b[i]; i++)
        if(b[i] == '1')
            b_cnt++;
    
    if(a_cnt & 1) a_cnt++;
    if(a_cnt >= b_cnt)
        printf("VICTORY\n");
    else
        printf("DEFEAT\n");
}