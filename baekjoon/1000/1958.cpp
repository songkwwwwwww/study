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


const int MAX_N = 100;
int d[MAX_N + 3][MAX_N + 3][MAX_N + 3];


int main(){
    freopen("1958.txt", "r", stdin);
    //setbuf(stdout, NULL);
    char a[MAX_N + 1];
    char b[MAX_N + 1];
    char c[MAX_N + 1];
    int i, j, k;
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    for(i = 0; a[i]; i++){
        for(j = 0; b[j]; j++){
            for(k = 0; c[k]; k++){

                if(a[i] == b[j] && b[j] == c[k]){
                    d[i + 1][j + 1][k + 1] = d[i][j][k] + 1;
                }
                else{
                    d[i + 1][j + 1][k + 1] = max(max(d[i][j + 1][k + 1], d[i + 1][j][k + 1])
                        , d[i + 1][j + 1][k]);
                }

            }
        }
    }
    printf("%d\n", d[i][j][k]);
}