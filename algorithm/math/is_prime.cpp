
bool is_prime(int n){
	if(n <= 1) return false;
	if(n == 2) return true;

	if(n % 2 == 0) return false;

	int sqrt_n = int(sqrt(n));
	for(int div = 3; div <= sqrt_n; div += 2)
		if(n % div == 0) return false;
i	return true;
}
