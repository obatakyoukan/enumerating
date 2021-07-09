#ifndef TREE_FUNCTION_HPP
#define TREE_FUNCTION_HPP
#include "tree.hpp"
#include <iostream>
#include <map>
/*
void node::print(){
 std::cout<< val << std::endl;
}
*/

void tree::dfs(node& a) {//列挙では，頂点修復用の方法を作る必要があり，
 // a.print();
 if( a.leaf() ) return;
 std::cout<< "(";
 for(int i = 0 ; i < a.size() ; i++ ){
  std::cout<< a.path[i] ;
  dfs( *a.children[i] );
 }
 std::cout<< ")";
}

int tree::sum( node& a ){
 if( a.val != -1 ) return a.val;
 if( a.leaf() ) return a.val = 1;
 int res = 1;//ここまででできるケース
 std::map< int , int > cnt;
 for( int i = 0 ; i < a.size() ; i++ ){
  cnt[ a.path[i] ]++;
  res += sum( *a.children[i] );
 }
 for( auto i : cnt )
  res -= i.second - 1 ;
 return a.val = res;
}

#endif
