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
const int MAX_N = 200;
int N;
int a[MAX_N + 1][MAX_N + 1];
int d[MAX_N + 1][MAX_N + 1];

int main(){
    freopen("MAXMAT.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                scanf("%d", &a[i][j]);
        int max = -987654321;
        // d[i][j] : i, j 번째까지의 최대 합
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                
                if(max < current) max = current;
            }
        }
        printf("%d\n", max);
    }
}