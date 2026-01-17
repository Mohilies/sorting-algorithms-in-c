#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define n 10
int Partition(int Array[],int size){
int i=-1;
for(int j=0;j<size-1;j++){
if(Array[j]<Array[size-1]){
i++;
int tmp=Array[j];
Array[j]=Array[i];
Array[i]=tmp;
}
}
int tmp=Array[++i];
Array[i]=Array[size-1];
Array[size-1]=tmp;
return i+1;
}
void Quicksort(int Array[],int start,int end){
if(end<=start)return;
int pivot=Partition(Array,end);
Quicksort(Array,start,pivot-1);
Quicksort(Array,pivot+1,end);
return;
}
void Display(int Array[]){
    printf("\n");
    for(int i=0;i<n;i++){
    printf("%d \t",Array[i]);
  }  
}
void main(){
int Array[10];
srand(time(NULL));
for(int i=0;i<n;i++){
    Array[i]=rand()%100;
}
printf("not touched:");
Display(Array);
Partition(Array,n);
printf("\n after partition:");
Display(Array);
printf("\n sorted :");
Quicksort(Array,0,n);
Display(Array);
}