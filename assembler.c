#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*******************************************************
 * Function Declaration
 *
 *******************************************************/
char *change_file_ext(char *str);
int hti(char hex[]);
/*******************************************************
 * Function: main
 *
 * Parameters:
 *  int
 *      argc: the number of argument
 *  char*
 *      argv[]: array of a sting argument
 *
 * Return:
 *  return success exit value
 *
 * Info:
 *  The typical main function in C language.
 *  It reads system arguments from terminal (or commands)
 *  and parse an assembly file(*.s).
 *  Then, it converts a certain instruction into
 *  object code which is basically binary code.
 *
 *******************************************************/
void itb (int number,FILE * output)
{
	int position=31;
	int binary[32]={0,};
	while(1)
	{
		binary[position]=number%2;
		number = number/2;

		position--;
		if(number==0)
		{
			break;
		}
	}
	for(int i=0;i<32;i++)
	{
		fprintf(output,"%d",binary[i]);
	}
}

void itb_data(char argv1[50][10][10],int t_loc,FILE * output)
{
	for(int i=1;i<t_loc;i++)
	{
		int c=0;
		int a = argv1[i][9][9];
		if(argv1[i][a-1][0]=='0'&&argv1[i][a-1][1]=='x')
		{
			c = hti(argv1[i][a-1]);
			itb(c,output);
		}
		else
		{
			c = atoi(argv1[i][a-1]);
			itb(c,output);
		}
	}
}

