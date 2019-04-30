////
// @file file.cpp
// @brief
// 实现文件
//
// @author zhangzhe
// @email 18909545659@163.com
//
#include"block.h"
#include "pch.h"
#include "file.h"

int File::create(LPCSTR path, int size,void* file)
{
    LPDWORD bytenum = 0;
    handle_ = CreateFileA(
        path,
        GENERIC_WRITE,
        FILE_SHARE_READ,
        nullptr,
        OPEN_EXISTING,
        FILE_FLAG_NO_BUFFERING,
        nullptr);
    if (handle_ != INVALID_HANDLE_VALUE)  return false; //文件已经存在
    handle_ = CreateFileA(
        (LPCSTR) path,
        GENERIC_WRITE,
        FILE_SHARE_READ,
        nullptr,
        CREATE_NEW,
        FILE_FLAG_NO_BUFFERING,
        nullptr);
    Block *block = (Block *) file;

    WriteFile(handle_, block, size, bytenum, nullptr);

    return true;
}