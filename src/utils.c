static int mytest_riWithNonZero(int x, int y, int nonZero);
static int * mytest_rfrWithProper(int numWidth, int denomWidth, int proper);
static int mytest_widthDouble(double x);
static int mytest_widthInt(int x);

#include "utils.h"
#include "primes.h"
#include "gjlib_arrays.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdarg.h>

int max_prime;
int primes_count; //100008

int mytest_get_max_prime(){
    int * p = prime_numbers;
    int i=0;
    while(*p++)
        i++;
    primes_count=i;
    printf("\n primes count: %d", primes_count);
    max_prime = prime_numbers[i-1];
    return prime_numbers[i-1];
}

void mytest_swap(int *x, int *y){
    int tmp = *y;
    *y = *x;
    *x = tmp;
}

int mytest_ri(int x, int y){
    int nonZero = 1;
    if( x == y)
        return x;

    int rtn = 0;

    int negBit=0;
    int posBit=0;

    if( x < 0 && y < 0 ){
        // negative range
        x = abs(x);
        y = abs(y);
        if( x > y )
            mytest_swap(&x, &y);
        while(nonZero == 1 && rtn == 0)
            rtn = mytest_GetR(x,y)*-1;

    }else if( x < 0 ){
        if(y==0) {  // range is negative
            while(nonZero == 1 && rtn == 0)
                rtn = -1*mytest_GetR(0,abs(x));
        }else{
            // range crosses the zero
            while(nonZero == 1 && rtn==0){
                negBit = mytest_GetR(0, abs(x))*-1;
                posBit = mytest_GetR(0, y);
                rtn= ( negBit + posBit);
            }
        }
    }else if( y < 0 ){
        if(x==0){   // range is negative
            while(nonZero == 1 && rtn == 0)
                rtn= -1*mytest_GetR(0,abs(y));
        }else{
            // range crosses the zero
            while(nonZero == 1 && rtn==0){
                negBit = mytest_GetR(0, abs(y))*-1;
                posBit = mytest_GetR(0, x);
                rtn= ( negBit + posBit );
            }
        }
    }else{
        // positive range
        if( x > y )
            mytest_swap(&x, &y);
        int nudge=0;
        if(x==0)
            nudge++;
        if(y==0)
            nudge++;
        while(nonZero == 1 & rtn==0)
            rtn = mytest_GetR(x+nudge,y+nudge)-nudge;
    }
    return rtn;
}

int mytest_GetR(int x, int y){
    return rand()%(y-x+1)+x;
}

double mytest_rd(int x, int y, int z){
    if(z==0)
        return (double)mytest_ri(x,y); //swap etc covered

    //if(z==1)
    //    return (double)mytest_ri(x,y) + (double)mytest_ri(1,9)/10.0;
        
    if(x==INT_MAX){
        x--;
    }else if(x==INT_MIN){
        x++;
    }    
    if(y==INT_MAX){
        y--;
    }else if(y==INT_MIN){
        y++;    
    }

    z=abs(z);
    float dec = (float)rand()/RAND_MAX;
    while( (int)(round(dec*pow(10,z)-.5)) % 10 == 0 || dec==0) //make right-most decimal non-zero
        dec=(float)rand()/RAND_MAX;

    double power = pow(10, z);
    if(x==y){
        if(x<0)
            dec=1-dec;
        return ((int)((x+dec) * power)) / power;
    }

    double rtn=0;
    int nonZero=1;
    int negBit=0;
    int posBit=0;

    if( x < 0 && y < 0 ){
        // range negative
        x = abs(x);
        y = abs(y);
        if( x > y )
            mytest_swap(&x, &y);
        if(y-x==1){
            rtn = (x+dec)*-1;
        }else{
            while(nonZero == 1 && rtn == 0)
                rtn = ((float)mytest_GetR(x,(y-1))+dec) *-1;
        }

    }else if( x < 0 ){
        if(y-x==1){ // implication: -1, 0
            rtn= dec*-1;
        }else if(y==0){   // range is negative
            rtn= -1.0*((float)mytest_GetR(0,abs(x))+dec);
        }else{
            // range crosses the zero
            while(nonZero == 1 && rtn==0){
                negBit = mytest_GetR(0, abs(x))*-1;
                posBit = mytest_GetR(0, y-1);
                rtn= (float)(negBit + posBit) + dec;
            }
        }

    }else if( y < 0 ){
        if(x-y==1){ // implication: 0, -1
            rtn= dec*-1;
        }else if(x==0){   // range is negative
            rtn= -1.0*((float)mytest_GetR(0,abs(y))+dec);
        }else{
            // range crosses the zero
            while(nonZero == 1 && rtn==0){
                negBit = mytest_GetR(0, abs(y))*-1;
                posBit = mytest_GetR(0, x-1);
                rtn=  (float)(negBit + posBit) + dec;
            }
        }

    }else{
        // range positive
        if( x > y )
            mytest_swap(&x, &y);
        int nudge=0;
        y--;
        if(x==0)
            nudge++;
        if(y==0)
            nudge++;
        while(nonZero == 1 & rtn==0)
            rtn = (float)(mytest_GetR(x+nudge,y+nudge)-nudge)+dec;
     }

     return ((int)(rtn * power)) / power;
}

