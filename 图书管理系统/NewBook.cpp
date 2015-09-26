//
//  NewBook.cpp
//  图书管理系统
//
//  Created by 肖镇龙 on 15/9/25.
//  Copyright © 2015年 肖镇龙. All rights reserved.
//

#include "NewBook.h"
#include "Book.h"
#include <iostream>
#include "WinCon.h"
using namespace std;

void GuideInput()
{
    char inName[NUM1];
    char inIsdn[NUM1];
    char inPrise[NUM2];
    char inAuthor[NUM2];
    
    cout << "输入书名" << endl;
        cin >> inName;
    cout << "输入ISBN" << endl;
        cin >> inIsdn;
    cout << "输入价格" << endl;
        cin >> inPrise;
    cout << "输入作者" << endl;
        cin >> inAuthor;
    CBook book(inName, inIsdn, inPrise, inAuthor);
    book.WriteData();
    cout << "Write Finish" << endl;
    WaitUser();
}