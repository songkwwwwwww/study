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


int solve(string& s){
    string output;
    output.reserve(s.size() * 2);
    bool flag = false;
    for(int i = 0; i < s.size(); i++){
        char cur = s[i];
        int count = 1, next = i + 1;
        while(next < s.size() && (s[i] == s[next])){
            i = next;
            next++;
            count++;
            flag = true;
        }
        string digit;
        while(count){
            digit.push_back(count + '0');
            count /= 10;
        }
        reverse(digit.begin(), digit.end());
        output.append(1, cur);
        output.append(digit);
    }
    if(flag)
        printf("%s\n", output.c_str());
    else
        printf("%s\n", s.c_str());
}

int main(){
    //freopen(".txt", "r", stdin);
    //setbuf(stdout, NULL);
    string input("aabccccccccaaa");
    solve(input);
}