#include <iostream>


/*
	@input
2		// test case C (C <= 60)
6 4		// 인형 상자의 수 N(1<=N), 어린이의 수 K(K<=100000)
1 2 3 4 5 6	// 각 인형 상자에 있는 인형의 개수 D_i(0<=i<=N-1,1<=D_i<=100000)
4 1		
1 2 3 4		

	@output
3 1
10 4

MOD 20091101
*/

int ways_to_but(const vector<int>& psum, int k){
	const int MOD = 20091101;
	int ret = 0;

	//psum[]의 각 값을 몇 번이나 본 적이 있는지 기록한다.
	vector<long long> count(k, 0);
	for(int i = 0; i < psum.size(); ++i)
		count[psum[i]]++;

	for(int i = 0; i < k; ++i)
		if(count[i] >= 2)
			ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % MOD;
	return ret;	
}

// D[] 의 부분 합 배열 psum[]과 k가 주어질 때, 겹치지 않게 몇 번이나 살 수 있는지 반환한다.
// psum[]의 첫 번째 원소 전에 0을 삽입한다고 가정한다.

int maxBuys(const vector<int>& psum, int k){
	// ret[i] = 첫 번째 상자부터 i 번째 상자까지 고려했을 때 살 수 있는 최대 횟수
	vector<int> ret(psum.size(), 0);
	// prev[s] = psum[]이 s였던 마지막 위치
	vector<int> prev(k, -1);

	for(int i = 0; i < psum.size(); ++i){
		//i 번째 상자를 아예 고려하지 않는 경우
		if(i > 0)
			ret[i] = ret[i-1];
		else
			ret[i] = 0;
		// psum[i]를 전에도 본 적이 있으면, prev[psum[i]] + 1 부터 여기까지 쭉 사본다.
		int loc = prev[psum[i]];
		if(loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
		prev[psum[i]] = i;
	}
	return ret.back();
}

int main(){

}

