#include<stdio.h>


void Sort(int array[],int length)
{
    int p,i;
    int tmp;
    for( p=1;p<length;p++){
        tmp = array[p];
        for(i=p;i>0 && array[i-1] > tmp;i--){
            array[i] = array[i-1];
    
        }
        array[i] = tmp;
    }
}
void InsertionSort( int A[], int N )
{ /* 插入排序 */
     int P, i;
     int Tmp;
     
     for ( P=1; P<N; P++ ) {
         Tmp = A[P]; /* 取出未排序序列中的第一个元素*/
         for ( i=P; i>0 && A[i-1]>Tmp; i-- )
             A[i] = A[i-1]; /*依次与已排序序列中元素比较并右移*/
         A[i] = Tmp; /* 放进合适的位置 */
     }
}
int main( )
{
    int num_a[]={7,2,9,10,21,3,8,4,0};
    int size = sizeof(num_a) / sizeof(int);
    Sort(num_a,size);
    // Sort(num_a,size);
    for (int i = 0;i<size;i++ ){
        printf("%d\t",num_a[i]);
    }
    return 0;
}


