//
//  ViewData.cpp
//  图书管理系统
//
//  Created by 肖镇龙 on 15/9/26.
//  Copyright © 2015年 肖镇龙. All rights reserved.
//

#include <stdio.h>
#include "book.h"
#include <fstream>
#include "WinCon.h"
#include <iostream>
#include <iomanip>
using namespace std;
void ViewData(int iSelPage = 1)
{
    long GetFileLength(ifstream & ifs);
    int iPage = 0;
    int iCurPage = 0;
    int iDataCount = 0;
    char inName[NUM1];  //储存图书名称的变量
    char inIsbn[NUM1];  //储存图书ISBN编号的变量
    char price[NUM2];   //储存图书价格的变量
    char inAuthor[NUM2];    //储存图书作者的变量
    bool bIndex = false;
    int iFileLength;
    iCurPage = iSelPage;
    ifstream ifile;
    ifile.open("book.dat", ios::binary);
    iFileLength = GetFileLength(ifile);
    iDataCount = iFileLength/(NUM1+NUM1+NUM2+NUM2);    //根据文件长度，计算文件中总的记录数
    if (iDataCount >= 1)
        bIndex = true;
    iPage = iDataCount/20 + 1;
    ClearScreen();          //清除屏幕信息
    cout << " 共有记录" << iDataCount << " ";
    cout << " 共有页数" << iPage << " ";
    cout << " 当前页数" << iCurPage << " ";
    cout << " n 显示下一页 m 返回" << endl;
    cout << setw(5) << "Index";
    cout << setw(22) << "Name" << setw(22) << "Isbn";
    cout << setw(15) << "Price" << setw(15) << "Author";
    cout << endl;
    try
    {
        //根据图书记录编号查找在文件中的位置
        ifile.seekg((iCurPage - 1)*20*(NUM1+NUM1+NUM2+NUM2), ios::beg);
        if(!ifile.fail())
        {
            for (int i = 1; i < 21; i++)
            {
                memset(inName, 0, 128);     //将变量清零
                memset(inIsbn, 0, 128);
                memset(price, 0, 50);
                memset(inAuthor, 0, 50);
                if (bIndex)
                    cout << setw(3) << ((iCurPage - 1)*20 + i);
                ifile.read(inName, NUM1);   //读取图书名称
                cout << setw(24) << inName;
                ifile.read(inIsbn, NUM1);   //读取图书ISBN编号
                cout << setw(24) << inIsbn;
                ifile.read(price, NUM2);    //读取图书价格
                cout << setw(12) << price;
                ifile.read(inAuthor, NUM2); //读取图书作者
                cout << setw(12) << inAuthor;
                cout << endl;
                if (ifile.tellg() < 0)
                    bIndex = false;
                else
                    bIndex = true;
            }
        }
    }
    catch(...)
    {
        cout << "throw file exception" << endl;
        throw "file error occurred";    //抛出异常
        ifile.close();                  //异常后关闭文件流
    }
    if (iCurPage < iPage)
    {
        iCurPage = iCurPage + 1;
        WaitView(iCurPage);             //等待用户处理
    }
    else
    {
        WaitView(iCurPage);
    }
    ifile.close();
}

/*计算文件总长度，并将指针放回当前位置*/
long GetFileLength(ifstream &ifs)
{
    long tmppos;
    long respos;
    tmppos = ifs.tellg();
    ifs.seekg(0, ios::end);
    respos = ifs.tellg();
    ifs.seekg(tmppos, ios::beg);
    return respos;
}
