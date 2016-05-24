#include<stdio.h>
# include <stdio.h>

double power(int base,int index);
float BinaryToDouble(char* bin);

int main(){
    char binary[]="0100000000101111000111110101100110001001110111110001000101110011";
    float k=BinaryToDouble(binary);
    printf("%f",k);

return 0;
}


float BinaryToDouble(char *bin){
        int i,j,sum2=0,expo=0;
        int bina[64];
        float sum=0;
    for(i=0;i<64;i++){
        if(bin[i]=='0'){
            bina[i]=0;
        }else{
            bina[i]=1;
        }
    }

    for(i=11;i>0;i--){
        expo+=(bina[i]*power(2,11-i));
    }
    expo-=1023;


    bina[11]=1;
    j=expo+1;
    for(i=11;i<11+expo;i++){
        sum2+=(bina[i]*power(2,--j));
    }
    for(i=11+expo;i<64;i++){
        sum+=(bina[i]*(1/power(2,i-11-expo)));
    }

    if(bina[0]==1){
        return (-(sum2+sum+0.0000001));
    }else{
        return (sum2+sum+0.0000001);
    }



}

double power(int base,int index){
    double value=1;
    int count;
    if(index==0){
        value=1;
    }else if(index<0){
        index=-index;
        for(count=1;count<=index;count++){
            value*=base;
        }
            value=1/value;
    }else if(index>0){
        for(count=1;count<=index;count++){
            value*=base;
            }
        }
return value;
}
