#include <iostream>

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}


int partition(int A[], int lo, int hi){
	int pivot = A[hi];
	int i = lo;
	for(int j = lo; j < hi; j++){
		if(A[j] <= pivot){
			swap(A[i], A[j]);
			i++;
		}
	}
	swap(A[i], A[hi]);
	return i;
}

/*

*/
void quick_sort(int A[], int lo, int hi){
	if(lo < hi){
		int p = partition(A, lo, hi);	// pivot
		quick_sort(A, lo, p -1);
		quick_sort(A, p + 1, hi);		
	}
}

int main(){
	int A[] = {0 , 5, 2, 73, 43, 11, 33, 66, 22, 44};

	std::cout << "before : " << std::endl;	
	for(int i = 0; i < 10; i++){
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	quick_sort(A, 0, 9);

	std::cout << "after : " << std::endl;	
	for(int i = 0; i < 10; i++){
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}


/*
정올 교재
void swap(int a, int b) {
	int t = S[a];
	S[a] = S[b];
	S[b] = t;
}
void quick_sort(int s, int e) {
	if(s<e){
		int p = s, l = s+1, r = e;
		while(l<=r){
			while(l<= e && S[l]<=S[p]) l++;
			while(r>=s+1 && S[r]>=S[p]) r‐‐;
			if(l<r) swap(l,r);
		}
		swap(p, r);
		quick_sort(s, r‐1);
		quick_sort(r+1, e);
	}
}
*/