/*
	boj problem #

2344

2151

2347

10725

10726

4211

*/

#include <cstdio>
#include <cstring>

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int N; // 1 <= N <= 1000
int dir;
int rooms[1000][1001];
bool visited[1000][1000];


int change_dir(int dir, int mirror){
	if(mirror == 1){
		// (3 - x)
		return 3 - dir;
	}
	else{ // mirror == 2
		// (x + 2) % 4
		return (dir + 2) % 4;
	}
}

int main(){
	freopen("mirror_in_room.txt", "r", stdin);
	int TC, x, y, count;
	scanf("%d", &TC);
	for(int tc = 1; tc <= TC; tc++){
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				scanf("%1d", &rooms[i][j]);
				visited[i][j] = false;
			}
		}


		dir = 2;
		count = x = y = 0;
		while(0 <= x && x < N && 0 <= y && y < N){
			if(rooms[x][y] != 0){
				if(visited[x][y] == false){
					visited[x][y] = true;
					count++;
				}
				dir = change_dir(dir, rooms[x][y]);
			}
			x += dx[dir];
			y += dy[dir];
		}
		printf("Case #%d\n%d\n", tc, count);
	}	
}
