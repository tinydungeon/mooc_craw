#include <iostream>
#include <string>
using namespace std;

public class Solution {
    public double Power(double base, int exponent) {
 		double output;
 		if(equal(base,0.0) && exponent<0){
 			return 0;
 		}

 		unsigned int absExponent = (unsigned int)(exponent);
 		if(exponent<0)
 			absExponent = (-exponent);
 		output = PowerwithUnsigned(bae,absExponent);
 		if(exponent<0)
 			return 1.0/output;
 		else
 			return output;

  }

	public double PowerwithUnsigned(double base,unsigned int abs){
		double result = 1.0;
		for(int i=1;i<=abs;i++)
			result = result*base;
		return result;
	}
}

/*int main(){
	string num1,num2;
	while(cin>>num1>>num2){
		int flag = 0;
		if(num1[0] == '-'){
			num1 = num1.substr(1);
			flag++;
		}
		if(num2[0]=='-'){
			num2 = num2.substr(1);
			flag++;
		}

		if(flag ==1)
			cout <<"-";

	}
}*/

/*bool is_num(char c){
	if(c>='0' && c<='9')
		return true;
	else
		return false;
}

int main(){
	string input;
	while(cin>>input){
		//字符串长度
		int number = 0,max=0;
		int pos =0,tag=0;
		for(int i=0;i<input.size();i++){
			number = 0;
			pos =0;
			if(is_num(input[i])){
				pos = i;
				int j=0;
				for(j=i;j<input.size();j++){
					if(is_num(input[j]))
					{

						number++;
					}
					else
					{
						
						break;
					}

				}
				i = j;
			}
			if(number>=max){
				tag = pos;
				max = number;
			}

		}
		if(max!=0){
			for(int i=0;i<max;i++)
			cout << input[pos+i];
			cout<<","<<max<<endl;
		}
		else
			cout<<"";
	}
	return 0;
}*/

/*int main(){
	int n,num;
	while(cin>>n){
		num=0;
		while(n!=0){
			num += n&0x1;
			n =n>>1;
		}
		cout<<num<<endl;
	}
}*/

/*int main(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=w;j++){
			if(j <w[i]) dp[i][j] =dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
		}
	}
}*/
/*//判断是是否是合法的ip地址
int count[8]={0};
bool is_leg1(string ipaddress){
	int flag = 1;
	int pos = 
	if(flag == 1)
		return true;
	else
		return false;
}

bool is_leg2(string subnet){
	int flag = 1;
	if(flag ==1)
		return true;
	else
		return false;
}

int class_ip(string ipaddress){
	int pos = ipad
}


int main(){



	for(int i=0;i<8;i++)
		cout << count[i] <<" ";
}*/
/*
#include <iostream>
#include <string>
using namespace std;

unsigned int uiInputLen;

unsigned int uiElementNum;

struct ELEMENT_STRU
{
     unsigned int uiElementLength;    //表示uiElementValue占用BIT数，范围1~32
     unsigned int uiElementValue=0;     //从字节流中按顺序解析的数值，用于输出
};

bool int_value(unsigned char c,int num){
	/*cout << "char c is " <<c <<endl;
	cout << "num is "<<num <<endl;*/
	/*for(int i=0;i<8-num;i++)
		c = c>>1;*/
	c = (c>>(8-num)) &(0x1);
	if(c>0)
		return true;
	else
		return false;
	/*switch(num){
		case 8:return(c&0x00000001);
		case 7:return(c&0x00000010);
		case 6:return(c&0x00000100);
		case 5:return(c&0x00001000);
		case 4:return(c&0x00010000);
		case 3:return(c&0x00100000);
		case 2:return(c&0x01000000);
		case 1:return(c&0x10000000);
	}*/
}

unsigned char strtochar(string str){
	unsigned char c=0;
	c = (str[2]-'0')*16+(str[3]-'0');
	return c;
}

int main(){
	string  input[1000];
	unsigned char aInputByte[1000];
	ELEMENT_STRU ele[1000];
	while(cin>>uiInputLen){
		for(int i=0;i<uiInputLen;i++)
			cin >> input[i];
		for(int i=0;i<uiInputLen;i++)
			aInputByte[i] = strtochar(input[i]);

		/*for(int i=0;i<uiInputLen;i++)
			cout << int(aInputByte[i])<<endl;*/

		cin >> uiElementNum;
		for(int i=0;i<uiElementNum;i++)
			cin >> ele[i].uiElementLength;
		int num = 1;
		for(int i=0;i<uiElementNum;i++)
		{
			//开始从字节流中取数字l
			int sum=0;
			unsigned char cont = 128;
			for(int j=0;j<ele[i].uiElementLength;j++)
			{

				sum = sum*2+int_value(aInputByte[num/8],num%8);
				//cout << sum << endl;
				num++;
			}
			ele[i].uiElementValue = sum;
		}

		for(int i=0;i<uiElementNum;i++)
			cout << ele[i].uiElementValue<<endl;
	}
}*/

