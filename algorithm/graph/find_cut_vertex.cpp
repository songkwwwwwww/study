/*
참조 :
    알고리즘 문제 해결 전략(종만북)
*/
/*
절단점(Cut vertex) :
어떤 무향 그래프의 절단점이란 이 점과 인접한 간선들믕 모두 지웠을 때
해당 컴포넌트가 두 개 이상으로 나뉘어지는 정점을 말한다.

컴포넌트의 개수는 깊이 우선 탐색으로 간단하게 셀 수 있다.
모든 정점의 절단점 여부를 확인하려면 dfs를 |V|번 수행해야 하는가?
탐색 과정에서 얻는 정보를 잘 이용하면 한 번의 깊이 우선 탐색만으로
그래프의 모든 절단점을 찾아낼 수 있다.

깊이 우선 탐색을 이용해 풀 수 있는 응용 문제.
*/

/*
임의의 정점에서부터 dfs를 수행해 dfs spanning tree를 만든다.
이때 어떤 정점 u가 절단점인지를 어떻게 알 수 있는가?
무향 그래프의 스패닝 트리에서는 교차 간선이 없으므로
u와 연결된 정점들은 모두 u의 선조 아니면 자손이다.

무향 그래프에는 교차 간선이 있을 수 없기 때문에
u가 지워졌을 때 그래프가 쪼개지지 않는 유일한 경우는
u의 선조와 u의 자손들이 전부 역방향 간선으로 연결되어 있을 때 뿐이다.

이것을 확인하는 간단한 방법은 dfs를 수행하는 함수가 
각 정점을 루트로 하는 서브트리에서 역방향 간선을 통해 갈 수 있는 정점의 최소 깊이를
반환하도록 하는 것이다.

만약 u의 자손들이 모두 역방향 간선을 통해 u의 선조로 올라갈 수 있다면
 u는 절단점이 아니다.

만약 u가 스패닝트리의 루트라서 선조가 없다면?
u는 무조건 절단점이라고 생각하기 쉽지만 예외가 있다.
이는 자손이 하나이거나 하나도 없는 경우이다. 
이 경우에 u가 없어져도 그래프는 쪼개지지 않는다.
따라서 이 경우 u가 둘 이상의 자손을 가질 때만 절단점이 된다.
*/


vector<vector<int> > adj;
// 각 정점의 발견 순서. -1로 초기화한다.
vector<int> discovered;
vector<bool> is_cut_vertex;
int counter = 0;

// here를 루트로 하는 서브트리에 있는 절단점들을 찾는다.
// 반환 값은 해당 서브트리에서 역방향 간선으로 갈 수 있는 정점 중
// 가장 일찍 발견된 정점의 발견 시점. 처음 호출할 때는 is_root = true로 둔다.
int find_cur_vertex(int here, bool is_root){
    // 발견 순서를 기록한다.
    discovered[here] = counter++;
    int ret = discovered[here];

    // 루트인 경우 절단점 판정을 위해 자손 서브트리의 개수를 센다.
    int children = 0;
    for(int i = 0; i < adj[here].size(); i++){
        int there = adj[here][i];
        // 방문하지 않은 정점이라면
        if(discovered[there] == -1){
            children++;
            // 이 서브트리에서 갈 수 있는 가장 높은 정점의 번호
            int sub_tree = find_cur_vertex(there, false);
            // 그 노드가 자기 자신 이하에 있다면 현재 위치는 절단점
            if(!is_root && sub_tree >= discovered[here])
                is_cut_vertex[here] = true;
            ret = min(ret, sub_tree);
        }
        // 방문한 정점이라면
        else
            ret = min(ret, discovered[there]);
    }
    // 루트인 경우 절단점 판정은 서브트리의 개수로 한다.
    if(is_root) is_cut_vertex[here] = (children >= 2);
    return ret;
}