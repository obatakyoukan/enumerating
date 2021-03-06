#ifndef TREE_FUNCTION_HPP
#define TREE_FUNCTION_HPP
#include "tree.hpp"
#include <iostream>

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

#endif
