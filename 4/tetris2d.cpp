#include <bits/stdc++.h>

#define TREE_SIZE 2097220

//podwójne drzewa przedziałowe

int Wysokosci[ TREE_SIZE ];
int Maxima[ TREE_SIZE ];

void init_tree(){
	
	memset( Wysokosci, -1, sizeof(int) *TREE_SIZE);
	//ustalam na calej tablicy wartosc 0
	Wysokosci[1] = 0;
	memset( Maxima, 0, sizeof(int) *TREE_SIZE );
}


int find_max( int a, int b, int u, int low, int high){
	if( a==low && b==high){
		return Maxima[u];
	}
	
	if( b <= a )
		return 0;
		
	int mid = (low+high)/2;
	
	int left = find_max( a, std::min(mid, b), 2*u, low, mid);
	int right = find_max( std::max(a, mid), b, 2*u+1, mid, high); 
	
	return std::max( left, std::max(right, Wysokosci[u]) );
}



void set_value( int value, int a, int b, int u, int low, int high){
	if( a==low && b==high){
		Wysokosci[u] = value;
		Maxima[u] = value;
		return;
	}
	
	if( b <= a )
		return;
		
	if( Wysokosci[u] != -1 ){
		Wysokosci[2*u] = Wysokosci[u];
		Wysokosci[2*u + 1] = Wysokosci[u];
		Wysokosci[u] = -1;
	}
	
	int mid = (low+high)/2;
	
	set_value( value, a, std::min(mid, b), 2*u, low, mid);
	set_value( value, std::max(a, mid), b, 2*u+1, mid, high); 
	
	Maxima[u] = std::max( Maxima[2*u], std::max(Maxima[2*u+1], Wysokosci[u]));
}



int main(){
	int d, n;
	std:: cin >> d; std::cin >> n;

	init_tree();
	
	for( int klocek = 0; klocek < n; ++klocek ){
		int l, x;
		std::cin >> l; std::cin >> x;
		x+=1;
		int max = find_max(x, x+l, 1, 1, d+1);
		set_value( max+1, x, x+l, 1, 1, d+1);	
	}

	std::cout << Maxima[1] << std::endl;
	
	return 0;		
}
