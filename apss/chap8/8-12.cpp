/*
	Longest Increasing Subsequence Problem

	http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/

	http://www.cplusplus.com/reference/vector/vector/

*/

#include <iostream> // std::cout

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>

#include <algorithm> // std::max


int cache[101];



int lis3(std::vector<int>& v, int start){
	int& ret = cache[start + 1];
	if(ret != -1) return ret;

	ret = 1;
	for(int next = start + 1; next < v.size(); ++next)
		if(start == -1 ||  v.at(start) < v.at(next))
			ret = std::max(ret, lis3(v, next) + 1);
	return ret;
}

int main(){
	using namespace std;
	memset(cache, -1, sizeof(cache));

	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
	std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

	int maxLen = lis3(vec, 0);

	cout<< "result : " << maxLen << endl;

}
