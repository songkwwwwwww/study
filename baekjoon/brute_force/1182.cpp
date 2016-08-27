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

/*
서로 다른 N개의 정수로 이루어진 집합이 있을 때, 
이 집합의 공집합이 아닌 부분집합 중에서 그 집합의 원소를 다 더한 값이 S가 되는 
경우의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. 
(1≤N≤20, |S|≤1,000,000) 
둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 
주어지는 정수의 절대값은 100,000을 넘지 않는다.
*/

int N, S;

int go(vector<int>& v, int index, int current_sum){
   if(index == v.size()){
       if(current_sum == S) 
            return 1;
       else 
            return 0; 
   }
   return go(v, index + 1, current_sum) + go(v, index + 1, current_sum + v[index]);
}

int main(){
    freopen("1182.txt", "r", stdin);
    scanf("%d %d", &N, &S);
    vector<int> v(N);
    for(int i = 0; i < N; i++) scanf("%d", &v[i]);

    for(int i = 0; i < N; i++) printf("%d ", v[i]);
    printf("\n");
    int ans = go(v, 0, 0);
    if(S == 0) ans--;
    cout << ans << endl;
}
