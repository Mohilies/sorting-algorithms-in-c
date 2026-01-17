#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 200
void Sort(int Array[]){
for(int i=0;i<n;i++){
    int k=0;
    int Max=Array[0];
    for(int j=1;j<n-i;j++){
        if(Array[j]>Max){
            Max=Array[j];
            k=j;
        }
    }
    int temp=Array[n-i-1];
    Array[n-i-1]=Max;
    Array[k]=temp;
}}
void Sort_recursive(int Array[],int i,int j,int k,int Max){
if(i==n){return;}
if(j==0){
    Max=Array[0];
    k=0;
    return Sort_recursive(Array,i,j+1,k,Max);
}
if(j==n-i){
    int temp =Array[n-i-1];
    Array[n-i-1]=Max;
    Array[k]=temp;
    return Sort_recursive(Array,i+1,0,k,Max);
    }
    if(Array[j]>Max){
        k=j;
        Max=Array[j];
        return Sort_recursive(Array,i,j+1,k,Max);
    }else{
        return Sort_recursive(Array,i,j+1,k,Max);
    }
}
void Display(int Array[]){
    for(int i=0;i<n;i++){
    printf("%d \t",Array[i]);
  }  
}

void main (){
    int Array[n];
    int copy[n];
    srand(time(NULL));
    for(int i=0;i<n;i++){
        Array[i]=rand()%100;
        copy[i]=Array[i];
    }

    printf("unsorted \n");
    Display(Array);
    Sort(Array);//works fine for any input of n but it's complexity is n² so be careful because it takes a lot of time to run big arrays ( such as 250k)
    printf("\nsorted \n");
    Display(Array);
    printf("\n sorted copy \n");
    Sort_recursive(copy,0,0,0,0);//the recursive function WIll CRASH IF n is higher than 200 , why ? i think there is a limit on how much ram the program could use  which makes it crash because recursion uses a lot of memory if the input if very large 
    Display(copy);
}