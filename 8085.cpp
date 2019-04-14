#include<iostream>
#include<fstream>
#include<string.h>
#include<map>
#include<iterator>
using namespace std;
class Fetch{
	public:
		int sno,loc;
		string opcode;
		string data;
		int time;
		string hexcode,samplehex;
		string value;
		int byte; 
};
class Timer:public Fetch{
	private:
		int maxLen=0;
		int i=6999;
		int time1=0;
		string hex1;
		Fetch f[10000];
		int totalTime;
		//registers A,B,C,D,E,H,L
		int A=0,B=0,C=0,D=0,E=0,H=0,L=0,M=0;
		string low,high;
		map <int,string> memVal;
	public:
			ofstream myfile;
				
		Timer(){
			myfile.open("sample.txt");
			do{
				//cout<<".........."<<endl;
				i++;
				maxLen=i;
				cout<<i<<" : ";
				cin>>hex1;
				f[i].hexcode=hex1;
				myfile<<i<<" "<<hex1<<endl;
				timer(f[i].hexcode);
				
			}while(f[i].hexcode!="CF");
			myfile.close();
			cout<<"Enter memory locations and values to be inserted"<<endl;
			cout<<"To exit pls enter 0000"<<endl;
			do{
				cin>>i;
				if(i!=0000)
				cin>>f[i].value;
				if(i!=0)
				//cout<<"value stored in ["<<i<<"] = "<<f[i].value<<endl;
				memVal.insert(pair <int, string> (i,f[i].value));
			}while(i!=0000);
			map <int, string> :: iterator itr;
			int currentValue=0;
			int currentFlag=0;
			for(int i=7000;i<=maxLen;i++){
				ifstream theFile2("sample.txt");
				ifstream theFile1("mpj.txt");
				/*should call each and every
				instruction from the beginning
				and compute the time........
				*/
				int j=i;
				while(theFile2 >> loc >> samplehex){
					if(i==loc){
						while(theFile1 >> sno >> opcode >> data >> time >> hexcode >> byte){
							
							if(samplehex==hexcode){
								//ADD A,B,C,D,E,H,L,M
								if(samplehex=="87"){
									A=A+A;
									currentValue=A;
								}
								else if(samplehex=="80"){
									A=A+B;
									currentValue=A;
								}
								else if(samplehex=="81"){
									A=A+C;
									currentValue=A;
								}
								else if(samplehex=="82"){
									A=A+D;
									currentValue=A;
								}
								else if(samplehex=="83"){
									A=A+E;
									currentValue=A;
								}
								else if(samplehex=="84"){
									A=A+H;
									currentValue=A;
								}
								else if(samplehex=="85"){
									A=A+L;
									currentValue=A;
								}
								else if(samplehex=="86"){
									A=A+M;
									currentValue=M;
								}
								//ADI data
								if(samplehex=="CE"){
									A=A+hexToDec(f[++j].value);
									currentValue=A;
								}
									
								//MVI A,B,C,D,E,H,L,M
								if(samplehex=="3E"){
									A=hexToDec(f[++j].value);
									currentValue=A;
								}
								else if(samplehex=="06"){
									B=hexToDec(f[++j].value);
									currentValue=B;
								}
								else if(samplehex=="0E"){
									C=hexToDec(f[++j].value);
									currentValue=C;
								}
								else if(samplehex=="16"){
									D=hexToDec(f[++j].value);
									currentValue=D;
								}
								else if(samplehex=="1E"){
									E=hexToDec(f[++j].value);
									currentValue=E;
								}
								else if(samplehex=="26"){
									H=hexToDec(f[++j].value);
									currentValue=H;
								}
								else if(samplehex=="2E"){
									L=hexToDec(f[++j].value);
									currentValue=L;
								}
								else if(samplehex=="36"){
									M=hexToDec(f[++j].value);
									currentValue=M;
								}
									
								//MOV
								if(samplehex=="7F"){
									A=A;
									currentValue=A;
								}
								else if(samplehex=="78"){
									A=B;
									currentValue=A;
								}
								else if(samplehex=="79"){
									A=C;
									currentValue=A;
								}
								else if(samplehex=="7A"){
									A=D;
									currentValue=A;
								}
								else if(samplehex=="7B"){
									A=E;
									currentValue=A;
								}
								else if(samplehex=="7C"){
									A=H;
									currentValue=A;
								}
								else if(samplehex=="7D"){
									A=L;
									currentValue=A;
								}
								else if(samplehex=="47"){
									B=A;
									currentValue=B;
								}
								else if(samplehex=="40"){
									B=B;
									currentValue=B;
								}
								else if(samplehex=="41"){
									B=C;
									currentValue=B;
								}
								else if(samplehex=="42"){
									B=D;
									currentValue=B;
								}
								else if(samplehex=="43"){
									B=E;
									currentValue=B;
								}
								else if(samplehex=="44"){
									B=H;
									currentValue=B;
								}
								else if(samplehex=="45"){
									B=L;
									currentValue=B;
								}
								else if(samplehex=="4F"){
									C=A;
									currentValue=C;
								}
								else if(samplehex=="48"){
									C=B;
									currentValue=C;
								}
								else if(samplehex=="49"){
									C=C;
									currentValue=C;
								}
								else if(samplehex=="4A"){
									C=D;
									currentValue=C;
								}
								else if(samplehex=="4B"){
									C=E;
									currentValue=C;
								}
								else if(samplehex=="4C"){
									C=H;
									currentValue=C;
								}
								else if(samplehex=="4D"){
									C=L;
									currentValue=C;
								}
								else if(samplehex=="57"){
									D=A;
									currentValue=D;
								}
								else if(samplehex=="50"){
									D=B;
									currentValue=D;
								}
								else if(samplehex=="51"){
									D=C;
									currentValue=D;
								}
								else if(samplehex=="52"){
									D=D;
									currentValue=D;
								}
								else if(samplehex=="53"){
									D=E;
									currentValue=D;
								}
								else if(samplehex=="54"){
									D=H;
									currentValue=D;
								}
								else if(samplehex=="55"){
									D=L;
									currentValue=D;
								}
								else if(samplehex=="5F"){
									E=A;
									currentValue=E;
								}
								else if(samplehex=="58"){
									E=B;
									currentValue=E;
								}
								else if(samplehex=="59"){
									E=C;
									currentValue=E;
								}
								else if(samplehex=="5A"){
									E=D;
									currentValue=E;
								}
								else if(samplehex=="5B"){
									E=E;
									currentValue=E;
								}
								else if(samplehex=="5C"){
									E=H;
									currentValue=E;
								}
								else if(samplehex=="5D"){
									E=L;
									currentValue=E;
								}
								else if(samplehex=="67"){
									H=A;
									currentValue=H;
								}
								else if(samplehex=="60"){
									H=B;
									currentValue=H;
								}
								else if(samplehex=="61"){
									H=C;
									currentValue=H;
								}
								else if(samplehex=="62"){
									H=D;
									currentValue=H;
								}
								else if(samplehex=="63"){
									H=E;
									currentValue=H;
								}
								else if(samplehex=="64"){
									H=H;
									currentValue=H;
								}
								else if(samplehex=="65"){
									H=L;
									currentValue=H;
								}
								else if(samplehex=="6F"){
									L=A;
									currentValue=L;
								}
								else if(samplehex=="68"){
									L=B;
									currentValue=L;
								}
								else if(samplehex=="69"){
									L=C;
									currentValue=L;
								}
								else if(samplehex=="6A"){
									L=D;
									currentValue=L;
								}
								else if(samplehex=="6B"){
									L=E;
									currentValue=L;
								}
								else if(samplehex=="6C"){
									L=H;
									currentValue=L;
								}
								else if(samplehex=="6D"){
									L=L;
									currentValue=L;
								}
								else if(samplehex=="77"){
									M=A;
									currentValue=M;
								}
								else if(samplehex=="70"){
									M=B;
									currentValue=M;
								}
								else if(samplehex=="71"){
									M=C;
									currentValue=M;
								}
								else if(samplehex=="72"){
									M=D;
									currentValue=M;
								}
								else if(samplehex=="73"){
									M=E;
									currentValue=M;
								}
								else if(samplehex=="74"){
									M=H;
									currentValue=M;
								}
								else if(samplehex=="75"){
									M=L;
									currentValue=M;
								}
								else if(samplehex=="7E"){
									A=M;
									currentValue=A;
								}
								else if(samplehex=="46"){
									B=M;
									currentValue=B;
								}
								else if(samplehex=="4E"){
									C=M;
									currentValue=C;
								}
								else if(samplehex=="56"){
									D=M;
									currentValue=D;
								}
								else if(samplehex=="5E"){
									E=M;
									currentValue=E;
								}
								else if(samplehex=="66"){
									H=M;
									currentValue=H;
								}
								else if(samplehex=="6E"){
									L=M;
									currentValue=L;
								}
																
								//SUB
								if(samplehex=="97"){
									A=A-A;
									currentValue=A;
								}
								else if(samplehex=="90"){
									A=A-B;
									currentValue=A;
								}
								else if(samplehex=="91"){
									A=A-C;
									currentValue=A;
								}
								else if(samplehex=="92"){
									A=A-D;
									currentValue=A;
								} 
								else if(samplehex=="93"){
									A=A-E;
									currentValue=A;
								}
								else if(samplehex=="94"){
									A=A-H;
									currentValue=A;
								}
								else if(samplehex=="95"){
									A=A-L;
									currentValue=A;
								}
								else if(samplehex=="96"){
									A=A-M;
									currentValue=A;
								}
								//SUI
								if(samplehex=="D6"){
									A=A-hexToDec(f[++j].value);
									currentValue=A;
								}
								//XRA
								if(samplehex=="AF"){
									A=0;
									currentValue=A;
								}
								else if(samplehex=="A8"){
									B=0;
									currentValue=B;
								}
								else if(samplehex=="A9"){
									C=0;
									currentValue=C;
								}
								else if(samplehex=="AA"){
									D=0;
									currentValue=D;
								}
								else if(samplehex=="AB"){
									E=0;
									currentValue=E;
								}
								else if(samplehex=="AC"){
									H=0;
									currentValue=H;
								}
								else if(samplehex=="AD"){
									L=0;
									currentValue=L;
								}
								//STA and STAX
								if(samplehex=="32"){
									int temp=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
									f[temp].value=A;
								}
								else if(samplehex=="02"){
									int temp=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
									f[temp].value=B;
								}
								else if(samplehex=="12"){
									int temp=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
									f[temp].value=D;
								}
								//DCR
								if(samplehex=="3D"){
									A=A-1;
									currentValue=A;
								}
								else if(samplehex=="05"){
									B=B-1;
									currentValue=B;
								}
								else if(samplehex=="0D"){
									C=C-1;
									currentValue=C;
								}
								else if(samplehex=="15"){
									D=D-1;
									currentValue=D;
								}
								else if(samplehex=="1D"){
									E=E-1;
									currentValue=E;
								}
								else if(samplehex=="25"){
									H=H-1;
									currentValue=H;
								}
								else if(samplehex=="2D"){
									L=L-1;
									currentValue=L;
								}
								//INR
								if(samplehex=="3C"){
									A=A+1;
									currentValue=A;
								}
								else if(samplehex=="04"){
									B=B+1;
									currentValue=B;
								}
								else if(samplehex=="0C"){
									C=C+1;
									currentValue=C;
								}
								else if(samplehex=="14"){
									D=D+1;
									currentValue=D;
								}
								else if(samplehex=="1C"){
									E=E+1;
									currentValue=E;
								}
								else if(samplehex=="24"){
									H=H+1;
									currentValue=H;
								}
								else if(samplehex=="2C"){
									L=L+1;
									currentValue=L;
								}
								//CMP
								if(samplehex=="BF"){
									int temp;
									temp=A-A;
									currentValue=temp;
								}
								else if(samplehex=="B8"){
									int temp;
									temp=A-B;
									currentValue=temp;
								}
								else if(samplehex=="B9"){
									int temp;
									temp=A-C;
									currentValue=temp;
								}
								else if(samplehex=="BA"){
									int temp;
									temp=A-D;
									currentValue=temp;
								}
								else if(samplehex=="BB"){
									int temp;
									temp=A-E;
									currentValue=temp;
								}
								else if(samplehex=="BC"){
									int temp;
									temp=A-H;
									currentValue=temp;
								}
								else if(samplehex=="BD"){
									int temp;
									temp=A-L;
									currentValue=temp;
								}
								else if(samplehex=="BE"){
									int temp;
									temp=A-M;
									currentValue=temp;
								}
								//JUMP statements
								if(samplehex=="DA"){
									currentFlag=currentValue;
									if(currentFlag<0){
										i=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
										i=i-3;
									}
								}
								else if(samplehex=="FA"){
									if(currentValue<0){
										i=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
										i=i-3;
									}
								}
								else if(samplehex=="C3"){
									i=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
									i=i-3;
								}
								else if(samplehex=="D2"){
									currentFlag=currentValue;
									if(currentFlag>0){
										i=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
										i=i-3;
									}
								}
								else if(samplehex=="C2"){
									if(currentValue!=0){
										i=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
										i=i-3;
									}
								}
								else if(samplehex=="CA"){
									if(currentValue==0){
										i=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
										i=i-3;
									}
								}
								//LDA and LDAX
								if(samplehex=="3A"){
									int temp=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
									A=hexToDec(f[temp].value);
									currentValue=A;
								}
								else if(samplehex=="0A"){
									int temp=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
									B=hexToDec(f[temp].value);
									currentValue=B;
								}
								else if(samplehex=="1A"){
									int temp=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
									D=hexToDec(f[temp].value);
									currentValue=D;
								}
								//LXI
								if(samplehex=="01"){
									C=hexToDec2(f[++j].value);
									B=hexToDec2(f[++j].value);
									int temp=(B*100)+C;
									M=hexToDec(f[temp].value);
									currentValue=M;
								}
								else if(samplehex=="11"){
									E=hexToDec2(f[++j].value);
									D=hexToDec2(f[++j].value);
									int temp=(D*100)+E;
									M=hexToDec(f[temp].value);
									currentValue=M;
								}
								else if(samplehex=="21"){
									L=hexToDec2(f[++j].value);
									H=hexToDec2(f[++j].value);
									int temp=(H*100)+L;
									M=hexToDec(f[temp].value);
									currentValue=M;
								}
								//INX
								if(samplehex=="03"){
									int temp;
									temp=((B*100)+C)+1;
									M=hexToDec(f[temp].value);
									currentValue=M;
								}
								else if(samplehex=="13"){
									int temp;
									temp=((D*100)+E)+1;
									M=hexToDec(f[temp].value);
									currentValue=M;
								}	
								else if(samplehex=="23"){
									int temp;
									temp=((H*100)+L)+1;
									M=hexToDec(f[temp].value);
									currentValue=M;
								}
								//DCX
								if(samplehex=="0B"){
									int temp;
									temp=((B*100)+C)-1;
									M=hexToDec(f[temp].value);
									currentValue=M;
								}
								else if(samplehex=="1B"){
									int temp;
									temp=((D*100)+E)-1;
									M=hexToDec(f[temp].value);
									currentValue=M;
								}	
								else if(samplehex=="2B"){
									int temp;
									temp=((H*100)+L)-1;
									M=hexToDec(f[temp].value);
									currentValue=M;
								}
								//LHLD
								if(samplehex=="2A"){
									int temp1=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
									int temp2=temp1+1;
									L=hexToDec(f[temp1].value);
									H=hexToDec(f[temp2].value);
								}				
								//SHLD
								if(samplehex=="22"){
									int temp1=hexToDec2(f[++j].value)+(hexToDec2(f[++j].value)*100);
									int temp2=temp1+1;
									f[temp1].value=L;
									f[temp2].value=H;
								}
											
								time1=time1+time;
								//cout<<loc<<"-->Time:"<<time1<<endl;
								//cout<<"Current Value = "<<currentValue<<endl;
								if(byte==3)
									i=i+2;
								else if(byte==2)
									i=i+1;
							
							}
						}
					}
				}
			}
			//cout<<"---------------------------------------"<<endl;
			cout<<"\nTotal Time:"<<time1<<endl;
			
			for(itr=memVal.begin();itr!=memVal.end();++itr){
				cout<<itr->first<<"		"<<itr->second<<endl;
			}
			
			//cout<<"Total Time:"<<totalTime<<endl;
		}
		void timer(string hex2){
			ifstream theFile1("mpj.txt");
			while(theFile1 >> sno >> opcode >> data >> time >> hexcode >> byte){
				if(hexcode==hex2 && opcode=="RST" && data=="1"){
					//return time1;
					return;
				}
				if(hexcode==hex2){
					if(byte==3){
						for(int c=1;c<byte;c++){
							i++;
							cout<<i<<" : ";
							cin>>f[i].value;
							if(c==1){
								low=f[i].value;
								myfile<<i<<" "<<f[i].value<<endl;
								//cout<<"Lower order 8 bits:"<<low<<endl;
							}
							if(c==2){
								high=f[i].value;
								myfile<<i<<" "<<f[i].value<<endl;
								//cout<<"Higher order 8 bits:"<<high<<endl;
							}
						
						}
						
						//cout<<"Location saved in "<<high<<low<<endl;
					}
					if(byte==2){
						i++;
						cout<<i<<" : ";
						cin>>f[i].value;
						int x=hexToDec(f[i].value);
						
						if(data[0]=='A')
							A=x;
						else if(data[0]=='B')
							B=x;
						else if(data[0]=='C')
							C=x;
						else if(data[0]=='D')
							D=x;
						else if(data[0]=='E')
							E=x;
						else if(data[0]=='H')
							H=x;
						else if(data[0]=='L')
							L=x;
						
						myfile<<i<<" "<<f[i].value<<endl;	
						//cout<<"Value stored "<<x<<endl;
					}
					if(byte==1){
						//Accumulator actions!!
					}
					//time1=time1+time;
				}
			}
			return;
			//return time1;
		}
		
