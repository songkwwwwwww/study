/*
https://en.wikipedia.org/wiki/Insertion_sort

nsertion-Sort(A)

for j = 2 to A.length                     // A.length는 배열 A의 원소의 개수
	key = A[j]
	// A[j] 를 정렬된 배열 A[1.. j - 1]에 삽입한다.
	i = j - 1
	while i > 0 그리고 A[i] > key
		A[i + 1] = A[i]
		i = i - 1
	A[i + 1] = key

*/




void insertion_sort(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];

		list[j + 1] = key;
	}
}

