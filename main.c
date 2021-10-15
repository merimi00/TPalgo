#include <stdio.h>
#include <stdlib.h>

/*********question 1: e = ∑∞n=0 1/n!****ajouter un argument pour garder *******/
float fact_div_T(int n){
    if (n==0){return 1.0;}
    else return (1.0/n)*fact_div_T(n-1);
}

float fact_div(int n){
    if(n==0){return fact_div_T(n);}
    else {return fact_div_T(n)+fact_div(n-1);}
}

/*********question 2: Puissance***********/

//itérative
float puissanceI(int n, float x){
    float a = 1;
    if (n > 0) {

        for(int i = 0; i<n; i++) {
                a = a*x;
        }
    }
    else if (n < 0)  {
            for(int i = n; i<0; i++) {
                a = a*(1.0/x);
            }

        }

    return a;

}

//récursive
float puissanceR(int n, float x){
    if (n == 0) return 1;
    else if (n>0) return x*puissanceR(n-1,x);
    else return (1/x)*puissanceR(n+1,x);

}

//récursive terminale
float puissanceRT(int n, float x, float acc){
    if(n == 0) return acc;
    else if (n > 0) return puissanceRT(n-1, x, acc*x);
    else return puissanceRT(n+1, x,(1.0/x)*acc);
}

//récursif 2^p= 2(n*2)
///////////////////////////////::::::::::::::::::
float puissanceR2(int n, float x){
    if(n == 0) return 1;
    else if (n > 0){
        if (n%2 == 0) return puissanceR2(n/2,x)*puissanceR2(n/2,x);
        else return puissanceR2(n/2,x)*puissanceR2(n/2,x)*x;
    }
    else{
        if (n%2 == 0) return puissanceR2(n/2,1.0/x)*puissanceR2(n/2,1.0/x);
        else return puissanceR2(n/2,1.0/x)*puissanceR2(n/2,1.0/x)*(1.0/x);
    }
}

/*********question 3: Ackermann***********/

//itérative
/**heyyyyyy elle est pas récursive elle**/
int Ack(int n, int m){
    int res;
    if (m == 0) return n+1;
    else if (n == 0) res = Ack(0,m-1);
    else {
        res=1;
        for(int i = 0; i<(m+1); i++){res = Ack(res,m-1);}
    }
    return res;
}

//récursive
int Ackrec(int n, int m){
    if (m == 0) return n+1;
    else if (n == 0) return Ackrec(1, m-1);//return m+1
    else return Ackrec(Ack(n-1,m),m-1);

}


/*********question 4: Suite***********/

//itérative
float suiteX(int n){
    float res = 0;
    if (n == 0) res = 1;
    else for(int i = 0; i<n; i++) res = res + (1.0/res);
    return res;
}

//récursive

float suiteXrec(int n){
    //float a = suiteXrec(n-1);
    if(n == 0) return 1;
    else return suiteXrec(n-1)+(1.0/suiteXrec(n-1));
}

int main()
{
    /***question 1: e = ∑∞n=0 1/n!***/
    /*
    printf("fact_div de 7: %f\n" , fact_div(7));//2.718254
    printf("fact_div de 5: %f\n" , fact_div(5));//2.716667
    printf("fact_div de 2: %f\n" , fact_div(2));//2.500000
    printf("fact_div de 1: %f\n" , fact_div(1));//2.000000
    printf("fact_div de 0: %f\n" , fact_div(0));//1.000000
    */

    /***question 2***/ //calculer (1 + 10-k )^(10^k)/
   /* printf("puissanceI(-2,10.0): %f\n" , puissanceI(-3,5.0));
    printf(" puissanceR(-3,5.0): %f\n" , puissanceR(-3,5.0));*/
    printf(" puissanceR2(-4,5.0): %f\n" , puissanceR2(-2,2.0));
    //printf(" puissanceRT(-3,5.0): %f\n" , puissanceRT(-3,5.0,1));
    //puissanceI(-2,1+puissanceI(-2,10))
    /***question 3***/ //Ackermann
    /*
    printf("Ack(0,0): %d\n" , Ack(0,0));
    printf("Ack(1,0): %d\n" , Ack(1,0));
    printf("Ack(2,0): %d\n" , Ack(2,0));
    printf("Ack(3,0): %d\n" , Ack(3,0));
    printf("Ack(4,0): %d\n" , Ack(4,0));
    printf("Ack(5,0): %d\n" , Ack(5,0));
    printf("Ackrec(0,0): %d\n" , Ackrec(0,0));
    printf("Ackrec(1,0): %d\n" , Ackrec(1,0));
    printf("Ackrec(2,0): %d\n" , Ackrec(2,0));
    printf("Ackrec(3,0): %d\n" , Ackrec(3,0));
    printf("Ackrec(4,0): %d\n" , Ackrec(4,0));
    printf("Ackrec(5,0): %d\n" , Ackrec(5,0));

    printf("Ack(5,3): %d\n" , Ack(2,3));
    printf("Ackrec(5,3): %d\n" , Ackrec(3,3));
    */

    /***question 4***/
     //printf("suiteXrec(int n): %f\n" , suiteXrec(2));



    return 0;
}

