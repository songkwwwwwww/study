/*
	https://algospot.com/judge/problem/read/GALLERY

*/

#include <cstdio>
#include <vector>

using namespace std;

#define MAX_V 1000

int V, E; // 1 <= V <= 1000, 0 <= E < V


vector<int> adj[MAX_V];
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

// 지금까지 설치한 카메라의 총 수
int installed;

/*
	set graph
*/
void make_graph(){
	int a, b;
	for(int i = 0; i < V; i++)
		adj[i].clear();

	for(int i = 0; i < E; i++){
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

// here로부터 깊이 우선 탐색을 하고, here의 정보를 반환한다.
int dfs(int here){
	visited[here] = true;
	int children[3] = {0, 0, 0};
	for(int i = 0; i < adj[here].size(); i++){
		int there = adj[here][i];
		if(!visited[there])
			children[dfs(there)]++;
	}
	
	// 자손 노드 중 감시되지 않는 노드가 있을 경우 카메라를 설치한다.
	if(children[UNWATCHED]){
		installed++;
		return INSTALLED;		
	}
	// 자손 노드 중 카메라가 설치된 노드가 있을 경우 설치할 필요가 없다.
	if(children[INSTALLED]){
		return WATCHED;
	}

	return UNWATCHED;	
}

// 그래프를 감시하는 데 필요한 카메라의 최소 수를 반환한다.
int install_camera(){
	installed = 0;
	visited = vector<bool>(V, false);
	for(int i = 0; i < V; i++){
		if(!visited[i] && dfs(i) == UNWATCHED)
			installed++;
	}
	return installed;
}

int main(){
	freopen("GALLERY.txt", "r", stdin);
	int TC; // TC <= 50
	scanf("%d", &TC);
	for(int tc = 1; tc <= TC; tc++){
		scanf("%d %d", &V, &E);
		make_graph();
		
		printf("%d\n", install_camera());	
	}

}

