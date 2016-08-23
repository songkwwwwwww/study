#include <stdio.h>

using namespace std;

int N; // 1 <= N <= 50,0000

int a[500000];
int b[500000];
long long solve(int start, int end) {
    if (start == end) {
        return 0;
    }
    int mid = (start+end)/2;
    long long ans = solve(start, mid) + solve(mid+1, end);
    int i = start;
    int j = mid+1;
    int k = 0;
    while (i <= mid || j <= end) {
        if (i <= mid && (j > end || a[i] <= a[j])) {
            b[k++] = a[i++];
        } else {
            ans += (long long)(mid-i+1);
            b[k++] = a[j++];
        }
    }
    for (int i=start; i<=end; i++) {
        a[i] = b[i-start];
    }
    return ans;
}
long long merge(int start, int end){    
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = 0;
    long long ans = 0;
    while(i <= mid && j <= end){
        if(a[i] <= a[j]) b[k++] = a[i++];
        else { // a[i] > a[j]
            b[k++] = a[j++];
            ans += (long long)(mid - i + 1);
        }
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= end) b[k++] = a[j++];

    for(int i = start; i <= end; i++){
        a[i] = b[i - start];
    }

    return ans;
}

long long merge_sort(int start, int end){
    if(start == end)
        return 0;
    
    int mid = (start + end) / 2;
    long long ans = 0;
    ans += merge_sort(start, mid);
    ans += merge_sort(mid + 1, end);
    ans += merge(start, end);
    return ans;
}



int main(){
    freopen("1517.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    printf("%lld\n", merge_sort(0, N-1));
}