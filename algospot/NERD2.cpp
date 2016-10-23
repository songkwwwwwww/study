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
	// x���� �����ʿ� �ִ� �� ���� ���ʿ� �ִ� ���� ã�´�.
	std::map<int, int>::iterator it = coords.lower_bound(x);

	// �׷� ���� �������� ������ (x, y)�� ��������� �ʴ´�.
	if (it == coords.end()) return false;

	// �׷� ���� �����ϸ� y ���̿� ���� ���� ���ΰ� �޶�����.
	return y < it->second;
}

// ���ο� �� (x, y)�� ������ϴ� ������ �����.
void remove_dominated(int x, int y) {
	std::map<int, int>::iterator it = coords.lower_bound(x);

	// ������ϴ� ���� �������� �ʴ´�.
	if (it == coords.begin()) return ;

	// ���� ���ϴ� ���� �����ϸ�
	--it;

	while (true) {

		// ��������� �ʴ� ���� ������ ����
		if (it->second > y) break;

		// ������ϴ� ���� ����Ű�� �����Ͱ� �� ó�� ���̶��
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

// �� ��(x, y)�� �߰��Ǿ��� �� coords�� �����ϰ� 
// �ٸ� ���� ��������� �ʴ� ������ ������ ��ȯ�Ѵ�
int registered(int x, int y) {
	// �߰��Ǵ� ���� ������Ѵٸ� �����ص� �ȴ�.
	if (is_dominated(x, y)) return coords.size();

	// ���� ������ �����Ѵٸ�, ������ϴ� ���� ������ �����Ѵ�
	remove_dominated(x, y);

	// �� ��(x, y)�� �߰��Ѵ�
	coords[x] = y;

	// ���ŵ� ������ ��ȯ�Ѵ�.
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
