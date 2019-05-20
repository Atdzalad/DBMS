////
// @main main.cpp
// @brief
// 实现文件
//
// @author zhangzhe
// @email 18909545659@163.com
//
#include <iostream>
#include "Data_block.h"
#include "Tree_node.h"
#include "file.h"
#include "Bplus_tree.h"

int main(int argc, char *argv[])
{
    Bplus_tree tree;
    tree.root = (Tree_node *) malloc(BLOCK_SIZE);
    std::cout << tree.root << std::endl;
    Data_block *a = (Data_block *) malloc(BLOCK_SIZE);
    tree.root->header.count = 0;
    tree.root->header.type = 1;
    for (int i = 1; i <= 1000; i++) {
        tree.Insert_key(i, a);
    }
    //tree.Insert_key(70, a);
    //tree.Insert_key(1000, a);
    Tree_node *c1 = (Tree_node *) tree.root->pointer[0];
    Tree_node *c2 = (Tree_node *) tree.root->pointer[1];
    Tree_node *c3 = (Tree_node *) tree.root->pointer[17];
    
    system("pause");
    return 0;
}