void itb_instruction(int brr[50][9],int b,FILE*output)
{
	for (int i = 0; i < b; i++)
	{
		int position;
		int temp[32] = { 0, };
		int binary[32] = { 0, };
		if (brr[i][0] == 1)
		{
			position = 5;
			while (1)
			{
				binary[position] = brr[i][1] % 2;
				brr[i][1] = brr[i][1] / 2;

				position--;
				if (brr[i][1] == 0)
					break;
			}
			position = 10;
			while (1)
			{
				binary[position] = brr[i][2] % 2;
				brr[i][2] = brr[i][2] / 2;

				position--;
				if (brr[i][2] == 0)
					break;
			}
			position = 15;
			while (1)
			{
				binary[position] = brr[i][3] % 2;
				brr[i][3] = brr[i][3] / 2;

				position--;
				if (brr[i][3] == 0)
					break;
			}
			position = 20;
			while (1)
			{
				binary[position] = brr[i][4] % 2;
				brr[i][4] = brr[i][4] / 2;

				position--;
				if (brr[i][4] == 0)
					break;
			}
			position = 25;
			while (1)
			{
				binary[position] = brr[i][5] % 2;
				brr[i][5] = brr[i][5] / 2;

				position--;
				if (brr[i][5] == 0)
					break;
			}
			position = 31;
			while (1)
			{
				binary[position] = brr[i][6] % 2;
				brr[i][6] = brr[i][6] / 2;

				position--;
				if (brr[i][6] == 0)
					break;
			}
			for (int j = 0; j < 32; j++)
			{
				fprintf(output,"%d", binary[j]);
			}
		}
		else if (brr[i][0] == 2)
		{
			position = 5;
			while (1)
			{
				binary[position] = brr[i][1] % 2;
				brr[i][1] = brr[i][1] / 2;

				position--;
				if (brr[i][1] == 0)
					break;
			}
			position = 10;
			while (1)
			{
				binary[position] = brr[i][2] % 2;
				brr[i][2] = brr[i][2] / 2;

				position--;
				if (brr[i][2] == 0)
					break;
			}
			position = 15;
			while (1)
			{
				binary[position] = brr[i][3] % 2;
				brr[i][3] = brr[i][3] / 2;

				position--;
				if (brr[i][3] == 0)
					break;
			}
			position = 31;
			if (brr[i][4] >= 0)
			{
				for (int k = position; k > 15; k--)
				{
					binary[k] = brr[i][4] % 2;
					brr[i][4] = brr[i][4] / 2;
				}
			}
			else if (brr[i][4] < 0)
			{
				for (int k = position; k > 15; k--)
				{
					temp[k] = brr[i][4] % 2;
					brr[i][4] = brr[i][4] / 2;
					binary[k] = !temp[k];
				}
				for (int k = position; k > 15; k--)
				{
					if (binary[k] == 0)
					{
						binary[k] += 1;
						k = 14;
					}
					else if (binary[k] == 1)
					{
						binary[k] = 0;
					}
				}
			}
			for (int j = 0; j < 32; j++)
			{
				fprintf(output,"%d", binary[j]);
			}
		}
		else if (brr[i][0] == 3)
		{
			position = 5;
			while (1)
			{
				binary[position] = brr[i][1] % 2;
				brr[i][1] = brr[i][1] / 2;

				position--;
				if (brr[i][1] == 0)
					break;
			}
			position = 31;
			while (1)
			{
				binary[position] = brr[i][2] % 2;
				brr[i][2] = brr[i][2] / 2;

				position--;
				if (brr[i][2] == 0)
					break;
			}
			for (int j = 0; j < 32; j++)
			{
				fprintf(output,"%d", binary[j]);
			}
		}
		else if (brr[i][0] == 4)
		{
			if (brr[i][5] != 0)
			{
				position = 5;
				while (1)
				{
					binary[position] = brr[i][1] % 2;
					brr[i][1] = brr[i][1] / 2;

					position--;
					if (brr[i][1] == 0)
						break;
				}
				position = 10;
				while (1)
				{
					binary[position] = brr[i][2] % 2;
					brr[i][2] = brr[i][2] / 2;

					position--;
					if (brr[i][2] == 0)
						break;
				}
				position = 15;
				while (1)
				{
					binary[position] = brr[i][3] % 2;
					brr[i][3] = brr[i][3] / 2;

					position--;
					if (brr[i][3] == 0)
						break;
				}
				position = 31;
				while (1)
				{
					binary[position] = brr[i][4] % 2;
					brr[i][4] = brr[i][4] / 2;

					position--;
					if (brr[i][4] == 0)
						break;
				}
				position = 5;
				while (1)
				{
					temp[position] = brr[i][5] % 2;
					brr[i][5] = brr[i][5] / 2;

					position--;
					if (brr[i][5] == 0)
						break;
				}
				position = 10;
				while (1)
				{
					temp[position] = brr[i][6] % 2;
					brr[i][6] = brr[i][6] / 2;

					position--;
					if (brr[i][6] == 0)
						break;
				}
				position = 15;
				while (1)
				{
					temp[position] = brr[i][7] % 2;
					brr[i][7] = brr[i][7] / 2;

					position--;
					if (brr[i][7] == 0)
						break;
				}
				position = 31;
				while (1)
				{
					temp[position] = brr[i][8] % 2;
					brr[i][8] = brr[i][8] / 2;

					position--;
					if (brr[i][8] == 0)
						break;
				}
				for (int j = 0; j < 32; j++)
				{
					fprintf(output,"%d", binary[j]);
				}
				for (int j = 0; j < 32; j++)
				{
					fprintf(output,"%d", temp[j]);
				}
			}
			else
			{
				position = 5;
				while (1)
				{
					binary[position] = brr[i][1] % 2;
					brr[i][1] = brr[i][1] / 2;

					position--;
					if (brr[i][1] == 0)
						break;
				}
				position = 10;
				while (1)
				{
					binary[position] = brr[i][2] % 2;
					brr[i][2] = brr[i][2] / 2;

					position--;
					if (brr[i][2] == 0)
						break;
				}
				position = 15;
				while (1)
				{
					binary[position] = brr[i][3] % 2;
					brr[i][3] = brr[i][3] / 2;

					position--;
					if (brr[i][3] == 0)
						break;
				}
				position = 31;
				while (1)
				{
					binary[position] = brr[i][4] % 2;
					brr[i][4] = brr[i][4] / 2;

					position--;
					if (brr[i][4] == 0)
						break;
				}
				for (int j = 0; j < 32; j++)
				{
					fprintf(output,"%d", binary[j]);
				}
			}
		}
	}
}

typedef struct atr
{
	char a[10];
	int b;
}Atr;

typedef struct adr
{
	char a[10];
	int b;
}Adr;

