#include <iostream>
#include <cstdio>

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

int block[4][3][2] = {
    {
	{0, 0},
	{0, 1},
	{1, 0}
    },
    {
	{0, 0},
	{0, 1},
	{1, 1},
    },
    {
	{0, 0},
	{1, 0},
	{1, -1},
    },
    {
	{0, 0},
	{1, 0},
	{1, 1},
    }
};

const int MAX_H = 20;
const int MAX_W = 20;
int H, W;
int result = 0;

char map[MAX_H + 3][MAX_W + 3];

inline bool is_range(int x, int y){
    return (0 <= x && x < H && 0 <= y && y < W);
}

bool check(int x, int y, int type){
    for(int i =  0; i < 3; i++){
	int nx = x + block[type][i][0];
	int ny = y + block[type][i][1];
	if(!is_range(nx, ny) || map[nx][ny] != '.'){
	    return false;
	}
    }
    return true;
}

void set(int x, int y, int type, char c){
    for(int i = 0; i < 3; i++){
	int nx = x + block[type][i][0];
	int ny = y + block[type][i][1];
	map[nx][ny] = c;
    }
}

void solve(int x, int y){
    // base case
    if(x == H){
	result++;
	return;
    }
    else if( y == W ){
	return solve(x + 1, 0);
    }
    else if(map[x][y] == '#'){
	return solve(x, y + 1);
    }

    for(int type = 0; type < 4; type++){
	if(!check(x, y, type))
	    continue;
	set(x, y, type, '#');
	solve(x, y + 1);
	set(x, y, type, '.');
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        result = 0;
        scanf("%d %d", &H, &W);
        for(int i = 0; i < H; i++){
            scanf("%s", &map[i]);
        }
        solve(0, 0);
        printf("%d\n", result);
    }
}
