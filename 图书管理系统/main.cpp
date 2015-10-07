//
//  main.cpp
//  图书管理系统
//
//  Created by 肖镇龙 on 15/9/17.
//  Copyright (c) 2015年 肖镇龙. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <fstream>
#include "Book.h"
#include "WinCon.h"

#define CMD_COLS 80
#define CMD_LINES 25
using namespace std;



void main()
{
    
    SetScreenGrid();
    SetSysCaption("图书管理系统");
    mainloop();
 }