int t_loc(char br[50][10][10], int  a)
{
	int c;
	for (int i = 0; i < a; i++)
	{
		if (strcmp(br[i][0], ".text") == 0)
		{
			c = i;
			break;
		}
	}
	return c;
}

int t_length(char br[50][10][10], int a, int b,Adr d[10])
{
	int count = 0;
	int count1 = 0;
	for (int i = a + 1; i < b; i++)
	{
		if (br[i][9][9] == 1)
			count++;
		if(strcmp(br[i][0],"la")==0)
		{
			for(int j=0;j<10;j++)
			{
				if(strcmp(br[i][2],d[j].a)==0)
				{
					if(d[j].b%65536!=0)
						count1++;
				}
			}
		}
	}
	return b - (a+1) - count+count1;
}

void data_address(char br[50][10][10], int  t_loc, Adr d[10])
{
	int c =  t_loc;
	int count = 0;
	for (int i = 1; i < c; i++)
	{
		if (br[i][9][9] == 3)
		{
			strcpy(d[count].a, br[i][0]);
			d[count].b = hti("0x10000000") + 4 * (i-1);
			count++;
		}
	}
}

void text_address(char br[50][10][10], int b, Atr t[10],int t_loc,Adr d[10])
{
	int c=t_loc;
	int count=0;
	int count1=0;
	for (int i = c+1; i < b; i++)
	{
		if(strcmp(br[i][0],"la")==0)
		{
			for(int j=0;j<10;j++)
			{
				if(strcmp(br[i][2],d[j].a)==0)
				{
					if(d[j].b%65536!=0)
					{
						count1++;
					}
				}
			}
		}
		if (br[i][9][9] == 1)
		{
			strcpy(t[count].a, br[i][0]);
			t[count].b = hti("0x400000") + 4 * (i - (c+1) - count+count1);
			count++;
		}
	}
}

int hti(char hex[])
{
	int a=0;
	int b;
	int c;
	int position = 0;
	int len = strlen(hex);
	for (int i = len - 1; i > 1; i--)
	{
		char ch = hex[i];
		if (ch >= 48 && ch <= 57)
		{
			b = 1;
			c = 0;
			c += (ch - 48);
			for (int j = 0; j < position; j++)
			{
				b = b * 16;
			}
			a += c * b;
		}
		else if (ch >= 97 && ch <= 102)
		{
			b = 1;
			c = 0;
			c += (ch - 97+10);
			for (int k = 0; k < position; k++)
			{
				b = b * 16;
			}
			a += c * b;
		}
		position++;
	}
	return a;

}

