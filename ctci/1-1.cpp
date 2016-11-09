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


const int MAX_N = 8;
const int MAX_M = 8;

bool solve(const string& s){
    int check = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] < 'a' || 'z' < 'a') return false;

        int digit = s[i] - 'a';
        if(check & (1 << digit))
            return false;
        check |= (1 << digit);
    }
    return true;
}

int main(){
    //freopen(".txt", "r", stdin);
    //setbuf(stdout, NULL);
    vector<string> v;
    v.push_back(string("aabcseirojgaok"));
    v.push_back(string("abcseirojgok"));
    v.push_back(string("abcseirojgkwt"));
    for(int i = 0; i < v.size(); i++){
        if(solve(v[i])){
            printf("true\n");
        }
        else
            printf("false\n");        
    }
}