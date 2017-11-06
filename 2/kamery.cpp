#include <bits/stdc++.h>

int domy[ 100001 ];

int main()
{
    int wstawiono = 0;
    
    int n, k, r;

    
    std:: cin  >> n; std:: cin >> k; std:: cin >> r;

    for( int i=0; i<n; ++i){
        domy[i] = 0;
    }
    
    for( int i=0; i<k; ++i){
        int input;
        std::cin >> input;
        domy[ input ] = 1;
    }
    
    std:: cout << std:: endl << std::endl;
    
    int last_kamery = 0;
    for( int i = 1; i <= n-r+1; ++i){
        int kamery = 0;
        if( i == 1 ){
            for( int d = 0; d<r; ++d){
                if( domy[ i+d ] )
                    kamery++;
            }
        }
        else{
			kamery = last_kamery - domy[i-1] + domy[i+r-1];
        }
        
        
        if( kamery > 2 ){
        	last_kamery = kamery;
        	kamery = 0; 
        }else{
        	kamery = 2 - kamery;
        	last_kamery = 2;
        }
        wstawiono += kamery;

        int d = r-1;
        while( kamery ){
            if( domy[ i + d ] );
            else{
                domy[ i + d] = 1;
                kamery--;
            }
            d--;
        }
        
        

    }
    
    std:: cout << wstawiono << std::endl;
    
    return 0;
}
