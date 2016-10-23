#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

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
string solve(string::iterator& it){
    char c = *(it); it++;
    if(c == 'w' || c == 'b')
        return string(1, c);
    string upper_left = solve(it);
    string upper_right = solve(it);
    string lower_left = solve(it);
    string lower_right = solve(it);
    return string("x") + lower_left + lower_right + upper_left + upper_right;
}

int main(){
    freopen("QUADTREE.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        string s;
        cin >> s;
        string::iterator it = s.begin();
        cout << solve(it) << endl;
    }
}