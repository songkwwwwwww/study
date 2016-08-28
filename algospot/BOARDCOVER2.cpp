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

// 게임판의 크기 H, W (1 ≤ H, W ≤ 10)
// 블록의 모양을 나타내는 격자의 크기 R, C  (1 ≤ R, C ≤ 10)
int H, W, R, C;


int main(){
    freopen("BOARDCOVER2.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= 1; tc++){
        scanf("%d %d %d %d", &H, &W, &R, &C);
        for(int i = 0; i < H; i++)
            scanf("%s", a[i]);
        

        /*
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                printf("%c", a[i][j]);
            }
            printf("\n");
        }
        */
    }
}