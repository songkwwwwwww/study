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

const int MAX_N = 10000;

bool visited[MAX_N];
int from[MAX_N];
char how[MAX_N];

void print(int start, int end) {
    if (start == end) return;
    print(start, from[end]);
    printf("%c", how[end]);
}

int main(){
    freopen("9019.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        int start, end;
        scanf("%d %d", &start, &end);
        
        memset(visited, false, sizeof(visited));
        visited[start] = true;
        from[start] = -1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int now = q.front(); q.pop();

            if(now == end) break;

            // Case 'D'
            int next = (now * 2) % 10000;
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                from[next] = now;
                how[next] = 'D';
            }

            // Case 'S'
            next = (now - 1 + 10000) % 10000;
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                from[next] = now;
                how[next] = 'S';
            }

            // Case 'L'
            next = (now % 1000) * 10 + (now / 1000);
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                from[next] = now;
                how[next] = 'L';
            }

            // Case 'R'
            next = (now % 10) * 1000 + (now / 10);
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                from[next] = now;
                how[next] = 'R';
            }
        }
        print(start, end);
        printf("\n");
    }
    return 0;
}