#ifndef DRAW_H
#define DRAW_H
#include<iostream>  
#include<windows.h>  
#include<conio.h>  
#include<time.h>  
#include<string> 

using namespace std;
//������һ����ܽṹ�壬��Ƴ����������ı߽�����
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
	void SetPos(COORD a);//�趨����  
	void SetCoord(int i, int j);//����������������λ��
	void drawRow(int y, int x1, int x2, string ch);//��a, b ��������ͬ��ǰ���£������� [a, b] ֮�����Ϊ ch   
	void drawCol(int x, int y1, int y2, string ch);//��a, b ��������ͬ��ǰ���£������� [a, b] ֮�����Ϊ ch  
  
	void drawFrame(COORD a, COORD  b, string row, string col);
	void drawFrame(Frame frame, string ch );
	void drawchar(COORD a,string stri);//���ض���������ַ��� 
	void drawPlaying();//����Ϸʱ��Ľ���
	void drawinterface_2();//����
	void drawinterface_3();//����
	void Over();//��������
	int random(int a, int b);//��[a, b)֮�����һ���������  
	COORD random(COORD a, COORD b);//��������������ľ��ο����������һ������ 
  
	bool judgeCoordInFrame(Frame frame, COORD spot);//�ж��Ƿ���ײ 
	int drawMenu();//Ŀ¼ 
};
  
#endif