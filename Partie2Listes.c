
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*************************************************/
/*                                               */
/*                sucre syntaxique               */
/*                                               */
/*************************************************/

#define AND &&
#define OR ||
#define ISNOT !=
#define NOT !
#define then

//typedef enum { FALSE, TRUE} bool;

/*************************************************/
/*                                               */
/*          definition type liste                */
/*                                               */
/*************************************************/

typedef struct Bloc
{
    int nombre;
    struct Bloc *suivant;
} Bloc;

typedef Bloc *Liste ;

/*************************************************/
/*                                               */
/*                predeclarations                */
/*                                               */
/*************************************************/

/* initialise une Liste à vide */
void initVide(Liste *L);

/* renvoie 1 si la Liste en parametre est vide, 0 sinon */
bool estVide(Liste l);

/* renvoie le premier element de la Liste en parametre */
int premier(Liste l);

/* renvoie une nouvelle Liste correspondant a celle en parametre, avec l'element x ajoute en haut de la pile */
Liste ajoute(int x, Liste l);

/* modifie la Liste en parametre: x est ajoute comme premier element */
void empile(int x, Liste* L);

/* renvoie une nouvelle Liste correspondant a celle en parametre sans son premier element */
Liste suite(Liste l);

/* modifie la Liste en parametre: le premier element est retire */
void depile(Liste* l);

/* affichage simple en recursif et en iteratif */
void affiche_rec(Liste l);
void affiche_iter(Liste l);

/* longueur en recursif et en iteratif */
int longueur_rec (Liste l);
int longueur_iter (Liste l);

/*  Elimination du dernier element en recursif et en iteratif  */
/*  VD est la sousprocedure utilitaire de la version recursive */
void VD (Liste *L);
void VireDernier_rec (Liste *L);
void VireDernier_iter (Liste *L);


/*************************************************/
/*                                               */
/*                briques de base                */
/*                                               */
/*************************************************/


void initVide( Liste *L)
{
    *L = NULL ;
}

bool estVide(Liste l)
{
    return l == NULL ;
}

int premier(Liste l)
{
    return l->nombre ;
}

Liste ajoute(int x, Liste l)
{
    Liste tmp = (Liste) malloc(sizeof(Bloc)) ;
    tmp->nombre = x ;
    tmp->suivant = l ;
    return tmp ;
}

void empile(int x, Liste *L)
{
      *L = ajoute(x,*L) ;
}

Liste suite(Liste l)
{
    return l->suivant ;
}


void depile(Liste *L)
{
    Liste tmp = *L ;
    *L = suite(*L) ;
    free(tmp) ;
}

/*************************************************/
/*                                               */
/*     Affiche, avec les briques de base         */
/*                                               */
/*************************************************/

void affiche_rec(Liste l)
{
    if(estVide(l))
        printf("\n");
    else
    {
        printf("%d ", premier(l));
        affiche_rec(suite(l));
    }
}


void affiche_iter(Liste l)
{
    Liste L2 = l;
    while(!estVide(L2))
    {
        printf("%d ", premier(L2));
        L2 = suite(L2);
    }
    printf("\n");
}

/*************************************************/
/*                                               */
/*     Longueur, sans les briques de base        */
/*                                               */
/*************************************************/

int longueur_rec (Liste l)
{
    if (l == NULL)
         return 0 ;
    else return (1 + longueur_rec(l->suivant)) ;
}


int longueur_iter (Liste l)
{
    Liste P = l;
    int cpt = 0 ;
    while (P ISNOT NULL)
    {   P = P->suivant ;
        cpt++ ;
    }
    return cpt ;
}

/*************************************************/
/*                                               */
/*       VireDernier,                            */
/*               sans les briques de base,       */
/*               ni le "->"                      */
/*                                               */
/*************************************************/

void VD (Liste *L)
          // *L non NULL ie liste non vide
{
     if ( ((**L).suivant) == NULL )
            depile(L) ;   // moralement : depile(& (*L)) ;
     else VD (& ( (**L).suivant )) ;
}

void VireDernier_rec (Liste *L)
{
     if ( (*L) ISNOT NULL )
          VD(L);        // moralement : VD(& (*L)) ;
}

void VireDernier_iter (Liste *L)
{
    if ( (*L) ISNOT NULL)
    {
        while ( ((**L).suivant) ISNOT NULL )
                 L = & ( (**L).suivant ) ;
        free(*L) ;
        *L = NULL ;
     }
}


/*************************************************/
/*                                               */
/*       Libere la memoire                       */
/*                                               */
/*************************************************/

void VideListe(Liste *L)
{
    if(NOT(estVide(*L)))
    {
        depile(L);
        VideListe(L);
    }

}

/*************************************************/
/*                                               */
/*       Fonction à implémenter                  */
/*                                               */
/*************************************************/
bool ZeroEnDeuxiemePosition(Liste l){
    //vrai sur [2,0,3,6,0] et faux sur [0,2,0,6,0]
    if(!estVide(l) && !estVide(suite(l))) return (0 == premier(suite(l)));
    return false;
}

