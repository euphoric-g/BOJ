#include <stdio.h>

#pragma warning(disable:4996)



int main()
{

		int i = 0;
		int time2;
		char word[1000001];
	    scanf("%s", word);
		int count[100] ;
		int top;
		int sametop = 0;
		int topnum;
		for (int c = 65; c <= 90; c++) {
			count[c] = 0;
		}
		for (int c = 65; c <= 90; c++) {
			for (int i = 0; i <= 1000001; i++) {
				if (word[i] == (char)c || word[i] == (char)(c + 32))
				{
					count[c]++;
				
				}
			}
	
			// printf("%d", count[c]);                                      //이부분은 제출 안했습니다
		}
	
		top = count[65];
		topnum = 65;
		for (int c = 65; c < 90; c++) {

			if (top <= count[c + 1])
			{
				
				if (count[topnum] == count[c + 1])
				{
					sametop = c + 1;
				}

				top = count[c + 1];
				topnum = c + 1;
             }
			
		}
		
		if (sametop == topnum)
		{
			printf("?");

		}
		else {
			printf("%c", topnum);
		}
	
	}

	
