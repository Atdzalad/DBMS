#include "pch.h"
#include "CppUnitTest.h"
#include "../proj/block.h"
#include "../proj/file.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
TEST_CLASS(File_UnitTest)
	{
	public:
		
		TEST_METHOD(Test_Create)
		{
            Data_block *block = (Data_block *) _aligned_malloc(BLOCK_SIZE, BLOCK_SIZE);
			File file;
			int ret = file.create("i://filetest", 512, block);
//            int ret = 0;
			Assert::AreEqual(ret, 1);
		}

		TEST_METHOD(FILE_OPERATE)
        {
            Data_block *block = (Data_block *) _aligned_malloc(BLOCK_SIZE, BLOCK_SIZE);
            Bool data[12] = {1, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            Record *record = (Record *) data;
            File file;
            int ret = file.create("i://filetest", 512 , block);
            Assert::AreEqual(ret, 1);

        }

		TEST_METHOD(BLOCK_ADD)
		{ 
			Data_block *block = (Data_block *) malloc(BLOCK_SIZE);
            Bool data[12] = {1, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            block->header.count = 0;
            block->header.free = sizeof(Header);
            Record *record = (Record *) data;
            block->Add_Record(record);
            Assert::AreEqual(
                (unsigned long long)(block->Get_tailer()->directory[0]), sizeof(Header) + 12);
            Assert::AreEqual(1, (int)block->header.count);
            Assert::AreEqual((long long)block->header.free,(long long)sizeof(Header)+12);

		}

		TEST_METHOD(BLOCK_CHANGE)
		{
            Data_block *block = (Data_block *) malloc(BLOCK_SIZE);
            Bool data[12] = {1, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            block->header.count = 0;
            block->header.free = sizeof(Header);
            Record *record = (Record *) data;
            block->Add_Record(record);
            Bool data2[12] = {12, 105, 1, 2, 3, 9, 3, 3, 5, 6, 7, 9};
            block->Change_record(1, (Record *) data2);
			for (int i = 0; i < 12; i++)
			{
                Bool* datacompare=(Bool *) &block->header + 12;
                Assert::AreEqual(data[i], datacompare[i]);
			}

		}

        TEST_METHOD(BLOCK_DEL) 
		{
		
			Data_block *block = (Data_block *) malloc(BLOCK_SIZE);
            Bool data[12] = {1, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            block->header.count = 0;
            block->header.free = sizeof(Header);
            Record *record = (Record *) data;
            block->Add_Record(record);
            block->Add_Record(record);
            block->Update_record(1);
            Assert::AreEqual((int)block->header.count,1);
            Assert::AreEqual((unsigned long long)block->header.free,sizeof(Header)+12);
		}
	};
}