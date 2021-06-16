#include "enum_clique.hpp"
#include "enum_clique_brute_force.hpp"

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
 /*
 std::cout<<g.Cert1()<<std::endl;
 std::cout<<g.Cert2()<<std::endl;
 std::cout<<g.Cert3()<<std::endl;
 std::cout<<g.Cert4()<<std::endl;
 */
 g.enumeration_bf();

 return 0;
}

