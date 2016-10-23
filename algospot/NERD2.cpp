#include <iostream>
#include <cstdio>

#include <map>

/*

NERD2
( https://algospot.com/judge/problem/read/NERD2 )

@input
2
4
72 50
57 67
74 55
64 60
5
1 5
2 4
3 3
4 2
5 1

@output
8
15

*/

std::map<int, int> coords;


bool is_dominated(int x, int y) {
	// x보다 오른쪽에 있는 점 가장 왼쪽에 있는 점을 찾는다.
	std::map<int, int>::iterator it = coords.lower_bound(x);

	// 그런 점이 존재하지 않으면 (x, y)는 지배당하지 않는다.
	if (it == coords.end()) return false;

	// 그런 점이 존재하면 y 높이에 따라 지배 여부가 달라진다.
	return y < it->second;
}

// 새로운 점 (x, y)에 지배당하는 점들을 지운다.
void remove_dominated(int x, int y) {
	std::map<int, int>::iterator it = coords.lower_bound(x);

	// 지배당하는 점이 존재하지 않는다.
	if (it == coords.begin()) return ;

	// 지배 당하는 점이 존재하면
	--it;

	while (true) {

		// 지배당하지 않는 점을 만나면 종료
		if (it->second > y) break;

		// 지배당하는 점을 가리키는 포인터가 맨 처음 점이라면
		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		else {
			std::map<int, int>::iterator cur = it;
			--it;
			coords.erase(cur);
		}
	}

}

// 새 점(x, y)가 추가되었을 때 coords를 갱신하고 
// 다른 점에 지배당하지 않는 점들의 개수를 반환한다
int registered(int x, int y) {
	// 추가되는 점이 지배당한다면 무시해도 된다.
	if (is_dominated(x, y)) return coords.size();

	// 기존 점들을 지배한다면, 지배당하는 기존 점들을 제거한다
	remove_dominated(x, y);

	// 새 점(x, y)을 추가한다
	coords[x] = y;

	// 갱신된 개수를 반환한다.
	return coords.size(); 
}

int main() {
	using std::cout;
	using std::endl;

	if (freopen("NERD2.txt", "r", stdin) == NULL)
		cout << "fileopen failed" << endl;
	
	int TC;
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		int N, p, q, result = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d %d", &p, &q);// p_i, q_i
			result += registered(p, q);
		}
		cout << result << endl;
		coords.clear();
	}
}
