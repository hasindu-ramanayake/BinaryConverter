#include <stdio.h>
int charCounter(char input[]);
void HexToBinary(char *hex,int AS);
void HexToInt(char *hex,int ArraySize);
void HexToInteger(char *hex,int AS);
double power(int base,int index);
float HexToFloat(char *hex,int AS);
double HexToDouble(char *hex,int AS);

int main(){
    char hex[]="C0B0A0FFC0B0A0FF";
    HexConvertion(hex,'D');
return 0;
}


void HexConvertion(char *hex, char outputType){
        int j,i=charCounter(hex);

    if (outputType=='I'){
        HexToInt(hex,i);
        HexToInteger(hex,i);

    }else if(outputType=='B'){
        HexToInt(hex,i);
        HexToBinary(hex,i);

    }else if(outputType=='H'){
        printf("%s",hex);

    }else if(outputType=='F'){
        HexToInt(hex,i);
        printf("%f",HexToFloat(hex,i));
    }else if(outputType=='D'){
        HexToInt(hex,i);
        printf("%lf",HexToDouble(hex,i));
    }

}

double HexToDouble(char *hex,int AS){
    int i,k,j=((AS*4)-1);
    int binary[AS*4];
    for(i=0;i<(AS*4);i++){
        binary[i]=0;
    }
    for(i=(AS-1);i>=0;i--){
        for(k=0;k<4;k++){
            binary[j]=hex[i]%2;
            hex[i]/=2;
            j--;
        }
    }

//binary to Double
        int sum2=0,expo=0;
        double sum=0;

for(i=11;i>0;i--){
        expo+=(binary[i]*power(2,11-i));

    }
    expo-=1023;


    binary[11]=1;
    j=expo+1;
    for(i=11;i<11+expo;i++){
        sum2+=(binary[i]*power(2,--j));
    }
    for(i=11+expo;i<64;i++){
        sum+=(binary[i]*(1/power(2,i-11-expo)));
    }

    if(binary[0]==1){
        return (-(sum2+sum+0.0000001));
    }else{
        return (sum2+sum+0.0000001);
    }








}

float HexToFloat(char *hex,int AS){
    int i,k,j=((AS*4)-1);
    int binary[AS*4];
    for(i=0;i<(AS*4);i++){
        binary[i]=0;
    }
    for(i=(AS-1);i>=0;i--){
        for(k=0;k<4;k++){
            binary[j]=hex[i]%2;
            hex[i]/=2;
            j--;
        }
    }

    // binary ti float

      int sum2=0,expo=0;
        float sum=0;

    for(i=8;i>0;i--){
        expo+=(binary[i]*power(2,8-i));
    }
    expo-=127;

    binary[8]=1;
    j=expo+1;
    for(i=8;i<8+expo;i++){
        sum2+=(binary[i]*power(2,--j));
    }
    for(i=8+expo;i<32;i++){
        sum+=(binary[i]*(1/power(2,i-8-expo)));
    }

    if(binary[0]==1){
        return (-(sum2+sum));
    }else{
        return (sum2+sum);
    }





}

void HexToInteger(char *hex,int AS){
    int i,k,j=((AS*4)-1);
    int binary[AS*4];
    for(i=0;i<(AS*4);i++){
        binary[i]=0;
    }
    for(i=(AS-1);i>=0;i--){
        for(k=0;k<4;k++){
            binary[j]=hex[i]%2;
            hex[i]/=2;
            j--;
        }
    }

   //binary to integer
    int sum=0;
            for(i=((AS*4)-1);i>0;i--){
                sum+=(binary[i]*power(2,31-i));
            }
            if(binary[0]==1){
                sum=(-1)*sum;
            }
            printf("%d",sum);
}

void HexToBinary(char *hex,int AS){
    int i,k,j=((AS*4)-1);
    int binary[AS*4];
    for(i=0;i<(AS*4);i++){
        binary[i]=0;
    }
    for(i=(AS-1);i>=0;i--){
        for(k=0;k<4;k++){
            binary[j]=hex[i]%2;
            hex[i]/=2;
            j--;
        }
    }
   for(i=0;i<(AS*4);i++){
        printf("%d",binary[i]);
    }
}

int charCounter(char input[]){
int counter =0;
while(input[counter]!='\0'){
    counter++;
}
return counter;
}

void HexToInt(char *hex,int ArraySize){
    int i=0;
    for(i=0;i<ArraySize;i++){

        if(hex[i]=='0'){
                hex[i]=0;
        }else if(hex[i]=='1'){
                hex[i]=1;
        }else if(hex[i]=='2'){
                hex[i]=2;
        }else if(hex[i]=='3'){
                hex[i]=3;
        }else if(hex[i]=='4'){
                hex[i]=4;
        }else if(hex[i]=='5'){
                hex[i]=5;
        }else if(hex[i]=='6'){
                hex[i]=6;
        }else if(hex[i]=='7'){
                hex[i]=8;
        }else if(hex[i]=='9'){
                hex[i]=9;
        }else if(hex[i]=='A'){
                hex[i]=10;
        }else if(hex[i]=='B'){
                hex[i]=11;
        }else if(hex[i]=='C'){
                hex[i]=12;
        }else if(hex[i]=='D'){
                hex[i]=13;
        }else if(hex[i]=='E'){
                hex[i]=14;
        }else if(hex[i]=='F'){
                hex[i]=15;
        }
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

