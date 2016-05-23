/*
	Author : Amar Prakash Pandey
	contact : http://a...content-available-to-author-only...y.me
*/
#include <string.h>
#include <stdio.h>
#include <math.h>
#define pi 3.14159
#define mod 1000000007
char s[2010];
int main() {
	int t,loop=1;
	scanf("%d",&t);
	while(t--) {
		int x, i, j=0, temp=0;
		int alpha[30]={0};
		int number[10]={0};
		scanf("%s",&s);
		for(i=0;i<strlen(s);i++) {
			x = (int)s[i] - 64;
			alpha[x]++;
		}
		// ZERO CHECK
		if(alpha[26] > 0) {
			temp = alpha[26];
			alpha[26] = 0;
			number[0] = temp;
			alpha[5] -= temp;
			alpha[18] -= temp;
			alpha[15] -= temp;
		}
		// TWO CHECK
		if(alpha[23] > 0) {
			temp = alpha[23];
			alpha[23] = 0;
			number[2] = temp;
			alpha[20] -= temp;
			alpha[15] -= temp;
		}
		// FOUR CHECK
		if(alpha[21] > 0) {
			temp = alpha[21];
			alpha[21] = 0;
			number[4] = temp;
			alpha[15] -= temp;
			alpha[18] -= temp;
			alpha[6] -= temp;
		}
		// CHECK SIX
		if(alpha[24] > 0) {
			temp = alpha[24];
			alpha[24] = 0;
			number[6] = temp;
			alpha[19] -= temp;
			alpha[9] -= temp;
		}
		// CHECK EIGHT
		if(alpha[7] > 0) {
			temp = alpha[7];
			alpha[7] = 0;
			number[8] = temp;
			alpha[5] -= temp;
			alpha[9] -= temp;
			alpha[8] -= temp;
			alpha[20] -= temp;
		}
		// CHECK THREE
		if(alpha[8] > 0) {
			temp = alpha[8];
			alpha[8] = 0;
			number[3] = temp;
			alpha[20] -= temp;
			alpha[18] -= temp;
			alpha[5] -= temp*2;
		}
		// CHECK FIVE
		if(alpha[6] > 0) {
			temp = alpha[6];
			alpha[6] = 0;
			number[5] = temp;
			alpha[9] -= temp;
			alpha[22] -= temp;
			alpha[5] -= temp;
		}
		// CHECK ONE
		if(alpha[15] > 0) {
			temp = alpha[15];
			alpha[15] = 0;
			number[1] = temp;
			alpha[14] -= temp;
			alpha[5] -= temp;
		}
		// CHECK SEVEN
		if(alpha[22] > 0) {
			temp = alpha[22];
			alpha[22] = 0;
			number[7] = temp;
			alpha[19] -= temp;
			alpha[5] -= temp*2;
			alpha[14] -= temp;
		}
		// CHECK NINE
		if(alpha[9] > 0) {
			temp = alpha[9];
			alpha[9] = 0;
			number[9] = temp;
			alpha[5] -= temp;
			alpha[14] -= temp*2;
		}
		printf("Case #%d: ",loop);loop++;
		for(i=0;i<10;i++) {
			if(number[i] !=0) {
				for(j=0;j<number[i];j++) {
					printf("%d",i);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
