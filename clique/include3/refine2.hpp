#ifndef REFINE2_HPP
#define REFINE2_HPP
#include "graph.hpp"
#include "graph_lib.hpp"
#include "basic_function.hpp"

std::map< int, std::set<int> > graph::REFINE2( std::map< int , std::set<int> > &A , std::vector< int > &Vs ){
 std::map< int , std::set<int> > B = A;
 std::map< int , std::set<int> > S;
 for( auto it : B )
  S[ B.size() - 1 - it.first ] = it.second;

 std::set< int > U , T;
 for( auto v : Vs ) U.insert( v );
 int N = B.size();
 while( N != 0 ) {
  N--;
  T = S[ N ];
  if( basic_function::SetInclude( T , U ) ){
   basic_function::SetDelete( U , T );
   int j = 0;
   //while( j < B.size() and B.size() < n )
   while( j < B.size() and B.size() < Vs.size() )
   {
    if( B.size() != 1 ) {
     SpritAndUpdate2( B , j , N , U , S , T , Vs );
    }
    j++;
   }
   //if( B.size() == n ) return B;
   if( B.size() == Vs.size() ) return B;
  }
 }
 return B;
}

void graph::SpritAndUpdate2( std::map< int,std::set<int> > &B , int j , 
  int &N , std::set< int >  &U, std::map< int,std::set< int > > &S, std::set< int > &T , std::vector< int > &Vs ) {
 std::map<int, std::set<int> > L;
 for( auto u : B[j] ){
  int h = AbsAndSet2( u , T , Vs );
  L[h].insert( u );
 }
 int m = 0;
 //for(int h = 0 ; h < n ; h++ )
 for(int h = 0 ; h < Vs.size() ; h++ )
  if( L[h].size() != 0 ) m++;
 if( m > 1 ){
  for( int h = B.size() - 1 ; h > j ; h-- )
   B[ m - 1 + h ] = B[ h ];
  int k = 0;
  //for( int h = 0 ; h < n ; h++ )
  for( int h = 0 ; h < Vs.size() ; h++ )
   if( L[h].size() != 0 ){
    B[ j + k ] = L[h];
    S[ N + m -1 -k ] = L[h];
    //S[ N + k ] = L[h];
    for( auto x : L[h] ) U.insert( x );
    k++;
   }
  j += m - 1;
  N += m;
 }
}

int graph::AbsAndSet2( int u, std::set< int > &T , std::vector< int > &Vs ){
 int res = 0;
 //for( int i = 0 ; i < n ; i++ ) 
 //for( int i : Vs ) 
 for( int i = 0 ; i < Vs.size() ; i++ ) 
  if( is_edge( Vs[u] , Vs[i] ) ) {
   auto it = T.find( i );
   if( it != T.end() ) res++; 
  }
 return res;
}

CompResult graph::Compare2( std::vector< int > &mu , std::vector< int > &pi, int l , std::vector<int> &Vs ){
 for(int j = 1 ; j < l ; j++ ){
  for(int i = 0; i < j ; i++ ){
   int x = is_edge( Vs[ mu[i] ] , Vs[ mu[j] ] ) ? 1 : 0;
   int y = is_edge( Vs[ pi[i] ] , Vs[ pi[j] ] ) ? 1 : 0;
   if( x < y ) return CompResult::Worse;
   if( x > y ) return CompResult::Better;
  }
 }
 return CompResult::Equal;
}




#endif
