/*
coaded by: Hasindu Ramanayaka;
date:19/03/2016;
*/

#include <stdio.h>
//----------binary convetion functions---------//
int charCounter(char input[]);
double power(int base,int index);
void BinaryToInteger(char *binary,int size);
void BinaryToHex(char *binary,int size);
double BinaryToDouble(char *bin);
float BinaryToFloat(char *bin);
void binaryConvertion(char *binary, char outputType);
//----------double convetion functions---------//
double chaToDouble(char input[]);
void DoubleToBinary(double num);
void DoubleToHex(double num);
void DoubleConvertion(char *dou, char outputType);
//----------float convetion functions---------//
void FloatConvertion(char *flo, char outputType);
void FloatToBinary(float num);
void FloatToHex(float num);

//----------hex convetion functions---------//
void HexToBinary(char *hex,int AS);
void HexToInt(char *hex,int ArraySize);
void HexToInteger(char *hex,int AS);
float HexToFloat(char *hex,int AS);
double HexToDouble(char *hex,int AS);
void HexConvertion(char *hex, char outputType);
//----------integer convetion functions---------//
void IntegerConvertion(char *integer, char outputType);
void IntegerToBinary(int integer);
void IntegerToHex(int integer);
//-----------error handling functions---------------//
int errorInputFormat(char* input);
int errorOutputFormat(char* output);
int errorInput(char* input,char* inputFormat);
int erroroutput(char* outputType,char* inputType,char *input);



