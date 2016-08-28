/*
	https://www.algospot.com/judge/problem/read/WEIRD
	
	
	What is Weird number?
	-> https://en.wikipedia.org/wiki/Weird_number
	

	@ Problem
In mathematics, weird numbers are natural numbers that are abundant but not semiperfect. In other words, a natural number N is a weird number if and only if:

Sum of its proper divisors (i.e. less than N ) is greater than the number.	-> condition1
No subset of its divisors sum to N.						-> condition2

For example, the set of proper divisors of 12 is { 1, 2, 3, 4, 6 } . 
The sum of these numbers exceed 12, however, 12 is not a weird number since 1 + 2 + 3 + 6 = 12.
However, 70 is a weird number since its proper divisors are {1, 2, 5, 7, 10, 14, 35} and no subset sums to 70 .

Write a program to determine if the given numbers are weird or not.


	@ Input Format
In the first line of input, the number of test cases C ( <= 200 ) is given. 
In each of the following C lines, a natural number N_i is given. 
All input numbers are greater than 1, and less than or equal to 500,000 .

	
	@ Output Format
Output will consist of C lines, each line containing either weird or not weird , 
denoting the weird-ness of the corresponding input.	


	@ Example Input
2
12
70

	@ Example Output 
not weird
weird

*/
#include <iostream>
#include <cstdio>
#include <vector>


bool sum_recur(const std::vector<int>& v, int index, int sum, int target_sum);

bool is_weird(int n){
	int sum = 0;
	std::vector<int> divisors;
	divisors.reserve(32);

	for(int i = 1; i < n; i++)
		if((n % i) == 0){
			sum += i;
			divisors.push_back(i);
		}

	if(sum > n){ // condition1
		if(sum_recur(divisors, 0, 0, n)) return false; // condition2
		else return true;
	}
	else
		return false;
}

/*
	@function sum_recur

	if subset of vector sum to n, then return true
	else return false
*/
bool sum_recur(const std::vector<int>& v, int index, int sum, int target_sum){

	// base case 1
	if(index > v.size()) return false;

	// base case 2
	if(sum > target_sum) return false;

	// base case 3
	if(sum == target_sum) return true;

	int next_index = index + 1;
	return sum_recur(v, next_index, sum, target_sum) ||
		sum_recur(v, next_index, sum + v[index], target_sum);

}

int main(){
	int TC, n, result;

	if(freopen("WEIRD.txt", "r", stdin) == NULL ){
		printf("file open failed");
	}
	setbuf(stdout, NULL);	

	scanf("%d", &TC);
	if( TC > 200) return 0;

	for(int i = 0; i < TC; i++){
		scanf("%d", &n);
		if(n <= 500000 || n > 1){
			result = is_weird(n);
			if(result) printf("weird\n");
			else printf("not weird\n");
		}
	}
}
