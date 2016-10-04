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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다.

출력
첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 
가장 작은 수를 나타내는 수열만 출력한다.
수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다.
*/
int s[81];
int n;
bool end = false;

bool same(int a, int b){
    int i;
    for(i = a; i < b; i++)
        if(s[i] != s[i + b - a])
            break;

    return ( a == b ? false : i == b);
}

bool good(int m){
    for(int i = 1; i <= m/2; i++)
        for(int j = 1; j <= m - i; j++)
            if(same(j, j + i))
                return false;
    return true;
}

void solve(int k){
    if(end) return;
    if(k > n){
        end = true;
        for(int i = 1; i <= n; i++)
            printf("%d", s[i]);
        printf("\n");
        return ;
    }
    for(int i = 1; i <= 3; i++){
        s[k] = i;
        if(good(k))
            solve(k + 1);
        s[k] = 0;
    }
}

int main(){
    freopen("2661.txt", "r", stdin);
    scanf("%d", &n);
    solve(1);
}