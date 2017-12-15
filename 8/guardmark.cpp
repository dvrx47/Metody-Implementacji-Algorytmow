#include <bits/stdc++.h>
#define NUM_OF_COWS 20

int64_t Heights[ NUM_OF_COWS ];
int64_t Weights[ NUM_OF_COWS ];
int64_t Strengths[ NUM_OF_COWS ];

int64_t Stacks[ 1<<(NUM_OF_COWS) ];

int64_t N;
int64_t H;
std::vector<int64_t> Order;


void init();
bool porownanie (int64_t i, int64_t j);
void posortuj();
int64_t stack_height(int64_t bits);


int main(){

	init();
	
	std::cin >> N;
	std::cin >> H;
	
	
	for(int64_t i=0; i<N; ++i){
		
		Order.push_back(i);
		
		std::cin >> Heights[ i ];
		std::cin >> Weights[ i ];
		std::cin >> Strengths[ i ];
	}

	std::sort(Order.begin(), Order.end(), porownanie);
	
	posortuj();

	
	for(int64_t i=1; i < (1<<N); ++i){
		
		int to_extract = i;
		int64_t max_value = -1000000001;
		while( to_extract ){
			int extracted_bit = to_extract & (-to_extract);
			to_extract -= extracted_bit;
			int current_idx = i&(~extracted_bit);
			
			int64_t cow = 31 - __builtin_clz(extracted_bit);
			
			int64_t current_value = std::min( Stacks[ current_idx ] - Weights[cow], Strengths[cow] ); 
			
			if(current_value > max_value)
				max_value = current_value;
		} 
		
		Stacks[i] = max_value;
		
	}
	
	std::cout << std::endl;
	int max_safety_factor = -1000000001;
	for(int i=1; i< (1<<N); ++i){
		if( stack_height(i) >= H ){
			if( max_safety_factor < Stacks[i] )
				max_safety_factor = Stacks[i];	
		}
	}
	
	if( max_safety_factor  >= 0)
		std::cout << max_safety_factor << std::endl;
	else
		std::cout << "Mark is too tall" << std::endl;
		

	return 0;
}


void init(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	Stacks[0] = 2000000001;
	for(int64_t i=1; i<(1<<NUM_OF_COWS); ++i)
		Stacks[i] = -1000000001;
	
}


bool porownanie (int64_t i, int64_t j){ 
	int64_t s_i = Weights[i] + Strengths[i];
	int64_t s_j = Weights[j] + Strengths[j];
	return (s_i>s_j);
}


void posortuj(){
	int64_t h_temp[NUM_OF_COWS];
	int64_t w_temp[NUM_OF_COWS];
	int64_t s_temp[NUM_OF_COWS];
	
	for(int i=0; i<N; ++i){
		h_temp[i] = Heights[ Order[i] ];
		w_temp[i] = Weights[ Order[i] ];
		s_temp[i] = Strengths[ Order[i] ];
	}
	
	for(int i=0; i<N; ++i){
		Heights[i] = h_temp[i];
		Weights[i] = w_temp[i];
		Strengths[i] = s_temp[i];
	}
}


int64_t stack_height(int64_t bits){
	int64_t height = 0;
	for( int64_t i=0; i<N ; ++i ){
		if( bits & (1<<i) )
			height += Heights[i];
	}
	
	return height;
}


