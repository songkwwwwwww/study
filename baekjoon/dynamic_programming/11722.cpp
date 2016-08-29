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
문제
수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 
가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.
*/
/*
 처리과정
 dp[n] : n번째에서 가장 긴 감소 수열의 합
 1. 위치의 배열 값과 비교한다.
 2. 현재 위치가 더 작다면
    2.1 배열의 길이를 갱신한다
 3. 가장 긴 길이를 출력한다.
 4. 끝낸다.
*/
int N;
int arr[1001];
int d[1001];



int calc(int index){
	int& ret = d[index + 1];
	if(ret != -1) return ret;

	ret = 1;
	for(int next = index + 1; next < N; next++){
		if(index == -1 || arr[index] > arr[next])
			ret = MAX(ret, calc(next) + 1);
	}
	return ret;	
}


int main(){
    freopen("11722.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    memset(d, -1, sizeof(d));
    printf("%d\n", calc(-1) - 1);
}