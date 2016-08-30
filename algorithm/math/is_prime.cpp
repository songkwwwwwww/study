// 알고리즘 문제 해결 전략(종만북) 참조
bool is_prime(int n){
	if(n <= 1) return false;
	if(n == 2) return true;

	if(n % 2 == 0) return false;

	int sqrt_n = int(sqrt(n));
	for(int div = 3; div <= sqrt_n; div += 2)
		if(n % div == 0) return false;
i	return true;
}
