#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    freopen("10610.txt", "r", stdin);
    string s;
    cin >> s;
    int sum = 0;
    int s_size = s.size();
    for(int i = 0; i < s_size; i++){
        sum += s[i] - '0';
    }
    sort(s.begin(), s.end(), greater<int>());
    if((s[s_size - 1] == '0') && (sum % 3 == 0)) {
        cout << s << endl;
    }
    else{
        printf("-1\n");
    }
}