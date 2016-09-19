#include <stdio.h>
#include <stdlib.h>
int main()
{
	int k,i,j;
	int *date;
	while(scanf("%d",&k) != EOF)
	{
		date = (int *)malloc(k * sizeof(int));
        for ( i = 0; i < k; i ++)
        {
            scanf("%d", &date[i]);
        }
		
		int sum = 0, start = 0, end = k - 1, temp = 0,tempi = 0,tempj = 0;
		for (j = 0; j < k; j++)
		{
			if (temp >= 0)
			{
				temp += date[j];
				tempj = j;
			}
			else
			{
				temp = date[j];
				tempi = j;
				tempj = j;
			}
			if (temp > sum || (temp == 0 && end == k - 1))
			{
				sum = temp;
				start = tempi;
				end = tempj;
			}
		}
		
		
		printf("%d %d %d\n",sum, start, end);
	}
	return 0;
}
