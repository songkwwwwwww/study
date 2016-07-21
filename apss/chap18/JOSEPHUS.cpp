#include <iostream>
#include <list>
#include <cstdio>

/*
	@input
2		test case C (C<=50)
6 3		N K (3<=N, K<=1000)
40 3		

	@output
3 5		
11 26

포위당한 N명의 사람
시계 방향으로 K번째 살아 있는 사람		
*/

void josephus(int n, int k){
	std::list<int> survivors;
	std::list<int>::iterator target;

	for(int i = 1; i <= n; ++i){
		survivors.push_back(i);
	}
	target = survivors.begin();

	while(n > 2){
		target = survivors.erase(target);
		if(target == survivors.end()){
			target = survivors.begin();
		}
		n--;

		for(int i = 0; i < k - 1; i++){
			target++;
			if(target == survivors.end()){
				target = survivors.begin();
			}
		}
	}
	printf("%d %d\n", survivors.front(), survivors.back());
}

int main(){
	int TC;
	if(freopen("JOSEPHUS.txt", "r", stdin) == NULL){
		printf("file open failed");
	}
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for(int i =0; i < TC; i++){
		int n, k;
		scanf("%d %d", &n, &k);
		josephus(n, k);
	}
}

