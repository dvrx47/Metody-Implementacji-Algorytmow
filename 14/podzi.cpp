#include <iostream>
#include <vector>
#include <stdint.h>


#define endline '\n'
#define zero '0'
#define one '1'
#define MAX_SIZE 1000009

std::vector<bool> zerojeden;
std::vector<int> indeksy;
std::vector<int64_t> liczby;
bool reszty[MAX_SIZE];

void init();
void read_data(int& n);
void solve(int n);
void print_result();


int main() {
    init();

    int n;
    read_data(n);

    solve(n);

    print_result();

    return 0;
}


void init(){
    std::ios::sync_with_stdio(0);
    std::cin.tie();
    for(int i=0; i<MAX_SIZE; ++i)
        reszty[i] = false;
    liczby.push_back(1);
    reszty[1] = true;
    indeksy.push_back(-1);
    zerojeden.push_back(true);
}


void read_data(int& n){
    std::cin >> n;
}


void solve(int n){
    int left = 0;
    int right = 1;

    while(!reszty[0]){
        for(int i=left; i<right; ++i){

            int64_t base = liczby[i]*10;
            if(!reszty[base % n]){
                reszty[base % n] = true;
                liczby.push_back( base % n );
                indeksy.push_back( i );
                zerojeden.push_back( false );
            }
            if(reszty[0])
                break;

            if(!reszty[(base+1) % n]){
                reszty[(base+1) % n] = true;
                liczby.push_back( (base+1) % n );
                indeksy.push_back( i );
                zerojeden.push_back( true );
            }
            if(reszty[0])
                break;
        }

        left = right;
        right = liczby.size();
    }

}

void print_result(){
    std::vector<bool> wynik;
    int idx = indeksy[ indeksy.size() - 1];

    for(int idx = indeksy.size() - 1; idx >= 0; idx = indeksy[ idx ] ){
        wynik.push_back( zerojeden[idx] );
    }

    for(int i=wynik.size()-1; i>=0; --i){
        if(wynik[i])
            std::cout << one;
        else
            std::cout << zero;
    }
    std::cout << endline;
}
