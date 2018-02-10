#include <bits/stdc++.h>

void init();
void init_test_case();
void solve();
void wplac(int64_t kwota, int64_t& koperty, int64_t& kasa);
void wyplac(int64_t kwota, int64_t& koperty, int64_t& kasa);
void wyplac_z_kopert(int64_t kwota, int64_t & koperty, int64_t& kasa);


#define MAX_VAL 1000001
int64_t sumy[ MAX_VAL ];
int64_t minima[ MAX_VAL ];

#define INF 100000000



int main(){
    init();

    int test_cases;
    std::cin >> test_cases;

    for(int i=0; i< test_cases; ++i){
        init_test_case();
        solve();
    }

    return 0;
}



void init(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
}

void init_test_case(){
    sumy[0] = 0;
    minima[0] = INF;
}

void solve(){

    int64_t koperty = 0;
    int64_t n, kasa;
    std::cin >> n; std::cin >> kasa;

    for(int64_t i=0; i<n; ++i){
        int64_t kwota;
        std::cin >> kwota;

        if(kwota >= 0)
            wplac(kwota, koperty, kasa);
        else
            wyplac(-kwota, koperty, kasa);
    }

    std::cout << kasa << " " << sumy[koperty] << std::endl;
}


void wplac(int64_t kwota, int64_t& koperty, int64_t& kasa){
    koperty++;
    sumy[koperty] = sumy[koperty - 1] + kwota;
    minima[koperty] = std::min( minima[koperty-1], kwota );
}


void wyplac(int64_t kwota, int64_t& koperty, int64_t& kasa){
    if( kwota < minima[koperty] ){
        kasa -= kwota;
        return;
    }

    if( sumy[koperty] < kwota ){
        kwota -= sumy[koperty];
        koperty = 0;
        kasa -= kwota;
        return;
    }

    wyplac_z_kopert(kwota, koperty , kasa);
}


void wyplac_z_kopert(int64_t kwota, int64_t & koperty, int64_t& kasa){
    //zmodyfikowany bin_search
    int64_t left = 0;
    int64_t right = koperty;
    int64_t base = sumy[koperty];

    while(left != right){
        int64_t mid = (left + right)/2;


        if(base - sumy[mid] >= kwota)
            left = mid;
        else
            right = mid;

        
        if(right - left == 1)
            break;
    }

    int64_t reszta = base - sumy[left] - kwota;
    kasa += reszta;
    koperty = left;
}