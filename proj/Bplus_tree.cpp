#include <algorithm>
#include "Bplus_tree.h"
void Insert(char *key, char *pointer);

bool Bplus_tree::Insert_key(char key, Tree_node index, Data_block *datapointer)
{
    if (root->If_leaf()) //���ڵ���Ҷ�ӽڵ�
    {
        if (root->header.count != MAXKEY) ////���ڵ�δ��
        {
            root->key[root->header.count] = key;
            root->pointer[root->header.count] = (char*)datapointer;
        } 
		else ////���ڵ�����
        {
            Tree_node *temproot = new Tree_node;
            Data_block *tmeppointer[MAXKEY + 1];

        }

    } else //���ڵ㲻��Ҷ�ӽڵ�
    {
    }
}

bool Bplus_tree::Delete_key(char key) {}

bool Bplus_tree::Serch_key(char key) {}





void Insert(char* key, char* pointer)
{

}