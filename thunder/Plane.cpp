#include"Plane.h"
using namespace std;

Plane::Plane()  
{  
    initPlane();  
    initP_Bullet();  
    initEnemy_1();  
    score = 0;  
    rank = 25;  
	flag_1=0;
}  

void Plane::initPlane()  
{  
    COORD centren={27,29};  
    position[0].X=position[2].X=position[5].X=position[8].X=centren.X;  
    position[1].X=position[7].X=centren.X-2;     
    position[4].X=centren.X-2;  
    position[6].X=centren.X+2;  
    position[3].X=position[9].X=centren.X+2;    
    position[0].Y=centren.Y;  
    for(int j=1; j<4; j++)  
        position[j].Y=centren.Y+1;
	for(int k=4;k<7;k++)
		position[k].Y=centren.Y+2;
	for(int p=7;p<10;p++)
		position[p].Y=centren.Y+3;  
}  
  
void Plane::drawPlane()  
{  
    for(int i=0; i<10; i++)  
    {  
        draw.SetPos(position[i]);  
        if(i==0)  
            cout<<"▲";  
		else if(i==1||i==3)
            cout<<"▅";    
		else if(i==2||i==5)
            cout<<"█"; 
		else if(i==4)
			cout<<"【";
		else if(i==6)
			cout<<"】";
		else if(i==7||i==8||i==9)
            cout<<"■";    		
    } 
}  
  
void Plane::drawPlaneToNull()  
{  
    for(int i=0; i<10; i++)  
    {  
        draw.SetPos(position[i]);  
        cout<<" ";  
    }     
}  
  
void Plane::initP_Bullet()  
{  
    for(int i=0; i<10; i++)  
        P_bullet[i].Y = 33;  
}  
  
void Plane::drawP_Bullet()  
{  
    for(int i=0; i<10; i++)  
    {  
        if( P_bullet[i].Y != 33)  
        {  
            draw.SetPos(P_bullet[i]);  
            cout<<"●";      
        }  
    }  
}  
  
void Plane::drawP_BulletToNull()  
{  
    for(int i=0; i<10; i++)  
        if( P_bullet[i].Y != 33 )  
            {  
                COORD pos={P_bullet[i].X, P_bullet[i].Y+1};  
                draw.SetPos(pos);  
                cout<<" ";  
            }     
}  
//	〓█〓
//	  ¤  
void Plane::initEnemy_1()  
{  
    COORD a={3,2};  
    COORD b={51,7};  
    for(int i=0; i<8; i++)  
    {  
        enemy_1[i].position[0] = draw.random(a, b);  
        enemy_1[i].position[1].X = enemy_1[i].position[0].X + 2;  
        enemy_1[i].position[1].Y = enemy_1[i].position[0].Y;
		enemy_1[i].position[2].X = enemy_1[i].position[0].X + 4;  
        enemy_1[i].position[2].Y = enemy_1[i].position[0].Y;
        enemy_1[i].position[3].X = enemy_1[i].position[0].X + 2;  
        enemy_1[i].position[3].Y = enemy_1[i].position[0].Y + 1;
    }  
}  
void Plane::drawEnemy_1()  
{   
	for(int i=0;i<8;i++)
	{  
		draw.drawchar(enemy_1[i].position[0],"〓");
		draw.drawchar(enemy_1[i].position[1],"█");
		draw.drawchar(enemy_1[i].position[2],"〓");
		draw.drawchar(enemy_1[i].position[3],"¤");		
	}
}  
  
void Plane::drawEnemy_1ToNull()  
{  
	for(int i=0;i<8;i++)
	{  
		draw.drawchar(enemy_1[i].position[0]," ");
		draw.drawchar(enemy_1[i].position[1]," ");
		draw.drawchar(enemy_1[i].position[2]," ");
		draw.drawchar(enemy_1[i].position[3]," ");		
	}
}  
  
void Plane::Pause()  
{  
    draw.SetCoord(66,17);
	cout<<"                ";
	draw.SetCoord(66,17);
    cout<<"〖游戏暂停〗";  
    char c=_getch();  
    while(c!='p')  
        c=_getch();  
    draw.SetCoord(66,17);  
    cout<<"            ";
	draw.SetCoord(66,17);
	cout<<"〖游戏中〗";
} 


void Plane::planeMove(char x)  
{  
	if(x == 'a')
	{
        if(position[1].X != 3)  
		{
			for(int i=0; i<=9; i++)  
                position[i].X -= 2;
		}
		else
			for(int i=0; i<=9; i++) 
				position[i].X -= 0;
	}             
    if(x == 's')  
	{
		if(position[7].Y != 33)  
        {
			for(int i=0; i<=9; i++)  
                position[i].Y += 1;
		}
		else
			for(int i=0; i<=9; i++)
				position[i].Y += 0;
	}
    if(x == 'd')  
	{
		if(position[3].X != 55)  
		{
			for(int i=0; i<=9; i++)  
                position[i].X += 2;
		}
		else
			for(int i=0; i<=9; i++)
				position[i].X += 0;
	}
  
    if(x == 'w')  
	{
		if(position[0].Y != 3)  
		{
			for(int i=0; i<=9; i++)  
                position[i].Y -= 1;
		}
		else
			for(int i=0; i<=9; i++)
				position[i].Y -= 0;
	}
}  
  
void Plane::P_bulletMove()  
{  
    for(int i=0; i<10; i++)  
    {  
        if( P_bullet[i].Y != 33)  
        {  
            P_bullet[i].Y -= 1;  
            if( P_bullet[i].Y == 1 )  
            {  
                COORD pos={P_bullet[i].X, P_bullet[i].Y+1};  
                drawThisBulletToNull( pos );  
                P_bullet[i].Y=33;  
            }          
        }  
    }  
}  
  
