#include"Draw.h"

void Draw::SetPos(COORD a)
{													 
    HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);      
    SetConsoleCursorPosition(out, a);  
}  
//�������λ�ú���
void Draw::SetCoord(int i,int j)      
{  
    COORD pos={i,j};  
    SetPos(pos);  
}

//�ѵ�y�У�[x1, x2] ֮����������Ϊ ch  
void Draw::drawRow(int y, int x1, int x2, string ch)  
{  
    SetCoord(x1,y);  
    for(int i = 0; i <= (x2-x1); i=i+2)  
        cout<<ch;  
}  
 
//�ѵ�x�У�[y1, y2] ֮����������Ϊ ch  
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

//������
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
//���ڻ������˵��м亯��
void Draw::drawchar(COORD a,string stri)
{
	SetCoord(a.X,a.Y);
	cout<<stri;
}
  
//��[a, b)֮�����һ���������  
int Draw::random(int a, int b)  
{  
    int c=(rand() % (a-b))+ a;  
    return c;  
}  
  
//��������������ľ��ο����������һ������  
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
//��Ϸ���ҳ��
void Draw::drawPlaying()  
{  
    drawRow(1, 1, 85,"��");
    drawRow(34, 1, 85,"��");
	drawRow(6, 58, 83,"�ީ�");  	
    drawRow(15, 58, 83,"�ީ�");  	
    drawRow(20, 58, 83,"�ީ�");	
    drawCol(1, 2, 33, "��");
    drawCol(57, 2, 33, "��");
	drawCol(83, 2, 33, "��");  	  
    SetCoord(67, 3);  
    cout<<"���׵硿";  
    SetCoord(61, 4);
    cout<<"�x�z�|�}�����}�|�z�x";  
	SetCoord(61,8);  
    cout<<"��������ʽ��";  
    SetCoord(59,9);  
    cout<<"��w��a��s��d�����Ʒ���";  
    SetCoord(59,10); 
    cout<<"��k�������ӵ�";  
    SetCoord(59,11);  
    cout<<"��p����ͣ���ٰ�������Ϸ";  
	SetCoord(59,12);  
    cout<<"��e���˳���Ϸ";
	SetCoord(66,17);
	cout<<"����Ϸ�С�";
}  

void Draw::drawinterface_2()
{   
	drawRow(1, 1, 85,"��");
    drawRow(34, 1, 84,"��");
	drawRow(10, 21, 63,"��");
    drawRow(21, 21, 63,"��");
    drawCol(1, 2, 33, "��");
	drawCol(19, 2, 33, "��");
    drawCol(65, 2, 33, "��");
	drawCol(83, 2, 33, "��");
	
} 
void Draw::drawinterface_3()
{   
	drawRow(1, 1, 85,"��");
    drawRow(34, 1, 84,"��");
    drawCol(1, 2, 33, "��");;
	drawCol(83, 2, 33, "��");
	
} 
int Draw::drawMenu()  
{   
	
	drawRow(1, 1, 85,"��");
    drawRow(34, 1, 84,"��");
    drawCol(1, 2, 33, "��");
	drawCol(22, 2, 33, "��");
    drawCol(63, 2, 33, "��");
	drawCol(83, 2, 33, "��");  	  
    SetCoord(38, 5);  
    cout<<"���׵硿";  
    SetCoord(32, 7);
    cout<<"�x�z�|�}�����}�|�z�x";  
	SetCoord(65,7);  
    cout<<"��������ʽ��";  
    SetCoord(65,9);  
    cout<<"��w��s�����²�����";  
    SetCoord(65,11); 
    cout<<"��k��ȷ����";  
	SetCoord(35,11);
	cout<<"����ͨģʽ��";
	SetCoord(35,13);
	cout<<"���߼�ģʽ��";
	SetCoord(35,15);
	cout<<"�����а�";
	SetCoord(35,17);
	cout<<"�����ڡ�";
	SetCoord(35,19);
	cout<<"��������";
	SetCoord(35,21);
	cout<<"���˳���";
    int j=11;  
    SetCoord(33, j);  
    cout<<"��";  
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
                            cout<<"��";  
                        }  
						else
						{  
                            j = 11;  
                            SetCoord(33, j);  
                            cout<<"��";
						}
						break;
                    }  
            case 's': 
                    {     
                        if( j < 21 )  
                        {  
                            SetCoord(33, j);  
                            cout<<"��";         
                            j = j + 2;
                            SetCoord(33, j);  
                            cout<<"��";  
                        } 
						else
						{
						    j = 21;  
                            SetCoord(33, j);  
                            cout<<"��";	
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