#include"About.h"

void About::about()
{
	drawinterface_3();
	SetCoord(5,4);
	cout<<"|程序名称|:\t雷电";
	SetCoord(5,5);
	cout<<"~~~~~~~~~~~ \t^^^^^";
	SetCoord(5,7);
	cout<<"|版本信息|:\t简易版";
	SetCoord(5,8);
	cout<<" ~~~~~~~~~ \t^^^^^^";
	SetCoord(5,9);
	cout<<"|开发时间|:\t2018年6月24日";
	SetCoord(5,10);
	cout<<"~~~~~~~~~~ \t^^^^^^^^^^^^^";
	SetCoord(5,12);
	cout<<"|开发者信息|:";
	SetCoord(5,13);
	cout<<"~~~~~~~~~~~~";
	SetCoord(5,14);
	cout<<"|姓名|:黄龙        学号:8002117337  专业:软件工程 班级:软工八班";
	SetCoord(5,15);
	cout<<"^^^^^^^^^^^        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
	SetCoord(5,17);
	cout<<"按任意键即可返回主菜单";
	string a;
	a=_getch();
}
void About::help()
{
	drawinterface_3();
	SetCoord(5,4);
	cout<<"|游戏帮助|:";
	SetCoord(5,5);
	cout<<"~~~~~~~~~~";
	SetCoord(5,8);
	cout<<"<1> <己方战机>玩家所控制的飞机";
	SetCoord(5,9);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~";
	SetCoord(5,10);
	cout<<"<2> <敌方战机>由电脑自动生成的飞机";
	SetCoord(5,11);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	SetCoord(5,12);
	cout<<"<3> <子弹>游戏中的飞机对象均可发出，被击中的飞机将被摧毁";
	SetCoord(5,13);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	SetCoord(5,14);
	cout<<"<4> <得分>由玩家摧毁战机而获得，将不断更新";
	SetCoord(5,15);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	SetCoord(5,17);
	cout<<"按任意键即可返回主菜单";
	string a;
	a=_getch();
}
