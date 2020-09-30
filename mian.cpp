//Discription: This is a demo for Realtime drawing
//Createy by Lin
//Update: 29,Sept,2020 
//        
//Functions: 
//Issue: #1 Can not draw two drawings
//       #2 Console window will be occupied, and can not open a new console window
//           
#include <iostream>
#include <string>
#include<thread>
#include<windows.h>
#include<mutex>
#include <condition_variable>

#include "draw.h"
#define PI 3.141592


double res = 0;
std::mutex data_mutex;
std::condition_variable data_var;
bool flag = true;

void generateData()
{
	int i = 0;

	while (1)
	{
		Sleep(100);
		std::unique_lock<std::mutex> lck(data_mutex);
		data_var.wait(lck, [] {return flag;});
		res = sin(2 * PI * 5 * i / 500);
		i++;
		flag = false;
		data_var.notify_one();
	}


}


/*************************** MAIN 函数 *********************************/
int main()
{

	std::thread gen(generateData);
	gen.detach();

	// 定义动态窗口：
	//            X 坐标：长度 = 2 * PI，	10 个刻度，500 分辨率（采样点）
	//            Y 坐标：长度 = 1，		5 个刻度
	DynaWin win(2 * PI, 2, 10, 5, 500);
	win.InitBackGround(); //背景初始化
	int i = 0;
	BeginBatchDraw();
	while (1)
	{
		std::unique_lock<std::mutex> lck(data_mutex);
		data_var.wait(lck, [] {return !flag;});
		win.UpateWin(res);	// 更新窗
		win.ShowWin();								// 显示窗
		FlushBatchDraw();
		Sleep(10);
		++i;
		flag = true;
		data_var.notify_one();

	}
	EndBatchDraw();
	// 按任意键退出
	//_getch();
	closegraph();
	return 0;
}
