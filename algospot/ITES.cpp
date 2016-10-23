/*
문제

수환이는 외계에서 날아오는 전파를 연구하는 범세계 대규모 프로젝트, ITES@home에 참가하고 있습니다. 외계에서 날아오는 전파는 전처리를 거쳐 각 숫자가 [1,10000] 범위 안에 들어가는 자연수 수열로 주어지는데, 이 전파가 과연 단순한 노이즈인지 아니면 의미 있는 패턴을 가지고 있는 것인지를 파악하고 싶습니다. 수환이는 전파의 부분 수열 중에 합이 K인 것이 유독 많다는 것을 눈치챘습니다. 부분 수열이란 연속된 수열의 일부를 말합니다. 예를 들어 수열 {1,4,2,1,4,3,1,6} 에서 합이 7 인 부분 수열은 모두 5개 있습니다. {1,4,2} , {4,2,1} , {2,1,4}, {4,3}, {1,6} 이 부분 수열들은 서로 겹쳐도 된다는 데 유의합시다.

K가 외계인에게 의미 있는 숫자일까요? 수환이의 가설을 확인하기 위해, 길이 N인 신호 기록이 주어질 때 합이 K인 부분 수열이 몇 개나 있는지 계산하는 프로그램을 작성하세요.

입력 생성

입력의 크기가 큰 관계로, 이 문제에서는 신호 기록을 입력받는 대신 다음과 같은 식을 통해 프로그램 내에서 직접 생성합니다.

A[0] = 1983
A[i] = (A[i-1] * 214013 + 2531011) % 232
이 때 i(1 <= i <= N)번째 입력 신호는 A[i-1] % 10000 + 1입니다.
문제의 해법은 입력을 생성하는 방식과는 아무 상관이 없습니다. 
이 규칙에 따르면 첫 5개의 신호는 각각 1984, 8791, 4770, 7665, 3188입니다.

입력

입력 파일의 첫 줄에는 테스트 케이스의 수 C (1 <= C <= 20)가 주어지고, 
그 후 C 줄에 각 2개의 정수로 K(1 <= K <= 5,000,000) 과 N(1 <= N <= 50,000,000) 이 주어집니다.

출력

각 테스트 케이스마다 한 줄에 첫 N 개의 신호 중 합이 K 인 구간의 수를 출력합니다.
*/
#include <iostream>
#include <queue>
#include <cstdio>	// freopen

// code 19.6
class RNG{
public:
	unsigned seed;
	RNG() : seed(1983){}
	unsigned next(){
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

// code 19.5
int count_ranges(int k, int n){
	RNG rng;
	std::queue<int> range;
	int ret = 0, range_sum = 0;
	for(int i = 0; i < n; i++){
		int new_signal = rng.next();
		range_sum += new_signal;
		range.push(new_signal);
		while(range_sum > k){
			range_sum -= range.front();
			range.pop();			
		}
		if(range_sum == k) ret++;
	}
	return ret;
}

int main(){
	int TC, k, n;		// 1<= TC <= 20

	freopen("ITES.txt", "r", stdin);
	
	std::cin >> TC;
	for(int i = 0; i < TC; i++){
		std::cin >> k >> n;	// 1<= K <= 5,000,000 	
		std::cout << count_ranges(k, n) << std::endl;
	}
	
}





/*
	- code 19.4

int optimized(const vector<int>& signals, int k){
	int ret = 0, tail = 0, range_sum = signals[0];
	for(int head = 0; head <signals.size(); ++head){
		while(range_sum < k && tail + 1 < signals)
			range_sum += signals[++tail];
		if(range_sum == k) ret++;
		range_sum -= signals[head];
	}
	return ret;
}
*/

