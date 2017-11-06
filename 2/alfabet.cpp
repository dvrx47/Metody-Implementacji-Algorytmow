#include <bits/stdc++.h>


int main(){
	std:: string input;
	std::cin >> input;
	
	std:: vector < int > tablica[30];
	int wysokosc = 1;
	tablica[1].push_back( input[ 0 ] );
	
	for( int i=1; i < input.length(); ++i){
		int wstawiono = 0;
		int poziom = 1;
		while( !wstawiono ){
			if( poziom == wysokosc ){
				if( tablica[poziom].back() < input[i] )
					wysokosc++;
				tablica[wysokosc].push_back( input[ i ] );
				wstawiono = 1;
				break;
			}
			
			if(	tablica[poziom].back() < input[i] )
				poziom++;
			else{
				tablica[poziom].push_back( input[ i ] );
				wstawiono = 1;
			}			
		}
	}
	
	std:: cout << 26 - wysokosc << std:: endl;
	
	return 0;
}
