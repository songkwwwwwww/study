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

const int MAX = 200000;
bool visited[MAX + 1];

/*
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
*/
int main(){
    freopen("1697.txt", "r", stdin);
    int N; // 수민이의 현재 위치 N (0 <= N <= 10,0000)
    int K; // 동생의 위치 K (0 <= K <= 10,0000)
    scanf("%d %d", &N, &K);
    visited[N] = true;
    queue< pair<int, int> > q;
    q.push(make_pair(N, 0));
    pair<int, int> now;
    while(!q.empty()){
        //now.fist = current_location;
        //now.second = current_time;
        now = q.front(); q.pop();
        int current_location = now.first; 
        int current_time = now.second;
        if(current_location == K){ 
            break;
        }
        if (current_location - 1 >= 0 && 
            visited[current_location - 1] == false) {
            
            q.push(make_pair(current_location - 1, current_time + 1));
            visited[current_location - 1] = true;
        }

        if (current_location + 1 <= 200000 && 
            visited[current_location + 1] == false) {
            
            q.push(make_pair(current_location + 1, current_time + 1));
            visited[current_location + 1] = true;
        }

        if (current_location * 2 <= 200000 && 
            visited[current_location * 2] == false) {
            
            q.push(make_pair(current_location * 2, current_time + 1));
            visited[current_location * 2] = true;
        }
    }
    cout << now.second << endl;
}