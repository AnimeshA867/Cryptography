//Find the totient of a given number

#include<stdio.h>

int gcd(int a, int b){
    if(a==0){
        return b;
    }else{
        return gcd(a%b,a);
    }
}

void main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int arr[n],index=0;
    for(int i=0;i<n;i++){
        if(gcd(i,n)==1){
            arr[index]=i;
            index++;
        }
    }
    printf("The totient of %d are :\n",n);
    for( int i=0;i<index+1;i++){
        printf("%d\t",arr[i]);
    }
}