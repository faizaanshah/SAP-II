#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "head.h"
using namespace std;

int main(){
			OPERATIONS obj;
			int choice;
			char operations;
			cout<<"\n             *#*#*#*#*#*#*#  Welcome To  *#*#*#*#*#*#\n\n";
			cout<<"            *#*#*#*#*#*#         SAP-2          *#*#*#*#*#*#\n\n\n\n";
			cout<<"                             Prepared By\n";
			cout<<"        *#*#*#*#*#*#* Faizan Shah Reg: 15PWCSE1287 *#**#*#*#*#*#*#*\n\n\n\n\n\n\n\n\n";
cout<<"Press Enter To Start\n\n\n\n\n\n" ;
_getch();
	do{
		cout<<"SAP2";
		cout<<"Choose the operation to be performed?"<<endl;
		cout<<"1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.MovingData\n";
		cout<<"6.Anding\n7.Oring\n8.Xoring\n9.LoadingData\n10.StoringData\n";
		cin>>choice;
		switch(choice){
			case 1: system("cls");
					obj.add();
						break;
			case 2:	system("cls");
					obj.sub();
						break;
			case 3: system("cls");
					obj.multp();
						break;
			case 4:	system("cls");
					obj.divn();
						break;
			case 5:	system("cls");
					obj.movement();
						break;
			case 6:	system("cls");
					obj.AndGate();
						break;
			case 7:	system("cls");
					obj.OrGate();
						break;
			case 8:	system("cls");
					obj.XorGate();
						break;
			case 9:	system("cls");
					obj.LoadingAcc();
						break;
			case 10: system("cls");
					obj.storingAm();
						break;
			default:
						break;
		}
//	nope : system("cls");
			cout<<"do you want ot perform some other operation?(Y/N)";
			cin>>operations;
	}while(operations!='N');
	system("cls");
	obj.showMemory();
	return 0;
}
