/*
This program find the value of M[n] for a given n and check whether it satisfy merten's conjecture or not
Name: Garvit Bansal
Roll No: Y11UC092
*/

#include<stdio.h>
#include<math.h>
#define size 100000
long long int mu[size+1]={0};
FILE *fp;
	
void getMu(long long int n)
{
	long long int result = (long long int)sqrt(n);
	long long int i,j;
	
	for(i=1;i<=n;i++)
		mu[i] = 1;
		
	for(i=2;i<=result;i++)
	{
		if(mu[i] == 1)
		{
			for(j=i ; j<= n ; j+=i)
				mu[j]*= -i;
			for(j=i*i ; j<= n ; j+=i*i)
				mu[j] = 0;
		}
	}	
	
	for(i=2 ; i <= n ; i++)
	{
		if(mu[i] == i)
			mu[i] = 1;
		else if(mu[i] == -i)
			mu[i] = -1;
		else if (mu[i] < 0)
            mu[i] = 1;
        else if (mu[i] > 0)
            mu[i] = -1;
	} 
} 

int main()
{
	int T;
	fp = fopen("Y11UC092_CP6_output.txt","w");
 	
    fprintf(fp,"Code by: Garvit Bansal THE LNMIIT.\n\n");
    
	scanf("%d",&T);
	fprintf(fp,"Enter the number of Test Cases:\n",T);
	while(T--)
	{
		long long int n,i;
		fprintf(fp,"---------------------------------------------------\n");
		fprintf(fp,"TestCase %d: \n \n",T);
		
		scanf("%lld",&n);
		fprintf(fp,"\nENTER THE NUMBER:\n",n);
		
		getMu(100000);
		printf(fp,"\nThe value of M[n] is :%lld\n",mu[n]);
		printf("\n");
		
		long long int Mn=0,Mc;
		for(i=1;i<=n;i++)
			Mn+=mu[i];
			
		fprintf(fp,"The value of Merten's function is: %lld\n\n",Mn);
//		fprintf(fp,"\n");
		
		if(Mn < 0)
			Mn *= -1;
			
		Mc = (int)sqrt(n);
		
		if(Mn < Mc)
			fprintf(fp,"N satisfied Merten's Conjecture\n");
		else
			fprintf(fp,"N does not satisfy Merten's Conjecture\n");
			
		fprintf(fp,"\n");
	}
	
	return 0;
}