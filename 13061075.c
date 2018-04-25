#include <stdio.h>
int main()
 {
    int dizi[100],i,n,secim;
    printf("Dizinin uzunlugunu giriniz: ");
    scanf("%d",&n);
    for(i=0;i<n;++i)
      {
       printf("%d. elemani giriniz: ",i+1);
       scanf("%d",&dizi[i]);
    }
    
    printf("\nSelection Sort ile siralamak icin 1 e, Heap Sort ile siralamak icin 2 ye basiniz: ");
    scanf("%d",&secim);
    if(secim == 1){
		selectionSort(dizi, n);
	}
    else if(secim ==2){
		printf("Siralanmamis dizi: ");
    	diziyi_bas(dizi, n);
    	printf("\n");
    	heapSort(dizi, n);
    	printf("Siralanmis dizi: ");
    	diziyi_bas(dizi, n);
	}
	else{
		printf("Yanlýs Secim");
	}
}

void selectionSort(int dizi[],int n){
	int i,kademe,gecici;
	printf("Siralanmamis dizi -> ");
    for(i=0;i<n;i++){
	printf("%d  ", dizi[i]);
	}
	printf("\n------------------------------------------------");
	for(kademe=0;kademe<n;++kademe){
		for(i=kademe+1;i<n;++i)
		 {
		     if(dizi[kademe]>dizi[i])  
		      {
		         gecici=dizi[kademe];
		         dizi[kademe]=dizi[i]; 
		         dizi[i]=gecici;
		      }
		}
		printf("\n%d. iterasyon      -> ", (kademe+1));
		for(i=0;i<n;++i){
			printf("%d  ", dizi[i]);
		}
	}
	printf("\n------------------------------------------------\n");
	printf("Selection Sort ile siralanmis dizi   -> ");
	for(i=0;i<n;++i){
		printf("%d  ", dizi[i]);
	}
}


void swap(int* x, int* y)
{
    int gecici = *x;
    *x = *y;
    *y = gecici;
}
  
void MaxHeapify(int A[], int n, int i)
{
    int enbyk = i;
    int l = 2*i + 1;  
    int r = 2*i + 2;  
  
    if (l < n && A[l] > A[enbyk])
        enbyk = l;
    if (r < n && A[r] > A[enbyk])
        enbyk = r;
  
    if (enbyk != i)
    {
        swap(&A[i], &A[enbyk]);
        printf("Max Heapify sonucu %d ile %d yer degistirdi.\n", A[i], A[enbyk]);
		diziyi_bas(A, n);
        MaxHeapify(A, n, enbyk);
    }
}
BuildMaxHeap(int A[], int n)
{
    int i;
    for (i=(n/2)-1;i>=0;i--){
        MaxHeapify(A, n, i);
        }
}
  
void heapSort(int A[], int n)
{
    int i;
    BuildMaxHeap(A, n);
    for (i=n-1; i>=0; i--)
    {
        swap(&A[0], &A[i]);
        int heap_size= i;
        MaxHeapify(A, heap_size, 0);
        printf("heapsort sonucu\ndizi : ");
        diziyi_bas(A, n);
        printf("\n------------------------------------------------\n");
    }
}
  
void diziyi_bas(int A[], int boyut)
{
    int i;
    for (i=0; i < boyut; i++)
        printf("%d ", A[i]);
    printf("\n\n");
}