int * mytest_rfr(int numWidth, int denomWidth){
    if(numWidth<=0 || denomWidth<=0 || numWidth>9 || denomWidth>9){
        printf("\nArgument error - numWidth: %d, denomWidth: %d in mytest_rfr\n", numWidth, denomWidth);
        exit(-1);
    }

    static int rtn[2];

    int proper=1;
    int num = mytest_ri(pow(10, numWidth-1), pow(10, numWidth)-1);
    int denom = mytest_ri(pow(10, denomWidth-1), pow(10, denomWidth)-1);
    if(numWidth>denomWidth)
        proper=0;
    while ( num >= denom && proper){
        num = mytest_ri(pow(10, numWidth-1), pow(10, numWidth)-1);
        denom = mytest_ri(pow(10, denomWidth-1), pow(10, denomWidth)-1);
    }
    rtn[0]=num;
    rtn[1]=denom;
    return rtn;
}

int mytest_is_prime(int x){
    if(x==2)
        return 1;
    if(x<2)
        return 0;
    if(x % 2==0 && x >2){
        return 0;        
    }
    if(x < max_prime){
        return gjlib_int_array_contains(x, prime_numbers, primes_count);
    } else {
        for(int y=0; y<x; y++){
            if( y % x == 0){
                return 0;
            }
        }
        return 1;
    }
}

char * mytest_boolOut(int b, char * rtn){
    return b==1 ? "True" : "False";
}

int *mytest_prime_factors(int x, int * rtn, int * element_count){
    int current_element=0;
    int counter=0;
    int last_assignment = 0;

    if(x > 1048577){
        printf("\nArgument too large (mytest_prime_factors) : %d", x);
        exit(-1);
    }
    // 1st time initialisation 
    if(*element_count==0){
        *element_count=8;
        rtn = (int *) malloc(8*sizeof(int));
        if (rtn==NULL){
            printf("\nError initialising memory: prime_factors");
            exit(-1);
        }
    } //---------------------
    
    if(x<1){
        *rtn =0;
        *(rtn+1)='\0';
        return rtn;
    }
    int i =  (x / ( fmax(mytest_strlen_int(x)*2-2,1))); // upper(ish) bound for prime space
    while(i>=0){
        if(x % prime_numbers[i] ==0){
            // memory management bit
            if(current_element==(*element_count)-1){ //overflowing my array now..
                *element_count*=2;
                rtn = (int *)realloc(rtn, *element_count*sizeof(int));
                if (rtn==NULL){
                    printf("\nUnable to (re)allocate memory: prime_factors");
                    exit(-1);
                }
            } //---------------------
     
            * (rtn+current_element)=prime_numbers[i];
            last_assignment = current_element;
            ++current_element;
            x /= prime_numbers[i];
            if(x==1)
                break;
            i = (x / ( fmax(mytest_strlen_int(x)*2-2,1)))+2; // bring the bound down accordingly
        }else{
            i-=1;
        }
    }
    * (rtn +(last_assignment+1))='\0';
    return rtn;
}

