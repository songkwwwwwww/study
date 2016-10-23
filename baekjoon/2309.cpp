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


const int MAX_N = 9;
int h[9];

bool solve(int index, int sum, vi ans){
    if(index == MAX_N){
        if(sum == 100 && ans.size() == 7){
            for(int i = 0; i < ans.size(); i++){
                printf("%d\n", ans[i]);
            }
            return true;
        }
        else 
            return false;
    }
    
    // 현재 index의 난쟁이를 포함하지 않거나
    if(solve(index + 1, sum, ans))
        return true;
    // 포함하거나
    ans.push_back(h[index]);
    if(solve(index + 1, sum + h[index], ans))
        return true;

    return false;
}

int main(){
    freopen("2309.txt", "r", stdin);
    //setbuf(stdout, NULL);
    for(int i = 0; i < 9; i++)
        scanf("%d", &h[i]);
    sort(h, h + 9);
    vi ans;
    solve(0, 0, ans);
}