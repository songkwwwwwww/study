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
int N;
int d[MAX_N + 1][MAX_N + 1];
int choice[MAX_N + 1][MAX_N + 1];

char str1[MAX_N + 1];
char str2[MAX_N + 1];

// 0 : 동쪽
// 1 : 남쪽
// 2 : 남동쪽
int solve(int a, int b){
    // base case
    if(str1[a] =='\0' || str2[b] =='\0') return 0;

    int& ret = d[a][b];
    if(ret != -1) return ret;

    ret = 0;
    if(str1[a] == str2[b]){
        ret = max(ret, solve(a + 1, b + 1) + 1);
        choice[a][b] = 2;
    }
    else{
        ret = solve(a + 1, b);
        int temp = solve(a, b + 1);
        if(ret < temp){
            choice[a][b] = 1;
            ret = temp;
        }
        else{
            choice[a][b] = 0;

        }
    }
    return ret;
}

void reconstruct(int a, int b){
    if(str1[a] =='\0' || str2[b] =='\0') return ;
    // 0 : 동쪽
    // 1 : 남쪽
    // 2 : 남동쪽
    switch(choice[a][b]){
        case 0:
            reconstruct(a + 1, b);        
            break;
        case 1:
            reconstruct(a, b + 1);
            break;
        case 2:
            printf("%c", str1[a]);
            reconstruct(a + 1, b + 1);        
            break;  
    }
}

int main(){
    freopen("9252.txt", "r", stdin);
    //setbuf(stdout, NULL);
    memset(d, -1, sizeof(d));
    scanf("%s", str1);
    scanf("%s", str2);
    printf("%d\n", solve(0, 0));
    
    reconstruct(0, 0);
    printf("\n");
}