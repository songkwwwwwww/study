#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*

*/
int N; // 1 <= N <= 100

vector<vector<int> > adj;
vector<string> graph[26][26];

vector<int> in_degree, out_degree;

void make_graph(const vector<string>& words){
    // 그래프 초기화
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            graph[i][j].clear();

    adj = vector<vector<int> >(26, vector<int>(26, 0));
    in_degree = out_degree = vector<int>(26, 0);
    for(int i = 0; i < words.size(); i++){
        int a = words[i][0] - 'a';
        int b = words[i][words[i].size() - 1] - 'a';
        graph[a][b].push_back(words[i]);
        adj[a][b]++;
        out_degree[a]++;
        in_degree[b]++;
    }
}

// 유향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷 혹은 트레일을 계산한다.
void get_euler_circuit(int here, vector<int>& circuit){
    for(int there = 0; there < adj.size(); there++)
        while(adj[here][there] > 0){
            // 이 문제는 방향 그래프이기 때문에 양 쪽 간선을 지우지 않는다.
            adj[here][there]--;
            get_euler_circuit(there, circuit);
        }
    circuit.push_back(here);
}

// 현재 그래프의 오일러 트레일이나 서킷을 반환한다.
vector<int> get_euler_trail_or_circuit(){
    vector<int> circuit;
    // 우선 트레일을 찾아본다. 시작점을 찾는 경우
    for(int i = 0; i < 26; i++){
        if(out_degree[i] == in_degree[i] + 1){
            get_euler_circuit(i, circuit);
            return circuit;
        }
    }

    // 아니면 서킷이니 간선에 인접한 아무 정점에서나 시작한다.
    for(int i = 0; i < 26; i++){
        if(out_degree[i]){
            get_euler_circuit(i, circuit);
            return circuit;
        }
    }

    // 모두 실패한 경우 빈 배열을 반환한다.
    return circuit;
}

bool check_euler(){
    // the number of plus1, minus1;
    int plus1 = 0, minus1 = 0;
    for(int i = 0; i < 26; i++){
        int delta = out_degree[i] - in_degree[i];
        // 모든 정점의 차수는 -1, 1 또는 0이어야 한다.
        if(delta < -1 || 1 < delta) return false;
        if(delta == 1) plus1++;
        if(delta == -1) minus1++;
    }

    // 시작점과 끝 점은 각 하나씩 있거나 하나도 없어야 한다.
    return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

string solve(const vector<string>& words){
    make_graph(words);
    // 차수가 맞지 않으면 실패!
    if(!check_euler()) return "IMPOSSIBLE";
    // 오일러 서킷이나 경로를 찾아낸다.
    vector<int> circuit = get_euler_trail_or_circuit();
    // 모든 간선을 방문하지 못했으면 실패!
    if(circuit.size() != words.size() + 1) return "IMPOSSIBLE";

    // 아닌 경우 방문 순서를 뒤집은 뒤 간선들을 모아 문자열로 만들어 반환한다.
    reverse(circuit.begin(), circuit.end());
    string ret;
    for(int i = 1; i < circuit.size(); i++){
        int a = circuit[i - 1], b = circuit[i];
        if(ret.size()) ret += " ";
        ret += graph[a][b].back();
        graph[a][b].pop_back();
    }
    return ret;
}
int main(){
    freopen("WORDCHAIN.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        cin >> N;
        vector<string> words;
        for(int i = 0; i < N; i++){
            string s;
            cin >> s;
            words.push_back(s);
        }
        cout << solve(words) << endl;
    }
}