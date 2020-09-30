#pragma once

#include <easyx.h>

struct AxisX {
	double index; // ����
	double label; // ��ǩ
};

class DynaWin {
public:
	DynaWin(double XLIM, double YLIM, unsigned short xSegment, unsigned short ySegment, int xResolution);	// ������
	void UpateWin(double y);	// ���´���
	void ShowWin();				// ���ƴ���
	void InitBackGround();		// ������ʼ������̬���ڣ�

private:
	const int CENTERX = 50;		// ����ԭ��
	const int CENTERY = 200;
	const int ROWS = 150;		// ����߳�
	const int COLS = 1000;

	double XLIM;				// ���� X ������
	double YLIM;				// ���� Y ������
	unsigned short xSegment;	// ��������Ŀ̶�
	unsigned short ySegment;
	int xResolution;			// x��ֱ���(���� Dynaque �ĳ���)
	int DynaNum = 0;			// �Ѷ��źŸ���
	double* DynaQue;			// ʵʱ�źŶ���
	AxisX* xAxis;				// ʵʱ�������
	IMAGE* canvas;				// ��ǰ����
	IMAGE local;				// �ֲ�����

	void UpdateAxisX();			// ��������

};
