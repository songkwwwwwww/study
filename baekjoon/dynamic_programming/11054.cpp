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
입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. 
(1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.
*/
/*
 처리과정
 dp[n] = n번째 가장 긴 증가 부분 수열의 길이
 dp2[n] =n번째 가장 긴 감소 부분 수열의 길이
 1. 해당 위치까지 제일 긴 증가 부분 수열을 구한다.
 2. 끝에서 해당 위치까지 제일 긴 감소 부분 수열을 구한다.
 3. 최대 값을 구한다.
 4. 출력한다.
 5. 끝낸다.
*/
int N;
int a[1001];
int d1[1001]; // 오름차순
int d2[1001]; // 내림차순

int main(){
    freopen("11054.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &a[i]);

    for(int i = 1; i <= N; i++){
        d1[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[j] < a[i] && d1[i] < d1[j] + 1)
                d1[i] = d1[j] + 1;
        }
    }
    for(int i = N; i >= 1; i--){
        d2[i] = 1;
        for(int j = N; j > i; j--){
            if(a[i] > a[j] && d2[i] < d2[j] + 1)
                d2[i] = d2[j] + 1;
        }
    }


    int ans = 0;
    for(int i = 1; i <= N; i++)
        ans = MAX(ans, d1[i] + d2[i] - 1);
    printf("%d\n", ans);
}