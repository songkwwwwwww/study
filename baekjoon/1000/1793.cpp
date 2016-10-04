#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*

*/
string f(string a, string b) {
    int t = 0;
    string r;
    while (!a.empty() || !b.empty() || t) {
        if (!a.empty()){
            t += a.back()-'0';
            a.pop_back();
        }
        if (!b.empty()){
            t += b.back()-'0';
            b.pop_back();
        } 
        r += t % 10 + '0';
        t /= 10;
    }
    reverse(r.begin(), r.end());
    return r;
}
string dp[251] = { "1","1" };
int main(){
    freopen("1793.txt", "r", stdin);
    for (int i = 2; i <= 250; i++) 
        dp[i] = f(f(dp[i - 2], dp[i - 2]), dp[i - 1]);
    int n;
    while (cin >> n) {
        printf("%s\n", dp[n].c_str());        
    }
    return 0;
}