int mytest_strlen_int(int x){
    return snprintf(NULL, 0, "%d", abs(x));
}

int mytest_strlen_double(double x){
    return snprintf(NULL, 0, "%f", fabs(x));
}

long long mytest_lcm(int * set){
    if(*(set+1)=='\0')
        return *set;
    // make set positive
    int i=0;
    while(*(set+i)){
        if(*(set+i)==INT_MIN){
            printf("\nInvalid element in input array (INT_MIN): mytest_hcf");
            exit(-1);
        }
        *(set+i)=abs(*(set+i));
        i++;
    }
        
    long long mult = llabs(gjlib_int_array_product( set ));
    if(mult > 1000000000){
        printf("\nInput array product too large: %lld - mytest_lcm\n", mult);
        exit(-1);
    }
    long long rtn=mult;
    int skip = 0;
    int j;
    for(long long i=mult; i>=1; i--){
        skip = 0;
        j=0;
        while(*(set+j) ){
            if( i % *(set+j)!= 0){
                skip = 1;
                j++;
                break;
            }
            j++;
        }
        if(skip==0)
            rtn=i;
    }
    return rtn;
}

int mytest_hcf(int * set){
    int rtn=0;

    // make set positive
    int i=0;
    while(*(set+i)){
        if(INT_MIN == *(set+i)){
            printf("\nInvalid element in input array (INT_MIN): mytest_hcf");
            exit(-1);
        }
        *(set+i)=abs(*(set+i));
        i++;
    }
    int bound = gjlib_int_array_min(set);
    if(INT_MAX == bound ){
        printf("\nInvalid element in input array (INT_MAX): mytest_hcf");
        exit(-1);
    }
    bound++;
    int skip = 0;
    int j=0;
    for(i=1; i<bound; i++){
        j=0;
        while(*(set+j)){
            if( *(set+j) % i !=0){
                skip =1;
                break;
            }
            j++;
        }
        if(skip==0)
            rtn=i;
        skip =0;
    }
    return rtn;
}

int mytest_otherhcf(int * set){
    //printf("otherhcf");
    // No initial traversal for min
    int rtn=0;
    int skip=0;
    int min=INT_MAX;
    int i,j=0;
    int current;
    while(current = *(set+j)){
        printf("Current: %d", current);
        min = (min < current) ? min : current;
        for(i=0;i<current;i++){
            if(current % i != 0){
                skip =1;
                break;
            }
            j++;
        }
        if(skip==0)
            rtn=i;
        skip=0;
    }
    return (rtn < min) ? rtn : min;
}

int gjlib_sq(int x, int y){
    // random square integer
    if(y<0 || x > sqrt(INT_MAX)){
        printf("Argument(s) exception: %d, %d in gjlib_sq", x, y);
        exit(-1);
    }
    if(x==0)
        return 0;
    
    int ran = mytest_ri(x,y);
    long long rslt = pow(ran,2);
    if(rslt <= INT_MIN || rslt >= INT_MAX ){
        printf("\nArgument(s) exception: (%d, %d) in gjlib_sq\n", x, y);
        exit(-1);
    }
    //printf("\nx: %d, y: %d, ran: %d, rslt: %lld", x, y, ran, rslt);
    return rslt;
}

int gjlib_notSq(int x, int y){
    int rtn=4;
    while(gjlib_isSquare(rtn)){
        rtn = mytest_ri(x,y);
        if(1==abs(rtn))
            break;
    }
    return rtn;
}

int gjlib_isInt(double x){
    if( x - (int)x == 0)
        return 1;
    return 0;
}

int gjlib_isSquare(int x){
    if(x<4)
        return 0;
    return gjlib_isInt(sqrt(x))==1;
}

int gjlib_int_choose(int * inbound){
    int el_count=0;
    while(*inbound++)
        el_count++;
    int randElement = mytest_ri(1,el_count);
    *inbound--;
    inbound = inbound - randElement;
    return *inbound;
}

