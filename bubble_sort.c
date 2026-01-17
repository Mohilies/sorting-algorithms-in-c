#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#define n 10
void Display(int Array[]){
    printf("\n");
    for(int i=0;i<n;i++){
    printf("%d \t",Array[i]);
  }  
}
void Bubble(int Array[]){
for(int i=0;i<n;i++){
    int count=0;
    for(int j=0;j<n-1-i;j++){
        if(Array[j]>Array[j+1]){
            int tmp=Array[j];
            Array[j]=Array[j+1];
            Array[j+1]=tmp;
            count++;
        }
    }
    if(count==0){break;}
}
}
void Recursive_Bubble(int Array[],int i,int j, int count){
    if(i==n){return;}
    else{
        if(j==n-1){
            if(count==0){return;}
            return Recursive_Bubble(Array,i+1,0,0);}
        else{
            if(Array[j]>Array[j+1]){
               int tmp=Array[j];
                Array[j]=Array[j+1];
                Array[j+1]=tmp;
                count++; 
                
            }
            Recursive_Bubble(Array,i,j+1,count);
        }
    }
}
void main(){
int Array[n];
int copy[n];
srand(time(NULL));
for(int i=0;i<n;i++){
    Array[i]=rand()%100;
    copy[i]=Array[i];
}
Bubble(Array);
Display(Array);
Recursive_Bubble(copy,0,0,0);
Display(copy);

}