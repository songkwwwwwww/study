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

char a[20][21];

int dx[4] = {0, 0, 1, -1}; // U D R L
int dy[4] = {-1, 1, 0, 0};

int go(vector<string>& board, vector<bool>& checked, int x, int y){
    int ans = 0;
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()){
            if(checked[board[nx][ny] - 'A'] == false){
                checked[board[nx][ny] - 'A'] = true;
                ans = MAX( ans, go(board, checked, nx, ny));
                //int next = go(board, checked, nx, ny);
                //if( ans < next) ans = next;
                checked[board[nx][ny] - 'A'] = false;
            }
        }
    }
    return ans + 1;
}

int main(){
    freopen("1987.txt", "r", stdin);
    int R, C; // 1 <= R, C <= 20
    scanf("%d %d", &R, &C);
    vector<string> board(R);
    for(int i = 0; i < R; i++){
        cin >> board[i];

    }
    vector<bool> checked(26);
    checked[board[0][0] - 'A'] = true;
    cout << go(board, checked, 0, 0) << endl;
}