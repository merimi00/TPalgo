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
    float tmp = fact_div_aux(n);
    if(n==0){return tmp;}
    else {return tmp+fact_div(n-1);}
}

/**< amélioration: de la précision avec double et
du temps d'éxécution avec la fonction récursive terminale */

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

    else
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
        double tmp = puissanceR2(n/2,x);
        if (n%2 == 0) return tmp*tmp;
        else return tmp*tmp*x;
    }
    else{
        double tmp = puissanceR2(n/2,x);
        if (n%2 == 0) return tmp*tmp;
        else return tmp*tmp*(1.0/x);
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
    if (n != 0)
        for(int i = 0; i<n; i++)
            res = res + (1.0/res);
    return res;
}

//récursive

double suiteXrec(int n){
    //float a = suiteXrec(n-1);
    if(n == 0) return 1;
    else return suiteXrec(n-1)+(1.0/suiteXrec(n-1));
}


double suiteXrec1(int n){
    double a = 0;
    double b ;
    if(n == 0){
        a += 1;

    }else{
        b = suiteXrec(n-1);
        a += b + (1.0/b);
    }
    return a;
}
/**
double suiteXrecTer(int n){

    double res = 1;
    return suiteXrecTer_aux(n, res);

}

double suiteXrecTer_aux(int n, double res){
    if(n == 0){
        return res;
    }else{
        return suiteXrecTer_aux(n-1, res + (1.0/res) );
    }
}
**/
/*
int main()
{

    //question 1: e = ∑∞n=0 1/n!

    for(int i = 0;i<10;i++){
        printf("fact_div de %d: %f\n" , i, fact_div(i));
    }

    int test = 30000;
    printf("fact_divT de %d: %f\n" , test, fact_divT(test));
    printf("fact_div de %d: %f\n" , test, fact_div(test));

    //question 2 calculer (1 + 10^-k )^(10^k)/
    printf("puissanceI(-3,5.0): %f\n" , puissanceI(-3,5.0));
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

    //question 3 Ackermann

    for(int i = 0; i<5; i++){
        printf("Ack(%d,0): %d\n" , i, Ack(i,0));//6 secondes
        printf("Ackrec(0,0): %d\n" ,i, Ackrec(i,0)); //6 secondes mais sans m=5
    }

    printf("Ack(2,3): %d; Ackrec(2,3): %d\n" , Ack(2,3), Ackrec(2,3));
    printf("Ack(3,4): %d; Ackrec(3,4): %d\n" , Ack(3,4), Ackrec(3,4));


    //question 4

    for(int i = 40;i<50;i++){
        //printf("suiteXrec(%d): %f\n" , i, suiteXrec(i));
        printf("suiteX(%d): %f\n" , i, suiteX(i));
        //printf("suiteXrec1(%d): %f\n" , i, suiteXrec1(i));
    }

     printf("suiteX(100): %f\n" , suiteX(100));
     printf("suiteXrecTer(100): %f\n" , suiteXrecTer(100));


    return 0;
}

*/
