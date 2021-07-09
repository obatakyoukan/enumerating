#ifndef GRAPH_LIB_HPP
#define GRAPH_LIB_HPP

#include "graph_lib.hpp"

std::map< std::tuple<int,Vector> , std::vector<int> > graph::getPartitions(std::vector< int > &Vs) {
 std::map< std::tuple<int, Vector > , std::vector<int> > res;
 
 std::vector< int > deg = make_deg( Vs );
 for(int i = 0 ; i < Vs.size() ; i++ ) {
  int d1 = deg[i];
  std::vector< int > d2( Vs.size() , 0 );
  for( int j = 0 ; j < Vs.size() ;  j ++ ) {
   if( is_edge( Vs[i], Vs[j] ) ) d2[ deg[j] ]++;
  }
  Vector d2v( d2 );
  
  res[ std::tie( d1 , d2v ) ].push_back( Vs[i] );
  //res[ std::tie( d1 , d2v ) ].push_back( i );
 }
 return res;
}

std::map< std::tuple<int,Vector> , std::vector<int> > graph::getPartitions2(std::vector< int > &Vs) {
 std::map< std::tuple<int, Vector > , std::vector<int> > res;
 
 std::vector< int > deg = make_deg( Vs );
 for(int i = 0 ; i < Vs.size() ; i++ ) {
  int d1 = deg[i];
  std::vector< int > d2( Vs.size() , 0 );
  for( int j = 0 ; j < Vs.size() ;  j ++ ) {
   if( is_edge( Vs[i], Vs[j] ) ) d2[ deg[j] ]++;
  }
  Vector d2v( d2 );
  
  //res[ std::tie( d1 , d2v ) ].push_back( Vs[i] );
  res[ std::tie( d1 , d2v ) ].push_back( i );
 }
 return res;
}


std::map< std::tuple<int,Vector> , std::vector<int> > graph::getPartitions() {
 std::vector< int > Vs( size() );
 iota( Vs.begin() , Vs.end() , 0 );
 return getPartitions(Vs);
}


//要修正 Vs 持たせるなど ?? 　ひょっとしたら必要ない? mu , pi \in Vs
CompResult graph::Compare( std::vector< int > &mu , std::vector< int > &pi, int l ){
 for(int j = 1 ; j < l ; j++ ){
  for(int i = 0; i < j ; i++ ){
   int x = is_edge( mu[i], mu[j] ) ? 1 : 0;
   int y = is_edge( pi[i], pi[j] ) ? 1 : 0;
   if( x < y ) return CompResult::Worse;
   if( x > y ) return CompResult::Better;
  }
 }
 return CompResult::Equal;
}

#include <cassert>
#include <queue>
std::vector< std::vector< int > > graph::disjoint_graph( std::vector< int > &Vs ){
 std::vector< std::vector< int > > res;
 std::vector< bool > use( Vs.size() , false );

 for( int i = 0 ; i < Vs.size() ; i++ ){
  if( use[ i ] ) continue;
  std::vector< int > tmp;
  std::queue< int > que;
  que.push( i );
  use[i] = true;
  while( !que.empty() ){
   int now = que.front();
   que.pop();
   tmp.push_back( Vs[now] );
   //tmp.push_back( now );
   for( int j = 0 ; j < Vs.size() ; j++ ){
    if( is_edge( Vs[now] , Vs[j] ) and !use[ j ] ){
     que.push( j );
     use[ j ] = true;
    }
   }
  }
  res.push_back( tmp );
 }

 int sum = 0;
 for( int i = 0 ; i < res.size(); i++ ) sum += res[i].size();
 assert( sum == Vs.size() );

 return res;
}


#endif
