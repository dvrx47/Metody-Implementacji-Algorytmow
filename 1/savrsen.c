#include <stdio.h>
#include <stdint.h>

int64_t sum_table[ 1000000 ];


int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	
	int64_t sum;
	
	sum = ( a == 1);
	
	
	for(int i=a; i <= b; ++i)
		sum_table[i] = i-1;
		
	for(int64_t dzielnik = 2; dzielnik <= b; ++dzielnik){
		int64_t base = a - (a % dzielnik);
		base = (base > 0)? base : base + dzielnik;
		for(int64_t i=0; base + i*dzielnik <= b; ++i){

			sum_table[ base + i*dzielnik ] -= (base + i*dzielnik > dzielnik) ? dzielnik : 0;
		}

	}  
	
	
	for(int i=a; i<=b; ++i){
		sum += ( sum_table[i] > 0)? sum_table[i] : -sum_table[i];
	}
	
	printf("%lld\n", sum);
		
	return 0;
}
