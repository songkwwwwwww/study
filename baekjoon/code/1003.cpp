#include <iostream>
#include <cstdio>
/*

@input
3
0
1
3

@output
1 0
0 1
1 2

*/
int main() {
	using std::cout;
	using std::endl;

	if (freopen("input.txt", "r", stdin) == NULL)
		cout << "fileopen failed" << endl;

	int TC;
	int n;  //  0 <= N <= 40 
	scanf("%d", &TC);

	for (int i = 0; i < TC; i++) {
		scanf("%d", &n);
		int zero_count[3] = { 1, 0, 1 };
		int one_count[3] = { 0, 1, 1 };

		if (n >= 0 && n <= 2) {
			cout << zero_count[n % 3] << " " << one_count[n % 3] << endl;
		}
		else if (n >= 3) {
			for (int i = 3; i <= n; i++) {
				zero_count[i % 3] = zero_count[(i - 1) % 3] + zero_count[(i - 2) % 3];
				one_count[i % 3] = one_count[(i - 1) % 3] + one_count[(i - 2) % 3];
			}
			cout << zero_count[n % 3] << " " << one_count[n % 3] << endl;
		}

	}

}