void comm(char br[50][10][10],int c,int cr[50][9],Atr f[10],int t_loc,Adr d[10])
{
	int a = t_loc;
	int count = 0;
	for (int j = a + 2; j < c; j++)
	{
		if (br[j][9][9] == 1)
			count++;
		if (strcmp(br[j][0], "addiu") == 0)
		{
			cr[j - (a + 2)][0] = 2;
			cr[j - (a + 2)][1] = 9;
			cr[j - (a + 2)][2] = atoi(br[j][2]);
			cr[j - (a + 2)][3] = atoi(br[j][1]);
			if (br[j][3][0] == '0'&&br[j][3][1] == 'x')
			{
				cr[j - (a + 2)][4] = hti(br[j][3]);
			}
			else
				cr[j - (a + 2)][4] = atoi(br[j][3]);
		}
		if (strcmp(br[j][0], "addu") == 0)
		{
			cr[j - (a + 2)][0] = 1;
			cr[j - (a + 2)][1] = 0;
			cr[j - (a + 2)][2] = atoi(br[j][2]);
			cr[j - (a + 2)][3] = atoi(br[j][3]);
			cr[j - (a + 2)][4] = atoi(br[j][1]);
			cr[j - (a + 2)][5] = 0;
			cr[j - (a + 2)][6] = 33;
		}
		if (strcmp(br[j][0], "and") == 0)
		{
			cr[j - (a + 2)][0] = 1;
			cr[j - (a + 2)][1] = 0;
			cr[j - (a + 2)][2] = atoi(br[j][2]);
			cr[j - (a + 2)][3] = atoi(br[j][3]);
			cr[j - (a + 2)][4] = atoi(br[j][1]);
			cr[j - (a + 2)][5] = 0;
			cr[j - (a + 2)][6] = 36;
		}
		if (strcmp(br[j][0], "andi") == 0)
		{
			cr[j - (a + 2)][0] = 2;
			cr[j - (a + 2)][1] = 12;
			cr[j - (a + 2)][2] = atoi(br[j][2]);
			cr[j - (a + 2)][3] = atoi(br[j][1]);
			if (br[j][3][0] == '0'&&br[j][3][1] == 'x')
			{
				cr[j - (a + 2)][4] = hti(br[j][3]);
			}
			else
				cr[j - (a + 2)][4] = atoi(br[j][3]);
		}
		if (strcmp(br[j][0], "beq") == 0)
		{
			cr[j - (a + 2)][0] = 2;
			cr[j - (a + 2)][1] = 4;
			cr[j - (a + 2)][2] = atoi(br[j][1]);
			cr[j - (a + 2)][3] = atoi(br[j][2]);
			for(int i=0;i<c;i++)
			{
				if(strcmp(br[j][3],br[i][0])==0)
				{
					if(i-j<0)
					{
						cr[j - (a + 2)][4]=i-j;
					}
					else
					{
						cr[j - (a + 2)][4]=i-j-1;
					}
				}
			}
		}
		if (strcmp(br[j][0], "bne") == 0)
		{
			cr[j - (a + 2)][0] = 2;
			cr[j - (a + 2)][1] = 5;
			cr[j - (a + 2)][2] = atoi(br[j][1]);
			cr[j - (a + 2)][3] = atoi(br[j][2]);
			for(int i=0;i<c;i++)
			{
				if(strcmp(br[j][3],br[i][0])==0)
				{
					if(i-j<0)
					{
						cr[j - (a + 2)][4]=i-j;
					}
					else
					{
						cr[j - (a + 2)][4]=i-j-1;
					}
				}
			}
		}
		if (strcmp(br[j][0], "j") == 0)
		{
			cr[j - (a + 2)][0] = 3;
			cr[j - (a + 2)][1] = 2;
			for (int k = 0; k < 10; k++)
			{
				if (strcmp(f[k].a, br[j][1]) == 0)
				{
					cr[j - (a + 2)][2] = f[k].b>>2;
					break;
				}
			}
		}
		if (strcmp(br[j][0], "jal") == 0)
		{
			cr[j - (a + 2)][0] = 3;
			cr[j - (a + 2)][1] = 3;
			for (int k = 0; k < 10; k++)
			{
				if (strcmp(f[k].a, br[j][1]) == 0)
				{
					cr[j - (a + 2)][2] = f[k].b>>2;
					break;
				}
			}
		}
		if (strcmp(br[j][0], "jr") == 0)
		{
			cr[j - (a + 2)][0] = 1;
			cr[j - (a + 2)][1] = 0;
			cr[j - (a + 2)][2] = atoi(br[j][1]);
			cr[j - (a + 2)][3] = 0;
			cr[j - (a + 2)][4] = 0;
			cr[j - (a + 2)][5] = 0;
			cr[j - (a + 2)][6] = 8;
		}
		if (strcmp(br[j][0], "lui") == 0)
		{
			cr[j - (a + 2)][0] = 2;
			cr[j - (a + 2)][1] = 15;
			cr[j - (a + 2)][2] = 0;
			cr[j - (a + 2)][3] = atoi(br[j][1]);
			if (br[j][2][0] == '0'&&br[j][2][1] == 'x')
			{
				cr[j - (a + 2)][4] = hti(br[j][2]);
			}
			else
				cr[j - (a + 2)][4] = atoi(br[j][2]);
		}
		if (strcmp(br[j][0], "lw") == 0)
		{
			cr[j - (a + 2)][0] = 2;
			cr[j - (a + 2)][1] = 35;
			cr[j - (a + 2)][2] = atoi(br[j][3]);
			cr[j - (a + 2)][3] = atoi(br[j][1]);
			cr[j - (a + 2)][4] = atoi(br[j][2]);
		}
		if (strcmp(br[j][0], "la") == 0)
		{
			for (int k = 0; k < 10; k++)
			{
				if (strcmp(d[k].a, br[j][2]) == 0)
				{
					if (d[k].b % 65536 == 0)
					{
						cr[j - (a + 2)][0] = 4;
						cr[j - (a + 2)][1] = 15;
						cr[j - (a + 2)][2] = 0;
						cr[j - (a + 2)][3] = atoi(br[j][1]);
						cr[j - (a + 2)][4] = d[k].b / 65536;
					}
					else
					{
						cr[j - (a + 2)][0] = 4;
						cr[j - (a + 2)][1] = 15;
						cr[j - (a + 2)][2] = 0;
						cr[j - (a + 2)][3] = atoi(br[j][1]);
						cr[j - (a + 2)][4] = d[k].b / 65536;
						cr[j - (a + 2)][5] = 13;
						cr[j - (a + 2)][6] = atoi(br[j][1]);
						cr[j - (a + 2)][7] = atoi(br[j][1]);
						cr[j - (a + 2)][8] = d[k].b % 65536;
					}
					break;
				}
			}
		}
		if (strcmp(br[j][0], "nor") == 0)
		{
			cr[j - (a + 2)][0] = 1;
			cr[j - (a + 2)][1] = 0;
			cr[j - (a + 2)][2] = atoi(br[j][2]);
			cr[j - (a + 2)][3] = atoi(br[j][3]);
			cr[j - (a + 2)][4] = atoi(br[j][1]);
			cr[j - (a + 2)][5] = 0;
			cr[j - (a + 2)][6] = 39;
		}
		if (strcmp(br[j][0], "or") == 0)
		{
			cr[j - (a + 2)][0] = 1;
			cr[j - (a + 2)][1] = 0;
			cr[j - (a + 2)][2] = atoi(br[j][2]);
			cr[j - (a + 2)][3] = atoi(br[j][3]);
			cr[j - (a + 2)][4] = atoi(br[j][1]);
			cr[j - (a + 2)][5] = 0;
			cr[j - (a + 2)][6] = 37;
		}
		if (strcmp(br[j][0], "ori") == 0)
		{
			cr[j - (a + 2)][0] = 2;
			cr[j - (a + 2)][1] = 13;
			cr[j - (a + 2)][2] = atoi(br[j][2]);
			cr[j - (a + 2)][3] = atoi(br[j][1]);
			if (br[j][3][0] == '0'&&br[j][3][1] == 'x')
			{
				cr[j - (a + 2)][4] = hti(br[j][3]);
			}
			else
				cr[j - (a + 2)][4] = atoi(br[j][3]);
		}
		if (strcmp(br[j][0], "sltiu") == 0)
		{
			cr[j - (a + 2)][0] = 2;
			cr[j - (a + 2)][1] = 11;
			cr[j - (a + 2)][2] = atoi(br[j][2]);
			cr[j - (a + 2)][3] = atoi(br[j][1]);
			if (br[j][3][0] == '0'&&br[j][3][1] == 'x')
			{
				cr[j - (a + 2)][4] = hti(br[j][3]);
			}
			else
				cr[j - (a + 2)][4] = atoi(br[j][3]);
		}
		if (strcmp(br[j][0], "sltu") == 0)
		{
			cr[j - (a + 2)][0] = 1;
			cr[j - (a + 2)][1] = 0;
			cr[j - (a + 2)][2] = atoi(br[j][2]);
			cr[j - (a + 2)][3] = atoi(br[j][3]);
			cr[j - (a + 2)][4] = atoi(br[j][1]);
			cr[j - (a + 2)][5] = 0;
			cr[j - (a + 2)][6] = 43;
		}
		if (strcmp(br[j][0], "sll") == 0)
		{
			cr[j - (a + 2)][0] = 1;
			cr[j - (a + 2)][1] = 0;
			cr[j - (a + 2)][2] = 0;
			cr[j - (a + 2)][3] = atoi(br[j][2]);
			cr[j - (a + 2)][4] = atoi(br[j][1]);
			cr[j - (a + 2)][5] = atoi(br[j][3]);
			cr[j - (a + 2)][6] = 0;
		}
		if (strcmp(br[j][0], "srl") == 0)
		{
			cr[j - (a + 2)][0] = 1;
			cr[j - (a + 2)][1] = 0;
			cr[j - (a + 2)][2] = 0;
			cr[j - (a + 2)][3] = atoi(br[j][2]);
			cr[j - (a + 2)][4] = atoi(br[j][1]);
			cr[j - (a + 2)][5] = atoi(br[j][3]);
			cr[j - (a + 2)][6] = 2;
		}
		if (strcmp(br[j][0], "sw") == 0)
		{
			cr[j - (a + 2)][0] = 2;
			cr[j - (a + 2)][1] = 43;
			cr[j - (a + 2)][2] = atoi(br[j][3]);
			cr[j - (a + 2)][3] = atoi(br[j][1]);
			cr[j - (a + 2)][4] = atoi(br[j][2]);
		}
		if (strcmp(br[j][0], "subu") == 0)
		{
			cr[j - (a + 2)][0] = 1;
			cr[j - (a + 2)][1] = 0;
			cr[j - (a + 2)][2] = atoi(br[j][2]);
			cr[j - (a + 2)][3] = atoi(br[j][3]);
			cr[j - (a + 2)][4] = atoi(br[j][1]);
			cr[j - (a + 2)][5] = 0;
			cr[j - (a + 2)][6] = 35;
		}

	}
}


