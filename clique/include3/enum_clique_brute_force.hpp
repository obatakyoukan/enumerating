#ifndef ENUM_CLIQUE_BRUTE_FORCE_HPP
#define ENUM_CLIQUE_BRUTE_FORCE_HPP
#include "enum_clique.hpp"

void CliqueSolve::enumeration_bf() {
 std::vector<int> Vs = V;
 node_num = 0;
 std::cout<<"Start enumrating"<<std::endl;
 expand_bf( Vs , &t.root );
 std::cout<<"End enumrating"<<std::endl;
 t.dfs( t.root );
}

void CliqueSolve::expand_bf( std::vector<int>& Vs , node* a ){
 
 //if( Vs.size() == 0 ) return;

 for( int i = 0 ; i < Vs.size() ; i++ ){

  if( Vs.size() == size() ) std::cerr<<i<<std::endl; //Debug
  
  std::vector<int> Vsp;
  int p = Vs[i];
  for( int j = i + 1 ; j < Vs.size(); j++ )
   if( is_edge( p , Vs[j] ) )
    Vsp.push_back( Vs[j] );

  if( Vsp.size() != 0 ){
   node* next;
   next = new node;
   node_num++;
   if( node_num % 100 == 0 )  std::cerr<<"Node : "<< node_num << std::endl;
   
   //木の下に構成
   (*a).push( next , p );
   if( Vsp.size() != 0 ) expand_bf( Vsp , next );
  }
 }
}


#endif
