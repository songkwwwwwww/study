#include <stdio.h>

int month[12] = {
    31, // 1
    28, // 2
    31, // 3
    30, // 4
    31, // 5
    30, // 6
    31, // 7
    31, // 8
    30, // 9
    31, // 10
    30, // 11
    31  // 12
};

char days[7][4] = {
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT",
    "SUN"
};

int main(){
    freopen("1924.txt", "r", stdin);
    int x, y;
    scanf("%d %d", &x, &y);
    
    int ans = 0;
    for(int i = 0; i < x - 1; i++){
	ans += month[i];
    }
    ans += (y - 1);
    ans %= 7;
    printf("%s\n", days[ans]);
}
