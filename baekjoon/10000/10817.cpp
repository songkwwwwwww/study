#include <cstdio>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}


int main(){
    freopen("10817.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int a[3];
    
    scanf("%d %d %d", &a[0], &a[1], &a[2]);

    for(int i = 0; i < 2; i++){
        for(int j = 1; j < 3; j++){
            if(a[i] > a[j])
                swap(a[i], a[j]);
        }
    }

    printf("%d\n", a[1]);
}