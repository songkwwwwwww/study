

#include <cstdio>
#include <deque>
using namespace std;
int a[100][100];
int d[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int main(){
	int m, n;
	freopen("1261.txt", "r", stdin);
	scanf("%d %d", &m, &n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &a[i][j]);
			d[i][j] = -1;
		}		
	}
	deque<pair<int, int> > q;
	q.push_back(make_pair(0, 0));
	d[0][0] = 0;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for(int k = 0; k < 4; k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(0 <= nx && nx < n && 0 <= ny && ny < m){
				if(d[nx][ny] == -1){
					if(a[nx][ny] == 0){
						d[nx][ny] = d[x][y];
						q.push_back(make_pair(x, y));
					}
					else{
						d[nx][ny] = d[x][y] + 1;
						q.push_back(make_pair(nx, ny));						
					}
				}
			}
		}
		
	}
	printf("%d\n", d[n-1][m-1]);
	
}
