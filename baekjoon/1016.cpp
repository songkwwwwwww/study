#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const ll MAX_min = 1000000000000;
const ll GAP = 1000000;
const ll MAX_max = MAX_min + GAP;

ll min, max;
bool check[GAP + 1];


int main(){
    freopen("1016.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%lld %lld", &min, &max);
    vector<ll> a;
    ll gap = max - min + 1;
    a.reserve(gap);
    
    ll n = min;
    for(int i = 0; i < gap; i++)
        a[i] = n++;
    
    vector<bool> check(gap, true);
    for(ll i = 2; i * i <= max; i++){
        
        if(check[min])

        for(int i )
    }
}