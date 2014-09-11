/*
This program find the repunits numbers less than the given number and find which number is repunit out of them
Name: Garvit Bansal
Roll No: Y11UC092
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

FILE *fp;

int find_size(long long int a)
{
	int counter=0;
	while(a!=0)
	{
		a=a/10;
		counter++;
	}
	return (counter-1);
}

void find_repunitprimes(long long int a[],int size)
{
	long long int j,k,range;
	int flag;

	for(j=1;j<size;j++)
	{
		range=sqrt(a[j]);
		flag=0;
		for(k=2;k<range;k++)
		{
			if(a[j]%k == 0)
				flag = 1;
		}
		if(!flag)
			fprintf(fp,"\nRepunit prime is :%lld \n",a[j]);
	}
}

int main()
{
	long long int N;
	int size,testcases;
 	fp = fopen("Y11UC092_CP6_output.txt","w");
 	
    fprintf(fp,"Code by: Garvit Bansal THE LNMIIT.\n\n");
	scanf("%d",&testcases);

	fprintf(fp,"Number of Test Cases are %d\n",testcases);
	while(testcases--)
	{
		clock_t start = clock();
		fprintf(fp,"---------------------------------------------------\n");
		fprintf(fp,"TestCase %d: \n \n",testcases);
		size=0;
		scanf("%lld",&N);
		size=find_size(N);
		fprintf(fp,"The value of N is: \n%lld",N);
		
		long long int repunit[size];
		int i=1;
		repunit[0]=1;
		size--;
		
		if(size < 1)
			fprintf(fp,"\nThere exist no Repunit for number %lld \n",N);
		else
		{
			fprintf(fp,"\nRepunits less than N are:\n");
			while(size--)
			{
				repunit[i]=repunit[i-1]*10+1;
				fprintf(fp,"%lld ",repunit[i]);
				i++;
			}
			fprintf(fp,"\n");
			find_repunitprimes(repunit,i);	
		}
		fprintf(fp,"\n");
		clock_t stop = clock();
		
		fprintf(fp,"Elapsed: %f seconds\n", (double)(stop - start) / CLOCKS_PER_SEC);
	}
	return 0;
}