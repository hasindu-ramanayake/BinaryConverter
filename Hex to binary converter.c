#include <stdio.h>

void HexToInt(char *hex,int ArraySize);
void HexToBinary(char *hex,int ArraySize);

int main(){
    int i;
    char HexArray[]="C0B0A0FF";
    HexToInt(HexArray,8);
    HexToBinary(HexArray,8);

return 0;
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
