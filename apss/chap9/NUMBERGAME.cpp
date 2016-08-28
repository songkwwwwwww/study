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

const int EMPTY = 0xffffffff;

int n; // 1 <= n <= 50
int board[50];
int cache[50][50];

/*
play(left, right) = max{
    board[left] - play(left + 1, right),
    board[right] - play(left, right - 1),
    -play(left + 2, right)      // (right - left >= 1),
    -play(left, right - 2)      // (right - left >= 1)
}
*/
int play(int left, int right){
    if(left > right) return 0;
    int& ret = cache[left][right];
    if(ret != EMPTY) return ret;
    // 수를 가져가는 경우
    ret = max(board[left] - play(left + 1, right),
        board[right] - play(left, right - 1));
    
    // 수를 없애는 경우
    if(right - left + 1 >= 2){
        ret = max(ret, -play(left + 2, right));
        ret = max(ret, -play(left, right - 2));
    }
    return ret;    
}

int main(){
    freopen("NUMBERGAME.txt", "r", stdin);
    int TC;
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d", &n);
        memset(cache, EMPTY, sizeof(cache));
        for(int i = 0; i < n; i++) scanf("%d", &board[i]);
        cout << play(0, n - 1) << endl;
    }
}