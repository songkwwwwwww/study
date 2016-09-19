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

typedef vector<int> vi;
typedef vector<vi> vvi;

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

int d[64];

int main(){
    freopen("prob_id_25.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    for(int i = 2000; i > 0; i--){
        int num = i;
        int count = 0;
        while(num != 1){
            // num이 홀수이면
            // 3N + 1
            if(num & 1){
                num = 3 * num + 1;
                count++;
            }
            else{
                // 짝수이면 
                // 계속 N/2 한다.
                // 결국 num 1이 될 때 반복문이 끝난다.
                while( !(num & 1) ){
                    num >>= 1;
                    count++;
                }
            }
        }
        // count가 K 범위를 벗어나지 않으면 현재 수인 i를 기록
        if(count <= 63)
            d[count] = i;
    }
    for(int K, tc = 1; tc <= TC; tc++){
        scanf("%d", &K);
        printf("Case #%d\n%u %llu\n", tc, d[K], 1ull << K);
    }
}