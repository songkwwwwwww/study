#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, num; // 1 <= M, N <= 50,0000
int* a;

bool check(int target){
    int left = 0;
    int right = N-1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == target) return true;
        else if(a[mid] > target) right = mid - 1;
        else left = mid + 1; // arr[mid] < target
    }
    return false;
}

int main(){
    freopen("10815.txt","r", stdin); 
    scanf("%d", &N);
    a = new int[N];
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    sort(a, a + N);

    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &num);
        printf("%d ", check(num));
    }
    printf("\n");
    delete[] a;
    return 0;
}