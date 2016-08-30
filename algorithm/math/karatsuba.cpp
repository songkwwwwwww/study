// 알고리즘 문제 해결 전략(종만북) 참조

// num[]이 자릿수 올림을 처리한다
void normalize(vector<int>& num){
    num.push_back(0);
    // 자릿수 올림을 처리한다.
    for(int i = 0; i < num.size(); i++){
        if(num[i] < 0){
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else{
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while(num.size() > 1 && num.back() == 0) num.pop_back();
}

// O(n ^ 2) multiply
vector<int> multiply(const vector<int>& a, const vector<int>& b){
    vector<int> c(a.size() + b.size() + 1, 0);
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    normalize(c);
    return c;    
}

// a += b * (10 ^ k)
void add_to(vector<int>& a, const vector<int>&b, int k){

}

// a -= b; ( a >= b )
void sub_from(vector<int>& a, const vector<int>& b){

}

// (a0 + a1) * (b0 + b1) 
// = a0 * b0 + (a1 * b0 + a0 * b1) + a1 * b1;
// ...
// z2 = a1 * b1;
// z0 = a0 * b0;
// z1 = (a0 + a1) * (b0 + b1) - z0 - z2;
vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
    int an = a.size(), bn = b.size();
    // if an < bn, swap
    if(an < bn) return karatsuba(b, a);
    // base case 1: a나 b가 비어 있는 경우
    if(an == 0 || bn == 0) return vector<int>();
    // bae case 2: a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경
    if(an <= 50) return multiply(a, b);
    int half = an/2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());

    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    // z2 = a1 * b1;
    vector<int> z2 = karatsuba(a1, b1);

    // z0 = a0 * b0;
    vecotr<int> z0 = karatsuba(a0, b0);

    //a0 = a0 + a1; b0 = b0 + b1;
    add_to(a0, a1, 0); add_to(b0, b1, 0);

    //z1 = (a0 * b0) - z0 - z2;
    vector<int> z1 = karatsuba(a0, b0);
    sub_from(z1, z0); sub_from(z1, z2);

    // ret = z0 + z1 * 10^half + z2 * 10^(half*2)
    vector<int> ret;
    add_to(ret, z0, 0);
    add_to(ret, z1, half);
    add_to(ret, z2, half + half);
    return ret;
}