bool QueDesZeros(Liste l){
    if (estVide(l)) return true;
    else if(premier(l) != 0) return false;
    else return QueDesZeros(suite(l));
    return true;/*essaie d'enlever cette ligne pour voir si
    des que suite de l sera vide ca va faire true ou cette
    ligne est indispensable*/
}
/**récursive sans sous-fonctionnalité et non-terminale **/
/**itérative **/
/**avec sous fonction recursive terminale avec arg supplementaire in **/
/**avec sous procédure récursive terminale avec argument supplémentaire inout **/

int Compte0InitiauxV1(Liste l){
    if (estVide(l)) && (premier(l) != 0) return 0;
    else return 1 + Compte0InitiauxV1(suite(l));
}

int Compte0InitiauxV2(Liste l){
    //not sure
    if (estVide(l)) return 0;
    else {
        int i;
        int premierDEsuite = premier(l);
        for(i = 0;premierDEsuite != 0;i++){
            premierDEsuite = premier(suite(l));
        }
        return i;
    }
}

void Compte0InitiauxV3_aux(Liste l, int *res){
    if (estVide(l)) *res = 0;
    else //(premier(l) == 0)
        Compte0InitiauxV3_aux(suite(l), *res++);
}
int Compte0InitiauxV3(Liste l){
    int res;
    Compte0InitiauxV3_aux(l, &res);
    return res;
}

int Compte0InitiauxV4_aux(Liste l, int res){
    if (estVide(l)) res = 0;
    else if(premier(l) != 0) return res;
    else Compte0InitiauxV4_aux(suite(l), res++);
    return res;
}
int Compte0InitiauxV4(Liste l){
    int res;
    return Compte0InitiauxV4_aux(l, res);
}
/**tentative 1 renverser la liste avec sous-fonction*/
Liste IntersectionTriee(Liste l1, Liste l2){
    if (estVide(l1)) return l2
    else if (estVide(l2)) return l1
    else {
        Liste ll1 = separerLesListes(l1);
        Liste ll2 = separerLesListes(l2);

        Liste ll0 = comparerLesListes(l1,l2);
        return ll0;

    }
}
Liste separerLesListes(Liste l){
    Liste p = l;
    initVide(res);
    int j = 0;
    for(int i=0; estVide(l); i++){
        if(premier(p) == j){

        }
    }
}

/**tentative2 avec renverser la liste itérative*/
Liste reverse(Liste l);//imaginons qu'on l'ai implémenter
Liste IntersectionTriee(Liste l1, Liste l2){
    Liste p = l1;
    Liste q = l2;
    Liste l3 = initVide(l3);
    while(!estVide(p) && !estVide(q)){
        if(premier(p)<premier(q)){
            p = suite(p);
        }
        else if(premier(p)>premier(q)){
            q = suite(q);
        }
        else {
            ajoute(premier(p),l3);
            p = suite(p);
            q = suite(q);
        }
    }
    return reverse(l3);
}

/**tentative 3 sans renverser la liste itérative*/
Liste IntersectionTriee(Liste l1, Liste l2){
    Liste p = l1;
    Liste q = l2;
    Liste l3 = initVide(l3);
    Liste r = l3;
    while(!estVide(p) && !estVide(q)){
        if(premier(p)<premier(q)){
            p = suite(p);
        }
        else if(premier(p)>premier(q)){
            q = suite(q);
        }
        else{
            if(!estVide(r)){
                Liste* head = (Liste) malloc (sizeof(Bloc));
                premier(head) = premier(p);
                l3 = head;
                r = head
                p = suite(p);
                q = suite(q);
            }
            else{
                Liste* tmp = (Liste) malloc (sizeof(Bloc));
                premier(tmp) = premier(p);
                suite(r) = tmp;
                r = tmp;
                p = suite(p);
                q = suite(q);
            }
        }
    }
    return l3;
}

/**tentative 4 sans renverser la liste récursive*/

//utiliser la question du td 2 la fonction pif
/** eliminer <un seul parcours de la liste> permuter **/

Liste ElimineKpremiersX(Liste l, int k, int x){

}

Liste ElimineKderniersX(Liste l, int k, int x){

}

Liste Liste Permutations(Liste l, int k, int x){

}

/** liste circulaire **/
ajoute(in int x, inout file F)
sortir(out int x, inout file F)

/*************************************************/
/*                                               */
/*           Main                                */
/*                                               */
/*************************************************/

void poup (Liste l)
{
        printf("Double Affichage \n") ;
        affiche_rec(l) ;
        affiche_iter(l) ;

        printf("Longueur en double %d %d \n\n",
                           longueur_rec(l),
                           longueur_iter(l)
               ) ;
}

int main(int argc, char** argv)
{
    Liste l ;

        initVide (&l) ;

          poup(l) ;

             empile(4, &l) ;

          poup(l) ;

             empile(5, &l) ;
             empile(6, &l) ;
             empile(7, &l) ;
             empile(8, &l) ;
             empile(9, &l) ;

          poup(l) ;

        VireDernier_rec  (&l) ;
        VireDernier_iter (&l) ;
        depile(& l) ;

          poup(l) ;

    VideListe(&l);
    return 0;
}





