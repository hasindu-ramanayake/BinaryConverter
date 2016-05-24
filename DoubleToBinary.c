#include<stdio.h>

double power(int base,int index);
void DoubleToBinary(double num);
int charCounter(char input[]);

int main(){
    double number=10.75;
    DoubleToBinary(number);
}

void DoubleToBinary(double num){
    int num1,num3=num,cou=0;
    double num2;
    int flo[64];
    int flo2[52];

     int i,j;
    for(i=52;i>=0;i--){
        flo2[i]=0;
    }
    for(i=63;i>=0;i--){
        flo2[i]=0;
    }

    if (num<0){
        flo[0]=1;
        num=num*(-1);
    }else{
        flo[0]=0;
    }

    num1=(int)num;
    num2=num-num1;



    //consider the integer part of the float number

    while (num1>1){
        flo2[cou]=num1%2;
        num1/=2;
        cou++;

    }
    int integerCount=cou;

//get exponent
   int cou2=0,expo=integerCount+1023;


        while (expo>=0){
        if(cou2>13){
            break;
        }
        flo[cou2]=expo%2;
        expo/=2;
        cou2++;

        }

    for(i=cou;i>=0;i--){
        flo[12+i]=flo2[i];
    }
    cou=0;
    while(cou<(52-integerCount)){
        flo2[cou]=(int)(num2*2);
        num2=(num2*2)-flo2[cou];
        cou++;
    }
    for(i=0;i<cou;i++){
        flo[i+12+integerCount]=flo2[i];
    }

     if (num3<0){
        flo[0]=1;
    }else{
        flo[0]=0;
    }



for(i=0;i<64;i++){
    printf("%d",flo[i]);

}








}


int charCounter(char input[]){
int counter =0;
while(input[counter]!='\0'){
    counter++;
}
return counter;
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
