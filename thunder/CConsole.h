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
	
	void SetCoord(int x, int y);//设置输出数据输出的位置
	void HideCursor(bool hide);//隐藏输出数据完成之后后面的那句话
	void SetTitle(char* title);//设置输出窗口的主题
	void SetSize(int width, int height);//设置输出窗口的长和宽
	void SetColor(char* cl);//设置输出窗口的背景颜色和输出数据的背景颜色
};

#endif