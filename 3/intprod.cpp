#include <bits/stdc++.h>

#define TREE_SIZE 262150

int Dsize; 
int Mnozniki[ TREE_SIZE ];

inline int sgn(int val) {
    if( val == 0) return 0;
    if( val > 0 ) return 1;
    return -1;
}


void computeDsize(int s){
	Dsize = 1;
	while( Dsize < s )
		Dsize <<= 1;
	Dsize -= 1;
}


void init_tree(int dsize){
	computeDsize( dsize );
	for(int i=0; i < TREE_SIZE; ++i)
		Mnozniki[i] = 1; 
	
}

void set_value( int value, int u ){
	Mnozniki[u] = value;
	while( u /= 2  ){
		Mnozniki[u] = Mnozniki[2*u] * Mnozniki[2*u+1];
	}
	return;
}

int find_mul( int a, int b, int u, int low, int high){
	if( a==low && b==high){
		return Mnozniki[u];
	}
	
	if( b <= a )
		return 1;
		
	int mid = (low+high)/2;
	
	int left = find_mul( a, std::min(mid, b), 2*u, low, mid);
	int right = find_mul( std::max(a, mid), b, 2*u+1, mid, high); 
	
	return left * right ;
}



int main(){
	int n, k;
	while( std::cin >> n ){
		
		 std:: cin >> k;
		
		init_tree(n);
		
		for( int i=1; i<=n; ++i){
			int x;
			std::cin >> x;
			set_value( sgn(x), Dsize + i );
		}
		
		
		for( int round=0; round<k; ++round){
			char command;
			int a, b;
			std:: cin >> command; std::cin >> a; std::cin >> b;
			
			if( command == 'C' )
				set_value( sgn(b), Dsize+a);
			else{

				int znak = find_mul( a, b+1, 1, 1, Dsize+2);
				if( znak == 0) std::cout<< "0";
				if( znak > 0 ) std::cout<< "+";
				if( znak < 0 ) std::cout<< "-";
				
			}
		
		}
		
		std::cout << std::endl;
	}
	
	return 0;
}
