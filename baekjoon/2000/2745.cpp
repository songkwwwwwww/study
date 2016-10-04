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
#include <utility> // std::pair

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*

*/
int main(){
    freopen("2745.txt", "r", stdin);
    string s;
    cin >> s;
    int base;
    scanf("%d", &base);
    int result = 0;
    for(int k = 1, i = (int)s.size() - 1; i >= 0; i--, k *= base){
        char c = s[i];
        if('0' <= c && c <= '9'){
            result += (c - '0') * k;
        }
        else{ // [A, Z]
            result += (c - 'A' + 10) * k; 
        }
    }
    printf("%d\n", result);
}