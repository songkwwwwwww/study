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
입력
19줄에 각 줄마다 19개의 숫자로 표현되는데, 
검은 바둑알은 1, 흰 바둑알은 2, 알이 놓이지 않는 자리는 0으로 표시되며, 숫자는 한 칸씩 띄어서 표시된다.

출력
첫줄에 검은색이 이겼을 경우에는 1을, 흰색이 이겼을 경우에는 2를, 아직 승부가 결정되지 않았을 경우에는 0을 출력한다. 
검은색 또는 흰색이 이겼을 경우에는 둘째 줄에 연속된 다섯 개의 바둑알 중에서 가장 왼쪽에 있는 바둑알
(연속된 다섯 개의 바둑알이 세로로 놓인 경우, 그 중 가장 위에 있는 것)의 가로줄 번호와, 세로줄 번호를 순서대로 출력한다.
*/

int a[21][21];

// 북동쪽 방향 검색
bool search1(int color, int x, int y){
    int count = 1;
    for(; color == a[x - 1][y + 1]; x--, y++)
        count++;
    return (count == 5 ? true : false);
}

// 동쪽 방향 탐색
bool search2(int color, int x, int y){
    int count = 1;
    for(; color == a[x][y + 1]; y++)
        count++;
    return (count == 5 ? true : false);
}

// 남동쪽 방향 검색
bool search3(int color, int x, int y){
    int count = 1;
    for(; color == a[x + 1][y + 1]; x++, y++)
        count++;
    return (count == 5 ? true : false);
}

// 남쪽 방향  검색
bool search4(int color, int x, int y){
    int count = 1;
    for(; color == a[x + 1][y]; x++)
        count++;
    return (count == 5 ? true : false);
}

int main(){
    freopen("2615.txt", "r", stdin);
    for(int i = 1; i <= 19; i++)
        for(int j = 1; j <= 19; j++)
            scanf("%d", &a[i][j]);
            
    for(int i = 1; i <= 19; i++){
        for(int j = 1; j <= 19; j++){
            // (i, j) 에 흰 돌이나 검은 색 돌이 놓여져 있다면
            if(a[i][j] != 0){
                // 북동쪽 방향 검색
                if((a[i][j] != a[i + 1][j - 1]) && search1(a[i][j], i, j)){
                    printf("%d\n%d %d\n", a[i][j], i, j);
                    return 0;
                }

                // 동쪽 방향 탐색
                if((a[i][j] != a[i][j - 1]) && search2(a[i][j], i, j)){
                    printf("%d\n%d %d\n", a[i][j], i, j);
                    return 0;
                }

                // 남동쪽 방향 검색
                if((a[i][j] != a[i - 1][j - 1]) && search3(a[i][j], i, j)){
                   printf("%d\n%d %d\n", a[i][j], i, j);
                    return 0;
                }

                // 남쪽 방향
                if((a[i][j] != a[i - 1][j]) && search4(a[i][j], i, j)){
                    printf("%d\n%d %d\n", a[i][j], i, j);
                    return 0;
                }
            }
        }
    }
    printf("0\n");
}