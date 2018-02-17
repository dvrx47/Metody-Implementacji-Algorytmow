#include <iostream>
#include <stdint.h>
#include <limits.h>

void init();
void init_query();
void read_data();
void read_RPNM();
void read_ingridients_on_hand();
void read_cost_arr();
void read_recipes();
int solve();
int ingridients_cost( int16_t subset );
void print_result( int result );


#define endline '\n'
#define MAX_SIZE (1<<13)
#define INF INT_MAX

#define MAX_RECIPES 31
#define MAX_INGRIDIENTS 14

int16_t recipes[MAX_RECIPES];
int cost[MAX_INGRIDIENTS];

int R, P, N, M;
int16_t pantry_vect;


int main(){
    init();

    int queries;
    std::cin >> queries;

    for(int q=0; q< queries; ++q){
        init_query();
        read_data();
        int result = solve();
        print_result( result );
    }

}

void init(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
}

void init_query(){
    pantry_vect = 0;
}

void read_data(){
    read_RPNM();
    read_ingridients_on_hand();
    read_cost_arr();
    read_recipes();
}

void read_RPNM(){
    std::cin >> R;
    std::cin >> P;
    std::cin >> N;
    std::cin >> M;
}

void read_ingridients_on_hand(){
    for(int i=0; i<M; ++i){
        int ingridient;
        std::cin >> ingridient;
        pantry_vect |= (1<<ingridient);
    }
}

void read_cost_arr(){
    for(int i=0; i<P; ++i){
        int current_cost;
        std::cin >> current_cost;
        cost[i] = current_cost;
    }
}

void read_recipes(){
    for(int i=0; i<R; ++i){
        int16_t ingridients = 0;
        for(int16_t ing = 0; ing<P; ++ing){
            int current_ing;
            std::cin >> current_ing;
            if(current_ing)
                ingridients |= (1<<ing);
        }
        recipes[i] = ingridients;
    }
}

int solve(){
    int32_t minimum = INF;

    for(int16_t subset= pantry_vect; subset < (1<<P); subset = (subset+1)|pantry_vect ) {
        int rec_count = 0;
        for(int rec = 0; rec<R; ++rec){
            if( (recipes[rec]&subset) == recipes[rec] ){
                rec_count++;
            }
        }

        if(rec_count >= N){
            int current_cost = ingridients_cost( subset );
            minimum = std::min( minimum, current_cost );
        }
    }
    return minimum;
}

int ingridients_cost( int16_t subset ){
    int sum=0;
    for(int i=0; i<P; ++i){
        if( subset&(~pantry_vect)&(1<<i) )
            sum += cost[i];
    }
    return sum;
}

void print_result( int result ){
    std::cout << result << endline;
}
