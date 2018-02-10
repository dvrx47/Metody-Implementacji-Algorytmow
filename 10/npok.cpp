#include <bits/stdc++.h>

void init();
int64_t solve(int64_t, int64_t, int64_t);
int64_t odwrotnosc_mod_p(int64_t, int64_t);

int64_t fast_pow(int64_t liczba, int64_t p, int64_t modulo);


std::map<int64_t, int64_t> halfcomputed;

int main( int argc, char * argv[] ){
    init();

    int test_cases;
    std::cin >> test_cases;

    for(int i=0; i < test_cases; ++i ){
        int64_t n, k, p;
        std::cin >> n; std::cin >> k; std::cin >> p;

        std::cout << solve(n, k, p) << std::endl;
    }

    return 0;
}

void init(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
}

int64_t solve(int64_t n, int64_t k, int64_t p){

    int64_t licznik_mod_p = 1;
    int64_t mianownik_mod_p = 1;


    for( int i=n; i > n-k; --i )
        licznik_mod_p = (licznik_mod_p*i)%p;

    for(int i=1; i <= k; ++i)
        mianownik_mod_p = (mianownik_mod_p*i)%p;

    //odwrotnosc mianownika w ciele Z_p
    int64_t mianownik_odwrotnosc = odwrotnosc_mod_p( mianownik_mod_p, p);  

    return (mianownik_odwrotnosc*licznik_mod_p)%p;
}


int64_t odwrotnosc_mod_p(int64_t liczba, int64_t p){
    //korzystam z twierdzenia fermata
    //a^(p-1) === 1 (mod p)
    halfcomputed.clear();
    return fast_pow(liczba, p-2, p);
}


int64_t fast_pow(int64_t liczba, int64_t p, int64_t modulo){
    
    if( p == 0)
        return 1;
    if( p == 1)
        return liczba;
    
    if( halfcomputed[p] )
        return halfcomputed[p];
    
    if(p%2 == 0){
        if( halfcomputed[p/2] )
            return ( halfcomputed[p/2] * halfcomputed[p/2] ) % modulo;
        
        int64_t base = fast_pow(liczba, p/2, modulo);
        halfcomputed[p/2] = base;
        halfcomputed[p] = ( base*base )%modulo;
        return halfcomputed[p];
    }
    else{
        int64_t a, b;
        if( halfcomputed[p/2] )
            a = halfcomputed[p/2];
        else{
            a = fast_pow(liczba, p/2, modulo);
            halfcomputed[p/2] = a;
        }

        if( halfcomputed[p/2 + 1] )
            b = halfcomputed[p/2 + 1];
        else{
            b = fast_pow(liczba, p/2 + 1, modulo);
            halfcomputed[p/2 + 1] = b;
        }
        halfcomputed[p] = ( a * b )%modulo;

        return halfcomputed[p];
    }
}