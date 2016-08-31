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
    freopen("MEETING.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        int N; // 1 <= N <= 10000
        scanf("%d", &N);
        vector<int> mans(N);
        vector<int> women(N);
        for(int i = 0; i < N; i++)
            scanf("%d", &mans[i]);
        for(int i = 0; i < N; i++)
            scanf("%d", &women[i]);
        
        sort(mans.begin(), mans.end());
        sort(women.begin(), women.end());
        int result = 0;
        for(int i = 0; i < N; i++){
            result += abs(mans[i] - women[i]);
        }
        printf("%d\n", result);
    }
}