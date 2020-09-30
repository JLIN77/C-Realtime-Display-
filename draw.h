#pragma once

#include <easyx.h>

struct AxisX {
	double index; // 坐标
	double label; // 标签
};

class DynaWin {
public:
	DynaWin(double XLIM, double YLIM, unsigned short xSegment, unsigned short ySegment, int xResolution);	// 构造器
	void UpateWin(double y);	// 更新窗口
	void ShowWin();				// 绘制窗口
	void InitBackGround();		// 背景初始化（静态窗口）

private:
	const int CENTERX = 50;		// 定义原点
	const int CENTERY = 200;
	const int ROWS = 150;		// 定义边长
	const int COLS = 1000;

	double XLIM;				// 定义 X 轴区间
	double YLIM;				// 定义 Y 轴区间
	unsigned short xSegment;	// 定义坐标的刻度
	unsigned short ySegment;
	int xResolution;			// x轴分辨率(决定 Dynaque 的长度)
	int DynaNum = 0;			// 已读信号个数
	double* DynaQue;			// 实时信号队列
	AxisX* xAxis;				// 实时坐标队列
	IMAGE* canvas;				// 当前画布
	IMAGE local;				// 局部背景

	void UpdateAxisX();			// 更新坐标

};
