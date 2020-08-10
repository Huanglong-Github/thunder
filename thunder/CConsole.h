#ifndef CCONSOLE_H
#define CCONSOLE_H

#include <windows.h>	// HANDLE
#include <stdio.h>		// sprintf

class CConsole
{
private:
	COORD coord;
	HANDLE HConsole;

public:
	CConsole();
	~CConsole();
	
	void SetCoord(int x, int y);//����������������λ��
	void HideCursor(bool hide);//��������������֮�������Ǿ仰
	void SetTitle(char* title);//����������ڵ�����
	void SetSize(int width, int height);//����������ڵĳ��Ϳ�
	void SetColor(char* cl);//����������ڵı�����ɫ��������ݵı�����ɫ
};

#endif