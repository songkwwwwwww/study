#include <stdio.h>

typedef long long ll;

int main(){
    freopen("1789.txt", "r", stdin);

    ll N;
    scanf("%lld", &N);
    
    // n(n + 1) / 2
    ll i;
    for(i = 1; ; i++){
	if( (i * (i + 1)) / 2 > N )
	    break;
    }
    printf("%lld\n", i - 1);
}
