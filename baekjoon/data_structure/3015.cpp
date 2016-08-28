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


int main(){
    freopen("3015.txt", "r", stdin);    
    int N; // 1 <= N <= 50,0000
    scanf("%d", &N);
    int a[500000];
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);

    stack<int> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(!s.empty()){
            if(s.top() < a[i]){
                ans++;
                s.pop():
            }
            else
                break;
        }
        if(!s.empty()) ans++;
        s.push(a[i]);
    }
    printf("%d\n", ans);
}