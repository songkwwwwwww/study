int f(int n){
    if(n == 1) return 1;
    return f(n - 1) + n;
}

int f(int n){
    if(n == 1) return 1;
    return 2 * f(n / 2) + ((n + 1) / 2) * ((n + 1) / 2);
}