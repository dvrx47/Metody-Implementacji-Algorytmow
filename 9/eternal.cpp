#include <bits/stdc++.h>

void init();

int main( int argc, char * argv[] ){

	init();
	
	int64_t a,b;
	std::cin >> a; std::cin >> b;
	
	if(b-a == 1){
		std::cout << b%10 << std::endl;
	}
	else if(a==b){
		std::cout << "1" << std::endl;
	}
	else if( b-a >= 5){
		std::cout << "0" << std::endl;
	}
	else{
		int digit = 1;
		for( int i=0; i < b-a; ++i){
			digit *= (b-i)%10;
		}
		std::cout << digit%10 << std::endl;
	}
	return 0;
}


void init(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
}
