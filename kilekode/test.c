#include <stdio.h>

int main()
{
	int j =-100;
	int h[3][3] = {1,2,3,
		       4,5,6,
		       7,8,9};
	while(j<100)
	{
	printf("hej til den nummer %i \n",j % 10);
	j++;
	}
	printf("%i",h[-1 % 2 ][4 % 2]);
	return 0;
	

}


