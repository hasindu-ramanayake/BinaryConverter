# include <stdio.h>

double power(int base,int index);
float BinaryToFloat();

int main(){
    char binary[]="11000001011110001111010111000011";
    float k=BinaryToFloat(binary);
    printf("%f",k);

return 0;
}


float BinaryToFloat(char *bin){
        int i,j,sum2=0,expo=0;
        int bina[32];
        float sum=0;
    for(i=0;i<32;i++){
        if(bin[i]=='0'){
            bina[i]=0;
        }else{
            bina[i]=1;
        }
    }

    for(i=8;i>0;i--){
        expo+=(bina[i]*power(2,8-i));
    }
    expo-=127;


    bina[8]=1;
    j=expo+1;
    for(i=8;i<8+expo;i++){
        sum2+=(bina[i]*power(2,--j));
    }
    for(i=8+expo;i<32;i++){
        sum+=(bina[i]*(1/power(2,i-8-expo)));
    }

    if(bina[0]==1){
        return (-(sum2+sum));
    }else{
        return (sum2+sum);
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
