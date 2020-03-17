    /* 

     * Programme C  pour construire un Arbre Binaire de Recherche, ajouter un noeud, supprimer un neoud, affiche le en ordre croissant.

     */ 

    #include <stdio.h>

    #include <stdlib.h>
	#include "19092_exo5.h"
     
    void supprimer1();

    void inserer();

    void supprimer();

    void afficher(struct noeud *t);

    void creer();

    void chercher(struct noeud *t); /* chercher pour l'insertion */


    void chercher1(struct noeud *t,int nbre); /* chercher pour la suppression */

    int plusPetit(struct noeud *t);

    int plusGrand(struct noeud *t);

     

    int flag = 1;

     

    void main()

    {

        int ch;

     

        printf("\nOPERATIONS ---");

        printf("\n1 - Inserer un element dans l'arbre\n");

        printf("2 - Supprimer un element de l'arbre\n");

        printf("3 - Afficher l'arbre en ordre\n");

        printf("4 - Quitter\n");

        while(1)

        {

            printf("\nEntrer votre choix : ");

            scanf("%d", &ch);

            switch (ch)

            {

            case 1:    

                inserer();

                break;

            case 2:    

                supprimer();

                break;

            case 3:    

                afficher(racine);

                break;

            case 4:    

                exit(0);

            default :     

                printf("Mauvais choix, Entrer un bon choix  ");

                break;    

            }

        }

    }

     

    /* Pour inserer un noeud*/

    void inserer()

    {

        creer();

        if (racine == NULL) 

            racine = temp;

        else    

            chercher(racine);    

    }

     

    /* creer un noeud */

    void creer()

    {

        int nbre;

     

        printf("Entrer le nombre que vous allez inserer : ");

        scanf("%d", &nbre);

        temp = malloc(sizeof(struct noeud*));

        temp->valeur = nbre;

        temp->g = temp->d = NULL;

    }

     

    /*  Chercher la posion appropriee pour l'insertion du nouvel noeud */

    void chercher(struct noeud *t)

    {

        if ((temp->valeur > t->valeur) && (t->d != NULL))      /* valeur plus grand que la valeur du noeud racine inserer a droite */

            chercher(t->d);

        else if ((temp->valeur > t->valeur) && (t->d == NULL))

            t->d = temp;

        else if ((temp->valeur < t->valeur) && (t->g != NULL))    /*valeur plus petit que la valeur du noud racine inserer a gauche */

            chercher(t->g);

        else if ((temp->valeur < t->valeur) && (t->g == NULL))

            t->g = temp;

    }

     

    /* Une fonction recursive qui affiche l'arbre en ordre croissante */

    void afficher(struct noeud *t)

    {

        if (racine == NULL)

        {

            printf("l'arbre ne contient aucun element");

            return;

        }

        if (t->g != NULL)    

            afficher(t->g);

        printf("%d -> ", t->valeur);

        if (t->d != NULL)    

            afficher(t->d);

    }

     

    /* Pour supprimer */

    void supprimer()

    {

        int nbre;

     

        if (racine == NULL)

        {

            printf("Pas d'element  dans l'arbre pour le supprimer");

            return;

        }

        printf("Entrer le nombre que vous voulez le supprimer : ");

        scanf("%d", &nbre);

        t1 = racine;

        t2 = racine;

        chercher1(racine, nbre);

    }

    /* chercher la place appropriee pour la suppression */

    void chercher1(struct noeud *t, int nbre)

    {

        if ((nbre>t->valeur))

        {

            t1 = t;

            chercher1(t->d, nbre);

        }

        else if ((nbre < t->valeur))

        {

            t1 = t;

            chercher1(t->g, nbre);

        }

        else if ((nbre==t->valeur))

        {

            supprimer1(t);

        }

    }

     

    /* Supprimer un noeud */

    void supprimer1(struct noeud *t)

    {

        int k;

     

        /* Pour supprimer une feuille */

        if ((t->g == NULL) && (t->d == NULL))

        {

            if (t1->g == t)

            {

                t1->g = NULL;

            }

            else

            {

                t1->d = NULL;

            }

            t = NULL;

            free(t);

            return;

        }

     

        /* Supprimer un noeud qui a un seul fils a gauche */

        else if ((t->d == NULL))

        {

            if (t1 == t)

            {

                racine = t->g;

                t1 = racine;

            }

            else if (t1->g == t)

            {

                t1->g = t->g;

     

            }

            else

            {

                t1->d= t->g;

            }

            t = NULL;

            free(t);

            return;

        }

     

        /* Supprimer un noeud qui a seul fils a droite */

        else if (t->g == NULL)

        {

            if (t1 == t)

            {

                racine = t->d;

                t1 = racine;

            }

            else if (t1->d == t)

                t1->d = t->d;

            else

                t1->g= t->g;

            t == NULL;

            free(t);

            return;

        }

     

        /* Supprimer un noeud qui a deux fils */

        else if ((t->g != NULL) && (t->d != NULL))  

        {

            t2 = racine;

            if (t->d != NULL)

            {

                k = plusPetit(t->d);

                flag = 1;

            }

            else

            {

                k =plusGrand(t->g);

                flag = 2;

            }

            chercher1(racine, k);

            t->valeur = k;

        }

     

    }

     

    /* Trouver l'element le plus petit dans le sous-arbre gauche */

    int plusPetit(struct noeud *t)

    {

        t2 = t;

        if (t->g != NULL)

        {

            t2 = t;

            return(plusPetit(t->g));

        }

        else    

            return (t->valeur);

    }

     

    /* Trouver l'element le plus grand dans le sous-arbre droite */

    int plusGrand(struct noeud *t)

    {

        if (t->d != NULL)

        {

            t2 = t;

            return(plusGrand(t->d));

        }

        else    

            return(t->valeur);

    }
