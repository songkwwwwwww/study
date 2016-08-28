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

vector<int> moves;
inline int cell(int y, int x){ return 1 << (y * 5 + x); }
void precalc(){
    // 세 칸짜리 L자 모양 블록을 계산한다.
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            vector<int> cells;
            for(int dy = 0; dy < 2; dy++)
                for(int dx = 0; dx < 2; dx ++)
                    cells.push_back(cell(y + dy, x + dx));
            int square = cells[0] + cells[1] + cells[2] + cells[3];
            for(int i = 0; i < 4; i++)
                moves.push_back(square - cells[i]);
        }
    }
    // 두 칸짜리 블록들을 계산한다.
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            moves.push_back(cell(i, j) + cell(i, j + 1));
            moves.push_back(cell(j, i) + cell(j + 1, i));
        }
    }
}

char cache[1 << 25];

char play(int board){
    //메모이제이션
    char& ret = cache[board];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < moves.size(); i++){
        if((moves[i] & board) == 0){
            if(!play(board + moves[i])){
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int main(){
    freopen("BLOCKGAME.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);
    memset(cache, -1, sizeof(cache));
    for(int tc = 1; tc <= TC; tc++){
        int board = 0;
        char c;
        //memset(cache, -1, sizeof(cache));
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cin >> c;
                if(c == '#')
                    board = board | (1 << (i * 5 + j));
            }
        }
        precalc();
        int result = play(board);
        if(result == 0) cout << "LOSING" << endl;
        else if(result == 1) cout << "WINNING" << endl;
    }
}