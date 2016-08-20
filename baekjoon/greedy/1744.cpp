#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    freopen("1744.txt", "r", stdin);
    int N, num; // N <= 10000
    scanf("%d", &N);

    vector<int> plus;
    plus.reserve(N/2);
    vector<int> minus;
    minus.reserve(N/2);

    int zero = 0;
    int one = 0;

    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        if(num == 0){
            zero++;
        }    
        else if(num == 1){
            one++;
        }
        else if(num > 0){
            plus.push_back(num);
        }
        else{
            minus.push_back(num); // num < 0
        }    
    }
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());

    if(plus.size() % 2 == 1) plus.push_back(1);
    
    if(minus.size() % 2 == 1){
        minus.push_back(zero > 0 ? 0 : 1);
    }
    
    int ans = one;
    for (int i=0; i<plus.size(); i+=2) {
        ans += plus[i] * plus[i+1];
    }
    for (int i=0; i<minus.size(); i+=2) {
        ans += minus[i] * minus[i+1];
    }
    printf("%d\n", ans);
    return 0;
}