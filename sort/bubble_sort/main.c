#include<stdio.h>
#include<stdlib.h>

void sort(int a[],int n)
{
   int p,i;
    for(p = n-1;p>=0;p--){
        for(i=0;i<p;i++){
            if(a[i] > a[i+1]){
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }

}

int main()
{
    int a[]={3,7,4,2,6,1};
    int size = 6;
    sort(a,size);
    for(int i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
}