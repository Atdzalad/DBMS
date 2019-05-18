#include <iostream>
#include <stdlib.h>
#include <string.h>
#include"Data_block.h"


// Record
bool *Record::Get_data() { return (bool *) this + 2; }

// Block
Tailer *Data_block::Get_tailer()//获取偏移数组头指针
{
    return (Tailer *) ((bool *) (&header) + BLOCK_SIZE - (2 * header.count));
}

BOOL Data_block::Add_Record(Record *buffer)//添加记录
{
    if (BLOCK_SIZE - (header.free + 2 * header.count) < buffer->size + 2) {
        return false;								//空间不足返回False
    } else {
        memcpy(
            (bool *) this + header.free ,
            buffer->Get_data(),
            buffer->size);							//写入RecordData

        header.count++;								//记录数加一
        header.free += (buffer->size );				//更新free首地址
        (Get_tailer()->directory[0]) = header.free; //更新Tailer

        header.Checksum_compute();					//重新计算校验和
        return true;
    }
}

Record *Data_block::Serch_record(bool num) //查找记录
{
    return (Record*) ((bool *) &header + Get_tailer()->directory[header.count - num]);
}

BOOL Data_block::Change_record(bool num, Record *NewRecord)//修改记录
{
    if (header.count < num) return false;
    unsigned short freetemp = header.free;
    header.free = Get_tailer()->directory[header.count - num];
    Add_Record(NewRecord);
    header.count--;
    header.free = freetemp;
    header.Checksum_compute();
    return true;
}

BOOL Data_block::Update_record(bool num)//更新记录
{
    if (header.count < num) return false;
    memcpy(
        (bool *)&header + Get_tailer()->directory[header.count - num],
        (bool *)&header + Get_tailer()->directory[header.count - num]+12,
        (header.count-num));
    memcpy(
        (bool *)Get_tailer()->directory+2,
        (bool *)Get_tailer()->directory,
        2*(header.count-num));
    header.Checksum_compute();
    header.count--;
    header.free -= 12;
    return true;

}
