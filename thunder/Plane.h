#ifndef PLANE_H
#define PLANE_H
#include"Draw.h"
#include"List.h"
#include<iostream>  
#include<windows.h>  
#include<conio.h>  
#include<time.h>  
#include<string>


using namespace std;

class Plane:public List  
{  
private:
	Draw draw;
public:  
    COORD position[11];
	
    COORD P_bullet[10];
    Frame enemy_1[8];
	
	Frame enemy_2[8];
    
	int score;  
    int rank;  
    //int rankf;   
    //int flag_rank;
	int flag_1;
  
    Plane();  
      
    //初始化  
    void initPlane();  
    void initP_Bullet();  
    void initEnemy_1();
	void initEnemy_2(); 
  
    void planeMove(char);  
    void P_bulletMove();  
    void enemy_1Move();  
      
    //填充  
    void drawPlane();  
    void drawPlaneToNull();  
    void drawP_Bullet();  
    void drawP_BulletToNull();  
    void drawEnemy_1();  
    void drawEnemy_1ToNull();  
  
    //填充其中一个  
    void drawThisBulletToNull( COORD );  
    void drawThisEnemyToNull( Frame );  
  
    void Pause();  
    void Playing();  

	void judgePlane_2();  
    void judgeEnemy_1();  
  
    void P_Shoot();
  
    void GameOver();  
    void printScore();
};  
  
#endif