//
//  Book.cpp
//  图书管理系统
//
//  Created by 肖镇龙 on 15/9/17.
//  Copyright (c) 2015年 肖镇龙. All rights reserved.
//
//  实现图书信息的读取、删除、信息更改和信息录入

#include "Book.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
CBook::CBook(char*cName, char*cIsbn, char*cPrice, char*cAuthor)
{
    strcmp(m_cName, cName);
    strcmp(m_cIsbn, cIsbn);
    strcmp(m_cPrice, cPrice);
    strcmp(m_cAuthor, cAuthor);
}

char* CBook::GetName()
{
    return m_cName;
}

char* CBook::GetIsbn()
{
    return m_cIsbn;
}

char* CBook::GetPrice()
{
    return m_cPrice;
}

char* CBook::GetAuthor()
{
    return m_cAuthor;
}

void CBook::SetName(char* cName)
{
    strcmp(m_cName, cName);
}

void CBook::SetIsbn(char* cIsbn)
{
    strcmp(m_cIsbn, cIsbn);
}

void CBook::SetPrice(char *cPrice)
{
    strcmp(m_cPrice, cPrice);
}

void CBook::SetAuthor(char *cAuthor)
{
    strcmp(m_cAuthor, cAuthor);
}

void CBook::WriteData()
{
    ofstream ofile;
    ofile.open("book.dat", ios::binary | ios::app);
    try
    {
        ofile.write(m_cName, NUM1);
        ofile.write(m_cIsbn, NUM1);
        ofile.write(m_cPrice, NUM2);
        ofile.write(m_cAuthor, NUM2);
    }
    catch (...)
    {
        throw "file error occured";
        ofile.close();
    }
    ofile.close();
}

void CBook::GetBookFromFile(int iCount)
{
    char cName[NUM1];
    char cIsbn[NUM1];
    char cPrise[NUM2];
    char cAuthor[NUM2];
    ifstream ifile;
    ifile.open("book.dat", ios::in | ios::binary);
    try
    {
        ifile.seekg(iCount*(NUM1 + NUM1 + NUM2 + NUM2), ios::beg);
        ifile.read(cName, NUM1);
        if (ifile.tellg()>0)
        {
            strncpy(m_cName, cName, NUM1);
        }
        ifile.read(cIsbn, NUM1);
        if (ifile.tellg()>0)
        {
            strncpy(m_cIsbn, cIsbn, NUM1);
        }
        ifile.read(cPrise, NUM2);
        if (ifile.tellg()>0)
        {
            strncpy(m_cPrice, cPrise, NUM2);
        }
        ifile.read(cAuthor, NUM2);
        if (ifile.tellg()>0)
        {
            strncpy(m_cAuthor, cAuthor, NUM2);
        }
    }
    catch (...)
    {
        throw "file get occurred";
        ifile.close();
    }
    ifile.close();
}

void CBook::DeleteData(int iCount)
{
    long respos;
    int iDataCount = 0;
    fstream file;
    //定义输入流file <- book.dat
    fstream tmpfile;
    //定义临时文件输入流 tmpfile <- temp.dat
    char cTempBuf[NUM1 + NUM1 + NUM2 + NUM2];
    ofstream ofile;
    file.open("book.dat", ios::binary | ios::in | ios::out);
    tmpfile.open("temp.dat", ios::binary | ios::in | ios::out | ios::trunc);
    file.seekg(0, ios::end);
    respos = file.tellg();
    iDataCount = respos / (NUM1 + NUM1 + NUM2 + NUM2);
    if (iCount < 0 && iCount > iDataCount)
    {
        throw "Input number error";
    }
    else
    {
        file.seekg(iCount*(NUM1 + NUM1 + NUM2 + NUM2), ios::beg);
        for (int j = 0; j <(iDataCount - iCount); j++)
        {
            memset(cTempBuf, 0, NUM1 + NUM1 + NUM2 + NUM2);
            file.read(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);
            tmpfile.write(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);
        }
        file.close();
        tmpfile.seekg(0, ios::beg);
        ofile.open("book.dat");
        ofile.seekp((iCount - 1)*(NUM1 + NUM1 + NUM2 + NUM2), ios::beg);
        for (int i = 0; i < (iDataCount - iCount); i++)
        {
            memset(cTempBuf, 0, NUM1 + NUM1 + NUM2 + NUM2);
            tmpfile.read(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);
            ofile.write(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);
        }
    }
    tmpfile.close();
    ofile.close();
    remove("temp.dat");
}
