#include<iostream>
using namespace std;
class StringToInt{
	public:
	int stoi(string number){
		int place=1,num=0;
		int t=number.length()-1;
		for(int i=t;i>=0;i--){
			switch(number[i]){
				case char(48):{
					(i==t)?num=0:num=num+(place*0);
					break;
				}
				case char(49):{
					(i==t)?num=1:num=num+(place*1);
					break;
				}
				case char(50):{
					(i==t)?num=2:num=num+(place*2);
					break;
				}
				case char(51):{
					(i==t)?num=3:num=num+(place*3);
					break;
				}
				case char(52):{
					(i==t)?num=4:num=num+(place*4);
					break;
				}
				case char(53):{
					(i==t)?num=5:num=num+(place*5);
					break;
				}
				case char(54):{
					(i==t)?num=6:num=num+(place*6);
					break;
				}
				case char(55):{
					(i==t)?num=7:num=num+(place*7);
					break;
				}
				case char(56):{
					(i==t)?num=8:num=num+(place*8);
					break;
				}
				case char(57):{
					(i==t)?num=9:num=num+(place*9);
					break;
				}
				default:{
					continue;
					break;
				}
			}
			place*=10;
		}
		return num;
	}
};
