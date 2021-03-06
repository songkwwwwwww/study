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


const int MAX_L = 1000;

bool is_pal(string s){
    int N = s.size();
    for(int i = 0; i <= (N - 1) / 2; i++){
        // i와 N - 1 - i를 비교
        if(s[N - 1 - i] == '@')
            continue;
        if(s[i] != s[N - 1 - i])
            return false;
    }
    return true;
}

int main(){
    freopen("1254.txt", "r", stdin);
    //setbuf(stdout, NULL);
    string str;
    cin >> str;
    while(true){
        if(is_pal(str)){
            break;
        }
        str += '@';
    }
    int ans = str.size();
    printf("%d\n", ans);
}