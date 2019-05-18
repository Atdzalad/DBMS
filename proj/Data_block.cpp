#include <iostream>
#include <stdlib.h>
#include <string.h>
#include"Data_block.h"


// Record
bool *Record::Get_data() { return (bool *) this + 2; }

// Block
Tailer *Data_block::Get_tailer()//��ȡƫ������ͷָ��
{
    return (Tailer *) ((bool *) (&header) + BLOCK_SIZE - (2 * header.count));
}

BOOL Data_block::Add_Record(Record *buffer)//��Ӽ�¼
{
    if (BLOCK_SIZE - (header.free + 2 * header.count) < buffer->size + 2) {
        return false;								//�ռ䲻�㷵��False
    } else {
        memcpy(
            (bool *) this + header.free ,
            buffer->Get_data(),
            buffer->size);							//д��RecordData

        header.count++;								//��¼����һ
        header.free += (buffer->size );				//����free�׵�ַ
        (Get_tailer()->directory[0]) = header.free; //����Tailer

        header.Checksum_compute();					//���¼���У���
        return true;
    }
}

Record *Data_block::Serch_record(bool num) //���Ҽ�¼
{
    return (Record*) ((bool *) &header + Get_tailer()->directory[header.count - num]);
}

BOOL Data_block::Change_record(bool num, Record *NewRecord)//�޸ļ�¼
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

BOOL Data_block::Update_record(bool num)//���¼�¼
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
