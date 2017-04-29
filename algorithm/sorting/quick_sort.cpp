quick_sort(l, r)
    if L < r
	p <- partition(l, r)
	quick_sort(l, p -  1)
	quick_sort(p + 1, r)


Hoare-Partition Algorithm
partition(l, r)
    p <- A[l]
    i <- l
    j <- r
    while i <= j
	while A[i] <= p : i++
	while A[j] >= p : j--
	if i < j swap(A[i], A[j])
    
    swap(a[l], a[j])
    return j


Lomuto-Partition Algorithm
partition(l, r)
    x <- A[r]
    i <- l - 1

    for j in l -> r - 1
	if a[j] <= x
	    i++, swap(A[i], A[j])

    swap(A[i + 1], A[r])
    return i + 1







void quick_sort(int left, int right, int input[]){
    int i = left, j = right;
    int pivot = inpuit[(left + right) / 2];
    while(i <= j){
	while(input[i] < pivot) i++;
	while(pivot < input[j]) j--;
	if(i <= j){
	    swap(input[i], input[j]);
	    i++;
	    j--;
	}
    }
    if(left < j) quick_sort(left, j, input);
    if(i < right) quick_sort(i, right, input);
}












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
