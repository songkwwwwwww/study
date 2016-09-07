#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <stack>
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

#include <map>
//#include <unordered_map>

#include <utility> // std::pair

#include <functional> // greater, less
#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
입력
첫째 줄에는 정수 N(3≤N≤100)이 주어지는데, 1부터 N-1까지는 기본 부품이나 중간 부품의 번호를 나타내고, N은 완제품의 번호를 나타낸다. 
그리고 그 다음 줄에는 정수 M(3≤M≤100)이 주어지고, 그 다음 M개의 줄에는 어떤 부품을 완성하는데 필요한 부품들 간의 관계가 3개의 정수 X, Y, K로 주어진다. 
이 뜻은 "중간 부품이나 완제품 X를 만드는데 필요한 중간 부품 혹은 기본 부품 Y가 K개 필요하다"는 뜻이다.

출력
하나의 완제품을 조립하는데 필요한 기본 부품의 수를 한 줄에 하나씩 출력하되(중간 부품은 출력하지 않음), 반드시 기본 부품의 번호가 작은 것부터 큰 순서가 되도록 한다. 각 줄에는 기본 부품의 번호와 소요 개수를 출력한다.
*/

const int MAX_N = 100;
const int MAX_M = 100;
int N, M;

vector< pair<int, int> > adj[MAX_N];
int in_degree[MAX_N];
int need[MAX_N][MAX_N];

int main(){
    freopen("2637.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int X, Y, K, i = 0; i < M; i++){
        scanf("%d %d %d", &X, &Y, &K);
        X--; Y--;
        adj[Y].push_back(make_pair(X, K));
        in_degree[X]++;
    }
    queue<int> q;
    vector<int> basic_item;
    basic_item.reserve(50);
    for(int i = 0; i < N; i++)
        if(in_degree[i] == 0){
            q.push(i);
            basic_item.push_back(i);
            need[i][i] = 1;
        }

    while(!q.empty()){
        int here = q.front(); q.pop();

        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int weight = adj[here][i].second;
            in_degree[there]--;
            for(int j = 0; j < basic_item.size(); j++)
                need[there][basic_item[j]] += need[here][basic_item[j]] * weight;
            
            if(in_degree[there] == 0)
                q.push(there);
        }
    }
    
    for(int i = 0; i < basic_item.size(); i++)
        printf("%d %d\n", i + 1, need[N - 1][basic_item[i]]);

}

