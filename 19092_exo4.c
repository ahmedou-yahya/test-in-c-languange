//EXO4: Structure et liste chainees


#include<stdio.h>
#include<stdlib.h>

//#Question1:
#include "19092_exo4.h"

//#Question2:

void afficheListe(struct Etudiant *L);

void ajoutEtudiant(struct Etudiant *L, int id);

void supEtudiant(struct Etudiant *L,int id);

int main(){

struct Etudiant* e1;
struct Etudiant* e2;
struct Etudiant* e3;

e1=malloc(sizeof(struct Etudiant*));
e2=malloc(sizeof(struct Etudiant*));
e3=malloc(sizeof(struct Etudiant*));

e1->id=19014;
e1->suivant=e2;

e2->id=19052;
e2->suivant=e3;

e3->id=19092;
e3->suivant=NULL;

afficheListe(e1);
printf("\n");

ajoutEtudiant(e1,19020);

supEtudiant(e1,19052); 

afficheListe(e1);
printf("\n");

//printf("\n%d\n",e1->id);
//printf("%d\n",e2->id);
//printf("%d\n",e3->id);
}

//#Question3:

void afficheListe(struct Etudiant *L){

struct Etudiant* p;

p=L->suivant;

printf("%d->",L->id);

while(p!=NULL){

	if(p->suivant!=NULL)

		printf("%d->",p->id);

	else

		printf("%d",p->id);

	p=p->suivant;

}

}


//#Question4:
void ajoutEtudiant(struct Etudiant *L, int id){

struct Etudiant* e;

struct Etudiant* p;

e=malloc(sizeof(struct Etudiant*));

e->id=id;

p=L;

while(p!=NULL && (p->suivant->id)>(e->id)){

/*

     _______               _______             _______ 
    |   19014  |____\  |   19052 |____\|   19092  |____\ NULL
    |_______|         /  |_______|        / |_______|         / 
*/
e->suivant=p->suivant;
/*
     _______              _______             _______ 
    |   19014  |____\ |   19052 |____\ |   19092 |____\ NULL
    |_______|         / |_______|        / |_______|         / 
                        / \
                         |
                         |
                    __|___
                 |   19020  |
                 |_______|
*/
p->suivant=e;
/*
     _______          _______             _______             _______ 
    |   19014 |___\|   19020 |____\|   19052  |____\ |   19092 |____\ NULL
    |_______|      /|_______|        / |_______|         / |_______|        / 
*/
}
p=p->suivant;
}


//#Question5:
void supEtudiant(struct Etudiant *L,int id){

struct Etudiant *p;
struct Etudiant *precedent;

p=L;

while (p!=NULL && p->id!=id){

precedent=p;

p=p->suivant;

}
//Dans le cas ou L est une liste vide:
if(p==NULL)
	return;
//Dans le cas ou on trouve l'entier id:

precedent->suivant=p->suivant;

/*                                   __________________________
     _______          ___|____             _______             ___|___ 
    |   19014 |___\|   19020 |____\|   19052  |____\ |   19092 |____\ NULL
    |_______|      /|_______|        / |_______|         / |_______|        / 
*/
free(p);
/*
     _______          _______              _______ 
    |   19014 |___\|   19020 |____\|   19092  |____\ NULL
    |_______|      /|_______|        / |_______|         /      
*/
}
