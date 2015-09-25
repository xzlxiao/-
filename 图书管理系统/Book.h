#pragma once
//
//  Book.h
//  图书管理系统
//
//  Created by 肖镇龙 on 15/9/17.
//  Copyright (c) 2015年 肖镇龙. All rights reserved.
//


#pragma once
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
	CBook() {}
	CBook(char*cName, char*cIsbn, char*cPrice, char*cAuthor);
	~CBook() {}
public:
	char* GetName();    //获取图书名
	void SetName(char* cName);  //设置图书名称
	char* GetPrice();   //获取价格
	void SetPrice(char* cPrice);    //设置价格
	char* GetIsbn();   //获取图书的ISBN编号
	void SetIsbn(char* cIsbn);     //设置图书的ISBN编号
	char* GetAuthor();  //获取图书的作者
	void SetAuthor(char* cAuthor);  //设置图书的作者
	void WriteData();
	void DeleteData(int iCount);
	void GetBookFromFile(int iCount);
};
