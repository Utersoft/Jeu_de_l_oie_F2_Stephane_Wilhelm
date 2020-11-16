#include <stdio.h>
#include <stdlib.h>
#include <time.h>




/*
//ALGORITHME : Jeu de l'oie
//BUT : Coder le jeu de l'oie en langage C
//ENTREE : La touche entrée pour passer les étapes
//SORTIE : Les cases, les effets de cases, la victoire

const plateau <- 66 : ENTIER
const caseMort <- 58 : ENTIER
const caseDepart <- 0 : ENTIER
const caseOie <- 9 : ENTIER
const nonCaseOie <- 63 : ENTIER

//Fonction du lancé de dé
Fonction lanceDe : ENTIER

//BUT : cette fonction permet de faire deux lancés de dés et de renvoyer le résultat des deux dés.
//ENTREE : /
//SORTIE : /

DEBUT
    lanceDe <- ALEA(10) + 2
    //On ajoute +2 pour être sur que le résultat du dé est compris entre 2 et 12
FINFONCTION

//Fonction de vérification du type de case
Fonction verifCase (caseJoueur : ENTIER, de : ENTIER) : ENTIER

//BUT : définir les bonus/malus octroyés par certaines cases
//ENTREE : la case du joueur et le résultat des dés
//SORTIE : /

var changementCase <- 0 :ENTIER

DEBUT
    SI ((caseJoueur % caseOie = 0) ET (caseJoueur <> nonCaseOie))
    DEBUT
        changementCase <- caseJoueur + de
        //On vérifie si la case est un multiple de 9 et non = à 63 et si c'est le cas, on ajoute à nouveau le résultat du dé
    SINON SI (caseJoueur > plateau)
    DEBUT
        changementCase <- plateau - (caseJoueur - plateau)
        //Si on dépasse la taille du plateau, on revient en arrière
    FINSI

    SI ((caseJoueur = caseMort) OU (changementCase = caseMort))
    DEBUT
        changementCase <- caseDepart
        //Si le joueur arrive à la case 58 on retourne 0 pour le remettre à la case de départ
    FINSI

    verifCase <- changementCase
FINFONCTION

var resDe <- 0, caseJoueur <- 0 : ENTIER

DEBUT
    ECRIRE "Bienvenue au jeu de l'oie.
    FAIRE
    DEBUT
        ECRIRE "Vous êtes sur la case " + caseJoueur
        ECRIRE "Veuilez appuyer sur entrer pour continuer
        LIRE
        resDe <- lanceDe
        caseJoueur <- caseJoueur + resDe
        caseJoueur <- verifCase(caseJoueur, resDe)
    TANT QUE (caseJoueur <> plateau)
    ECRIRE "Bravo, vous avez gagné"
FIN





*/
#define intervalle 11
#define plateau 66
#define caseMort 58
#define caseDepart 0
#define caseOie 9
#define nonCaseOie 63

int nombreAlea();
int lanceDe();
int verifCase(int caseJoueur, int de);



int main()
{
    int n_resDe = 0, n_caseJoueur = 0, n_tour = 1;
    srand(time(NULL));
    printf("Bienvenue au jeu de l'oie.\n");
    //il s'agit de la boucle principale. Elle répéte les actions jusqu'à ce que le joueur gagne
    do{
        printf("\nDebut du tour %d. Vous etes sur la case %d.\n", n_tour, n_caseJoueur);
        system("pause");
        n_resDe = lanceDe();
        printf("Vous avez fait un %d.\n", n_resDe);
        system("pause");
        n_caseJoueur = n_caseJoueur + n_resDe;
        n_caseJoueur = verifCase(n_caseJoueur, n_resDe);
        n_tour++;
    }while(n_caseJoueur != plateau);
    printf("Bravo, vous avez gagne! Vous avez atteint la case %d\n", plateau);


    return 0;
}

//Cette fonction retourne un nombre aléatoire
int nombreAlea(){
    return (rand() % intervalle) + 2;
}

//Cette fonction lance le dé
int lanceDe(){
    return nombreAlea();
}

//Cette fonction permet de vérifier les bonus/malus de la case où se trouve le joueur
int verifCase(int caseJoueur, int de){
    int changementCase = caseJoueur;


    if ((changementCase % caseOie == 0) && (changementCase != nonCaseOie) && (changementCase < plateau)){
        printf("Vous etes sur la case %d.", changementCase);
        changementCase = caseJoueur + de;
        printf("Il s'agit d'une case oie, votre resultat de de est double !\n");
        system("pause");
        //On vérifie si la case est un multiple de 9 et non = à 63 et si c'est le cas, on ajoute à nouveau le résultat du dé
    }
    else if (caseJoueur > plateau){
        changementCase = plateau - (caseJoueur - plateau);
        printf("Vous depassez la taille du plateau, retour en arriere sur la case %d.\n", changementCase);
        system("pause");
        //Si on dépasse la taille du plateau, on revient en arrière
    }

    if (changementCase == caseMort){
        changementCase = caseDepart;
        printf("Vous etes sur la case tete de mort. Vous vous retrouvez a la case de depart.\n");
        system("pause");
        //Si le joueur arrive à la case 58 on retourne 0 pour le remettre à la case de départ
        //On le test à la fin pour prendre en compte d'autres éventuels changement
    }
    return changementCase;
}


