#ifndef LIST_H
#define LIST_H

#include<vector>
#include<algorithm>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
#include"Draw.h"

using namespace std;

class List
{
public:
	List();
	int score;
	void Savetofile(int score_1);
	void Readfromfile();
	void Showfile();
private:
	vector<int> per;
	Draw draw2;
};


#endif
