/*

	Sieve of Eratosthenes

*/

int n;
bool is_prime[MAX_N + 1];

void eratosthenes(){
	memset(is_prime, 1, sizeof(is_prime));

	is_prime[0] = is_prime[1] = false;
	int sqrt_n = int(sqrt(n));
	for(int i = 2; i <= sqrt_n; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}		
	}
}
