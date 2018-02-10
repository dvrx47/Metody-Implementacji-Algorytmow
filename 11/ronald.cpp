#include <bits/stdc++.h>

void init();
void load_data(int & n, int & m );
bool solve( int n, int m );
void write_result( bool result );
int dfs( int start );
int dfs_recursive( int vertex );

#define PASS_MESSAGE "DA"
#define FAIL_MESSAGE "NE"
#define MAX_VERTEX 1001

std::vector<int> neighbour[ MAX_VERTEX ];
bool visited[ MAX_VERTEX ];
int vertex_visited = 0;


int main(int argc, char * argv[]){
    int n, m;
    
    init();

    load_data(n, m);

    write_result( solve(n ,m) );

    return 0;
}


void init(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i=0; i<MAX_VERTEX; ++i)
        visited[ i ] = false;
}


void load_data(int& n, int& m){
    std::cin >> n;
    std::cin >> m;

    for(int i=0; i<m; ++i){
        int a, b;
        std::cin >> a;
        std::cin >> b;

        neighbour[a].push_back( b );
        neighbour[b].push_back( a );
    }
}


bool solve(int n, int m){

    int num_of_edges = dfs(1);
    int left_edges = m - num_of_edges;
    int left_vertices = n - vertex_visited;

    if( vertex_visited*(vertex_visited-1)/2 == num_of_edges 
        && left_vertices*(left_vertices-1)/2 == left_edges )    
        return true;
    else
        return false;
}

int dfs( int start ){
    int num_of_edges = dfs_recursive( start );

    return num_of_edges/2;
}

int dfs_recursive(int vertex){
    if( visited[ vertex ] )
        return 0;
    
    visited[ vertex ] = true;
    vertex_visited++;
    
    int edges = 0;
    for(int i=0; i < neighbour[vertex].size(); ++i ){
        edges += dfs_recursive( neighbour[vertex][i] );
    }

    return neighbour[vertex].size() + edges;
}


void write_result( bool result ){
    if( result )
        std::cout << PASS_MESSAGE << std::endl;
    else
        std::cout << FAIL_MESSAGE << std::endl;
}   