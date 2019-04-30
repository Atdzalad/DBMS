#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "block.h"
#include "pch.h"

// Header
void Header::compute() //求校验和
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

// Record
byte *Record::data() { return (byte *) this + 2; }

// Block
Tailer *Block::gettailer()
{
    return (Tailer *) ((byte *) (&header) + BLOCK_SIZE - (2 * header.count));
}

BOOL Block::addRecord(Record *buffer)
{
    if (BLOCK_SIZE - (header.free + 2 * header.count) < buffer->size + 2) {
        return false; //空间不足返回False
    } else {
        memcpy(
            (byte *) this + header.free ,
            buffer->data(),
            buffer->size); //写入RecordData

        header.count++;                            //记录数加一
        header.free += (buffer->size );         //更新free首地址
        (gettailer()->directory[0]) = header.free; //更新Tailer

        header.compute(); //重新计算校验和
        return true;
    }
}

Record *Block::Serch(byte num) //查找记录
{
    return (Record*) ((byte *) &header + gettailer()->directory[header.count - num]);
}

BOOL Block::Change(byte num, Record *NewRecord) //修改记录
{
    if (header.count < num) return false;
    unsigned short freetemp = header.free;
    header.free = gettailer()->directory[header.count - num];
    addRecord(NewRecord);
    header.count--;
    header.free = freetemp;
    header.compute();
    return true;
}

BOOL Block::Del(byte num) 
{
    if (header.count < num) return false;
    memcpy(
        (byte *)&header + gettailer()->directory[header.count - num],
        (byte *)&header + gettailer()->directory[header.count - num]+12,
        (header.count-num));
    memcpy(
        (byte *)gettailer()->directory+2,
        (byte *)gettailer()->directory,
        2*(header.count-num));
    header.compute();
    header.count--;
    header.free -= 12;
    return true;

}