void parse_command(const char* input, int* a, int *b,char ar[50][10][10])
{
	*a = -1;
	char ptr1[500];
	strcpy(ptr1, input);
	char * ptr2 = strtok(ptr1, "\t ");
	do
	{
		(*a) += 1;
		strcpy(ar[*b][*a], ptr2);
	} while (ptr2 = strtok(NULL, "\t "));

	(*a) += 1;
	ar[*b][9][9] = *a;
	(*b)++;
}


int main(int argc, char *argv[])
{
    FILE *input, *output;
    char *filename;
    int k=0;
	int t_location=0;
	int t_len=0;
	int d_size=0;
	char buffer[4096]={0,};
	char argv1[50][10][10]={0,};
	int arr[50][9]={0,};
	Atr t[10];
	Adr d[10];
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <*.s>\n", argv[0]);
        fprintf(stderr, "Example: %s sample_input/example?.s\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }

    filename = strdup(argv[1]); // strdup() is not a standard C library but fairy used a lot.
    if(change_file_ext(filename) == NULL) {
        fprintf(stderr, "'%s' file is not an assembly file.\n", filename);
        exit(EXIT_FAILURE);
    }

    output = fopen(filename, "w");
    if (output == NULL) {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }
    // process();
	while(fgets(buffer,4096,input)!=NULL)
	{
		int argc1 = -1;
		if(buffer[strlen(buffer)-1]=='\n')
		{
			buffer[strlen(buffer)-1]='\0';
		}
		for(int i=0;i<strlen(buffer)+1;i++)
		{
			if(buffer[i]==','||buffer[i]==':'||buffer[i]=='('||buffer[i]==')'||buffer[i]=='$')
			{
				buffer[i]=' ';
			}
		}
		parse_command(buffer,&argc1,&k,argv1);
	}
	t_location = t_loc(argv1,k);
	d_size = t_location-1;
	data_address(argv1,t_location,d);
	text_address(argv1,k,t,t_location,d);
	comm(argv1,k,arr,t,t_location,d);
	t_len = t_length(argv1,t_location,k,d);
	itb(4*t_len,output);
	itb(4*d_size,output);
	itb_instruction(arr,k,output);
	itb_data(argv1,t_location,output);
	fprintf(output,"\n");
    fclose(input);
    fclose(output);
    exit(EXIT_SUCCESS);
}


/*******************************************************
 * Function: change_file_ext
 *
 * Parameters:
 *  char
 *      *str: a raw filename (without path)
 *
 * Return:
 *  return NULL if a file is not an assembly file.
 *  return empty string
 *
 * Info:
 *  This function reads filename and converst it into
 *  object extention name, *.o
 *
 *******************************************************/
char *change_file_ext(char *str)
{
    char *dot = strrchr(str, '.');

    if (!dot || dot == str || (strcmp(dot, ".s") != 0)) {
        return NULL;
    }

    str[strlen(str) - 1] = 'o';
    return "";
}
