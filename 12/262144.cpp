#include <bits/stdc++.h>

#define endline "\n"
#define MAX_SIZE 262145
#define MAX_VAL 60

void init();
void read_data(int& n);
int solve(int n);
void print_result( int result );




int dp[ MAX_VAL ][ MAX_SIZE ];
int numbers[ MAX_SIZE ];

int main(){
    
    init();

    int n;
    read_data(n);
    
    int max_value = solve(n);

    print_result( max_value );
    
    return 0;
}

void init(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
}

void read_data(int& n){
    std::cin >> n;

    for(int i=0; i < n; ++i )
        std::cin >> numbers[i];
}

int solve(int n){
    int max_val = -1;
    for(int i=0; i<n; ++i)
        dp[0][i] = -1;
    for(int current_val = 1; current_val < MAX_VAL; ++current_val){
        for(int index=0; index< n; ++index){
            if(numbers[index] == current_val){
                dp[current_val][index] = index+1;
                max_val = current_val;
                continue;
            }

            if( dp[current_val-1][index] == -1 ){
                dp[current_val][index] = -1;
                continue;
            }

            dp[current_val][index] = dp[current_val-1][ dp[current_val-1][index] ];

            if( dp[current_val][index] > 0)
                max_val = current_val;

        }
        dp[current_val][n] = -1;
    }

    return max_val;
}

void print_result(int result){
    std::cout << result << endline;
}