#include"Draw.h"

void Draw::SetPos(COORD a)
{													 
    HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);      
    SetConsoleCursorPosition(out, a);  
}  
//定义输出位置函数
void Draw::SetCoord(int i,int j)      
{  
    COORD pos={i,j};  
    SetPos(pos);  
}

//把第y行，[x1, x2] 之间的坐标填充为 ch  
void Draw::drawRow(int y, int x1, int x2, string ch)  
{  
    SetCoord(x1,y);  
    for(int i = 0; i <= (x2-x1); i=i+2)  
        cout<<ch;  
}  
 
//把第x列，[y1, y2] 之间的坐标填充为 ch  
void Draw::drawCol(int x, int y1, int y2, string ch)  
{  
    int y=y1;  
    while(y!=y2+1)  
    {  
        SetCoord(x, y);  
        cout<<ch;  
        y++;  
    }  
}  

//画敌人
void Draw::drawFrame(Frame frame, string stri )  
{  
    COORD a = frame.position[0];  
    COORD b = frame.position[1];
	COORD c = frame.position[2];  
    COORD d = frame.position[3];
    drawchar(a,stri);
    drawchar(b,stri);  
    drawchar(c,stri);  
    drawchar(d,stri);  
}  
//用于画出敌人的中间函数
void Draw::drawchar(COORD a,string stri)
{
	SetCoord(a.X,a.Y);
	cout<<stri;
}
  
//在[a, b)之间产生一个随机整数  
int Draw::random(int a, int b)  
{  
    int c=(rand() % (a-b))+ a;  
    return c;  
}  
  
//在两个坐标包括的矩形框内随机产生一个坐标  
COORD Draw::random(COORD a, COORD b)  
{  
    int x=random(a.X, b.X);  
    int y=random(a.Y, b.Y);  
    COORD c={x, y};  
    return c;  
}  
  //( draw.judgeCoordInFrame(enemy_1[i], P_bullet[j]) )
bool  Draw::judgeCoordInFrame(Frame frame, COORD spot)  
{  
    if(spot.X>=frame.position[0].X-1)
        if(spot.X<=(frame.position[2].X+2))  
            if(spot.Y>=frame.position[0].Y)  
                if(spot.Y<=frame.position[0].Y)
                    return true;  
				return false;  
}  
void Draw::Over()  
{  
    system("cls");                      
	drawinterface_2();
	SetCoord(36,12);  
    string str="Game Over!";  
	for(int i=0; i<str.size(); i++)  
    {  
        Sleep(80);  
        cout<<str[i];  
    }
	SetCoord(30,14);
}
//游戏框架页面
void Draw::drawPlaying()  
{  
    drawRow(1, 1, 85,"〓");
    drawRow(34, 1, 85,"〓");
	drawRow(6, 58, 83,"┺┺");  	
    drawRow(15, 58, 83,"┺┺");  	
    drawRow(20, 58, 83,"┺┺");	
    drawCol(1, 2, 33, "▓");
    drawCol(57, 2, 33, "▓");
	drawCol(83, 2, 33, "▓");  	  
    SetCoord(67, 3);  
    cout<<"【雷电】";  
    SetCoord(61, 4);
    cout<<"▁▃▅▆██▆▅▃▁";  
	SetCoord(61,8);  
    cout<<"〖操作方式〗";  
    SetCoord(59,9);  
    cout<<"▲w、a、s、d键控制方向";  
    SetCoord(59,10); 
    cout<<"▲k键发射子弹";  
    SetCoord(59,11);  
    cout<<"▲p键暂停，再按继续游戏";  
	SetCoord(59,12);  
    cout<<"▲e键退出游戏";
	SetCoord(66,17);
	cout<<"〖游戏中〗";
}  

void Draw::drawinterface_2()
{   
	drawRow(1, 1, 85,"〓");
    drawRow(34, 1, 84,"〓");
	drawRow(10, 21, 63,"★");
    drawRow(21, 21, 63,"★");
    drawCol(1, 2, 33, "▓");
	drawCol(19, 2, 33, "▓");
    drawCol(65, 2, 33, "▓");
	drawCol(83, 2, 33, "▓");
	
} 
void Draw::drawinterface_3()
{   
	drawRow(1, 1, 85,"▓");
    drawRow(34, 1, 84,"▓");
    drawCol(1, 2, 33, "▓");;
	drawCol(83, 2, 33, "▓");
	
} 
int Draw::drawMenu()  
{   
	
	drawRow(1, 1, 85,"〓");
    drawRow(34, 1, 84,"〓");
    drawCol(1, 2, 33, "▓");
	drawCol(22, 2, 33, "▓");
    drawCol(63, 2, 33, "▓");
	drawCol(83, 2, 33, "▓");  	  
    SetCoord(38, 5);  
    cout<<"【雷电】";  
    SetCoord(32, 7);
    cout<<"▁▃▅▆██▆▅▃▁";  
	SetCoord(65,7);  
    cout<<"〖操作方式〗";  
    SetCoord(65,9);  
    cout<<"〖w、s键上下操作〗";  
    SetCoord(65,11); 
    cout<<"〖k键确定〗";  
	SetCoord(35,11);
	cout<<"〖普通模式〗";
	SetCoord(35,13);
	cout<<"〖高级模式〗";
	SetCoord(35,15);
	cout<<"〖排行榜〗";
	SetCoord(35,17);
	cout<<"〖关于〗";
	SetCoord(35,19);
	cout<<"〖帮助〗";
	SetCoord(35,21);
	cout<<"〖退出〗";
    int j=11;  
    SetCoord(33, j);  
    cout<<"◆";  
    while(1)  
    {   if( _kbhit() )  
        {     
            char x=_getch();  
            switch (x)  
            {  
            case 'w': 
                    {     
                        if( j > 11)  
                        {  
                            SetCoord(33, j);  
                            cout<<"  ";  
                            j = j - 2;  
                            SetCoord(33, j);  
                            cout<<"◆";  
                        }  
						else
						{  
                            j = 11;  
                            SetCoord(33, j);  
                            cout<<"◆";
						}
						break;
                    }  
            case 's': 
                    {     
                        if( j < 21 )  
                        {  
                            SetCoord(33, j);  
                            cout<<"　";         
                            j = j + 2;
                            SetCoord(33, j);  
                            cout<<"◆";  
                        } 
						else
						{
						    j = 21;  
                            SetCoord(33, j);  
                            cout<<"◆";	
						}
                        break;  
                    }  
            case 'k' :  
                    {     
                        if (j == 11)
							return 1;
						if (j == 13)
							return 2;
                        if (j == 15)
							return 3;
                        if (j == 17)
							return 4;
                        if (j == 19)
							return 5;
						if (j == 21)
							return 6;
                    }  
            }  
        }  
    }  
} 