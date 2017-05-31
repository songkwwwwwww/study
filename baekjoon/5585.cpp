#include <stdio.h>

int coins[] = {500, 100, 50, 10, 5, 1};
int money;

int main(){
    freopen("5585.txt", "r", stdin);
    scanf("%d", &money);
    money = 1000 - money;
    int ans = 0;
    for(int i = 0; i < 6; i++){
	ans += money / coins[i];
	money %= coins[i];
    }
    printf("%d\n", ans);
}
