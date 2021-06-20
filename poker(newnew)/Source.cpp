#include<iostream>
#include<iomanip>
#include<cstdlib>
#include "test.h"
using namespace std;
void compare(string ch, int num)
{
	if (num == 11)
		cout << ch << "J" <<" ";
	else if (num == 12)
		cout << ch<< "Q" << " ";
	else if (num == 13)
		cout << ch << "K" << " ";
	else
		cout << ch << num << " ";
}
void trans(int list[],int size)
{
	for (int i = 0; i < size; i++)
		(list[i] % 13 > 10 || list[i] % 13 == 0) ? list[i] = 10 : list[i] = list[i] % 13;
}
void choice(int num1,int num2,int num3,int list[])
{
	int f[5] = {0};
	f[0] = list[num1-1];
	f[1] = list[num2-1];
	f[2] = list[num3-1];
	for (int g = 0; g < 5; g++)
	{
		if (g != (num1 - 1) && g != (num2 - 1) && g != (num3 - 1))	
			(f[3] == 0) ? f[3] = list[g] : f[4] = list[g];
	}
}
void choice(int list[], int size)
{
	int g = 0;
	for (int f = 0; f < size; f++)
	{
		for (int d = 0; d < size; d++)
		{
			for (int h = 0; h < size; h++)
			{
				g = list[f] + list[d] + list[h];
				if (g % 10 == 0&&f!=d&&f!=h&&d!=h)
				{
					choice(f, d, h, list);
				}
			}
		}
	}

}
void sort(int list[])
{
	int a,b,c;
	int g = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int h = 0; h < 5; h++)
		{
			for(int j=0;j<5;j++)
				g = list[g] + list[h]+list[j];
		}
		if (g % 10 == 0)
		{
			a = list[0];
			b = list[1];
			c = list[2];
			choice(a, b, c, list);
		}
	}
}

void Switch(int list[],int size) 
{
	for (int i = 0; i < size; i++)
	{
		int answer = 0;
		int remain = 0;
		answer = list[i] / 13;
		remain = list[i] % 13;
		if (remain == 0)
			remain = 13;
		if (answer == 0)
			compare("黑桃", remain);
		else if (answer == 1)
			compare("紅心", remain);
		else if (answer == 2)
			compare("梅花", remain);
		else if (answer == 3)
			compare("方塊", remain);
	}
}


int main()
{
	srand(time(NULL));
	int poker[10] = {0};
	for (int a = 0; a < 10; a++){
		poker[a] = rand() % 52+1;
		for (int g = 0; g < a; g++){
			if (poker[g] == poker[a]){
				a--;
				break;
			}
		}
	}
	int poker1[5] = {}, poker2[5] = {};
	for (int g = 0; g < 10; g++)
	{
		(g >= 5)? poker2[g - 5] = poker[g]: poker1[g] = poker[g];
	}
	cout << "你的牌:" << endl;
	Switch(poker1, 5);
	cout << endl <<setw(3)<< 1 << setw(5) << " " << 2 << setw(5) << " " << 3 << setw(5) << " " << 4 << setw(5) << " " << 5 << setw(5) << " ";
	int a, b, s;
	cout <<endl<< "選擇三張牌(加起來為10的倍數,如沒有輸入0):";
	cin >> a;
	if (a == 0)
		cout << "你輸了!";
	else
	{
		cin >> b >> s;
		int ll[3] = {poker1[a-1], poker1[b-1],poker1[s-1]};
		cout << "你選了:";
		Switch(ll, 3);
		cout << endl<<"電腦的牌:";
		Switch(poker2, 5);
		trans(poker1, 5);
		trans(poker2, 5);
		choice(a, b, s, poker1);
		choice(poker2,5);
		test list1(poker1[0], poker1[1], poker1[2], poker1[3], poker1[4]);
		test list2(poker2[0], poker2[1], poker2[2], poker2[3], poker2[4]);
		if (list1.compareThree(list2) == 1)
		{
			if (list1.compareTwo(list2) == 1)
			{
				cout <<endl<< "你贏了!";
			}
			else
			{
				int p1 = (poker1[3] + poker1[4]) % 10;
				int p2=  (poker2[3] + poker2[4]) % 10;
				if (p1 > p2)
					cout <<endl<< "你贏了";
			}
		}
		else
			cout <<endl<< "你輸了!";
	}

	
}







