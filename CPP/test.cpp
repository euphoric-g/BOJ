#include <iostream>

int main(void)
{
	int a, b, c;
	int count = 1;

	scanf("%d %d %d", &a, &b, &c);

	if (b >= c)
		printf("%d", -1);
	else {
		while (1)
		{
			if (a / (c-b) < count)
			{
				printf("%d", count);
				break;
			}
			else
				count++;
		}
	}
	return 0;
}