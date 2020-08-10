#include"Screen.h"

void Screen::init1Plane(COORD centren)  
{  
    // COORD centren={40,29};  
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
  
void Screen::draw1Plane()  
{  
    for(int i=0; i<10; i++)  
    {  
        draw.SetPos(position[i]);  
        if(i==0)  
            cout<<"��";  
		else if(i==1||i==3)
            cout<<"�|";    
		else if(i==2||i==5)
            cout<<"��"; 
		else if(i==4)
			cout<<"��";
		else if(i==6)
			cout<<"��";
		else if(i==7||i==8||i==9)
            cout<<"��";    		
    } 
}

void Screen::flyingplane()
{
	COORD centren1={50,32}; 
	init1Plane(centren1);
	draw1Plane();
	for(int i=0;i<=14;i++)
	{
		for(int j=0; j<=9; j++)  
			position[j].Y -= 2;
		system("cls");
		draw1Plane();
	}
} 

void Screen::GAMEOVER()
{
	cout<<"\n\n\n\n\n\n\n";
	cout<<"\t     ����������        ������      ��          ��  ��������������"<<endl;
	cout<<"\t   ����      ����    ����  ����    ����      ����  ����          "<<endl;
	cout<<"\t   ����            ����      ����  ������  ������  ����          "<<endl;
	cout<<"\t   ����    ������  ����      ����  ��������������  ������������  "<<endl;
	cout<<"\t   ����      ����  ��������������  ����  ��  ����  ����          "<<endl;
	cout<<"\t   ����      ����  ����      ����  ����      ����  ����          "<<endl;
	cout<<"\t     ����������    ����      ����  ����      ����  ��������������"<<endl;
	cout<<"                                                              "<<endl;
	cout<<"                                                              "<<endl;
	cout<<"\t     ����������    ����      ����  ��������������  ������������  "<<endl;
	cout<<"\t   ����      ����  ����      ����  ����            ����      ����"<<endl;
	cout<<"\t   ����      ����  ����      ����  ����            ����      ����"<<endl;
	cout<<"\t   ����      ����  ����      ����  ������������    ������������  "<<endl;
	cout<<"\t   ����      ����  ����      ����  ����            ����  ����    "<<endl;
	cout<<"\t   ����      ����    ����  ����    ����            ����    ����  "<<endl;
	cout<<"\t     ����������        ������      ��������������  ����      ����"<<endl;
	cout<<"\n\n\n\n\t\t\t\t������������˳���Ϸ";
	string a;
	a=_getch();
}
void Screen::START()
{
	cout<<"\n\n\n\n\n\n";
	cout<<"����      ����  ��������������  ����            ����������      ����������    ��          ��  ��������������"<<endl;
	cout<<"����      ����  ����            ����          ����      ����  ����      ����  ����      ����  ����          "<<endl;
	cout<<"����  ��  ����  ����            ����          ����            ����      ����  ������  ������  ����          "<<endl;
	cout<<"��������������  ������������    ����          ����            ����      ����  ��������������  ������������  "<<endl;
	cout<<"������  ������  ����            ����          ����            ����      ����  ����  ��  ����  ����          "<<endl;
	cout<<"����      ����  ����            ����          ����      ����  ����      ����  ����      ����  ����          "<<endl;
	cout<<"��          ��  ��������������  ������������    ����������      ����������    ����      ����  ��������������"<<endl;
	draw.SetCoord(34,15);
	cout<<"|��������|:\t\t�׵�";
	draw.SetCoord(34,16);
	cout<<"|�汾��Ϣ|:\t\t���װ�";
	draw.SetCoord(34,17);
	cout<<"|����ʱ��|:\t\t2018��6��24��";
	draw.SetCoord(34,18);
	cout<<"|����������|:    \t����";
	draw.SetCoord(34,19);
	cout<<"|ѧ��|:    \t\t8002117337";
	draw.SetCoord(34,20);
	cout<<"|רҵ|:    \t\t�������";
	draw.SetCoord(34,21);
	cout<<"|�༶|:    \t\t���˰�";
	draw.SetCoord(40,24);
	cout<<"|�밴�����������Ϸ|";
	string a;
	a=_getch();
}
