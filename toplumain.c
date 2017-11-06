#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define KNRM  "\x1B[0m"
#define KGRN  "\x1B[32m"

void setTimeout(int milliseconds)
{
    if (milliseconds <= 0) {
        return;
    }

    int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    int end = milliseconds_since + milliseconds;

    do {
        milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    } while (milliseconds_since <= end);
}

void AnaMenu() {
	int opt;
	printf(KNRM "Secilebilir Operatorler:");
	printf("\n1) Asal sayi bulma");
	printf("\n2) En kucuk sayi bulma");
	printf("\n3) En buyuk sayi bulma");
	printf("\n4) Reel kok bulma");
	printf("\n5) Kucukten buyuge siralama");
	printf("\n6) Buyukten kucuge siralama");
	printf("\n7) Pascal ucgeni");
	printf("\n8) Tek cift kontrol");
	printf("\n9) Matris carpimi");
	printf("\n");
	scanf("%d",&opt);
	switch(opt) {
		case 1: {	
			int n;
			printf("Kaca kadar olan asal sayilari yazdirmak istiyorsunuz? : ");
			scanf("%d",&n);
			int i, j, count;
			for(i=n;i!=1;i--)
			{
				count = 0;
				for(j=i-1;j!=1;j--)
				{
					if(!(i%j) && i!=j)
						count = 1;
				}
				if(count == 0)
					printf(KGRN "%d,",i);
			}
			printf("1\n\n");
			break;
		}
		case 2: {
			int n,i,lowest;
			printf("Kac sayi girmek istiyorsunuz? :");
			scanf("%d",&n);
			int num[n];
			for(i=0;i<n;i++) {
				printf("Sayiyi girin: "),scanf("%d",&num[i]);
			}
			lowest = num[0];
			for(i=0;i<n;i++) {
				if(num[i] < lowest)
					lowest = num[i];
			}
			printf(KGRN "%d\n\n",lowest);
			break;
		}
		case 3: {
			int n,i,highest;
			printf("Kac sayi girmek istiyorsunuz? :");
			scanf("%d",&n);
			int num[n];
			for(i=0;i<n;i++) {
				printf("Sayiyi girin: "),scanf("%d",&num[i]);
			}
			highest = num[0];
			for(i=0;i<n;i++) {
				if(num[i] > highest)
					highest = num[i];
			}
			printf(KGRN "%d\n\n",highest);
			break;
		}
		case 4: {
			int a,b,c;
			printf("ax2+bx+c=0 denkleminde a,b,c girin: "),scanf("%d %d %d",&a, &b, &c);
			int d = (b*b)-(4*a*c);
			if(d > 0) {
				printf(KGRN "Iki reel kok var. (%d,%d)",(int)(-b+sqrt(d))/(2*a),(int)(-b-sqrt(d))/(2*a));
			}
			else if(d == 0) {
				printf(KGRN "Tek reel kok var. (%d)",(int)-b/(2*a));
			}
			else {
				printf(KGRN "Reel kok yok.");
			}
			printf("\n\n");
			break;
		}
		case 5: {
			int n,i,j,temp;
			printf("Kac sayi girmek istiyorsunuz? :"),scanf("%d",&n);
			int num[n];
			for(i=0;i<n;i++) {
				printf("Sayi girin: "),scanf("%d",&num[i]);
			}
			for(i=0;i<n;i++) {
				for(j=i+1;j<n;j++)
				{
					if(num[i] > num[j]) {
						temp = num[j];
						num[j] = num[i];
						num[i] = temp;
					}
				}
			}
			for(i=0;i<n;i++) {
				printf(KGRN "%d ",num[i]);
			}
			printf("\n\n");
			break;
		}
		case 6: {
			int n,i,j,temp;
			printf("Kac sayi girmek istiyorsunuz? :"),scanf("%d",&n);
			int num[n];
			for(i=0;i<n;i++) {
				printf("Sayi girin: "),scanf("%d",&num[i]);
			}
			for(i=0;i<n;i++) {
				for(j=i+1;j<n;j++)
				{
					if(num[i] < num[j]) {
						temp = num[j];
						num[j] = num[i];
						num[i] = temp;
					}
				}
			}
			for(i=0;i<n;i++) {
				printf(KGRN "%d ",num[i]);
			}
			printf("\n\n");
			break;
		}
		case 7: {
			int rows,space,i,j,coef;
			printf("Kac satir yazdirmak istiyorsunuz? :"),scanf("%d",&rows);
			for(i=0; i<rows; i++)
		    {
		        for(space=1; space <= rows-i; space++)
		            printf("  ");
		
		        for(j=0; j <= i; j++)
		        {
		            if (j==0 || i==0)
		                coef = 1;
		            else
		                coef = coef*(i-j+1)/j;
		
		            printf(KGRN "%4d", coef);
		        }
		        printf("\n");
		    }
		    printf("\n\n");
			break;
		}
		case 8: {
			int num;
			printf("Sayi girin: "),scanf("%d",&num);
			if(!(num%2))
				printf(KGRN "%d cift sayi.",num);
			else
				printf(KGRN "%d tek sayi.",num);
			printf("\n\n");
			break;
		}
		default: {	
			printf("Hatali operator sectiniz, cikis yapiliyor.\n");
			exit(EXIT_SUCCESS);
			break;
		}
		case 9: {
			int n[2],m[2],i,j,k;
			printf("(unutmayin carpim yapabilmek icin 1. matrisin sutunu ile 2. matrisin satiri ayni olmali)\n");
			printf("1. matrisin kaca kac oldugunu girin: "),scanf("%d %d",&n[0],&m[0]);
			printf("2. matrisin kaca kac oldugunu girin: "),scanf("%d %d",&n[1],&m[1]);
			int A[n[0]][m[0]], B[n[1]][m[1]];
			printf("1. matris icin sayilari girin:\n");
			for(i=0;i<n[0];i++)
			{
				for(j=0;j<m[0];j++)
				{
					printf("%d.%d ",i+1,j+1),scanf("%d",&A[i][j]);
				}
			}
			printf("2. matris icin sayilari girin:\n");
			for(i=0;i<n[1];i++)
			{
				for(j=0;j<m[1];j++)
				{
					printf("%d.%d ",i+1,j+1),scanf("%d",&B[i][j]);
				}
			}
			printf("\n\n");
			for(i=0;i<n[0];i++)
			{
				printf(KGRN "|");
				for(j=0;j<m[0];j++)
				{
					
					printf("\t%d",A[i][j]);
				}
				printf("\t|");
				printf("\n");
			}
			printf("\n\t\\/\n");
			printf("\t/\\\n");
			for(i=0;i<n[1];i++)
			{
				printf("|");
				for(j=0;j<m[1];j++)
				{
					
					printf("\t%d",B[i][j]);
				}
				printf("\t|");
				printf("\n");
			}
			printf("\n\t||\n");
			printf("\t||\n\n");
			int C[n[0]][m[1]];
			for(i=0;i<n[0];i++)
			{
				for(j=0;j<m[1];j++)
				{
					
					C[i][j]=0;
				}
			}
			for(i=0;i<n[0];i++) {
				for(j=0;j<m[1];j++) {
					for(k=0;k<n[1];k++) {
						C[i][j] += A[i][k]*B[k][j];
					}
				}
			}
			for(i=0;i<n[0];i++)
			{
				printf("|");
				for(j=0;j<m[1];j++)
				{
					
					printf("\t%d",C[i][j]);
				}
				printf("\t|");
				printf("\n");
			}
			printf("\n\n");
			break;
		}
	}
	AnaMenu();
}

int main() {
	printf("Hosgeldiniz!\nProgram yukleniyor..");
	setTimeout(3000);
	system("cls");
	AnaMenu();
	return 0;
}