int main(int num,char** argv){
    //errors checking of the system.

    if (num!=4){
        fprintf(stderr,"ERROR: The number of arguments is wrong.");
        return 1;
        }
      else if(errorInputFormat(argv[1])!=0){
        fprintf(stderr,"ERROR: The input argument is wrong");
        return 1;
      }
        else if(errorOutputFormat(argv[2])!=0){
        fprintf(stderr,"ERROR: The output argument is wrong");
        return 1;
      }
        else if(errorInput(argv[3],argv[1])!=0){
        return 1;
      }
        else if(erroroutput(argv[2],argv[1],argv[3]) != 0){
        return 1;
      }


    ///////////////////////////////////////////////////////////////////////////////

    if(argv[1][1]=='B'){				// binary convertions
            binaryConvertion(argv[3],argv[2][1]);
	}else if(argv[1][1]=='H'){		        	//Hex convertions
             HexConvertion(argv[3],argv[2][1]);
	}else if(argv[1][1]=='I'){		            // Integer convertions
            IntegerConvertion(argv[3],argv[2][1]);
	}else if(argv[1][1]=='F'){		            // float convertions
            FloatConvertion(argv[3],argv[2][1]);
	}else if(argv[1][1]=='D'){                  //Double convertions
            DoubleConvertion(argv[3],argv[2][1]);
    }

return 0;
}
//////////////////////////////////////////////////////////////////
//---------binary convertion function--------------//
void binaryConvertion(char *binary, char outputType){

    int i,k;        //define variables for counter
    k = charCounter(binary);    //character count

    if (outputType=='I'){       //test wanted outputs
        BinaryToInteger(binary,k);

    }else if(outputType=='B'){
        for(i=0;i<k;i++){
		fprintf(stdout,"%c",binary[i]); //print binary number
		}

    }else if(outputType=='H'){
        BinaryToHex(binary,k);

    }else if(outputType=='F'){
       fprintf(stdout,"%.2f",BinaryToFloat(binary));

    }else if(outputType=='D'){
        fprintf(stdout,"%lf",BinaryToDouble(binary));

    }
}
float BinaryToFloat(char *bin){
        int i,j,sum2=0,expo=0;  // expo=exponent --- i,j counters
        int bina[32];   //binary array
        float sum=0;
    for(i=0;i<32;i++){  //convert char in to int
        if(bin[i]=='0'){
            bina[i]=0;
        }else{
            bina[i]=1;
        }
    }
    for(i=8;i>0;i--){
        expo+=(bina[i]*power(2,8-i));   //calculate the exponent

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

    if(bina[0]==1){         //CONSIDER THE SIGN BIT
        return (-(sum2+sum));
    }else{
        return (sum2+sum);
    }

}
double BinaryToDouble(char *bin){
        int i,j,sum2=0,expo=0;
        int bina[64];           // same as binary to float
        double sum=0;
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
void BinaryToHex(char *binary,int size){
    int i,j,sum=0;
    if(size==32){
        j=8;            //consider the array size of the hex
    }else{
        j=16;
    }
    int hex[j];         //define the array
            for(i=0;i<size;i++){
                if(binary[i]=='1'){
                    binary[i]=1;
                }else{
                    binary[i]=0;
                }
                }

            for(i=0;i<size;i+=4){           //consider 4 by array slots
                sum=0;
                sum+=((int)binary[i])*power(2,3);
                sum+=((int)binary[i+1])*power(2,2);
                sum+=((int)binary[i+2])*power(2,1);
                sum+=((int)binary[i+3])*power(2,0);
                hex[(i+1)/4]=sum;
                }
                printf("0x");
            for(i=0;i<j;i++){
                fprintf(stdout,"%X",hex[i]);
            }
}
void BinaryToInteger(char *binary,int size){
    int i,sum=0;
            for(i=0;i<size;i++){
                if(binary[i]=='1'){
                    binary[i]=1;
                }else{
                    binary[i]=0;
                }
            }
            for(i=size-1;i>0;i--){
                sum+=(binary[i])*power(2,31-i); //sum th integer numbers
            }
            if(binary[0]==1){   //consider the sign bit
                sum=(-1)*sum;
            }
            fprintf(stdout,"%d",sum);
            }
int charCounter(char input[]){
int counter =0;
while(input[counter]!='\0'){    //consider the \0 to stop the loop
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
        index=-index;       //make index positive number;
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

//--------- double convertion functions---------//

void DoubleConvertion(char *dou, char outputType){
        double Double=chaToDouble(dou);
    if (outputType=='I'){
        fprintf(stdout,"%d",(int)Double);
    }else if(outputType=='B'){
        DoubleToBinary(Double);
    }else if(outputType=='H'){
        DoubleToHex(Double);
    }else if(outputType=='F'){
        //fprintf("%.2f",(float)Double);
    }else if(outputType=='D'){
        fprintf(stdout,"%lf",Double);
    }

}
void DoubleToHex(double num){
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

    num1=(int)num;  //consider the integer part
    num2=num-num1;  //consider the decimal part



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
    while(cou<(52-integerCount)){       // multiply by two
        flo2[cou]=(int)(num2*2);
        num2=(num2*2)-flo2[cou];
        cou++;
    }
    for(i=0;i<cou;i++){
        flo[i+12+integerCount]=flo2[i];     // assigning to the full array
    }

     if (num3<0){
        flo[0]=1;   //CONSIDER THE SIGN BIT
    }else{
        flo[0]=0;
    }


//convert to binary

int size=64,sum=0;
    j=16;
    int hex[j];
            for(i=0;i<size;i+=4){
                sum=0;
                sum+=((int)flo[i])*power(2,3);
                sum+=((int)flo[i+1])*power(2,2);
                sum+=((int)flo[i+2])*power(2,1);
                sum+=((int)flo[i+3])*power(2,0);
                hex[(i+1)/4]=sum;
                }
                fprintf(stdout,"0x");
            for(i=0;i<j;i++){
                fprintf(stdout,"%X",hex[i]);
            }
}
void DoubleToBinary(double num){
    int num1,num3=num,cou=0;
    double num2;
    int flo[64];        //DEFINE MAIN VARIABLE FLOAT ARRY
    int flo2[52];

     int i;
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
    fprintf(stdout,"%d",flo[i]);

}
}

//----------float convertion function-----------//

void FloatConvertion(char *flo, char outputType){
        double FloatDouble=chaToDouble(flo);
        float FloatFloat=(float)FloatDouble;
        int FloatInt=(int)FloatFloat;
    if (outputType=='I'){
        printf("%d",FloatInt);
    }else if(outputType=='B'){
        FloatToBinary(FloatFloat);
    }else if(outputType=='H'){
        FloatToHex(FloatFloat);
    }else if(outputType=='F'){
        printf("%.2f",FloatFloat);
    }else if(outputType=='D'){
        printf("%lf",(double)FloatFloat);
    }
}
void FloatToHex(float num){
     int num1,cou=0;
    float num2,num3=num;
    int flo[32];
    int flo2[23];

     int i,j;
    for(i=23;i>=0;i--){
        flo2[i]=0;
    }
    for(i=31;i>=0;i--){
        flo[i]=0;
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
   int cou2=0,expo=integerCount+127;
        while (expo>=0){
        if(cou2>10){
            break;
        }
        flo[cou2]=expo%2;
        expo/=2;
        cou2++;
        }
    for(i=cou;i>=0;i--){
        flo[9+i]=flo2[i];
    }
    cou=0;
    while(cou<(23-integerCount)){
        flo2[cou]=(int)(num2*2);
        num2=(num2*2)-flo2[cou];
        cou++;
    }
    for(i=0;i<cou;i++){
        flo[i+9+integerCount]=flo2[i];
    }
     if (num3<0){
        flo[0]=1;
    }else{
        flo[0]=0;
    }

//binaary convertion

    int size=32,sum=0;
    j=8;
    int hex[j];
            for(i=0;i<size;i+=4){
                sum=0;
                sum+=((int)flo[i])*power(2,3);
                sum+=((int)flo[i+1])*power(2,2);
                sum+=((int)flo[i+2])*power(2,1);
                sum+=((int)flo[i+3])*power(2,0);
                hex[(i+1)/4]=sum;
                }
                printf("0x");
            for(i=0;i<j;i++){
                printf("%X",hex[i]);
            }
}
void FloatToBinary(float num){
    int num1,cou=0;
    float num2,num3=num;
    int flo[32];
    int flo2[23];

     int i;
    for(i=23;i>=0;i--){
        flo2[i]=0;
    }
    for(i=31;i>=0;i--){
        flo[i]=0;
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
   int cou2=0,expo=integerCount+127;
        while (expo>=0){
        if(cou2>10){
            break;
        }
        flo[cou2]=expo%2;
        expo/=2;
        cou2++;
        }
    for(i=cou;i>=0;i--){
        flo[9+i]=flo2[i];
    }
    cou=0;
    while(cou<(23-integerCount)){
        flo2[cou]=(int)(num2*2);
        num2=(num2*2)-flo2[cou];
        cou++;
    }
    for(i=0;i<cou;i++){
        flo[i+9+integerCount]=flo2[i];
    }
     if (num3<0){
        flo[0]=1;
    }else{
        flo[0]=0;
    }
    for(i=0;i<32;i++){
        printf("%d",flo[i]);
    }
}

//------------hex contertion functions----------//

double chaToDouble(char input[]){
double value=0;
int count,i=0, x=1;

if(input[0]=='-'){      // looking for minaz mark
    i=1;
}

while(input[x]!='.' && (x+i)<charCounter(input)){   //consider the decimal dot
    x++;
}
if(input[0]!='-'){
    x--;
}
for(count=x;count>=i;count--){          //get the   int part of the number
    int tempInput=(int)input[count]-48;
    value+=tempInput*power(10,(x-count));
}
for(count=x+2;count<charCounter(input);count++){    //get the decimal part of the number
    int tempInput=(int)input[count]-48;
    value+=tempInput*power(10,(x+1-count));
}
if(input[0]=='-'){      //consider the sign bit
    return (-value);
}else{
    return value;
}}
double HexToDouble(char *hex,int AS){
    int i,k,j=((AS*4)-1);       //hex to binary number
    int binary[AS*4];
    for(i=0;i<(AS*4);i++){
        binary[i]=0;
    }
    for(i=(AS-1);i>=0;i--){
        for(k=0;k<4;k++){
            binary[j]=hex[i]%2;     // hex number divide by 2
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
    for(i=0;i<(AS*4);i++){      //same as hex to double
        binary[i]=0;
    }
    for(i=(AS-1);i>=0;i--){
        for(k=0;k<4;k++){
            binary[j]=hex[i]%2;
            hex[i]/=2;
            j--;
        }
    }

    // binary to float

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
            fprintf(stdout,"%d",sum);
}
void HexToBinary(char *hex,int AS){
    int i,k,j=((AS*4)-1);   //AS is array size
    int binary[AS*4];
    for(i=0;i<(AS*4);i++){
        binary[i]=0;
    }
    for(i=(AS-1);i>=0;i--){
        for(k=0;k<4;k++){
            binary[j]=hex[i]%2; //convert to 1 and 0 numbers in hex array
            hex[i]/=2;
            j--;
        }
    }
   for(i=0;i<(AS*4);i++){
        fprintf(stdout,"%d",binary[i]);
    }
}
void HexToInt(char *hex,int ArraySize){
    int i=0;
    for(i=0;i<ArraySize;i++){   //change char hex to ASCII 1-15 values,

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
void HexConvertion(char *hex, char outputType){
        int i=charCounter(hex);

    if (outputType=='I'){
        HexToInt(hex,i);
        HexToInteger(hex,i);

    }else if(outputType=='B'){
        HexToInt(hex,i);
        HexToBinary(hex,i);

    }else if(outputType=='H'){
        fprintf(stdout,"%s",hex);

    }else if(outputType=='F'){
        HexToInt(hex,i);
        fprintf(stdout,"%.2f",HexToFloat(hex,i));
    }else if(outputType=='D'){
        HexToInt(hex,i);
        fprintf(stdout,"%lf",HexToDouble(hex,i));
    }

}

//-------------integer convetion functions---------//


void IntegerConvertion(char *integer, char outputType){
        double k=chaToDouble(integer);
        int inte=(int)k;
        float intFloat;
        double intDouble;
    if (outputType=='I'){
         fprintf(stdout,"%d",inte);
    }else if(outputType=='B'){
        IntegerToBinary(inte);
    }else if(outputType=='H'){
        IntegerToHex(inte);
    }else if(outputType=='F'){
        intFloat=(float)inte;
        printf("%.2f",intFloat);
    }else if(outputType=='D'){
        intDouble=(double)inte;
        fprintf(stdout,"%lf",intDouble);
    }

}
void IntegerToBinary(int integer){
    int binary[32],i,j;
    long max=power(2,32);
        for(j=0;j<32;j++){
            binary[j]=0;

			}
			i=31;
			if(integer>=0){
				while(integer>0){
    				binary[i]=integer%2;
    				integer=integer/2;
    				i--;
				}
			}else if(integer<0){
				integer = max+integer;
				while(integer>0){
    				binary[i]=integer%2;
    				integer=integer/2;
    				i--;
				}
			binary[0]=1;
			}
			for(j=0;j<32;j++){
    			fprintf(stdout,"%d",binary[j]);
			}
}
void IntegerToHex(int integer){
    int binary[32],i,j,sum=0,size=32;
    long max=power(2,32);// max number
        for(j=0;j<32;j++){
            binary[j]=0;

			}
			i=31;
			if(integer>=0){
				while(integer>0){
    				binary[i]=integer%2;
    				integer=integer/2;
    				i--;
				}
			}else if(integer<0){
				integer = max+integer;
				while(integer>0){
    				binary[i]=integer%2;
    				integer=integer/2;
    				i--;
				}
			binary[0]=1;
			}
    j=8;
    int hex[j];
            for(i=0;i<size;i+=4){
                sum=0;
                sum+=((int)binary[i])*power(2,3);
                sum+=((int)binary[i+1])*power(2,2);
                sum+=((int)binary[i+2])*power(2,1);
                sum+=((int)binary[i+3])*power(2,0);
                hex[(i+1)/4]=sum;
                }
                fprintf(stdout,"0x");
            for(i=0;i<j;i++){
                fprintf(stdout,"%X",hex[i]);
            }
}

//--------------error functions-------------------//

int erroroutput(char* outputType,char* inputType,char *input){

    int good=0;
    int chaCount=charCounter(input);
//-------check the output errors compare to the input format-----------------//
    if (inputType[1]=='D'){
        if(outputType[1]=='I' || outputType[1]=='F'){
            fprintf(stderr,"ERROR: This conversion is not possible.");
            good=1;
        }
//---------compare hex format---------------//
    }else if(inputType[1]=='H'){
        if(outputType[1]=='I' && chaCount!=8){
            fprintf(stderr,"ERROR: This conversion is not possible.");
            good=1;
        }else if(outputType[1]=='F' && chaCount!=8){
            fprintf(stderr,"ERROR: This conversion is not possible.");
            good=1;
        }else if(outputType[1]=='D' && chaCount!=16){
            fprintf(stderr,"ERROR: This conversion is not possible.");
            good=1;
        }
//-----------compare binary format-------------//
    }else if(inputType[1]=='B'){
        if(outputType[1]=='I' && chaCount!=32){
            printf("ERROR: This conversion is not possible.");
            good=1;
        }else if(outputType[1]=='F' && chaCount!=32){
            fprintf(stderr,"ERROR: This conversion is not possible.");
            good=1;
        }else if(outputType[1]=='D' && chaCount!=64){
            fprintf(stderr,"ERROR: This conversion is not possible.");
            good=1;
        }
    //----------compare float format--------------------------//
    }else if(inputType[1]=='F'){
        float flo = chaToDouble(input);
        if(outputType[1]=='I'){

            if(flo<2147483647){
            fprintf(stderr,"WARNING: There is a possibility for a precision loss.\n");
        }else{
            fprintf(stderr,"ERROR: This conversion is not possible.");
            good=1;
        }
    }

    }
return good;
}
int errorInputFormat(char* input){
    //------------check the input format errors---------------//
    int good=1;
    if(input[0]=='-' && (input[1]=='I' || input[1]=='B' || input[1]=='D' || input[1]=='F' || input[1]=='H')){
        good=0;
    }

return good;
}
int errorOutputFormat(char* input){
    //------------check the output format errors------------------//
    int good=1;
    if(input[0]=='-' && (input[1]=='I' || input[1]=='B' || input[1]=='D' || input[1]=='F' || input[1]=='H')){
        good=0;
    }

return good;
}
int errorInput(char* input,char* inputFormat){
    int good=1;             // if no errors return 0 else return 1
    int i,CharCounter=0,count=0;
    CharCounter=charCounter(input);
//-----------consider the integer format errors------------------//
    if(inputFormat[1]=='I'){
        if(CharCounter<12){
            for(i=0;i<CharCounter;i++){
                if((input[i]=='0' || input[i]=='1' || input[i]=='2' || input[i]=='3' || input[i]=='4' || input[i]=='5' || input[i]=='6' || input[i]=='7' || input[i]=='8' || input[i]=='9' || input[i]=='-')){
                   if(input[i]=='-' && input[0]!='-'){
                        count++;
                   }
                   good=0;
                   if(count>0){
                        good=1;
                        fprintf(stderr,"ERROR: Input format error at location %d.",i);
                        count--;
                        break;
                   }

                   }else{
                   good=1;
                   fprintf(stderr,"ERROR: Input format error at location %d.",i);
                   break;
                   }
            }
        }else{
            fprintf(stderr,"ERROR: The input size is wrong.");
            good=1;
        }
//----------consider the double and float format errors-----------------//
    }else if(inputFormat[1]=='D' || inputFormat[1]=='F'){
        int countMin=0,countDot=0;
            if(CharCounter<=15){
                for(i=0;i<CharCounter;i++){
                    if((input[i]=='0' || input[i]=='1' || input[i]=='2' || input[i]=='3' || input[i]=='4' || input[i]=='5' || input[i]=='6' || input[i]=='7' || input[i]=='8' || input[i]=='9' || input[i]=='-' || input[i]=='.')){
                   if(input[i]=='-' && input[0]!='-'){
                        countMin++;
                   }
                   if(countMin>0){
                        good=1;
                        fprintf(stderr,"ERROR: Input format error at location %d.",i);
                        countMin--;
                   }
                   if(input[i]=='.'){
                        countDot++;
                   }
                   if(countDot>1){
                        good=1;
                        fprintf(stderr,"ERROR: Input format error at location %d.",i);
                        countDot--;
                        break;
                   }
                    good=0;
                   }else{
                   good=1;
                   fprintf(stderr,"ERROR: Input format error at location %d.",i);
                   break;
                   }
            }
        }else{
            fprintf(stderr,"ERROR: The input size is wrong.");
            good=1;
        }
//-------------consider the binary format error------------------//
    }else if(inputFormat[1]=='B'){
            if(CharCounter==32 || CharCounter==64){
                for(i=0;i<CharCounter;i++){
                    if((input[i]=='0' || input[i]=='1' )){
                        good=0;
                   }else{
                        good=1;
                    fprintf(stderr,"ERROR: Input format error at location %d.",i);
                    break;
                   }
            }
        }else{
            fprintf(stderr,"ERROR: The input size is wrong.");
            good=1;
        }
//---------consider the hex format errors------------//
    }else if(inputFormat[1]=='H'){
        if(CharCounter==8 || CharCounter==16){
                for(i=0;i<CharCounter;i++){
                    if((input[i]=='0' || input[i]=='1' || input[i]=='2' || input[i]=='3' || input[i]=='4' || input[i]=='5' || input[i]=='6' || input[i]=='7' || input[i]=='8' || input[i]=='9' || input[i]=='A' || input[i]=='B' || input[i]=='C' || input[i]=='D' || input[i]=='E' || input[i]=='F')){
                        good=0;
                   }else{
                        good=1;
                        fprintf(stderr,"ERROR: Input format error at location %d.",i);
                        break;
                   }
                }
        }else{
            fprintf(stderr,"ERROR: The input size is wrong.");
            good=1;
        }
    }

return good;
}

