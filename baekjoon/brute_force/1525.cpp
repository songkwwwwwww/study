#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <map>

#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

const int N = 3;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};



int main(){
    freopen("1525.txt", "r", stdin);
    int start = 0;
    for(int i = 0; i < 9; i++){
        int in;
        scanf("%d", &in);
        if(in == 0) in = 9;
        start = start * 10 + in;
    }
    

    map<int, int> dist;
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int now = q.front(); q.pop();    
        string s = to_string(now);

        int z = s.find('9');
        int x = z / N;
        int y = z % N;
        
        for(int direction = 0; direction < 4; direction++){
            int nx = x + dx[direction];
            int ny = y + dy[direction];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                string next = s;
                swap(next[x * N + y], next[nx * N + ny]);
                int num = stoi(next);
                if(dist.count(num) == 0){
                    dist[num] = dist[now] + 1;
                    q.push(num);
                }
            }
        }
    }
    if(dist.count(123456789) == 0)
        printf("-1\n");
    else
        printf("%d\n", dist[123456789]);
}