double gjlib_shrink(double x, int power){
    return x/pow(10, power);
}

int gjlib_int_not( int notMe, int x, int y, int (*func)(int, int)){
    int rtn=notMe;
    while(notMe == rtn)
        rtn=(*func)(x, y);
    return rtn;
}

double gjlib_significant_figures(double num, int figures){
    if(figures<1){
        printf("\nArgument exception: gjlib_significant_figures - figures = %d\n", figures);
        exit(-1);
    }
    if(num==0.0)
        return 0.0;

    double rtn = fabs(num);

    int shifts=0;
    if(rtn<1.0){
        while(rtn<1.0){
            rtn*=10;
            shifts--;
        }
        rtn*=0.1;
        shifts++;
    }else{
        while(rtn>1.0){
            rtn*=0.1;
            shifts++;
        }
    }
    rtn*=(double)pow(10,figures);
    rtn=(double)((int)round(rtn));
    rtn*=(double)pow(10,shifts-figures);

    if(num<0)
        rtn*=-1;
    return rtn;
}

char * mytest_to_super(char * str, char * rtn){//  ³√27    x²
    //memset(rtn, 0, sizeof rtn);
    rtn = (char *) malloc(3*sizeof(int)*strlen(str));
    if(rtn==NULL){
        printf("Error allocating memory: mytest_to_super");
        exit(-1);
    }
    while (*str){
        switch(*str){ 
            case '1': strcat(rtn, "¹"); break; //printf("\n1: %ld", strlen("¹")); 
            case '2': strcat(rtn, "²"); break; //printf("\n2: %ld", strlen("²")); 
            case '3': strcat(rtn, "³"); break; //printf("\n3: %ld", strlen("³")); 
            case '4': strcat(rtn, "⁴"); break; //printf("\n4: %ld", strlen("⁴")); 
            case '5': strcat(rtn, "⁵"); break; //printf("\n5: %ld", strlen("⁵")); 
            case '6': strcat(rtn, "⁶"); break; //printf("\n6: %ld", strlen("⁶")); 
            case '7': strcat(rtn, "⁷"); break; //printf("\n7: %ld", strlen("⁷")); 
            case '8': strcat(rtn, "⁸"); break; //printf("\n8: %ld", strlen("⁸")); 
            case '9': strcat(rtn, "⁹"); break; //printf("\n9: %ld", strlen("⁹")); 
            case '0': strcat(rtn, "⁰"); break; //printf("\n0: %ld", strlen("⁰")); 
            case '-': strcat(rtn, "⁻"); break; //printf("\n-: %ld", strlen("⁻")); 
            case '+': strcat(rtn, "⁺"); break; //printf("\n+: %ld", strlen("⁺")); 
            case '*': strcat(rtn, "*"); break; //printf("\n*: %ld", strlen("*")); 
            case '/': strcat(rtn, "ᐟ"); break; //printf("\n/: %ld", strlen("ᐟ")); 
           case '\\': strcat(rtn, "ᐠ"); break; //printf("\n\\: %ld", strlen("ᐠ"));
            case 'a': strcat(rtn, "ᵃ"); break; //printf("\na: %ld", strlen("ᵃ")); 
            case 'b': strcat(rtn, "ᵇ"); break; //printf("\nb: %ld", strlen("ᵇ")); 
            case 'c': strcat(rtn, "ᶜ"); break; //printf("\nc: %ld", strlen("ᶜ")); 
            case 'd': strcat(rtn, "ᵈ"); break; //printf("\nd: %ld", strlen("ᵈ")); 
            case 'e': strcat(rtn, "ᵉ"); break; //printf("\ne: %ld", strlen("ᵉ")); 
            case 'f': strcat(rtn, "ᶠ"); break; //printf("\nf: %ld", strlen("ᶠ")); 
            case 'g': strcat(rtn, "ᵍ"); break; //printf("\ng: %ld", strlen("ᵍ")); 
            case 'h': strcat(rtn, "ʰ"); break; //printf("\nh: %ld", strlen("ʰ")); 
            case 'i': strcat(rtn, "ⁱ"); break; //printf("\ni: %ld", strlen("ⁱ")); 
            case 'j': strcat(rtn, "ʲ"); break; //printf("\nj: %ld", strlen("ʲ")); 
            case 'k': strcat(rtn, "ᵏ"); break; //printf("\nk: %ld", strlen("ᵏ")); 
            case 'l': strcat(rtn, "ˡ"); break; //printf("\nl: %ld", strlen("ˡ")); 
            case 'm': strcat(rtn, "ᵐ"); break; //printf("\nm: %ld", strlen("ᵐ")); 
            case 'n': strcat(rtn, "ⁿ"); break; //printf("\nn: %ld", strlen("ⁿ")); 
            case 'o': strcat(rtn, "ᵒ"); break; //printf("\no: %ld", strlen("ᵒ")); 
            case 'p': strcat(rtn, "ᵖ"); break; //printf("\np: %ld", strlen("ᵖ")); 
            case 'q': strcat(rtn, "۹"); break;
            case 'r': strcat(rtn, "ʳ"); break; //printf("\nr: %ld", strlen("ʳ")); 
            case 's': strcat(rtn, "ˢ"); break; //printf("\ns: %ld", strlen("ˢ")); 
            case 't': strcat(rtn, "ᵗ"); break; //printf("\nt: %ld", strlen("ᵗ")); 
            case 'u': strcat(rtn, "ᵘ"); break; //printf("\nu: %ld", strlen("ᵘ")); 
            case 'v': strcat(rtn, "ᵛ"); break; //printf("\nv: %ld", strlen("ᵛ")); 
            case 'w': strcat(rtn, "ʷ"); break; //printf("\nw: %ld", strlen("ʷ")); 
            case 'x': strcat(rtn, "ˣ"); break; //printf("\nx: %ld", strlen("ˣ")); 
            case 'y': strcat(rtn, "ʸ"); break; //printf("\ny: %ld", strlen("ʸ")); 
            case 'z': strcat(rtn, "ᶻ"); break; //printf("\nz: %ld", strlen("ᶻ")); 
            case 'A': strcat(rtn, "ᴬ"); break; //printf("\nA: %ld", strlen("ᴬ")); 
            case 'B': strcat(rtn, "ᴮ"); break; //printf("\nB: %ld", strlen("ᴮ")); 
            case 'C': strcat(rtn, "ᶜ"); break;
            case 'D': strcat(rtn, "ᴰ"); break; //printf("\nD: %ld", strlen("ᴰ")); 
            case 'E': strcat(rtn, "ᴱ"); break; //printf("\nE: %ld", strlen("ᴱ")); 
            case 'F': strcat(rtn, "ᶠ"); break;
            case 'G': strcat(rtn, "ᴳ"); break; //printf("\nG: %ld", strlen("ᴳ")); 
            case 'H': strcat(rtn, "ᴴ"); break; //printf("\nH: %ld", strlen("ᴴ")); 
            case 'I': strcat(rtn, "ᴵ"); break; //printf("\nI: %ld", strlen("ᴵ")); 
            case 'J': strcat(rtn, "ᴶ"); break; //printf("\nJ: %ld", strlen("ᴶ")); 
            case 'K': strcat(rtn, "ᴷ"); break; //printf("\nK: %ld", strlen("ᴷ")); 
            case 'L': strcat(rtn, "ᴸ"); break; //printf("\nL: %ld", strlen("ᴸ")); 
            case 'M': strcat(rtn, "ᴹ"); break; //printf("\nM: %ld", strlen("ᴹ")); 
            case 'N': strcat(rtn, "ᴺ"); break; //printf("\nN: %ld", strlen("ᴺ")); 
            case 'O': strcat(rtn, "ᴼ"); break; //printf("\nO: %ld", strlen("ᴼ")); 
            case 'P': strcat(rtn, "ᴾ"); break; //printf("\nP: %ld", strlen("ᴾ")); 
            case 'R': strcat(rtn, "ᴿ"); break; //printf("\nR: %ld", strlen("ᴿ")); 
            case 'T': strcat(rtn, "ᵀ"); break; //printf("\nT: %ld", strlen("ᵀ")); 
            case 'S': strcat(rtn, "ˢ"); break; //printf("\nT: %ld", strlen("ᵀ")); 
            case 'U': strcat(rtn, "ᵁ"); break; //printf("\nU: %ld", strlen("ᵁ")); 
            case 'V': strcat(rtn, "ⱽ"); break; //printf("\nV: %ld", strlen("ⱽ")); 
            case 'W': strcat(rtn, "ᵂ"); break; //printf("\nW: %ld", strlen("ᵂ")); 
            case 'X': strcat(rtn, "ˣ"); break; //printf("\nT: %ld", strlen("ᵀ")); 
            case 'Y': strcat(rtn, "ʸ"); break; //printf("\nT: %ld", strlen("ᵀ")); 
            case 'Z': strcat(rtn, "ᶻ"); break; //printf("\nT: %ld", strlen("ᵀ")); 
            case '=': strcat(rtn, "⁼"); break; //printf("\n=: %ld", strlen("₌")); 
            case '(': strcat(rtn, "⁽"); break; //printf("\n(: %ld", strlen("⁽")); 
            case ')': strcat(rtn, "⁾"); break; //printf("\n): %ld", strlen("⁾")); 
            default: strncat(rtn, str, 1); break;            
        }
        *str++;
    }
    return rtn;
}

