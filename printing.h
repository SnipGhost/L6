//----------------------------------------------------------------------------
#ifndef PRINTING_H
#define PRINTING_H
//----------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstring>
//----------------------------------------------------------------------------
struct I_print {	// ������ ��� ������ ����������� ��������������
	char* name;		// �������� �������
	double i_sum;	// �������� ������������ �����
	double i_toch;	// ������ �������� ���������
	int n;			// ����� ��������� ������� �������������� 
					// ��� ������� ���������� ��������� ��������
};
//----------------------------------------------------------------------------
void InputData(double &a, double &b, double &EPS);
void PrintTabl(I_print i_prn[], int k);
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------
