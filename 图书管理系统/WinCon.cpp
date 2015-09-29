//
//  WinCon.cpp
//  图书管理系统
//
//  Created by 肖镇龙 on 15/9/25.
//  Copyright © 2015年 肖镇龙. All rights reserved.
//

#include "WinCon.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "conio.h"
#include <string>
#include <fstream>
#include "Book.h"

#define CMD_COLS 80
#define CMD_LINES 25
using namespace std;
void ViewData(int iSelPage);

/*SetScreenGrid函数主要通过system函数来执行mode命令*/
void SetScreenGrid()
{
    char sysSetBuff[80];
    sprintf(sysSetBuff, "mode con cols=%d lines=%d", CMD_COLS, CMD_LINES);
    system(sysSetBuff);
}

/*该函数主要完成在控制台的标题栏上显示Sample信息。控制台的标题栏信息可以使用title命令来设置，函数中使用system函数来执行title命令*/
void SetSysCaption()
{
    system("title Sample");
}

/*ClearScreen函数主要通过system函数来执行cls命令，完成控制台屏幕信息的清除*/
void ClearScreen()
{
    system("cls");
}

/*SetSysCaption函数的另一个版本，实现在控制台的标题栏上显示指定字符*/
void SetSysCaption(const char *pText)
{
    char sysSetBuf[80];
    sprintf(sysSetBuf, "title %s", pText);
    system(sysSetBuf);
}

/*ShowWelcome函数在屏幕上显示“图书管理系统”字样的欢迎信息*/
void ShowWelcome()
{
    for (int i = 0; i < 7; i++)
    {
        cout << endl;
    }
    cout << setw(40);
    cout << "************" << endl;
    cout << setw(40);
    cout << "图书管理系统" << endl;
    cout << setw(40);
    cout << "************" << endl;
}

/*ShowRootMenu函数主要显示系统的主菜单，系统中有3个菜单选项，分别是添加新书、浏览全部和删除图书。3个菜单选项是进入系统3个模块的入口*/
void ShowRootMenu()
{
    cout << setw(40);
    cout << "请选择功能" << endl;
    cout << endl;
    cout << setw(38);
    cout << "1 添加新书" << endl;
    cout << endl;
    cout << setw(38);
    cout << "2 浏览全部" << endl;
    cout << endl;
    cout << setw(38);
    cout << "3 删除图书" << endl;
}

/*WaitUser函数主要负责当程序进入某一模块后，等待用户进行处理。用户可以选择返回主菜单，也可以直接退出系统*/
void WaitUser()
{
    int ilnputPage = 0;
    cout << "enter 返回主菜单  q 退出" << endl;
    char buf;
    cin >> buf;
    if (buf == 'q')
        system("exit");
}

int GetSelect()
{
    char buf[256];
    gets(buf);
    return atoi(buf);
}

void WaitView(int  iCurPage)
{
    char buf[256];
    gets(buf);
    if(buf[0]=='q')
        system("exit");
    if(buf[0]=='m')
        mainloop();
    if(buf[0]=='n')
        ViewData(iCurPage);
}

void mainloop()
{
    ShowWelcome();
    while(1)
    {
        ClearScreen();
        ShowWelcome();
        ShowRootMenu();
        switch(GetSelect())
        {
            case 1:
                ClearScreen();
                GuideInput();
                break;
            case 2:
                ClearScreen();
                int iSelPage;
                cin >> iSelPage;
                ViewData(iSelPage);
                break;
            case 3:
                ClearScreen();
                DeleteBookFromFile();
                break;
        }
    }
}

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