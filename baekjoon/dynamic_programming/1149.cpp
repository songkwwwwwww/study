#include <iostream>
#include <cstdio>
#include <cstring>

/*

RGB distance
( https://www.acmicpc.net/problem/1149 )

@input
3			// N <= 1000, the number of houses
26 40 83	// R, G, B 
49 60 57
13 89 99

@output
96
*/

int num_of_houses, cost_table[1000][3], cache[1001][3];

int min(int x, int y) { 
	return x < y ? x : y; 
}


/*
	 Memoization (Top Down):
	 assume that a cache array is initialized to -1 
*/
int select(int current_index, int color) {
	
	// base case
	if (current_index == num_of_houses) return 0;
	
	int& ret = cache[current_index][color];

	// is it cached? then return
	if (ret != -1) return ret;
	
	// otherwise...
	int result = 987654321;

	for (int i = 1; i <= 2; i++) {
		result = min(result, cost_table[current_index][color] + select(current_index + 1, (color + i) % 3) );
	}
	// cache
	ret = result;
	
	return ret;
}
void calc() {
	// otherwise...
	int result = 987654321;

	for (int color = 0; color < 3; color++) {
		result = min(result, select(0, color));
	}
	printf("%d", result);
}

int main() {
	using std::cout;
	using std::endl;

	if (freopen("1149.txt", "r", stdin) == NULL)
		cout << "fileopen failed" << endl;
	
	scanf("%d", &num_of_houses);
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < num_of_houses; i++) {
		scanf("%d %d %d", &cost_table[i][0], &cost_table[i][1], &cost_table[i][2]);
	}
	calc();
	return 0;
}