	int hexToDec(string s){
		int result=0;
		if(s[1]=='0'){
			result+=(0*1);
		}
		else if(s[1]=='1'){
			result+=(1*1);
		}
		else if(s[1]=='2'){
			result+=(1*2);
		}
		else if(s[1]=='3'){
			result+=(1*3);
		}
		else if(s[1]=='4'){
			result+=(1*4);
		}
		else if(s[1]=='5'){
			result+=(1*5);
		}
		else if(s[1]=='6'){
			result+=(1*6);
		}
		else if(s[1]=='7'){
			result+=(1*7);
		}
		else if(s[1]=='8'){
			result+=(1*8);
		}
		else if(s[1]=='9'){
			result+=(1*9);
		}
		else if(s[1]=='A'){
			result+=(1*10);
		}
		else if(s[1]=='B'){
			result+=(1*11);
		}
		else if(s[1]=='C'){
			result+=(1*12);
		}
		else if(s[1]=='D'){
			result+=(1*13);
		}
		else if(s[1]=='E'){
			result+=(1*14);
		}
		else if(s[1]=='F'){
			result+=(1*15);
		}
		if(s[0]=='0'){
			result+=(16*0);
		}
		else if(s[0]=='1'){
			result+=(16*1);
		}
		else if(s[0]=='2'){
			result+=(16*2);
		}
		else if(s[0]=='3'){
			result+=(16*3);
		}
		else if(s[0]=='4'){
			result+=(16*4);
		}
		else if(s[0]=='5'){
			result+=(16*5);
		}
		else if(s[0]=='6'){
			result+=(16*6);
		}
		else if(s[0]=='7'){
			result+=(16*7);
		}
		else if(s[0]=='8'){
			result+=(16*8);
		}
		else if(s[0]=='9'){
			result+=(16*9);
		}
		else if(s[0]=='A'){
			result+=(16*10);
		}
		else if(s[0]=='B'){
			result+=(16*11);
		}
		else if(s[0]=='C'){
			result+=(16*12);
		}
		else if(s[0]=='D'){
			result+=(16*13);
		}
		else if(s[0]=='E'){
			result+=(16*14);
		}
		else if(s[0]=='F'){
			result+=(16*15);
		}
		return result;
	}

	int hexToDec2(string s){
		int result=0;
		if(s[1]=='0')
			result=0;
		else if(s[1]=='1')
			result=1;
		else if(s[1]=='2')
			result=2;
		else if(s[1]=='3')
			result=3;
		else if(s[1]=='4')
			result=4;
		else if(s[1]=='5')
			result=5;
		else if(s[1]=='6')
			result=6;
		else if(s[1]=='7')
			result=7;
		else if(s[1]=='8')
			result=8;
		else if(s[1]=='9')
			result=9;
			
		if(s[0]=='0')
			result=result+(0);
		else if(s[0]=='1')
			result=result+10;
		else if(s[0]=='2')
			result=result+20;
		else if(s[0]=='3')
			result=result+30;
		else if(s[0]=='4')
			result=result+40;
		else if(s[0]=='5')
			result=result+50;
		else if(s[0]=='6')
			result=result+60;
		else if(s[0]=='7')
			result=result+70;
		else if(s[0]=='8')
			result=result+80;
		else if(s[0]=='9')
			result=result+90;
		
		return result;
	}					
};
int main()
{
	cout<<"Enter code:"<<endl;
	Timer obj;

	
}















