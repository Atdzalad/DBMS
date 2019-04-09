#include "stdafx.h"
#include "CppUnitTest.h"
#include "file.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
    TEST_CLASS(FileUnitTest)
    {
    public:

        TEST_METHOD(TestCreate)
        {
            File file;
            std::string path = "c:/hello/world";
            int ret = file.create(path, 4096);
            Assert::AreEqual(ret, 0);
        }

    };
}
