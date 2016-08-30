/*
참조 :
    알고리즘 문제 해결 전략(종만북)
*/
/*
	오일러 서킷(Eulerian circuit) :
	그래프의 모든 간선을 정확히 한 번씩 지나서 시작점으로 돌아오는 경로
	dfs를 이용해 풀 수 있는 유명한 문제.

	모든 정점이 짝수점이면서 간선들이 하나의 컴포넌트에 포함된 그래프가 주어질 때는
	항상 오일러 서킷을 찾아내는 알고리즘을 만들 수 있습니다.
	
*/

vector<vector<int> > adj;

// time complexcity : O(|V||E|)

void get_euler_circuit(int here, vector<int>& circuit){
	for(int there = 0; there < adj.size(); there++){
		while(adj[here][there] > 0){
			adj[here][there]--;
			adj[there][here]--;
			get_euler_circuit(there, circuit);
		}
	}	
	circuit.push_back(here);
}
