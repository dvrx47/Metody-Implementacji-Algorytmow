#include <bits/stdc++.h>

/*
 * wersja szybka
 * minimalnie szybsza i prostsza w implementacji jest wersja z 
 * Binary indexed tree zamiast drzewa przedziałowego
 */

#define fld(n,a,b) for(int a=(n); a<=(b); ++a)		   
#define fl1(a,b) for(int a=1; a<=(b); ++a)

#define COWS 100002

int Res[COWS]; 

std::vector< std::pair<int/*nr*/, int/*rating*/> > Input;
std::vector<int> Tree[COWS]; //tablica wektorów - wektor zawiera synów
int Start[COWS];
int Size[COWS];

#define TREE_SIZE 262150

int IntervalTree[ TREE_SIZE ];
int Dsize;


void computeDsize(int s){
	Dsize = 1;
	while( Dsize < s )
		Dsize <<= 1;
	Dsize -= 1;
}


void init_tree(int dsize){
	computeDsize( dsize );
	memset( IntervalTree, 0, sizeof(int) * TREE_SIZE );
}

void set_value( int value, int u ){
	u += Dsize;
	IntervalTree[u] = value;
	while( u /= 2  ){
		IntervalTree[u] = IntervalTree[2*u] + IntervalTree[2*u+1];
	}
	return;
}

int find_sum( int a, int b, int u, int low, int high){
	if( a==low && b==high){
		return IntervalTree[u];
	}
	
	if( b <= a )
		return 0;
		
	int mid = (low+high)/2;
	
	int left = find_sum( a, std::min(mid, b), 2*u, low, mid);
	int right = find_sum( std::max(a, mid), b, 2*u+1, mid, high); 
	
	return left + right ;
}


bool compare( std::pair<int,int> a, std::pair<int,int> b){
	return a.second > b.second ;
}


void dfs(int n){
	static int pos = 1;
	Start[n]=pos++;
	Size[n]=1;
 
	for (int i=0; i< Tree[n].size(); ++i){
		dfs(Tree[n][i]);
		Size[n] += Size[Tree[n][i]];
	}
}


int main(){	
	
	int n;
	scanf("%d", &n);
	
	init_tree( n );
	
	fl1( i, n ){
		int rating;
		scanf("%d", &rating);
		Input.push_back( std::make_pair(i, rating) );	
	}
	
	std::sort( Input.begin(), Input.end(), compare );

	
	fld( 2, i, n ){
		int parent;
		scanf("%d", &parent);
		Tree[parent].push_back( i );
	}
	
	dfs(1);
	
	
	for(int i=0; i<Input.size(); ++i){
		int a = Start[Input[i].first];
		int b = a + Size[Input[i].first];

		int r = find_sum( a, b, 1, 1, Dsize+2);	
		Res[Input[i].first] = r;	
		set_value(1, Start[Input[i].first]);
	}

	
	fl1( i, n ){
		printf("%d\n", Res[i]);
	}
	
	return 0;
}
