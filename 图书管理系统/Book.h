//
//  Book.h
//  ͼ�����ϵͳ
//
//  Created by Ф���� on 15/9/17.
//  Copyright (c) 2015�� Ф����. All rights reserved.
//

#ifndef __________Book__
#define __________Book__

#include <stdio.h>
#include "WinCon.h"

#endif /* defined(__________Book__) */

void GuideInput();

#define NUM1 128
#define NUM2 50
class CBook
{
protected:
    char m_cName[NUM1];
    char m_cIsbn[NUM1];
    char m_cPrice[NUM2];
    char m_cAuthor[NUM2];
public:
    CBook(){}
    CBook(char*cName, char*cIsbn, char*cPrice, char*cAuthor);
    ~CBook(){}
public:
    char* GetName();    //��ȡͼ����
    void SetName(char* cName);  //����ͼ������
    char* GetPrice();   //��ȡ�۸�
    void SetPrice(char* cPrice);    //���ü۸�
    char* GetIsbn();   //��ȡͼ���ISBN���
    void SetIsbn(char* cIsbn);     //����ͼ���ISBN���
    char* GetAuthor();  //��ȡͼ�������
    void SetAuthor(char* cAuthor);  //����ͼ�������
    void WriteData();
    void DeleteData(int iCount);
    void GetBookFromFile(int iCount);
};

void DeleteBookFromFile();