char * mytest_to_sub(char * str, char * rtn){
    //memset(rtn, 0, sizeof rtn);
    rtn = (char *) malloc(3*sizeof(int)*strlen(str));
    if(rtn==NULL){
        printf("Error allocating memory: mytest_to_subr");
        exit(-1);
    }

    while (*str){
        switch(*str){ 
            case '1': strcat(rtn, "₁"); break; //printf("\n₁ : %ld",strlen("₁"));
            case '2': strcat(rtn, "₂"); break; //printf("\n₂ : %ld",strlen("₂"));
            case '3': strcat(rtn, "₃"); break; //printf("\n₃ : %ld",strlen("₃"));
            case '4': strcat(rtn, "₄"); break; //printf("\n₄ : %ld",strlen("₄"));
            case '5': strcat(rtn, "₅"); break; //printf("\n₅ : %ld",strlen("₅"));
            case '6': strcat(rtn, "₆"); break; //printf("\n₆ : %ld",strlen("₆"));
            case '7': strcat(rtn, "₇"); break; //printf("\n₇ : %ld",strlen("₇"));
            case '8': strcat(rtn, "₈"); break; //printf("\n₈ : %ld",strlen("₈"));
            case '9': strcat(rtn, "₉"); break; //printf("\n₉ : %ld",strlen("₉"));
            case '0': strcat(rtn, "₀"); break; //printf("\n₀ : %ld",strlen("₀"));

            case '+': strcat(rtn, "₊"); break; //printf("\n₊ : %ld",strlen("₊"));
            case '-': strcat(rtn, "₋"); break; //printf("\n₋ : %ld",strlen("₋"));
            case '=': strcat(rtn, "₌"); break; //printf("\n₌ : %ld",strlen("₌"));
            case '(': strcat(rtn, "₍"); break; //printf("\n₍ : %ld",strlen("₍"));
            case ')': strcat(rtn, "₎"); break; //printf("\n₎ : %ld",strlen("₎"));

            case 'a': strcat(rtn, "ₐ"); break; //printf("\nₐ : %ld",strlen("ₐ"));
            case 'b' : strcat(rtn, "♭"); break;
            case 'e': strcat(rtn, "ₑ"); break; //printf("\nₑ : %ld",strlen("ₑ"));
            //case 'h': strcat(rtn, "ₕ"); break;; //printf("\nₕ : %ld",strlen("ₕ")); 
            case 'g': strcat(rtn, "₉"); break;
            case 'h': strcat(rtn, "ₕ"); break;
            case 'i': strcat(rtn, "ᵢ");  break; //printf("\nᵢ : %ld",strlen("ᵢ"));
            case 'j': strcat(rtn, "ⱼ");  break; //printf("\nⱼ : %ld",strlen("ⱼ"));
            // case 'k': strcat(rtn, "ₖ"); break;; //printf("\nₖ : %ld",strlen("ₖ")); 
            // case 'l': strcat(rtn, "ₗ"); break;; //printf("\nₗ : %ld",strlen("ₗ")); 
            // case 'm': strcat(rtn, "ₘ"); break;; //printf("\nₘ : %ld",strlen("ₘ")); 
            // case 'n': strcat(rtn, "ₙ"); break; //printf("\nₙ : %ld",strlen("ₙ"));
            case 'k': strcat(rtn, "ₖ"); break;
            case 'l': strcat(rtn, "ₗ"); break;
            case 'm': strcat(rtn, "ₘ"); break;
            case 'n': strcat(rtn, "ₙ"); break;
            case 'o': strcat(rtn, "ₒ"); break; //printf("\nₒ : %ld",strlen("ₒ"));
            //case 'p': strcat(rtn, "ₚ"); break; //printf("\nₚ : %ld",strlen("ₚ"));
            case 'p': strcat(rtn, "ₚ"); break;
            case 'r': strcat(rtn, "ᵣ"); break; //printf("\nᵣ : %ld",strlen("ᵣ"));
            // case 's': strcat(rtn, "ₛ"); break; //printf("\nₛ : %ld",strlen("ₛ")); 
            // case 't': strcat(rtn, "ₜ"); break; //printf("\nₜ : %ld",strlen("ₜ")); 
            case 's': strcat(rtn, "ₛ"); break;
            case 't': strcat(rtn, "ₜ"); break;
            case 'u': strcat(rtn, "ᵤ"); break; //printf("\nᵤ : %ld",strlen("ᵤ")); 
            case 'v': strcat(rtn, "ᵥ"); break; //printf("\nᵥ : %ld",strlen("ᵥ")); 
            case 'x': strcat(rtn, "ₓ"); break; //printf("\nₓ : %ld",strlen("ₓ")); 
            default: strncat(rtn, str, 1); break;            
        }
        *str++;
    }
    return rtn;
}

