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

bool is_finished(const vector<string>& board, char turn){
    // check row
    for(int x = 0; x < 3; x++){
        if(board[x][0] == turn && board[x][0] == board[x][1] 
            && board[x][0] == board[x][2])
            return true;
    }
    // check col
    for(int y = 0; y < 3; y++){
        if(board[0][y] == turn && board[0][y] == board[1][y] 
            && board[0][y] == board[2][y])
            return true;
    }

    // check /-dia
    if(board[0][2] == turn && board[0][2] == board[1][1]
        && board[0][2] == board[2][0])
        return true;
    
    // check \-dia 
    if(board[0][0] == turn && board[0][0] == board[1][1]
        && board[0][0] == board[2][2])
        return true;

    return false;
}

int bijection(const vector<string>& board){
    int ret = 0;
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
           ret = ret * 3;
            if(board[y][x] == 'o') ret++;
            else if(board[y][x] == 'x') ret += 2;
        }
    }
    return ret;
}

int cache[19683];

int can_win(vector<string>& board, char turn){
    if(is_finished(board, 'o' + 'x' - turn)) return -1;
    int& ret = cache[bijection(board)];
    if(ret != -2) return ret;

    int min_value = 2;
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            if(board[y][x] == '.'){
                board[y][x] = turn;
                min_value = min(min_value, can_win(board, 'o' + 'x' - turn));
                board[y][x] = '.';
            }
        }
    }
    if(min_value == 2 || min_value == 0 ) return ret = 0;
    return ret = -min_value;
}


int main(){
    freopen("TICTACTOE.txt", "r", stdin);
    vector<string> board(3);
    int TC;
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        //memset(cache, -2, sizeof(cache));
        for(int i = 0; i < 19683; i++) cache[i] = -2;
        for(int i = 0; i < 3; i++) cin >> board[i];
        for(int i = 0; i < 3; i++) cout << board[i] << endl;
        int result = can_win(board, 'x');
        if(result == 0) cout << "TIE" << endl;
        else if(result == 1) cout << 'x' << endl;
        else if(result == -1) cout<< 'o' << endl;
        else cout << "result : " << result << endl;
    }
}