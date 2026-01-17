#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define n 10
void Display(int Array[]){
    printf("\n");
    for(int i=0;i<n;i++){
    printf("%d \t",Array[i]);
  }  
}
void Insertion(int Array[]){
for(int i=1;i<n;i++){
    int tmp=Array[i];
    for(int j=i-1;j>=0;j--){
        if(tmp<Array[j]){
            Array[j+1]=Array[j];
            Array[j]=tmp;
        }else{
            break;
        }
    }
}
}
void Recursive_insertion(int Array[],int i, int j, int tmp){
if(i==n){return;}else{
if(j<0||i==0){
    tmp= Array[i+1];
    return Recursive_insertion(Array,i+1,i,tmp);
}else{
if(tmp<Array[j]){
    Array[j+1]=Array[j];
    Array[j]=tmp;
    Recursive_insertion(Array,i,j-1,tmp);
}else {
    Recursive_insertion(Array,i+1,i,Array[i+1]);
}}}}//i don't even know how this worked 
void main(){
    int array[n];
    int copy[n];
    srand(time(NULL));
    for(int i=0;i<n;i++){
        array[i]=rand()%100;
        copy[i]=array[i];
    }
    printf("original unsorted:\n");
    Display(array);
    Insertion(array);
    printf("\noriginal sorted:\n");
    Display(array);
    Recursive_insertion(copy,0,0,0);
    printf("\ncopy sorted:\n");
    Display(copy);
}