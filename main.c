#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct bloc_image {
    bool toutnoir ;
    struct bloc_image * fils[4] ;
} bloc_image ;

typedef bloc_image *image ;


void bis_print_profondeur(image i, int p);

image construit_blanc(){
    return NULL;
}
image construit_noir(){
    image i = (image) malloc(sizeof(image));
    i->toutnoir= true;
    i->fils[0]= NULL;
    i->fils[1]= NULL;
    i->fils[2]= NULL;
    i->fils[3]= NULL;
    return i;
}
image construit_composee(image ihg,image ihd,image ibg,image ibd){
    image i = (image) malloc(sizeof(image));
    i->toutnoir= false;
    i->fils[0]= ihg;
    i->fils[1]= ihd;
    i->fils[2]= ibg;
    i->fils[3]= ibd;
    return i;
}

//just 4 fun
void free_image(image i){
    if(i!=NULL){
        if(i->toutnoir){
            free(i);
        }
        else{
            free_image(i->fils[0]);
            free_image(i->fils[1]);
            free_image(i->fils[2]);
            free_image(i->fils[3]);
            free(i);
        }
    }
}

void print_normal(image i){
    if (i == NULL) {
        printf("B");
    }
    else {
        if (i->toutnoir) {
            printf("N");
        }
        else {
            printf("+");
            print_normal(i->fils[0]);
            print_normal(i->fils[1]);
            print_normal(i->fils[2]);
            print_normal(i->fils[3]);
        }
    }
}


void print_profondeur(image i){
    bis_print_profondeur(i,0);
}
void bis_print_profondeur(image i, int p){
    if(i==NULL){
        printf("B%d",p);
    }
    else{
        if(i->toutnoir){
            printf("N%d",p);
        }
        else{
            printf("+%d",p);
            bis_print_profondeur(i->fils[0],p+1);
            bis_print_profondeur(i->fils[1],p+1);
            bis_print_profondeur(i->fils[2],p+1);
            bis_print_profondeur(i->fils[3],p+1);
        }
    }
}


bool estBlanche(image i){
    if(i==NULL){
        return true;
    }
    else{
        if(i->toutnoir){
            return false;
        }
        else{
            return estBlanche(i->fils[0]) && estBlanche(i->fils[1]) && estBlanche(i->fils[2]) && estBlanche(i->fils[3]);
        }
    }
}
bool estNoire(image i){
    if(i==NULL){
        return false;
    }
    else{
        if(i->toutnoir){
            return true;
        }
        else{
            return estNoire(i->fils[0]) && estNoire(i->fils[1]) && estNoire(i->fils[2]) && estNoire(i->fils[3]);
        }
    }
}




int main() {
    /*
    image b = construit_blanc();
    image n = construit_noir();

    print_normal(n);
    printf("\n");
    print_profondeur(n);
    printf(estNoire(n) ? "true" : "false");
    printf(estBlanche(b) ? "true" : "false");
    */
    return 0;
}