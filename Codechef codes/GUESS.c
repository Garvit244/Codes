#include<stdio.h>

long long int find_gcd(long long int m, long long int n)
{
    long long int r;
    /* Check For Proper Input */
    if((m == 0) || (n == 0))
        return 0;
    else if((m < 0) || (n < 0))
        return -1;

    do
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }
    while(1);

    return n;
}

int main()
{
	long long int T;
	scanf("%lld",&T);	
	while(T--)
	{
		long long int N,M,numevenN,numevenM,result;
		scanf("%lld %lld",&N,&M);
		numevenN = N/2;
		numevenM = M/2;
	//	printf("%lld %lld\n",numevenN,numevenM);
		result = ((numevenN*numevenM) + ((N-numevenN)*(M-numevenM)));
	//	printf("resut:%lld\n",result);
		long long int gcd = find_gcd(result,(N*M));
	//	printf("gcd:%lld\n",gcd);
		long long int denom = (N*M)/gcd;
		result = denom - (result/gcd);
		printf("%lld/%lld\n",result,denom);
	}
	return 0;
}
