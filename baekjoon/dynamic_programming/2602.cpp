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

int d[22][2][102];

int l; // str_len
char str[22];
char a[2][102];

/*
현재 위치는 (x, y) 이고
밟아야 할 문자가 str[index] 일 때의 경우의 수
*/

int main(){
    freopen("2602.txt", "r", stdin);
    scanf("%s", str);
    scanf("%s", a[0]);
    scanf("%s", a[1]);
    int str_len, bridge_len;
    for(str_len = 0; str[str_len]; str_len++);
    for(bridge_len = 0; a[0][bridge_len]; bridge_len++);


    
    for(int i = 0; a[0][i]; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < bridge_len; k++){
                d[i][j][k] = 0;
                if(a[j][k] == str[i])
                    for(int l = 0; l <= k; l++)
                        d[i][j][k] += d[i-1][!j][l];
            }
        }
    }
    
    printf("%d\n", d[str_len - 1][0][bridge_len - 1]);
    printf("%d\n", d[str_len - 1][1][bridge_len - 1]);
    
    //printf("%s\n", str);
    //printf("%s\n", a[0] + 1);
    //printf("%s\n", a[1] + 1);

}