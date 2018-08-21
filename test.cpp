#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_H = 10;
const int MAX_W = 10;
const int MAX_R = 10;
const int MAX_C = 10;
int H, W, R, C;


bool is_range(int x, int y){
    return ();
}

int type[4][4][2] = {
    {
	{0, 0},
	{0, 1},
	{1, 1},
	{2, 1},
    },
    {
	{0, 0},
	{1, 0},
	{1, -1},
	{1, -2},
    },
    {
	{0, 0},
	{0, -1},
	{-1, -1},
	{-2, -1},
    },
    {
	{0, 0},
	{-1, 0},
	{-1, 1},
	{-1, 2},
    },
};



int main(){
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
	scanf("%d %d %d %d", &H, &W, &R, &C);

    }
}
