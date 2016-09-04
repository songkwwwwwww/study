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
첫 줄에 test case의 수가 주어진다. 
각 test case에 대해서 문서의 수 N(100이하)와 몇 번째로 인쇄되었는지 
궁금한 문서가 현재 Queue의 어떤 위치에 있는지를 알려주는 M(0이상 N미만)이 주어진다. 
다음줄에 N개 문서의 중요도가 주어지는데, 중요도는 적절한 범위의 int형으로 주어진다. 
중요도가 같은 문서가 여러 개 있을 수도 있다. 
위의 예는 N=4, M=0(A문서가 궁금하다면), 중요도는 2 1 4 3이 된다.

출력
각 test case에 대해 문서가 몇 번째로 인쇄되는지 출력한다.
*/
int TC, N, M;

int cmp(int a, int b){
    if( a > b )
        return true;
    else
        return false;
}
int main(){
    freopen("1966.txt", "r", stdin);
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        // <priority, index>
        queue<pair<int, int> > q;
        vector<int> v(N);
        
        for(int i = 0; i < N; i++){
            int priority;
            scanf("%d", &priority);
            q.push(make_pair(priority, i));
            v[i] = priority;
        }
        sort(v.begin(), v.end(), cmp);
        int p = 0;

        while(!q.empty()){
            
            if(v[p] == q.front().first){
                p++;
                if(q.front().second == M) break;
                q.pop();
            }
            else{
                pair<int, int> temp = q.front(); q.pop();
                q.push(temp);
            }
        }
        printf("%d\n", p);
    }
}