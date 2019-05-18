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
    int i = 100;
    while (i--) {
        tree.Insert_key(i, a);
        std::cout << tree.root << std::endl;
    }
    
    // std::cout << sizeof(bool);
    system("pause");
    return 0;
}
