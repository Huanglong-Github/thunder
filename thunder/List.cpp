#include"List.h"

List::List()
{
	per.assign(10,0);
}
void List::Savetofile(int score_1)
{
	ofstream outfile;
	outfile.open("D:\\score.dat",ios::out|ios::app|ios::binary);
	outfile<<score_1<<" ";
	outfile.close();
}

void List::Readfromfile()
{
	ifstream infile;
	infile.open("D:\\score.dat",ios::in|ios::binary);
	if(!infile)
	{
		draw2.drawinterface_3();
		draw2.SetCoord(38,8); 
		cout<<"�����а�";
		draw2.SetCoord(35,11); 
		cout<<"���а��޻�򿪴���";
		draw2.SetCoord(35,12);
		cout<<"��Ϊ����������";
		draw2.SetCoord(35,13);
		exit(0);
	}
	per.clear();
	int score_2;
	infile>>score_2;
	while(!infile.eof())
	{
		per.push_back(score_2);
		infile>>score_2;
	}
	infile.close();
}

void List::Showfile()
{
	Readfromfile();
	vector<int>::iterator pos;
	int c;
	sort(per.begin(),per.end());
	pos=per.end();
	int n=per.size();
	draw2.drawinterface_3();
	draw2.SetCoord(38,8); 
	cout<<"�����а�";
	if(n==0)
	{
		draw2.SetCoord(35,11); 
		cout<<"�����а�";
		draw2.SetCoord(34,13);
		cout<<"����������ɷ�����Ŀ¼";
		c=_getch();
	}
	if(n==1)
	{
		pos--;
		draw2.SetCoord(35,11);
		cout<<"�ڡ�1����"<<"\t"<<*pos;
		draw2.SetCoord(34,13);
		cout<<"�밴���������Ŀ¼";
		c=_getch();
	}
	if(n==2)
	{
		for(int i=0;i<2;i++)
		{	
			pos--;
			draw2.SetCoord(34,11+(i+1));
			cout<<"�ڡ�"<<i+1<<"��"<<"��"<<"\t"<<*pos;
		}
		draw2.SetCoord(34,11+(i+2));
		cout<<"�밴���������Ŀ¼";
		c=_getch();
	}
	if(n>=3)
	{
		for(int j=0;j<3;j++)
		{
			pos--;
			draw2.SetCoord(34,11+(j+1));
			cout<<"�ڡ�"<<j+1<<"��"<<"��"<<"\t"<<*pos;
		}
		draw2.SetCoord(34,11+(j+2));
		cout<<"�밴���������Ŀ¼";
		c=_getch();
	}
}


	