char * mytest_to_standard_form(double num, char * rtn){
    if(num==0){
        rtn= "0";
        return rtn;
    }
    if(num==1){
        rtn= "1";
        return rtn;
    }
    if(num==-1){
        rtn= "-1";
        return rtn;
    }

    double sign =num > 0 ? 1: -1;
    char buffer[20];
    int i=0;
    rtn = (char *)malloc(sizeof(double));
    if(rtn ==NULL){
        printf("Error allocating memory: mytest_to_standard_form");
        exit(-1);
    }

    if(fabs(num) >=1.0 && fabs(num) < 10.0){ //already in standard form.
        i=snprintf(buffer, 20, "%.10g", num);
        if(!(i>0 && i < 20)){
            printf("Conversion error: mytest_to_standard_form");
            exit(-1);
        }
        strcat(rtn, buffer);
        return rtn;
    }

    double orig = num;
    int shifts=0;
    char * supe;
    num = fabs(num);
    if(num <1){        
        while(num <1.0){
            num *=10.0;
            shifts++;
        }
    }else{
        while(num >=10.0){
            num /=10.0;
            shifts++;
        }
    }
    num *= sign;
    i=snprintf(buffer, 20, "%.10g", num);//(num* (sign==1?1.0:-1.0)));
    if(!(i>0 && i < 20)){
        printf("Conversion error: mytest_to_standard_form");
        exit(-1);
    }
    strcat(rtn, buffer);
    strcat(rtn, "*10");
    if(fabs(orig) >1)
        strcat(rtn, mytest_to_super("-", supe));
    i=snprintf(buffer, sizeof(int) * mytest_strlen_int(shifts), "%d", shifts);
    if(!(i>0 && i < 20)){
        printf("Conversion error: mytest_to_standard_form");
        exit(-1);
    }
    supe = mytest_to_super(buffer, supe);
    strcat(rtn, supe);
    return rtn;
}