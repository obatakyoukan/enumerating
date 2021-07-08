#include "enum_clique.hpp"
#include "enum_clique_function.hpp"
#include <time.h>
int main(){
 int n,m;
 std::cin>>n>>m;
 std::vector< std::vector< bool > > E( n , std::vector< bool > ( n , false ) );
 for( int i = 0 ; i < m ; i++ ){
  int u,v;
  std::cin>>u>>v;
  E[u][v] = E[v][u] = true;
 }
 CliqueSolve g( E );
 clock_t start = clock();
 g.enumeration2();
 clock_t end = clock();
 std::cerr <<  "Time : " << (double)( end - start ) / CLOCKS_PER_SEC << " sec.\n";
 return 0;
}

