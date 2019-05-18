#include"block.h"

// Header
void Header::Checksum_compute() //求校验和
{
    unsigned int tempsum = 0;
    for (int i = 0; i < free / 2; i++) {
        tempsum += ((unsigned short *) this)[i]; //累加
        if (tempsum >> 16)                       //回卷
        {
            tempsum = tempsum + 1 - 0x100;
        }
    }
    checksum = ~tempsum; //取反
    return;
}

