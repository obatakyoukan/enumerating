#ifndef ENUM_CLIQUE_FUNCTION_HPP
#define ENUM_CLIQUE_FUNCTION_HPP
#include "enum_clique.hpp"

void CliqueSolve::enumeration() {
 //std::vector<int> Vs = V;
 std::vector<int> Vs( size() );
 iota( Vs.begin() , Vs.end() , 0 );

 node_num = 0;
 std::cout<<"Start enumrating"<<std::endl;
 expand( Vs , &t.root );
 std::cout<<"End enumrating"<<std::endl;
 std::cerr << "Num of Nodes : " << node_num << std::endl;
 t.dfs( t.root );
 std::cout<<std::endl;
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

   //グラフのcert化
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

void CliqueSolve::enumeration2() {
 //std::vector<int> Vs = V;
 std::vector<int> Vs( size() );
 iota( Vs.begin() , Vs.end() , 0 );

 node_num = 0;
 std::cout<<"Start enumrating"<<std::endl;
 expand2( Vs , &t.root );
 std::cout<<"End enumrating"<<std::endl;
 std::cerr << "Num of Nodes : " << node_num << std::endl;
 t.dfs( t.root );
 std::cout<<std::endl;
}

void CliqueSolve::expand2( std::vector<int>& Vs , node* a ){
 
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

   //グラフのcert化
   /*
   int N_Vsp = Vsp.size();
   std::vector< std::vector<bool> > g_vsp( N_Vsp , std::vector<bool>( N_Vsp , false ) );
   for( int j = 0 ; j < N_Vsp ; j++ )
    for( int k = 0 ; k < N_Vsp ; k++ )
     g_vsp[j][k] = is_edge( Vsp[j] , Vsp[k] );
   graph G( g_vsp );
   std::string cert2 = G.Cert3();
   */

   //std::cerr<<"Vertices : ";
   //for( auto i : Vsp ) std::cerr<< i << ' ';
   //std::cerr<<std::endl;
   
   cert = Cert3( Vsp );
   
   /*
   if( cert != cert2 ){
    std::cerr<<"Vertices : ";
    for( auto i : Vsp ) std::cerr<< i << ' ';
    std::cerr<<std::endl;
    std::cerr<<"Different"<<std::endl;
    std::cerr<<cert<<std::endl<<cert2<<std::endl;
   }
   */
   
   

   //std::cerr<<cert<<std::endl;
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
   if( Vsp.size() != 0 ) expand2( Vsp , next );
  }
 }
}


#endif