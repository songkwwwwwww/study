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
첫째 줄에 멜로디에 포함되어 있는 음의 수 N과 한 줄에 있는 프렛의 수 P가 주어진다. 
(N ≤ 500,000, 2 ≤ P ≤ 300,000)

다음 N개 줄에는 멜로디의 한 음을 나타내는 두 정수가 주어진다. 
첫 번째 정수는 줄의 번호이고 두 번째 정수는 그 줄에서 눌러야 하는 프렛의 번호이다. 
입력으로 주어진 음의 순서대로 기타를 연주해야 한다.

출력
첫째 줄에 멜로디를 연주하는데 필요한 최소 손가락 움직임을 출력한다.
*/
int N, P;

int main(){
    freopen("2841.txt", "r", stdin);
    stack<int> s[6];
    int count = 0, l, p;
    
    scanf("%d %d", &N, &P);

    for(int i = 0; i < N; i++){
        scanf("%d %d", &l, &p);
        if(s[l - 1].empty() || s[l - 1].top() < p){
            s[l - 1].push(p);
            count++;
        }
        // s[l - 1].top() >= p
        else{ 
            while(!s[l - 1].empty() && s[l - 1].top() > p){
                s[l - 1].pop();
                count++;
            }

            if(s[l - 1].empty() || s[l - 1].top() != p){
                s[l - 1].push(p);
                count++;
            }
            
        }
    }
    printf("%d\n", count);
}