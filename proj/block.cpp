#include"block.h"

// Header
void Header::Checksum_compute() //��У���
{
    unsigned int tempsum = 0;
    for (int i = 0; i < free / 2; i++) {
        tempsum += ((unsigned short *) this)[i]; //�ۼ�
        if (tempsum >> 16)                       //�ؾ�
        {
            tempsum = tempsum + 1 - 0x100;
        }
    }
    checksum = ~tempsum; //ȡ��
    return;
}

