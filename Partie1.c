#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*********question 1: e = ∑∞n=0 1/n!***********/
/**< fonction récursive simple avec fonction auxiliaire */
float fact_div_aux(int n){
    if (n==0){return 1.0;}
    else return (1.0/n)*fact_div_aux(n-1);
}

float fact_div(int n){
    if(n==0){return fact_div_aux(n);}
    else {return fact_div_aux(n)+fact_div(n-1);}
}

/**< amélioration: de la précision avec double et du temps d'éxécution avec la fonction récursive terminale */

double fact_div_auxT(int n, double acc){
    if (n==0){return acc;}
    else return fact_div_auxT(n-1, acc*(1.0/n));
}

double fact_divT(int n){
    if(n==0){return fact_div_auxT(n,1);}
    else {return fact_div_auxT(n,1)+fact_divT(n-1);}
}

/*********question 2: Puissance***********/

//itérative
float puissanceI(int n, float x){
    float a = 1;

    if (n > 0)
        for(int i = 0; i<n; i++) a = a*x;

    else if (n < 0)
        for(int i = n; i<0; i++) a = a*(1.0/x);

    return a;

}

//récursive
float puissanceR(int n, float x){
    if (n == 0)
        return 1;

    else if (n>0)
        return x*puissanceR(n-1,x);

    else
        return (1/x)*puissanceR(n+1,x);

}
/**< amélioration moins de couche dans la pile de mémoire et précision avec double */
//récursif 2^p= 2(n*2)
double puissanceR2(int n, double x){
    if(n == 0) return 1;
    else if (n > 0){
        if (n%2 == 0) return puissanceR2(n/2,x)*puissanceR2(n/2,x);
        else return puissanceR2(n/2,x)*puissanceR2(n/2,x)*x;
    }
    else{
        if (n%2 == 0) return puissanceR2(n/2,x)*puissanceR2(n/2,x);
        else return puissanceR2(n/2,x)*puissanceR2(n/2,x)*(1.0/x);
    }
}

/**< amélioration précision avec double et temps de calcul */
//récursive terminale
double puissanceRTaux(int n, double x, double acc){
    if(n == 0) return acc;
    else if (n > 0) return puissanceRTaux(n-1, x, acc*x);
    else return puissanceRTaux(n+1, x,(1.0/x)*acc);
}

double puissanceRT(int n, double x){
    return puissanceRTaux(n, x, 1.0);
}



/*********question 3: Ackermann***********/

//méthode 1
int Ack(int m, int n){
    int res;
    if (m == 0) return n+1;
    else {
        res=1;
        for(int i = 0; i<(n+1); i++){res = Ack(m-1,res);}
    }
    return res;
}

//m&thode 2
int Ackrec(int m, int n){
    if (m == 0) return n+1;
    else if (n == 0) return Ackrec(m-1, 1);
    else return Ackrec(m-1, Ackrec(m,n-1));

}


/*********question 4: Suite***********/

//itérative
double suiteX(int n){
    double res = 1;
    if (n == 0) res = 1;
    else for(int i = 0; i<n; i++) res = res + (1.0/res);
    return res;
}

//récursive

double suiteXrec(int n){
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

    int test = 30000;
    printf("fact_divT de %d: %f\n" , test, fact_divT(test));
    printf("fact_div de %d: %f\n" , test, fact_div(test));
*/
    /***question 2***/ //calculer (1 + 10^-k )^(10^k)/
/*  printf("puissanceI(-3,5.0): %f\n" , puissanceI(-3,5.0));
    printf(" puissanceR(-3,5.0): %f\n" , puissanceR(-3,5.0));
    printf(" puissanceR2(-5,5.0): %f\n" , puissanceR2(-3,5.0));
    printf(" puissanceRT(-3,5.0): %f\n" , puissanceRT(-3,5.0));

    int k = 6;
    printf("k = %d; 10^k = %f \n", k, puissanceI(k,10));

    //printf("(1 + 10^-k )^(10^k) iterative: %f\n" , puissanceI(puissanceI(k,10),1.0+puissanceI(-k,10)));
    //printf("(1 + 10^-k )^(10^k) recursive: %f\n" , puissanceR(puissanceR(k,10),1+puissanceR(-k,10)));
    printf("(1 + 10^-k )^(10^k) recursive p=2n: %f\n" , puissanceR2(puissanceR2(k,10),1.0+puissanceR2(-k,10)));
    //printf("(1 + 10^-k )^(10^k) recursive terminale: %f\n" , puissanceRT(puissanceRT(k,10),1.0+puissanceRT(-k,10)));

    clock_t begin = clock();
    printf("(1 + 10^-k )^(10^k) recursive p=2n: %f\n" , puissanceR2(puissanceR2(k,10),1.0+puissanceR2(-k,10)));
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time: %f\n", time_spent);
*/
    /***question 3***/ //Ackermann
/*
    printf("Ack(0,0): %d\n; Ack(1,0): %d\n; Ack(2,0): %d\n; Ack(3,0): %d\n; Ack(4,0): %d\n; Ack(5,0): %d\n" ,
            Ack(0,0), Ack(1,0),Ack(2,0),Ack(3,0),Ack(4,0), Ack(5,0));//6 secondes

    printf("Ackrec(0,0): %d\n; Ackrec(1,0): %d\n; Ackrec(2,0): %d\n; Ackrec(3,0): %d\n; Ackrec(4,0): %d\n" ,
           Ackrec(0,0), Ackrec(1,0),Ackrec(2,0),Ackrec(3,0),Ackrec(4,0)); //6 secondes mais sans m=5

    printf("Ack(2,3): %d; Ackrec(2,3): %d\n" , Ack(2,3), Ackrec(2,3));
    printf("Ack(3,4): %d; Ackrec(3,4): %d\n" , Ack(3,4), Ackrec(3,4));
*/

    /***question 4***/
/*
     printf("suiteXrec(0): %f\n" , suiteXrec(0));
     printf("suiteXrec(1): %f\n" , suiteXrec(1));
     printf("suiteXrec(2): %f\n" , suiteXrec(2));
     printf("suiteXrec(3): %f\n" , suiteXrec(3));
     printf("suiteXrec(5): %f\n" , suiteXrec(5));
     printf("suiteXrec(10): %f\n" , suiteXrec(10));
     printf("suiteXrec(50): %f\n" , suiteX(50));
     printf("suiteXrec(100): %f\n" , suiteX(100));

*/

    return 0;
}
