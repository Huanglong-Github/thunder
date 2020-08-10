#ifndef SCREEN_H
#define SCREEN_H

#include"Draw.h"
#include<time.h>
#include<string>
using namespace std;

class Screen
{
private:
	Draw draw;
	COORD position[11];
public:
	void init1Plane(COORD centren);
	void draw1Plane();
	void flyingplane();
	void GAMEOVER();
	void START();
};
#endif