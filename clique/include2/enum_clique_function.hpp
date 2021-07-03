#ifndef ENUM_CLIQUE_FUNCTION_HPP
#define ENUM_CLIQUE_FUNCTION_HPP
#include "enum_clique.hpp"

void CliqueSolve::enumeration() {
 std::vector<int> Vs = V;
 node_num = 0;
 std::cout<<"Start enumrating"<<std::endl;
 expand( Vs , &t.root );
 std::cout<<"End enumrating"<<std::endl;
 t.dfs( t.root );
}

void CliqueSolve::expand( std::vector<int>& Vs , node* a ){
 
 //if( Vs.size() == 0 ) return;

 for( int i = 0 ; i < Vs.size() ; i++ ){

  if( Vs.size() == size() ) std::cerr<<i<<std::endl; //Debug
  
  std::vector<int> Vsp;
  int p = Vs[i];
  for( int j = i + 1 ; j < Vs.size(); j++ )
   if( is_edge( p , Vs[j] ) )
    Vsp.push_back( Vs[j] );

  std::string cert = "";
  if( Vsp.size() != 0 ){
   int N_Vsp = Vsp.size();
   std::vector< std::vector<bool> > g_vsp( N_Vsp , std::vector<bool>( N_Vsp , false ) );
   for( int j = 0 ; j < N_Vsp ; j++ )
    for( int k = 0 ; k < N_Vsp ; k++ )
     g_vsp[j][k] = is_edge( Vsp[j] , Vsp[k] );
   graph G( g_vsp );
   cert = G.Cert4();
  } else {
   cert = "empty set"; // サイズ1のときも空文字なので，分けるため.
  }
  node* next;
  if( chache.find( cert ) != chache.end() ){
   //見つかった
   //std::cerr<<"HIT : "<<Vs.size()<<std::endl;
   next = chache[ cert ];
   //木の下に構成
   (*a).push( next , p );
  }else{
   next = new node;
   node_num++;
   if( node_num % 100 == 0 )  std::cerr<<"Node : "<< node_num << std::endl;
   chache[ cert ] = next;
   //木の下に構成
   (*a).push( next , p );
   if( Vsp.size() != 0 ) expand( Vsp , next );
  }
 }
}


#endif