void Plane::enemy_1Move()  
{  
    for(int i=0; i<8; i++)  
    {  
        for(int j=0; j<4; j++)  
            enemy_1[i].position[j].Y++;  
  
        if(33 == enemy_1[i].position[3].Y)  
		{
			COORD a={3, 2};  
			COORD b={51,7};  
			enemy_1[i].position[0] = draw.random(a, b);  
			enemy_1[i].position[1].X = enemy_1[i].position[0].X + 2;  
			enemy_1[i].position[1].Y = enemy_1[i].position[0].Y;
			enemy_1[i].position[2].X = enemy_1[i].position[0].X + 4;  
			enemy_1[i].position[2].Y = enemy_1[i].position[0].Y;
			enemy_1[i].position[3].X = enemy_1[i].position[0].X + 2;  
			enemy_1[i].position[3].Y = enemy_1[i].position[0].Y + 1;   
		}  
	}
}  

void Plane::judgePlane_2()  
{  
    for(int i = 0; i < 8; i++)  
        for(int j=0; j<10; j++)  
            if(draw.judgeCoordInFrame(enemy_1[i], position[j]))  
            {   
                draw.drawFrame(enemy_1[i],"#");  
                Sleep(1000);  
                GameOver();  
                break;
            } 
}   

void Plane::drawThisBulletToNull( COORD c)  
{  
    draw.SetPos(c);  
    cout<<" ";  
}  
  
void Plane::drawThisEnemyToNull( Frame f )  
{  
    draw.drawFrame(f," ");  
}  
  
void Plane::judgeEnemy_1()  
{  
    for(int i = 0; i < 8; i++)  
        for(int j = 0; j < 10; j++)  
            if( draw.judgeCoordInFrame(enemy_1[i], P_bullet[j]) )  
            {  
                score += 5;  
                drawThisEnemyToNull( enemy_1[i] );  
				COORD a={3, 2};  
				COORD b={51,7};  
				enemy_1[i].position[0] = draw.random(a, b);  
				enemy_1[i].position[1].X = enemy_1[i].position[0].X + 2;  
				enemy_1[i].position[1].Y = enemy_1[i].position[0].Y;
				enemy_1[i].position[2].X = enemy_1[i].position[0].X + 4;  
				enemy_1[i].position[2].Y = enemy_1[i].position[0].Y;
				enemy_1[i].position[3].X = enemy_1[i].position[0].X + 2;  
				enemy_1[i].position[3].Y = enemy_1[i].position[0].Y + 1;                      
                drawThisBulletToNull( P_bullet[j] );  
                P_bullet[j].Y = 34;  
            }  
}  
  
void Plane::P_Shoot()  
{  
    for(int i=0; i<10; i++)  
        if(P_bullet[i].Y == 33)  
        {  
            P_bullet[i].X = position[0].X;  
            P_bullet[i].Y = position[0].Y-1;  
            break;  
        }  
}  
void Plane::printScore()  
{    
	draw.SetCoord(60,22);
	cout<<"〖击落敌机〗"<<" "<<score/5;
	draw.SetCoord(60,24);
	cout<<"〖获得分数〗"<<" "<<score; 
}  
  
void Plane::Playing()  
{    
    drawEnemy_1();  
    drawPlane();  

    int flag_P_bullet = 0;  
    int flag_enemy_1 = 0;  
	int b = 0;
    do{
		Sleep(2);
		printScore();
        if(_kbhit())  
        {  
            char x = _getch();  
            if ('a' == x || 's' == x || 'd' == x || 'w' == x)  
            {  
                drawPlaneToNull();  
                planeMove(x);  
                drawPlane();
				judgePlane_2();
            }             
            else if ('p' == x)  
                Pause();  
            else if( 'k' == x)  
                P_Shoot();
            else if( 'e' == x)  
			{  
                GameOver();  
            }  
                  
        }  
        /* 处理子弹 */  
        if( 0 == flag_P_bullet )  
        {  
            P_bulletMove();  
            drawP_BulletToNull();  
            drawP_Bullet();  
            judgeEnemy_1();  
        }             
        flag_P_bullet++;  
        if( 5 == flag_P_bullet )  
            flag_P_bullet = 0;  
  
        /* 处理敌人 */  
        if( 0 == flag_enemy_1 )  
        {  
            drawEnemy_1ToNull();  
            enemy_1Move();              
            drawEnemy_1();  
            judgePlane_2();  
        }  
        flag_enemy_1++;  
        if( flag_enemy_1 >= rank )  
            flag_enemy_1 = 0;
	}while(flag_1==0);
} 

void Plane::GameOver()  
{  
    flag_1=1;
	system("cls");                      
	draw.drawinterface_2();
	draw.SetCoord(36,12);  
    string str="Game Over!";  
	for(int i=0; i<str.size(); i++)  
    {  
        Sleep(80);  
        cout<<str[i];  
    }  
	Savetofile(score);
	draw.SetCoord(34,14);  
	cout<<"〖击落敌机〗"<<score/5<<"架";  
    draw.SetCoord(34, 15);  
    cout<<"〖获得分数〗"<<score<<"分";
	draw.SetCoord(34, 16);  
    cout<<"〖继续按y,退出游戏按n〗";  
    char x=_getch();  
    if (x == 'n')
	{
        draw.SetCoord(32, 17);
		exit(0);  
	}
   while(x!='y')
	   x=_getch();	
}


