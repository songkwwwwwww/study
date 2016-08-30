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

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*

*/
char str[51];
int main(){
    freopen("9012.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%s", str);
        int c = 0;
        for(int i = 0; str[i] && c >= 0; i++) str[i] == '(' ? c++ : c--;
        if(c == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}