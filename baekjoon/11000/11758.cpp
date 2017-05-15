#include <cstdio>

using namespace std;

// P1, P2, P3를 순서대로 이은 선분이 반시계 방향을 나타내면 1, 시계 방향이면 -1, 일직선이면 0을 출력한다.

// counterclockwise (left turn): σ < τ	    1
// clockwise (right turn): σ > τ	    -1
// collinear (left turn): σ = τ		    0
// (y2−y1) (x3−x2) − (y3−y2) (x2−x1)

const int MAX_N = 3;

struct point{
    int x, y;
};

point a[MAX_N];



int main(){
    freopen("11758.txt", "r", stdin);
    for(int i = 0; i < 3; i++){
	scanf("%d %d", &a[i].x, &a[i].y);
    }
    int temp = (a[1].y - a[0].y) * (a[2].x - a[1].x) - (a[2].y - a[1].y) * (a[1].x - a[0].x);
    int ans;
    if(temp < 0)
	ans = 1;
    else if(temp > 0)
	ans = - 1;
    else
	ans = 0;
    printf("%d\n", ans);
}
