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
#include <conio.h>
#include <string>
#include <fstream>
#include "Book.h"

#define CMD_COLS 80
#define CMD_LINES 25
using namespace std;

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