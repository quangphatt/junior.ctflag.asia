#include<iostream>
#include <string.h>

using namespace std;

//int check(char * password)
//{
//	  int lenpass = strlen(password);
//    if ((lenpass ^ 0xF))    //=> 15 characters  CTF{----------}
//		return 0;
//    if ((strncmp(password, "\x43"   //=> password="CTF{-----------";
//            "T\106{", 4) ^ 0x0)) 
//		return 0;
//    if (password[14] != '}') //=> password[14]='}'
//		return 0;
//    const char * pass22 = password + 0x4;    //=> pass22="----------}"
//    if ((pass22[0] > '0') & !!(pass22[0] > '0') || (pass22[0] < '0') & !!(pass22[0] < '0')) 
//		return 0;
//    if (((int) pass22[1] + (0x1B39) ^ 0x1B9B)) 
//		return 0;
//    if (((int) pass22[2] + (int) pass22[3] ^ 0xDB)) 
//		return 0;
//    if (((int) pass22[3] - (int) pass22[2] ^ 0xF)) 
//		return 0;
//    if (pass22[4] - pass22[3] != (char)(-(0x12))) 
//		return 0;
//    if (((pass22[5] ^ '0') ^ 0x4)) 
//		return 0;
//    char o_f5c8733d86f = (char) pass22[6] * (char) pass22[5];
//    if ((char)(pass22[6] * pass22[5]) != -(0x70)) 
//		return 0;
//    if (((0xA) * (int) pass22[7] - (0xC) * (int) pass22[8] + (0x13) * (int) pass22[9] ^ 0x7D4)) 
//		return 0;
//    if (((0x1C) * (int) pass22[7] - (int) pass22[8] + (0x45) * (int) pass22[9] ^ 0x22D2)) 
//		return 0;
//    if (((0x71) * (int) pass22[7] - (0x7E) * (int) pass22[8] + (0x3E7) * (int) pass22[9] ^ 0x1AB43)) 
//		return 0;
//    return 1;
//}

char findPass4()
{
	char res='-';
	
	for(char i='0';i<='z';i++)
	{
		if (!((i > '0') & !!(i > '0') || (i < '0') & !!(i < '0'))) 
		{
			res=i;
			break;
		}
		
	}
			
	return res;
}

char findPass5()
{
	char res='-';
	
	for(char i='0';i<='z';i++)
	{
		if (!((int) i + (0x1B39) ^ 0x1B9B)) 
		{
			res=i;
			break;
		}
		
	}
	
	return res;
}

string findPass67()
{
	string res;
	res="--";
	
	for(char i='0';i<='z';i++)
	{
		for(char j='0';j<='z';j++)
		{
			if(!(((int) i + (int) j ^ 0xDB) || ((int) j - (int) i ^ 0xF)))
			{
				res[0]=i;
				res[1]=j;
				return res;
			}
		}
	}
	
	return res;
}

char findPass8(char pass7)
{
	char res='-';
	
	for(char i='0';i<='z';i++)
	{
		if (!(i - pass7 != (char)(-(0x12)))) 
		{
			res=i;
			break;
		}
		
	}
	
	return res;
}

char findPass9()
{
	char res='-';
	
	for(char i='0';i<='z';i++)
	{
		if (!((i ^ '0') ^ 0x4)) 
		{
			res=i;
			break;
		}
		
	}
	
	return res;
}

char findPass10(char pass9)
{
	char res='-';
	//pass9='4';
		
	for(char i='0';i<='z';i++)
	{
		if (!((char)(i * pass9) != -(0x70)))     //(char)(pass22[6] * pass22[5]) != -(0x70)
		{
			res=i;
			//cout<<i<<"\n";
			break;
		}
		
	}
	
	return res;
}

string findPass11_12_13()
{
	string res;
	res="---";
	
	for(char i1='0';i1<='z';i1++)
	{
		for(char i2='0';i2<='z';i2++)
		{
			for(char i3='0';i3<='z';i3++)
			{
				if(!(((0xA) * (int) i1 - (0xC) * (int) i2 + (0x13) * (int) i3 ^ 0x7D4) || ((0x1C) * (int) i1 - (int) i2 + (0x45) * (int) i3 ^ 0x22D2) || ((0x71) * (int) i1 - (0x7E) * (int) i2 + (0x3E7) * (int) i3 ^ 0x1AB43)))
				{
					res[0]=i1;
					res[1]=i2;
					res[2]=i3;
					break;
				}
				
			}
			
		}
		
	}
	
	return res;
}

string findPass()
{
	char pass[20];
	
	pass[0]='C';
	pass[1]='T';
	pass[2]='F';
	pass[3]='{';
	pass[4]=findPass4();
	pass[5]=findPass5();
	pass[6]=findPass67()[0];
	pass[7]=findPass67()[1];
	pass[8]=findPass8(pass[7]);
	pass[9]=findPass9();
	pass[10]=findPass10(pass[9]);
	pass[11]=findPass11_12_13()[0];
	pass[12]=findPass11_12_13()[1];
	pass[13]=findPass11_12_13()[2];
	pass[14]='}';
	
	return pass;

}

int main()
{
		
	cout<<findPass()<<endl;

	return 0;
	
}
