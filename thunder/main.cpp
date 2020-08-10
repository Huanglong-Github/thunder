#include"CConsole.h"
#include"plane.h"
#include"Draw.h"
#include"Screen.h"
#include"About.h"
#include"List.h"
using namespace std;

void main()  
{    
	CConsole cconsole;
    cconsole.HideCursor(true);   //Òþ²Ø¹â±ê
	cconsole.SetTitle("À×µç");
	cconsole.SetColor("FC");
    cconsole.SetSize(108,36);
	Draw draw_1;
	Screen screen;
	About about;
	screen.flyingplane();
	system("cls");
	screen.START();
	List list; 
	system("cls");
	cconsole.SetSize(86,36);
	int a;
    while(1)
	{
		system("cls");
		Plane plane;
		a = draw_1.drawMenu();
		if(a==1)
		{
			srand((int)time(0));
			system("cls");  
			draw_1.drawPlaying();  
			plane.Playing();
		}
		if(a==2)
		{
			srand((int)time(0));
			plane.rank = 10;
			system("cls");  
			draw_1.drawPlaying();  
			plane.Playing();
		}
		if(a==3)
		{
			setbuf(stdin,NULL);
			system("cls");
			list.Showfile();
		}
		if(a==4)
		{
			system("cls");
			about.about();
		}
		if(a==5)
		{
			system("cls");
			about.help();
		}
		if(a==6)
		{
			system("cls");
			screen.GAMEOVER();
			cout<<"\n\t\t\t      ";
			exit(0);
		}
	}
} 
