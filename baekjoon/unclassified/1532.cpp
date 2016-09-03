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
#include <utility> // std::pair

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*
입력
첫째 줄에 G1 S1 B1이 들어오고, 둘째 줄에 G2 S2 B2가 들어온다. 모든 값은 1,000,000보다 작거나 같은 자연수이거나 0이다.

출력
첫째 줄에 정답을 출력한다. 못 바꾸는 경우에는 -1을 출력한다.
*/

/*
G 1 -> S 9
G 1 <- S 11

S 1 >- B 9
S 1 <- B 11
*/



int dx[4] = {-1, 1, 0, 0};
int dy[4] = {9, -11, -1, 1};
int dz[4] = {0, 0, 9, -11};

class state{
public:
    int g;
    int s;
    int b;
    state(int a, int b, int c){
        g = a;
        s = b;
        b = c;
    }
    vector<state> get_adjacent() const{
        vector<State> v;
        if(g >= 1)
            v.push(state(g - 1, s + 9, b));
        if(s >= 11)
            v.push(state(g + 1, s - 11, b));
        if(s >= 1)
            v.push(state(g, s - 1, b + 9));
        if(b >= 11)
            v.push(state(g, s + 1, b - 11));
    }

    bool operator<(const State& &rhs) const{
        if(g <= rhs.g){
            if(s <= rhs.s){
                if(b <= rhs.b) 
                    return true;
                else // b > rhs.b
                    return false;
            }
            else // s > rhs.s
                return false;
        }
        else // g > rhs.g
            return false;
    }

    bool operator==(const State& rhs) const{
        if(g == rhs.g && s == rhs.s && b == rhs.b)
            return true;
        else 
            return false;
    }
};


int sgn(int x){
    if(!x) return 0;
    else return x > 0 ? 1 : -1 ;
}

int incr(int x){
    if(x < 0) return x - 1;
    else return x + 1;
}

int solve(state start, state finish){
    // 각 정점까지의 최단 경로 길이를 저장한다.
    map<state, int> c;
    // 앞으로 방문할 정점들을 저장한다.
    queue<pair<state, bool>> q;
    // 시작 상태와 목표 상태가 같은 경우는 예외 처리.
    if(start == finish) return 0;
    q.push( make_pair(start, true) ); c[start] = 1;
    q.push( make_pair(finish, false) ); c[finish] = -1;

    // 너비 우선 탐색 시작
    while(!q.empty()){
        state here = q.front().first; 
        bool direction = q.front().second;
        q.pop();
        
        // 인접한 상태들을 검사
        vector<state> adjacent = here.get_adjacent();
        for(int i = 0; i < 4; i++){
            if(now.g + dx[i] >=)
        }
    }
    // 답을 찾지 못한 경우
    return -1;
}


int main(){
    freopen("1532.txt", "r", stdin);
    int G1, S1, B1, G2, S2, B2;

    scanf("%d %d %d %d %d %d", &G1, &S1, &B1, &G2, &S2, &B2);
    
    int count = 0;
    
}



// 만들 수 있는 동화의 총 개수
    int total_b = (((G1 * 9) + S1) * 9) + B1;
    // 목표치의 총 동화 개수
    int target_b = (((G2 * 9) + S2) * 9) + B2;
    
    // 만들 수 있는 경우.
    if(total_b >= target_b){
        solve(state(G1, S1, B1), state(G2, S2, B2));
    }
    // 만들지 못하는 경우
    else{
        printf("-1\n");
    }





/*




*/