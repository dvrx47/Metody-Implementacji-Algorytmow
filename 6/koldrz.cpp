#include <bits/stdc++.h>

#define MAX_N 500001
#define UNINITIALIZED 0

int	colorOfNode[MAX_N];
std::vector<int> EdgesLists[MAX_N];


int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int num_of_nodes;
	std::cin >> num_of_nodes;


	for(int node = 1; node < num_of_nodes; ++node){
		int edgeStart, edgeEnd;
		std::cin >> edgeStart;
		std::cin >> edgeEnd;
		EdgesLists[ edgeStart ].push_back( edgeEnd ); 
	}
	
	
	for(int node = 1; node <= num_of_nodes; ++node){
		int color;
		std::cin >> color;
		colorOfNode[ node ] = color;
	}
	
	
	
	int rootFirst 	= UNINITIALIZED;
	int rootSecond 	= UNINITIALIZED;
	
	for(int node = 1; node <= num_of_nodes; ++node){
		
		int currentColor = colorOfNode[ node ];
							
		for( int neighbour = 0; neighbour < EdgesLists[ node ].size(); ++neighbour ){
		
			int neighIndex = EdgesLists[ node ][neighbour];
			
			if( colorOfNode[neighIndex] != currentColor){
				if( neighIndex == rootFirst || neighIndex == rootSecond ){
					continue;
				}			
				
				if( !rootFirst ){
					/*roots uninitialized*/
					rootFirst  = node;
					rootSecond = neighIndex;
				}
				else{
					if( node != rootFirst && node != rootSecond){
						std::cout << "NIE" << std::endl;
						return 0;
					}
					
					rootFirst  = node;
					rootSecond = UNINITIALIZED;
				}
			}
		}
		
	}
	
	std::cout << "TAK" << std::endl;
	
	return 0;
}
