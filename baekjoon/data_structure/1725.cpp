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
같은 문제 : boj/6549

입력
첫 행에는 N (1 <= N <= 100,000) 이 주어진다. 
N은 히스토그램의 가로 칸의 수이다. 
다음 N 행에 걸쳐 각 칸의 높이가 왼쪽에서부터 차례대로 주어진다.

출력
첫째 줄에 가장 큰 직사각형의 넓이를 출력한다. 이 값은 20억을 넘지 않는다.
*/
int N;
int a[100000];
int main(){
    freopen("1725.txt", "r", stdin);
    scanf("%d", &N);
    stack<int> s;
    int ans = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
        int left = i;
        while(!s.empty() && a[s.top()] > a[i]){
            int height = a[s.top()];
            s.pop();;
            int width = i;
            if(!s.empty()) width = (i - s.top() - 1);
            if(ans < width * height) ans = width * height;
        }
        s.push(i);
    }
    while(!s.empty()){
        int height = a[s.top()];
        s.pop();
        int width = N;
        if(!s.empty()){
            width = N - s.top() - 1;
        }
        if( ans < width * height)
            ans = width * height;
    }
    printf("%d\n", ans);
}