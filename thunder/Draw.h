#ifndef DRAW_H
#define DRAW_H
#include<iostream>  
#include<windows.h>  
#include<conio.h>  
#include<time.h>  
#include<string> 

using namespace std;
//定义了一个框架结构体，设计程序输出界面的边界问题
typedef struct Frame      
{                         
    COORD position[4];
}Frame;  

class Draw
{
private:
	COORD coord;
	HANDLE HConsole;
public:   
	void SetPos(COORD a);//设定坐标  
	void SetCoord(int i, int j);//设置输出数据输出的位置
	void drawRow(int y, int x1, int x2, string ch);//在a, b 纵坐标相同的前提下，把坐标 [a, b] 之间填充为 ch   
	void drawCol(int x, int y1, int y2, string ch);//在a, b 横坐标相同的前提下，把坐标 [a, b] 之间填充为 ch  
  
	void drawFrame(COORD a, COORD  b, string row, string col);
	void drawFrame(Frame frame, string ch );
	void drawchar(COORD a,string stri);//在特定坐标输出字符串 
	void drawPlaying();//玩游戏时候的界面
	void drawinterface_2();//界面
	void drawinterface_3();//界面
	void Over();//结束界面
	int random(int a, int b);//在[a, b)之间产生一个随机整数  
	COORD random(COORD a, COORD b);//在两个坐标包括的矩形框内随机产生一个坐标 
  
	bool judgeCoordInFrame(Frame frame, COORD spot);//判断是否相撞 
	int drawMenu();//目录 
};
  
#endif