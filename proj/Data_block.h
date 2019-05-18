#pragma once
#include"block.h"

#pragma pack(push)
#pragma pack(1)

struct Record
{
    const static unsigned int size = 12;

  public:
    bool *Get_data();								//��ȡ��¼����
};

struct Tailer
{
    unsigned short directory[1];					// ���������ļ�¼ƫ��������
};
#pragma(pop)

struct Data_block
{
    const static unsigned int size =
        512;										// ȫ�־�̬����������ھ�̬�����������СΪ512 BYTES
    Header header;									// ͷ��

  public:
    Tailer *Get_tailer();                            //��ȡβ��
    BOOL Add_Record(Record *buffer);                 //��Ӽ�¼
    Record *Serch_record(bool num);                  //������¼
    BOOL Change_record(bool num, Record *NewRecord); //�޸ļ�¼
    BOOL Update_record(bool num);                    //ɾ����¼
};
