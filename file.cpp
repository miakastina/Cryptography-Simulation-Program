//Created by Mia Kastina
//   NIM 2015-81-178
#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
void binary(unsigned char x)
{
	for (int i=7; i>=0; i--)
    {
		if(x >= pow(2,i))
		{
			cout<<"1";
			x = x - pow(2,i);
		}
		else
		cout<<"0";
	}
} 
void headerStart()
{
	cout<<" ........................................ \n";
	cout<<" :   Cryptography Simulation Program    : \n";
	cout<<" :                Using                 : \n";
	cout<<" :             Hash and XOR             : \n";
	cout<<" ........................................ \n\n";
}
void headerProcessXOR()
{
cout<<" ============= PROCESS  XOR =============\n"; 
}
void headerEN(){
cout<<" =============  ENCRYPTION  =============\n\n";
}
void headerDE(){
cout<<" =============  DECRYPTION  =============\n\n";
}
void headerAfterEnkryption()
{
	cout<<"             After Encryption            \n";
	cout<<" ========================================\n";
	cout<<"\n"<<" ";
}
void headerAfterDekryption()
{
	cout <<"             After Decryption            \n";
	cout <<" ========================================\n";
	cout <<"\n"<<" ";
}
void CreatedBy()
{
	char n[20]= {78,97,109,97,32,58,32,77,105,97,32,75,97,115,116,105,110,97};
	char m[20]= {78,73,77,32,32,58,32,50,48,49,53,45,56,49,45,49,55,56};
	int i;
	cout <<" ========================================\n\t"<<"   ";
	for(i=0;i<=17;i++)
	{
	 	cout<<n[i];
	}	
	cout<<"\n\t"<<"   ";
	for(i=0;i<=17;i++)
	{
		cout<<m[i];
	}
	cout<<"\n"<<" ========================================\n";
}

int main()
{
unsigned char pw[100],encryption[100],decryption[100],name[100],address[100],num[100],type[100],exp[100],birth[100];
int long_data,long_key,i,j=0;
unsigned int ascii[100],ascii_key[100],ascii_encrypt[100],ascii_decrypt[100];
string username1;
string username2;
	headerStart();
	cout<<" Create an account\n";
	cout<<" Username : ";
	getline(cin,username1);
	string str(username1);
	cout<<" Password : ";
	cin.getline((char*)pw,100);
	cout<<"\n Add Profile\n";
	cout<<" Name       : ";
	cin.getline((char*)name,100);
	cout<<" Address    : ";
	cin.getline((char*)address,100);
	cout<<" Birthday   : ";
	cin.getline((char*)birth,100);
cout<<endl;
system("PAUSE");
system("CLS");
	cout<<"\n To make a transaction, enter your credit card information below !\n\n";
	cout<<" Add Credit Card\n";
	cout<<" Card Type         : ";
	cin.getline((char*)type,100);
	cout<<" Card Number       : ";
	cin.getline((char*)num,100);
	cout<<" Expiration Date   : ";
	cin.getline((char*)exp,100);
	system("CLS");
	cout<<" \n Data has been saved.\n\n Note:\t This is just a simulation.\n\t Username2 as another user, can be encrypt and decrypt data that has been entered\n\n";	
system("PAUSE");
system("CLS");	
	cout<<"\n SIGN IN\n";
	cout <<" Username : ";
	getline(cin,username2);
	if(username2 == username1)
	{
		cout<<"\n Data received !!!\n";
		goto next;
	}
	else
	{
		cout<<"\n Sorry, you can't be accessed :( \n";
	}
	return 0;
	next:
	cout <<" Password : "<<((char*)pw);
	cout<<"\n";
	long_data = str.length();
	long_key = strlen ((char*)pw);
 	int hash = 1;
    for (int i = 0; i <=long_key-1; i++) 
	{
        hash = 31 * hash + pw[i];
    }
	cout<<endl;
	cout<<" Key has been in hash : "<<hash<<endl<< " character \t: "<<char(hash)<<endl;
	cout<<" Binary \t: ";
	binary(int(hash));
cout<<"\n\n"; 
	headerProcessXOR();
	headerEN();
	for (i=0; i<=long_data; i++)
	{
		ascii[i]=username1[i];
		ascii_key[i]=int(hash);
		cout<<" ";
		binary(username1[i]);
		cout<<"  "<<" XOR "<<"  ";
		binary(int (hash));
		cout<<"   =   ";
		ascii_encrypt[i] = ascii[i] ^ ascii_key[j]; 
		j = j + 1;		
			if (j == long_key)
			{
				j = 0;
			}
		encryption[i] = int (ascii_encrypt[i]);
		binary(encryption[i]);
		cout<<endl;
		cout<<"\t\t  Decimal "<<"   =   "<<int(encryption[i])<<"\n"
			<<"\t\t  Char "<<"\t     =   "<<encryption[i]<<endl;
	}
cout<<endl;
	headerAfterEnkryption();
	for (i=0; i<=long_data-1; i++)
	{
		cout<<encryption[i]<<" ";
	}
cout<<"\n\n";
system("PAUSE");
system("CLS");
cout<<"\n";
	headerProcessXOR();
	headerDE();
	for (i=0; i<=long_data; i++)
	{
		cout<<" ";
		binary(encryption[i]);
		cout<<"  "<<" XOR "<<"  ";
		binary(int(hash));
		cout<<"   =   ";
		ascii_decrypt[i] = ascii_encrypt[i] ^ ascii_key[j]; 
		j = j + 1;		
			if (j == long_key)
			{
				j = 0;
			}
		decryption[i] = int(ascii_decrypt[i]);
		binary(decryption[i]);
		cout<<endl;
		cout<<"\t\t  Decimal "<<"   =   "<<int(decryption[i])<<"\n"
			<<"\t\t  Char "<<"\t     =   "<<decryption[i]<<endl;
	}
cout<<endl;
	headerAfterDekryption();
	for (i=0; i<=long_data-1; i++)
	{
		cout<<decryption[i]<<" ";
	}
cout<<"\n\n";
system("PAUSE");
system("CLS");
	cout<<"\n Profile Information\n";
	cout<<" Name            : "<<((char*)name);
	cout<<" \n";
	cout<<" Address         : "<<((char*)address);
	cout<<" \n";
	cout<<" Birthday        : "<<((char*)birth);
	cout<<" \n";
	cout<<"\n Credit Card Information\n";
	cout<<" Card Type       : "<<((char*)type);
	cout<<" \n";
	cout<<" Card Number     : "<<((char*)num);
	cout<<" \n";
	cout<<" Expiration Date : "<<((char*)exp);
	cout<<" \n";
	cout<<endl<<endl;
	CreatedBy();
return 0;
}

