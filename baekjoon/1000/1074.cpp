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

int solve(int x, int y, int n){
    if(n == 1) return 0;
    else{
        int m = n / 2;
        if(x < m){
            if(y < m){
                return solve(x, y, m);
            }
            else{ // y >= m
                return m * m + solve(x, y - m, m);
            }
        }
        else{ // x >= m
            if(y < m){ 
                return 2 * m * m + solve(x - m, y, m);                
            }
            else{ // y >= m
                return 3 * m * m + solve(x - m, y - m, m);                
            }
        }
    }

}

int main(){
    freopen("1074.txt", "r", stdin);
    int N, r, c;
    while(cin >> N >> r >> c){
        printf("%d\n", solve(r, c, 2 << N));
    }
}