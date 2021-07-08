#ifndef TREE_2_HPP
#define TREE_2_HPP
#include <vector>

struct node2 {
 std::vector< std::vector< node2* > > children;
 std::vector< int > path;
 node2(){}

 int size() { return children.size(); }
 bool leaf() { return children.size() == 0 ? true : false ; }
 void push( std::vector< node2* > &a , int v ){
  path.push_back( v );
  children.push_back( a );
 }

};

struct tree2 {
 node2 root;
 tree() {}
 void dfs( node2& a );
};

void tree2::dfs( node2& a ){
 if( a.leaf() ) return;
 std::cout<<"(";
 for( int i = 0 ; i < a.size() ; i++ ) {
  std::cout<< a.path[i];
  for( int j = 0 ; j < a.children[i].size() ; j++ ){
   if( j != 0 ) 
    std::cout<<"|";
   dfs( *a.children[i][j] );
  }
 }
 std::cout<<")";
}

#endif
