#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int getHex(string hexstr);
int memory[64000];
int i=2001;
int counter=0;
class OPCODES{
	protected:
	string Add_B, Add_C, ANA_B, ANA_C, ANI, Call, CMA, 
	DCR_B, DCR_C, HLT, IN,INR_A, INR_B, INR_C, JM, JMP,
	DCR_A, JNZ, JZ, LDA, Mov_A_B, Mov_A_C, Mov_B_A, 
	Mov_B_C, Mov_C_A, Mov_C_B, MVI_A, MVI_B,MVI_C,NOP,
	ORA_A, ORA_B, ORA_C, ORI, OUT, RAL, RAR, RET, STA,
	Sub_B, Sub_C, XRA_B, XRA_C, XRI;
	int Add_Bi, Add_Ci, ANA_Bi, ANA_Ci, ANIi, Calli, CMAi, 
	DCR_Bi, DCR_Ci, HLTi, INi,INR_Ai, INR_Bi, INR_Ci, JMi, JMPi,
	DCR_Ai, JNZi, JZi, LDAi, Mov_A_Bi, Mov_A_Ci, Mov_B_Ai, 
	Mov_B_Ci, Mov_C_Ai, Mov_C_Bi, MVI_Ai, MVI_Bi,MVI_Ci,NOPi,
	ORA_Ai, ORA_Bi, ORA_Ci, ORIi, OUTi, RALi, RARi, RETi, STAi,
	Sub_Bi, Sub_Ci, XRA_Bi, XRA_Ci, XRIi;
	public:
	OPCODES(){
		Add_B="80";Add_Bi=getHex(Add_B);
		Add_C="81";Add_Ci=getHex(Add_C);
		ANA_B="A0";ANA_Bi=getHex(ANA_B);
		ANA_C="A1";ANA_Ci=getHex(ANA_C);
		ANI="E6"; ANIi=getHex(ANI);
		Call="CD"; Calli=getHex(Call);
		CMA="2F"; CMAi=getHex(CMA);
		DCR_B="05";DCR_Bi=getHex(DCR_B);
		DCR_C="0D"; DCR_Ci=getHex(DCR_C);
		HLT="76"; HLTi=getHex(HLT);
		IN="DB";INi=getHex(IN);
		INR_A="3C";INR_Ai=getHex(INR_A);
		INR_B="04";INR_Bi=getHex(INR_B);
		INR_C="0C";INR_Ci=getHex(INR_C);
		JM="FA";JMi=getHex(JM);
		JMP="C3";JMPi=getHex(JMP);
		DCR_A="3D";DCR_Ai=getHex(DCR_A);
		JNZ="C2";JNZi=getHex(JNZ);
		JZ="CA";JZi=getHex(JZ);
		LDA="3A";LDAi=getHex(LDA);
		Mov_A_B="78";Mov_A_Bi=getHex(Mov_A_B);
		Mov_A_C="79";Mov_A_Ci=getHex(Mov_A_C);
		Mov_B_A="47";Mov_B_Ai=getHex(Mov_B_A);
		Mov_B_C="41";Mov_B_Ci=getHex(Mov_B_C);
		Mov_C_A="4F";Mov_C_Ai=getHex(Mov_C_A);
		Mov_C_B="48";Mov_C_Bi=getHex(Mov_C_B);
		MVI_A="3E"; MVI_Ai=getHex(MVI_A);
		MVI_B="06";MVI_Bi=getHex(MVI_B);
		MVI_C="0E";MVI_Ci=getHex(MVI_C);
		NOP="00";NOPi=getHex(NOP);
		ORA_B="B0";ORA_Bi=getHex(ORA_B);
		ORA_C="B1";ORA_Ci=getHex(ORA_C);
		ORI="F6"; ORIi=getHex(ORI);
		OUT="D3"; OUTi=getHex(OUT);
		RAL="17"; RALi=getHex(RAL);
		RAR="1F"; RARi=getHex(RAR);
		RET="C9";RETi=getHex(RET);
		STA="32";STAi=getHex(STA);
		Sub_B="90"; Sub_Bi=getHex(Sub_B);
		Sub_C="91"; Sub_Ci=getHex(Sub_C);
		XRA_B="A8";XRA_Bi=getHex(XRA_B);
		XRA_C="A9";XRA_Ci=getHex(XRA_C);
		XRI="EE";XRIi=getHex(XRI);
	}
};
class INSTRUCTIONS : public OPCODES{
	protected:
	string A,B,C;
	public:
	INSTRUCTION(){
		A="";B="";C="";
	}
	void addition(int a,int b){
		int test;
		cout<<"Addition"<<endl;
		char c_H [33];
		int tci=i;
		itoa(a,c_H,16);//converts decimal to hex
		memory[i++]=MVI_Ai;cout<<"MVI A,"<<c_H<<"H\n";//moves a immedietely
		test=getHex(c_H);//convert hex to decimal
		
		memory[i++]=test; 
		
		itoa(b,c_H,16);
		memory[i++]=MVI_Bi;cout<<"MVI B,"<<c_H<<"H\n";
		test=getHex(c_H);
		
		memory[i++]=test;
		memory[i++]=Add_Bi;cout<<"ADD B"<<endl;
		int tce=i;
		counter=counter+(tce-tci);
		int res=a+b;
		itoa(res,c_H,16);
		//
		A=c_H;
		cout<<"Result: "<<A<<endl;
		cout<<"Memory Add:\t\tContents"<<endl;
		for(int k=tci;k<tce;k++){
			char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
		}
	}
	void subtraction(int a,int b){
		cout<<"Subtraction"<<endl;
		char c_H [10];
		int tci=i;
		int test;
		itoa(a,c_H,16);
		memory[i++]=MVI_Ai;
		cout<<"MVI A,"<<c_H<<"H\n";
		test=getHex(c_H);
		//split string if needed
		memory[i++]=test;
		
		itoa(b,c_H,16);
		memory[i++]=MVI_Bi;
		cout<<"MVI B,"<<c_H<<"H\n";
		test=getHex(c_H);
		
		memory[i++]=test;

		memory[i++]=Sub_Bi;cout<<"Sub B"<<endl;
		int tce=i;
		counter=counter+(tce-tci);
		int res=a-b;
		itoa(res,c_H,16);
		//
		A=c_H;
		cout<<"Result: "<<A<<endl;
		cout<<"Memory Add:\t\tContents"<<endl;
		for(int k=tci;k<tce;k++){
			char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
		}
	}
	void multiplication(int a,int b){
		cout<<"Multiplication"<<endl;
		char c_H [10];
		int tci=i;
		int test;
		memory[i++]=MVI_Ai;cout<<"MVI A,00H\n";
		memory[i++]=00;
		itoa(a,c_H,16);
		int cs=i;
		
		memory[i++]=MVI_Bi;cout<<"MVI B,"<<c_H<<"H\n";
		
		test=getHex(c_H);
		
		memory[i++]=test;
		itoa(b,c_H,16);
		memory[i++]=MVI_Ci;cout<<"MVI C,"<<c_H<<"H\n";
		
		test=getHex(c_H);
		
		memory[i++]=test;

		memory[i++]=Add_Bi;cout<<"ADD B\n";
		memory[i++]=DCR_Ci;cout<<"DCR_C\n";
		memory[i++]=JNZi;cout<<"JNZ "<<cs<<"H\n";
		//splitting memory
		int mod=cs%100;
		int devd=cs/100;
		memory[i++]=mod;
		memory[i++]=devd;
		int tce=i;
		counter=counter+(tce-tci);
		int res=a*b;
		itoa(res,c_H,16);
		//
		A=c_H;
		cout<<"Result: "<<A<<endl;
		cout<<"Memory Add:\t\tContents"<<endl;
		for(int k=tci;k<tce;k++){
			char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
		}
	}
	void division(int a,int b){
		cout<<"Division"<<endl;
		char c_H [10];
		int tci=i;
		int test;
		itoa(a,c_H,16);
		memory[i++]=MVI_Ai;cout<<"MVI A "<<c_H<<"H\n";
		test=getHex(c_H);

		memory[i++]=test;
		int cs=i;
		itoa(b,c_H,16);
		memory[i++]=MVI_Bi;cout<<"MVI B,"<<c_H<<"H\n";
		test=getHex(c_H);
		//split string if needed
		memory[i++]=test;
		memory[i++]=MVI_Ci;cout<<"MVI C,00H\n";
		memory[i++]=00;
		
		memory[i++]=Sub_Bi;cout<<"SUB B\n";
		memory[i++]=DCR_Ci;cout<<"INR C\n";
		memory[i++]=i;cout<<"JNZ "<<cs<<"H\n";
		//split cs its necessary
		int mod=cs%100;
		int devd=cs/100;
		memory[i++]=mod;
		memory[i++]=devd;
		int tce=i;
		counter=counter+(tce-tci);
		int res=a/b;
		itoa(res,c_H,16);
		//
		A=c_H;
		cout<<"Result: "<<A<<endl;
		cout<<"Memory Add:\t\tContents"<<endl;
		for(int k=tci;k<tce;k++){
			char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
		}
	}
	void andingAImd(){
					int dc;
					int test;
			cout<<"Enter value: \n";
			cin>>dc;
		//	system("cls");
			char c_H [10];
			itoa(dc,c_H,16);
			int tci=i;
			memory[i++]=ANIi;cout<<"ANI "<<c_H<<endl;
			test=getHex(c_H);
		
			memory[i++]=test;
			int bn=getHex(A);
			int res=bn&dc;
			int tce=i;
			counter=counter+(tce-tci);
			itoa(res,c_H,16);
			cout<<"Result\nA: "<<c_H<<endl;
			cout<<"Memory\t\t\tContents"<<endl;
			for(int k=tci;k<tce;k++){
				char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
			}
			
	}
	void andingA(string a){
		//system("cls");
			char c_H [10];
			int dc;
			int bn;
			//itoa(dc,c_H,16);
			int tci=i;
			if(a==B){ memory[i++]=ANA_Bi;cout<<"ANA "<<B<<endl;
			dc=getHex(A);
			bn=getHex(C);
			}
			else if(a==C){ memory[i++]=ANA_Ci;cout<<"ANA "<<C<<endl;
			dc=getHex(A);
			bn=getHex(C);
			
			}
			int res=bn&dc;
			int tce=i;
			counter=counter+(tce-tci);
			itoa(res,c_H,16);
			cout<<"Result\nA: "<<c_H<<endl;
			cout<<"Memory\t\t\tContents"<<endl;
			for(int k=tci;k<tce;k++){
			char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
			}
			
	}
	void moving(string a,string b){
		int tci=i;
		if(a==A&&b==B){
			cout<<"MOV A, B\n";
			memory[i++]=Mov_A_Bi;
			A=B;
			cout<<"Output:\n";
			cout<<"A: "<<A<<endl;
			cout<<"B: "<<B<<endl;
			counter++;
		} 
		else if(a==A&&b==C){
			cout<<"MOV A, C\n";
			memory[i++]=Mov_A_Ci;
			A=C;
			cout<<"Output:\n";
			cout<<"C: "<<C<<endl;
			cout<<"A: "<<A<<endl;
			counter++;
		} 
		else if(a==B&&b==A){
			B=A;
			cout<<"MOV B, A\n";
			memory[i++]=Mov_B_Ai;
			cout<<"Output:\n";
			cout<<"B: "<<B<<endl;
			cout<<"A: "<<A<<endl;
			counter++;
		} 
		else if(a==B&&b==C){
			cout<<"MOV B, C\n";
			memory[i++]=Mov_B_Ci;
			B=C;
			cout<<"Output:\n";
			cout<<"B: "<<B<<endl;
			cout<<"C: "<<C<<endl;
			counter++;
		}
		else if(a==C&&b==B){
			cout<<"MOV C, B\n";
			memory[i++]=Mov_C_Bi;
			C=B;
			cout<<"Output:\n";
			cout<<"C: "<<C<<endl;
			cout<<"B: "<<B<<endl;
			counter++;
		}
		else if(a==C&&b==A){
			cout<<"MOV C, A\n";
			memory[i++]=Mov_C_Ai;
			C=A;
			cout<<"Output:\n";
			cout<<"C: "<<C<<endl;
			cout<<"A: "<<A<<endl;
			counter++;
		}
		
	}
	void oringAImd(){
			int dc;
			cout<<"Enter value: \n";
			cin>>dc;
			system("cls");
			char c_H [10];
			itoa(dc,c_H,16);
			int tci=i;
			memory[i++]=ORIi;cout<<"ORI "<<c_H<<endl;
			
			int bn=getHex(A);
			int res=bn|dc;
			int tce=i;
			counter=counter+(tce-tci);
			itoa(res,c_H,16);
			cout<<"Result\nA: "<<c_H<<endl;
			cout<<"Memory\t\t\tContents"<<endl;
			for(int k=tci;k<tce;k++){
				char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
			}
			
		
		
	}
	void oringA(string a){
			//system("cls");
			char c_H [10];
			int bn;
			int dc;
			//itoa(dc,c_H,16);
			int tci=i;
			if(a==B) {
			memory[i++]=ORA_Bi;cout<<"ORA "<<B<<endl;
			int bn=getHex(B);
			 dc=getHex(A);
			// res=bn|dc;
			}
			else if(a==C){
			memory[i++]=ORA_Ci;cout<<"ORA "<<C<<endl;
			 bn=getHex(C);
			 bn=getHex(A);
			 //res=bn|dc;
			}
			int res=bn|dc;
			int tce=i;
			counter=counter+(tce-tci);
			itoa(res,c_H,16);
			A=c_H;
			cout<<"Result\nA: "<<A<<endl;
			cout<<"Memory\t\t\tContents"<<endl;
			for(int k=tci;k<tce;k++){
				char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
			}
			
		
		
	}
	void xORingImd(){
		int dc;
			cout<<"Enter value: \n";
			cin>>dc;
		//	system("cls");
			char c_H [10];
			int test;
			itoa(dc,c_H,16);
			int tci=i;
			memory[i++]=ORIi;cout<<"XRI "<<c_H<<endl;
			
			test=getHex(c_H);
			memory[i++]=test;
			/*string c_H;
			c_H=convertToHex(dc);
			dc=toBinary(c_H);*/
			int bn=getHex(A);
			int res=bn^dc;
			int tce=i;
			counter=counter+(tce-tci);
			itoa(res,c_H,16);
			A=c_H;
			cout<<"Result\nA: "<<A<<endl;
			cout<<"Memory\t\t\tContents"<<endl;
			for(int k=tci;k<tce;k++){
				char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
			}
			
	}
	void XOring(string a){
		system("cls");
			char c_H [10];
			//c_H=convertToHex(dc);
			int tci=i;
			int bn;
			int dc;
			if(a==B){ 
			memory[i++]=XRA_Bi;cout<<"XRA "<<B<<endl;
			 bn=getHex(A);
			 dc=getHex(B);
			}
			
			else if(a==C){ 
			memory[i++]=XRA_Ci;cout<<"XRA "<<C<<endl;
			 bn=getHex(A);
			 dc=getHex(C);
			}
			int res=bn^dc;
			int tce=i;
			counter=counter+(tce-tci);
			itoa(res,c_H,16);
			A=c_H;
			cout<<"Result\nA: "<<A<<endl;
			cout<<"Memory\t\tContents"<<endl;
			for(int k=tci;k<tce;k++){
				char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
			}
			
	}
	void loadingAccumulator(string a){
		int tci=i;
		
		memory[i++]=LDAi;cout<<"LDA "<<a<<endl;
		int dc=getHex(a);//convert this to decimal
		int mod=dc%100;
		int divdn=dc/100;//split string
		memory[i++]=mod;
		memory[i++]=divdn;
		int tce=i;
		counter=counter+(tce-tci);
		A=a;
		cout<<"Result\nA: "<<A<<endl;
		cout<<"Memory\t\tContents"<<endl;
		for(int k=tci;k<tce;k++){
			char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
		}
	}
	void storingAccumulator(int a){
		
		memory[i++]=STAi;cout<<"STA "<<a<<endl;
		int m,n;
		//char c_H [10];
		m=a%100;
		int cdi=i;
		//itoa(m,c_H,16);
		memory[i++]=m;
		n=a/100;
		//n=toString(n);
		memory[i++]=n;
		
		int acs=getHex(A);//saved accumulator at acs
		memory[a]=acs;
		int cde=i;
		counter=counter+(cde-cdi);
		//cout<<"Result\nA: "<<<<endl;
		cout<<"Memory\t\tContents"<<endl;
		for(int k=cdi;k<cde;k++){
			char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
		}
		
	}
	void NoIn(){
		cout<<"didnothing";
		memory[i++]==NOPi;
		counter++;
	//	goto nope;
	}
	
};
class OPERATIONS : public INSTRUCTIONS{
	private:
	int firstn, secondn;
	public:
	OPERATIONS(){}
	INSTRUCTIONS OF;
	void add(){
		cout<<"Enter First Number: ";
		cin>>firstn;
		cout<<"Enter Second Number: ";
		cin>>secondn;
		addition(firstn,secondn);
		cout<<"///////////////////n";
		
	}
	void sub(){
		cout<<"Enter First Number: ";
		cin>>firstn;
		cout<<"Enter Second Number: ";
		cin>>secondn;
		subtraction(firstn,secondn);
		cout<<"///////////////////n";
		
	}
	void divn(){
		cout<<"Enter First Number: ";
		cin>>firstn;
		cout<<"Enter Second Number: ";
		cin>>secondn;
		if(secondn==0)cout<<"Invalid data";
		else	division(firstn,secondn);
		cout<<"///////////////////n";
		
	}
	void multp(){
		cout<<"Enter First Number: ";
		cin>>firstn;
		cout<<"Enter Second Number: ";
		cin>>secondn;
		multiplication(firstn,secondn);
		cout<<"///////////////////n";
	}
	void movement(){
		char xs,ys;
		cout<<"Which Register's Value do you want to move to:";
		cin>>xs;
		cout<<"Which value do you want to Move:";cin>>ys;
		if((xs=='A'||xs=='a')&&(ys=='b'||ys=='B')) moving(A,B);
		else if((xs=='A'||xs=='a')&&(ys=='c'||ys=='C')) moving(A,C);
		else if((xs=='B'||xs=='b')&&(ys=='a'||ys=='A')) moving(B,A);
		else if((xs=='B'||xs=='b')&&(ys=='c'||ys=='C')) moving(B,C);
		else if((xs=='C'||xs=='c')&&(ys=='b'||ys=='B')) moving(C,B);
		else if((xs=='C'||xs=='c')&&(ys=='a'||ys=='A')) moving(C,A);
	}
	void storingAm(){
		int loc;
		cout<<"Kindly enter the location: ";
		cin>>loc;
		storingAccumulator(loc);
	}
	void OrGate(){
		int typ;
		char rg;
		cout<<"\nChoose Type: 1.Immdiate \t \t 2.Registers\n";
		cin>>typ;
		if(typ==1) oringAImd();
		else if(typ==2){
			cout<<"Enter Register you want to OR: ";
			cin>>rg;
			if(rg=='B'||rg=='b') oringA(B);
			else if(rg=='C'||rg=='c') oringA(C);
		}
	}
	void XorGate(){
		int typ;
		char rg;
		cout<<"\nChoose Type: 1.Immdiate \t \t 2.Registers\n";
		cin>>typ;
		if(typ==1) xORingImd();
		else if(typ==2){
			cout<<"Enter Register you want to XOR: ";
			cin>>rg;
			if(rg=='B'||rg=='b') XOring(B);
			else if(rg=='C'||rg=='c') XOring(C);
	}
	}
	void AndGate(){
		int typ;
		char rg;
		cout<<"\nChoose Type: 1.Immdiate \t \t 2.Registers\n";
		cin>>typ;
		if(typ==1) andingAImd();
		else if(typ==2){
			cout<<"Enter Register you want to OR: ";
			cin>>rg;
			if(rg=='B'||rg=='b') andingA(B);
			else if(rg=='C'||rg=='c') andingA(C);
		}
	}
	void LoadingAcc(){
		string ddd;
		cout<<"\nEnter Data to be loaded:	\n";
		cin>>ddd;
		loadingAccumulator(ddd);
	}
	void showMemory(){
		cout<<"Total memory Used in Programm"<<endl;
	cout <<"Memory : \t\tContents"<<endl;
	for(int k=2001;k<=counter+2000;k++){
		char shwstring [10];
			itoa(memory[k],shwstring,16);
			cout<<k<<"\t\t"<<shwstring<<endl;
	}
	
	}
};
int getHex(string hexstr) {
    return (int)strtol(hexstr.c_str(), 0, 16);
}
