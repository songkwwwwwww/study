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

// 체스판의 크기 N
// 1 <= N <= 10;
int N;
int a[10][10]; // available
bool board[10][10];
bool checked_dia[30];   // /-dia, row + col
bool checked_dia2[30];  // \-dia, row - col + (N - 1)

bool check(int r, int c){
    // check /-dia
    if(checked_dia[r + c]) return false;
    // check \-dia
    if(checked_dia2[(N - 1) + r - c]) return false;
    
    return true;
}
int sol = 0;
// 놓을 수 있는 비숍의 최대 개수를 반환한다.
void go(vector<int>& candidates, int index, int n_bishops){
    
    for(int i = index; i < candidates.size(); i++){
        int x = candidates[i] / N;
        int y = candidates[i] % N;
        if(check(x, y)){
            checked_dia[x + y] = true;
            checked_dia2[(N - 1) + x - y] = true;
            go(candidates, index + 1, n_bishops + 1);
            if(n_bishops + 1 > sol) sol = n_bishops + 1;
            checked_dia[x + y] = false;
            checked_dia2[(N - 1) + x - y] = false;
        }
    }
}

int main(){
    freopen("1799.txt", "r", stdin);
    scanf("%d", &N);
    
    vector<int> candidates;
    candidates.reserve(N * N / 2);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 1)
                candidates.push_back(i * N + j);
        }
    }
    go(candidates, 0, 0);
    printf("%d\n", sol);
}