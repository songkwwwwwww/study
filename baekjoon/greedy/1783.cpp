#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    freopen("1783.txt", "r", stdin);
    int H, W; // 1 <= H, W <= 20,0000,0000
    scanf("%d %d", &H, &W);
    if(H == 1) printf("1\n");
    else if(H == 2) printf("%d\n", min(4, (W + 1)/2));
    else{ // H >= 3
        if(W >= 7){
            printf("%d\n", W-2);
        }
        else{ // W < 7
            printf("%d\n", min(4, W));
        }
    }
}