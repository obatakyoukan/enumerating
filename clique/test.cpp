#include "tree.hpp"
#include "tree_function.hpp"

int main() {
 tree t;
 //t.root.val = -1;
 for(int i = 1 ; i <= 2 ; i++ ){
  t.root.push( i );
 }
 for( int i = 0 ; i < 2; i++ ){
  for(int j = 0 ; j <= 3 ; j++ ){
  (*t.root.children[i]).push( j );
  }
 }
 std::cout<<"DFS"<<std::endl;
 t.dfs( t.root );
 std::cout<<std::endl;

}

