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

int main(){
    freopen("7785.txt", "r", stdin);
    int n;
    cin >> n;
    set<string> s;
    while (n--) {
        string name, what;
        cin >> name >> what;
        if (what == "enter") {
            s.insert(name);
        }
        else {
            s.erase(s.find(name));
        }
    }
    for (set<string>::reverse_iterator rit = s.rbegin(); rit!=s.rend(); rit++) {
        cout << *rit << '\n';
    }
}