/*
참조 :
    알고리즘 문제 해결 전략(종만북)
*/
/*
어떤 그래프를 깊이 우선 탐색이나 너비 우선 탐색했을 때
탐색이 따라가는 간선들만을  모아 보면 트리 형태를 띠게 된다.

이런 트리를 주어진 그래프의 깊이 우선 탐색 스패닝 트리(DFS Spanning Tree)
혹은 너비 우선 탐색 스패닝 트리(BFS Spanning Tree) 라고 한다.


트리 간선(Tree edge) :
스패닝 트리에 포함된 간선.

순방향 간선(Forward edge) :
스패닝 트리의 선조에서 자손으로 연결되지만 트리 간선이 아닌 간선

역방향 간선(Back edge) :
스패닝 트리의 자손에서 선조로 연결되는 간선을 말한다.

이 세 가지 분류를 제외한 나머지 간선들은 교차 간선(cross edge)라고 한다.
교차 간선은 트리에서 선조와 자손 관계가 아닌 정점들 간에 연결된 간선들을 의미한다.

탐색이 어느 순서대로 정점을 방문하느냐에 따라 서로 다른 트리가 생성될 수 있고
그에 따라 각 간선의 구분이 달라질 수 있다.

무향 그래프에서는 교차 간선이 있을 수 없고
순방향 간선과 역방향 간선의 구분이 없다.
*/

/*
        간선을 구분하는 방법
탐색 과정에서 각 정점을 방문한 적이 있는지 여부 외에 다른 정보를 저장해야 한다.
한 가지 방법은 각 정점을 방문할 때 이 정점이 방문되었다는 사실 뿐만 아니라,
이 정점이 몇 번째로 발견되었는지도 동시에 기록하는 것이다.

탐색 과정에서 각 정점을 몇 번째로 발견했느지를 배열 discovered[]에 저장한다고 하자.
이 정보를 이용해서 순방향과 역방향 그리고 교차 간선을 구분해낼 수 있을까?
간선 (u, v)를 검사했는데, v가 이미 방분된 상태였다고 하자. 
이때 u와 v의 방문 순서를 이용해 (u, v)를 분류할 수 있는가?

(u, v) 가 순방향 간선이라면 v는 u의 자손이어야 한다.
따라서 v는 u보다 더 늦게 발견되어야 한다.

(u, v) 가 역방향 간선이려면 v는 u의 선조여야 한다.
따라서 v는 u보다 더 일찍 발견되었어야 한다.

(u, v) 가 교차 간선이라면 dfs(v)가 종료한 후 dfs(u)가 호출되어야 한다.
따라서 v는 u보다 일찍 발견되었어야 한다.

이처럼 발견 순서 정보를 이용하면 해당 간선이 순방향 간선인지를 알아낼 수 있다.
반면 v가 u보다 먼저 방문되었다면 v가 u의 부모인지 아닌지를 구분할 방법이 없다.
이와 같은 경우를 구분하는 한 가지 방법은 dfs(v)가 종료햇는지를 확인하는 것이다.
dfs(v)가 종료하지 않았다면 v는 u의 선조이니 (u, v)는 역방향 간선이 되고,
아니면 교차 간선이 된다.
*/

// 간선을 구분하는 dfs
vector<vector<int> > adj;
// discovered[i] = i번 정점의 발견 순서(-1 로 초기화)
// finished[i] = dfs(i) 가 종료했으면 1, 아니면 0
vector<int> discovered, finished;
// 지금까지 발견한 정점의 수
int counter;
void dfs2(int here){
    discovered[here] = counter++;
    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i];
        cout << "(" << here "," << there << ") is a ";
        // 아직 방문한 적 없다면 방문한다.
        if(discovered[there] == -1){
            cout << "tree edge" << endl;
            dfs2(there);
        }
        // 방문한 적 있다면,
        
        // 만약 there가 here보다 늦게 발견됐으면 there는 here의 후손이다
        else if(discovered[here] < discovered[there])
            cout << "forward edge" << endl;
        // 만약 dfs2(there)가 아직 종료하지 않았으면 there는 here의 선조다.
        else if(finished[there] == 0)
            cout << "back edge" << endl;
        // 이 외의 경우는 모두 교차 간선.
        else
            cout << "cross edge" << endl;
    }
    finished[here] = 1;
}
