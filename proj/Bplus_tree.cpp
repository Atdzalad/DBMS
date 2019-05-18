#include <algorithm>
#include "Bplus_tree.h"
void Insert(char *key, char *pointer);

bool Bplus_tree::Insert_key(char key, Tree_node index, Data_block *datapointer)
{
    if (root->If_leaf()) //根节点是叶子节点
    {
        if (root->header.count != MAXKEY) ////根节点未满
        {
            root->key[root->header.count] = key;
            root->pointer[root->header.count] = (char*)datapointer;
        } 
		else ////根节点已满
        {
            Tree_node *temproot = new Tree_node;
            Data_block *tmeppointer[MAXKEY + 1];

        }

    } else //根节点不是叶子节点
    {
    }
}

bool Bplus_tree::Delete_key(char key) {}

bool Bplus_tree::Serch_key(char key) {}





void Insert(char* key, char* pointer)
{

}