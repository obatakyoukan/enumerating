#ifndef TREE_HPP
#define TREE_HPP
#include <vector>

struct node {
 //int val;
 std::vector< node* > children;
 std::vector< int > path; // children[i]へは，path[i]を追加したことど同じ


 node(){}
 //node(int val):val(val){}

 int size() { return children.size() ; }
 bool leaf() { return children.size() == 0  ? true : false; }
 //void print();
 void push( int v ){
  node* a = new node;
  //a->val = v;
  path.push_back( v );
  children.push_back( a );
 }
 void push( node* a , int v){
  path.push_back( v );
  children.push_back( a );
 }
};

struct tree{
 node root;
 tree(){}
 void dfs(node& a);
};

#endif
