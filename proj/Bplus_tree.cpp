#include <algorithm>
#include "Bplus_tree.h"
bool Bplus_tree::Insert_key(char key, Data_block *datapointer)
{
    Tree_node *newroot;
    if (root->header.count == MAXKEY) 
	{
        //newroot = new Tree_node;
        newroot = (Tree_node *) malloc(BLOCK_SIZE);
        (*newroot).pointer[0] = (char *) root;
        root->header.type = 1;
        root = newroot;
        (*root).header.type = 0;
        root->header.count = 0;
        Node_split(root, 0);
        Insert_nofull(root, key, datapointer);
        return true;
    } else {
        Insert_nofull(root, key, datapointer);
        return true;
    }
}

bool Bplus_tree::Delete_key(char key) { return false; }

bool Bplus_tree::Serch_key(char key) { return false; }

bool Bplus_tree::Insert_nofull(
    Tree_node *node,
    char key,
    Data_block *datapointer)
{
    if ((*node).header.type == 1) { //叶子节点插入
        int temp = 0;
        for (int i = 0; i < (*node).header.count && (*node).key[i] < key; i++) {
            temp = i + 1;
        }
        for (int j = temp; j < (*node).header.count; j++) {
            (*node).key[j + 1] = (*node).key[j];
            (*node).pointer[j + 1] = (*node).pointer[j];
        }
        (*node).key[temp] = key;
        (*node).pointer[temp] = (char *) datapointer;
        (*node).header.count++;
        return true;
    } else //内部节点插入
    {
        if (key > node->key[node->header.count - 1]) //插入至最后
        {
            if (((Tree_node *) (node->pointer[node->header.count]))
                    ->header.count == MAXKEY) {
                Node_split(node, node->header.count);
            } else {
                Insert_nofull(
                    ((Tree_node *) (node->pointer[node->header.count])),
                    key,
                    datapointer);
                return true;
            }
        } 
		else
		{
            int temp;
            for (int i = 0; i < (*node).header.count; i++) 
			{
                if (node->key[i] > key) 
				{
					if (((Tree_node *) (node->pointer[i]))
                            ->header.count == MAXKEY) {
                        Node_split(node, i);
                    } else {
                        Insert_nofull(
                            ((Tree_node *) (node->pointer[i])),
                            key,
                            datapointer);
                    }
                    return true;
				}
            }
        }
    }
}

bool Bplus_tree::Node_split(Tree_node *father, int aim)
{
    char mid = father->key[MINIKEY];
    Tree_node *newnode = (Tree_node*)malloc(BLOCK_SIZE);
    Tree_node *forsplit = (Tree_node *) (*father).pointer[aim];
    (*newnode).header.type = forsplit->header.type;
    if (forsplit->header.type != 1) //内部节点分裂
    {
        for (int i = 0; i < MINIKEY - 1; i++) {
            newnode->key[i] = forsplit->key[MINIKEY + i]; // key复制
        }
        for (int j = 0; j < MINIKEY; j++) {
            newnode->pointer[j] = forsplit->pointer[MINIKEY + j]; // pointer复制
        }
        newnode->header.count = MINIKEY - 1;
        forsplit->header.count = MINIKEY - 1;
        newnode->header.type = forsplit->header.type;
    } else //叶子节点分裂
    {
        for (int i = 0; i < MINIKEY - 1; i++) {
            newnode->key[i] = forsplit->key[MINIKEY + i]; // key复制
            newnode->pointer[i] = forsplit->pointer[MINIKEY + i];
        }
        newnode->header.count = MINIKEY - 1;
        forsplit->header.count = MINIKEY;
        newnode->header.type = forsplit->header.type;
    }
    father->header.count += 1;
    if (aim = father->header.count + 1) {
        father->key[aim] = mid;
        father->pointer[aim + 1] = (char *) newnode;
    } else {
        for (int i = aim; i <= father->header.count - 1; i++) {
            father->key[i + 1] = father->key[i];
        }
        father->key[aim] = mid;
        for (int j = aim + 1; j <= father->header.count; j++) {
            father->pointer[j + 1] = father->pointer[j];
        }
        father->pointer[aim + 1] = (char *) newnode;
    }
    return true;
}