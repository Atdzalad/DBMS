#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "block.h"
#include "pch.h"

// Header
void Header::compute() //��У���
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
        return false; //�ռ䲻�㷵��False
    } else {
        memcpy(
            (byte *) this + header.free ,
            buffer->data(),
            buffer->size); //д��RecordData

        header.count++;                            //��¼����һ
        header.free += (buffer->size );         //����free�׵�ַ
        (gettailer()->directory[0]) = header.free; //����Tailer

        header.compute(); //���¼���У���
        return true;
    }
}

Record *Block::Serch(byte num) //���Ҽ�¼
{
    return (Record*) ((byte *) &header + gettailer()->directory[header.count - num]);
}

BOOL Block::Change(byte num, Record *NewRecord) //�޸ļ�¼
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
