#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//***********************************************
bool validation(int v_Icounter,int v_Vcounter,int v_Xcounter,int v_Lcounter,int v_Ccounter,int v_Dcounter);
long calculate(long c_num1,long c_num2,char c_symbol);
int hierarchy(char char_check);//this function is to check if the hierarchy is correct
int getdata(int what_num);//what_num is a variable to know if is the first or second number
void printdata(long p_num);
//***********************************************

//***********************************************
int hierarchy(char char_check)
{
	if(char_check=='M')//Is the largest so it gives the biggest result
	{
		return 7;
	}
	else if(char_check=='D')
	{
		return 6;
	}
	else if(char_check=='C')
	{
		return 5;
	}
	else if(char_check=='L')
	{
		return 4;
	}
	else if(char_check=='X')
	{
		return 3;
	}
	else if(char_check=='V')
	{
		return 2;
	}
	else if(char_check=='I')//Is the smallest so it gives the lowest result
	{
		return 1;
	}
}
//***********************************************

//***********************************************
int getdata(int what_num)
{
	int Icounter=0,Vcounter=0,Xcounter=0,Lcounter=0,Ccounter=0,Dcounter=0,Mcounter=0;
	char roman_char,previous_char='M';
	long g_num=0;
	bool wrong_input=false;
	
	do
	{
		
		if(what_num==1)
		{
				printf("Enter the first number:\n");
		}
		else if(what_num==2)
		{
				printf("Enter the second number:\n");
		}
		
		//initialasing the variables in order to avoid errors.
		Icounter=0;
		Vcounter=0;
		Xcounter=0;
		Lcounter=0;
		Ccounter=0;
		Dcounter=0;
		Mcounter=0;
		g_num=0;
		previous_char='M';
		wrong_input=false;
	
		while((roman_char=getchar())!='\n')
		{
			
			switch(roman_char)
			{
				//The char_count is used to count how letters were used before wrong_input become true( used if the input is incorrect)
				case 'I':
						g_num+=1;
						Icounter++;
						break;
				case 'V':
						g_num+=5;
						Vcounter++;
						break;
				case 'X':
						g_num+=10;
						Xcounter++;
						break;
				case 'L':
						g_num+=50;
						Lcounter++;
						break;
				case 'C':
						g_num+=100;
						Ccounter++;
						break;
				case 'D':
						g_num+=500;
						Dcounter++;
						break;
				case 'M':
						g_num+=1000;
						Mcounter++;
						break;
				default:
						printf("Wrong Input(M,D,C,L,X,V,I)!\n");
						wrong_input=true;
						break;
			}
			
			if((hierarchy(previous_char)<hierarchy(roman_char)) && !wrong_input)
			{
				wrong_input=true;
				printf("Wrong Input! Wrong hierarchy!\n");
			}
			previous_char=roman_char;
			
		}
		
		//calling the validation function to check if the inputs are correct.
		if(!wrong_input)
		{
			wrong_input = validation(Icounter,Vcounter,Xcounter,Lcounter,Ccounter,Dcounter);
		}
		
	
	}while(Icounter>=5  || Vcounter>=2 || Xcounter>=5 || Lcounter>=2 || Ccounter>=5 ||Dcounter>=2 || wrong_input);
	
	return g_num;
	
}
//***********************************************



//***********************************************
void printdata(long p_num)
{
	while(p_num!=0)
	{
		if(p_num>=1000)
		{
			printf("M");
			p_num-=1000;
		}
		else if(p_num>=500)
		{
			printf("D");
			p_num-=500;
		}
		else if(p_num>=100)
		{
			printf("C");
			p_num-=100;
		}
		else if(p_num>=50)
		{
			printf("L");
			p_num-=50;
		}
		else if(p_num>=10)
		{
			printf("X");
			p_num-=10;
		}
		else if(p_num>=5)
		{
			printf("V");
			p_num-=5;
		}
		else if(p_num>=1)
		{
			printf("I");
			p_num-=1;
		}
	}
}
//***********************************************

//***********************************************
int main()
{
	char symbol;
	long num1=0,num2=0,result=0;
	
	num1=getdata(1);
	printf("The first number is %ld\n",num1);
	
	num2=getdata(2);
	printf("The second number is %ld\n",num2);
	
	//Read the mathimatic symbol(+,-,*,/)
	do
	{
		printf("Enter the desired arithmetic operation:\n");
		scanf("%s",&symbol);
		
		if(symbol!='+' && symbol!='-' && symbol!='*' && symbol!='/')
		{
			printf("Wrong Input(+,-,*,/)!\n");
		}
	}while(symbol!='+' && symbol!='-' && symbol!='*' && symbol!='/');
	
	//calling the calculate function find the result.
	result=calculate(num1,num2,symbol);
	
	if(symbol=='+')
	{
		printf("The sum of ");
	}
	else if(symbol=='-')
	{
		printf("The difference  of ");
	}
	else if(symbol=='*')
	{
		printf("The product  of ");
	}
	else if(symbol=='/')
	{
		printf("The quotient   of ");
	}
	
	//tranlate the first number to roman number.
	printdata(num1);	
	printf(" and ");
		
	//tranlate the second number to roman number.
	printdata(num2);
	printf(" is ");
		
	//tranlate the result to roman number.
	printdata(result);
	printf(" (%ld)\n",result);
	
	return 0;
}
//***********************************************

//***********************************************
bool validation(int v_Icounter,int v_Vcounter,int v_Xcounter,int v_Lcounter,int v_Ccounter,int v_Dcounter)
{
	if(v_Icounter>=5)
	{
		printf("Wrong input IIIII=V\n");
	}
	
	if(v_Vcounter>=2)
	{
		printf("Wrong input VV=X\n");
	}
	
	if(v_Xcounter>=5)
	{
		printf("Wrong input XXXXX=L\n");
	}
	
	if(v_Lcounter>=2)
	{
		printf("Wrong input LL=C\n");
	}
	
	if(v_Ccounter>=5)
	{
		printf("Wrong input CCCCC=D\n");
	}
	
	if(v_Dcounter>=2)
	{
		printf("Wrong input DD=M\n");
	}
	
	if(!(v_Dcounter>=2 && v_Ccounter>=5 && v_Lcounter>=2 && v_Xcounter>=5 && v_Vcounter>=2 && v_Icounter>=5))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//***********************************************

//***********************************************
long calculate(long c_num1,long c_num2,char c_symbol)
{
	if(c_symbol=='+')
	{
		return (c_num1+c_num2);
	}
	else if(c_symbol=='-')
	{
		return (abs(c_num1-c_num2));
	}
	else if(c_symbol=='*')
	{
		return (c_num1*c_num2);
	}
	else if(c_symbol=='/')
	{
		return (c_num1/c_num2);
	}
}
//***********************************************


