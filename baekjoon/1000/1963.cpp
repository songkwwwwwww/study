#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs
using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

int dist[10001];
bool visited[10001];
bool prime[10001];



int change(int num, int index, int digit) {
    if (index == 0 && digit == 0) return -1;
    string s = to_string(num);
    s[index] = digit+'0';
    return stoi(s);
}

int main(){
    freopen("1963.txt", "r", stdin);
    int TC; 
    scanf("%d", &TC);
    memset(prime, true, sizeof(prime));
    for(int i = 2; i <= 10000; i++){
        if(prime[i] == true){
            for(int j = i * i; j <= 10000; j += i){
                prime[j] = false;
            }
        }
    }
    for(int tc = 1; tc <= TC; tc++){
        int x, y;
        scanf("%d %d", &x, &y);
        memset(dist, 0, sizeof(dist));
        memset(visited, false, sizeof(visited));
        dist[x] = 0;
        visited[x] = true;
        queue<int> q;
        q.push(x);
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                for(int j = 0; j <= 9; j++){
                    int next = change(now, i, j);
                    if(next != -1 && prime[next] && visited[next] == false){
                        q.push(next);
                        dist[next] = dist[now] + 1;
                        visited[next] = true;
                    }
                }
            }
        }
        printf("%d\n", dist[y]);
    }
}