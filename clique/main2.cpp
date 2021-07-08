#include "graph.hpp"
#include "cert1.hpp"
#include "cert2.hpp"

int main(){
 int n,m;
 std::cin>>n>>m;
 std::vector< std::vector< bool > > E( n , std::vector< bool > ( n , false ) );
 for( int i = 0 ; i < m ; i++ ){
  int u,v;
  std::cin>>u>>v;
  E[u][v] = E[v][u] = true;
 }
 graph g( E );
 std::vector< int > Vs(n/2);

 //std::cout<<g.Cert1()<<std::endl;
 //iota( Vs.begin() , Vs.end() , 0 );
 //std::cout<<g.Cert1(Vs)<<std::endl;
 //std::cout<<g.Cert2()<<std::endl;
 iota( Vs.begin() , Vs.end() , 0 );
 std::cout<<g.Cert2(Vs)<<std::endl;
 //std::cout<<g.Cert3()<<std::endl;
 //iota( Vs.begin() , Vs.end() , 0 );
 //std::cout<<g.Cert3(Vs)<<std::endl;
 //std::cout<<g.Cert4()<<std::endl;
 //iota( Vs.begin() , Vs.end() , 0 );
 //std::cout<<g.Cert4(Vs)<<std::endl;

 return 0;
}

