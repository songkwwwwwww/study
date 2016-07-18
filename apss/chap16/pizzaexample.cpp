/*
	고객들이 원하는 토핑을 골라 주문할 수 있는 피자집의 주문 시스템

	0 ~ 19의 스무 가지 토핑

	주문시 토핑을 넣을지 않을지 선택할 수 있음( 0 / 1 )

	-> 비트마스크로 표현할 수 있다.
*/


#include <iostream>

/*
	# 공집합과 꽉 찬 집합 구하기

	상수 0 은 공집합을 의미.
	꽉 찬 집합은 마지막 20개의 비트가 모두 켜진 숫자
*/
int full_pizza = (1 << 20) - 1;



/*
	# 원소 추가

	추가하려는 토핑의 번호가 p(0 <= p < 20)
*/
toppings |= (1 << p);



/*
	# 원소의 포함 여부 확인

	아래 if 문에서 리턴 값은 0 혹은 1 << p 이다.
	0과 1 이 아님을 주의.
*/
if(toppings & (1 << p)) cout << "element is in" << endl;



/*
	# 원소의 삭제

	
*/
toppings &= ~(1 << p);


/*
	# 원소의 토글

	해당 비트가 켜져 있으면 끄고, 꺼져 있으면 킨다.
*/
toppings ^= (1 << p);




/*
	# 두 집합에 대해 연산하기

*/
int added = (a | b);
int intersection = (a & b);
int removed = (a & ~b);
int toggled = (a ^ b);



/*
	# 집합의 크기 구하기
*/
int bit_count(int x){
	if(x == 0) return 0;
	return x % 2 + bit_count(x/2);
}
/*
	builtin command

	Compiler/Language		function
	gcc/g++				__builtin_popcount(topiings)
	Visual C++			__popcnt(toppings)
	Java				Integer.bitCount(toppings)
*/



/*
	# 최소 원소 찾기

	builtin command
	
	Compiler/Language		function
	gcc/g++				__builtin_ctz(toppings)
	Visual C++			_BitScanForward(&index, toppings)
	Java				Integer.numberOfTrailingZeros(toppings)

	__builtin_ctz는 입력으로 0이 주어졌을 때의 결과가 정의되어 있지 않으므로 주의.

*/
int first_topping = (toppings & -toppings);



/*
	# 최소 원소 지우기

*/
toppings &= (toppings - 1);


/*
	# 모든부분 집합 순회하기


*/
for(int subset = pizza; subset; subset = ((subset - 1) & pizza) ){

}



