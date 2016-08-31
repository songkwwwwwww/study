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

char str[1001];
int main(){
    freopen("LECTURE.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%s", str);
        vector<string> v;
        v.reserve(500);
        for(int i = 0; str[i]; i+=2){
            string s(str + i, 2);
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++)
            printf("%s", v[i].c_str());
        printf("\n");
    }
}