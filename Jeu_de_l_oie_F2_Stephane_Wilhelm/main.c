#include <stdio.h>
#include <stdlib.h>
#include <time.h>




/*
//ALGORITHME : Jeu de l'oie
//BUT : Coder le jeu de l'oie en langage C
//ENTREE : La touche entr�e pour passer les �tapes
//SORTIE : Les cases, les effets de cases, la victoire

const plateau <- 66 : ENTIER
const caseMort <- 58 : ENTIER
const caseDepart <- 0 : ENTIER
const caseOie <- 9 : ENTIER
const nonCaseOie <- 63 : ENTIER

//Fonction du lanc� de d�
Fonction lanceDe : ENTIER

//BUT : cette fonction permet de faire deux lanc�s de d�s et de renvoyer le r�sultat des deux d�s.
//ENTREE : /
//SORTIE : /

DEBUT
    lanceDe <- ALEA(10) + 2
    //On ajoute +2 pour �tre sur que le r�sultat du d� est compris entre 2 et 12
FINFONCTION

//Fonction de v�rification du type de case
Fonction verifCase (caseJoueur : ENTIER, de : ENTIER) : ENTIER

//BUT : d�finir les bonus/malus octroy�s par certaines cases
//ENTREE : la case du joueur et le r�sultat des d�s
//SORTIE : /

var changementCase <- 0 :ENTIER

DEBUT
    SI ((caseJoueur % caseOie = 0) ET (caseJoueur <> nonCaseOie))
    DEBUT
        changementCase <- caseJoueur + de
        //On v�rifie si la case est un multiple de 9 et non = � 63 et si c'est le cas, on ajoute � nouveau le r�sultat du d�
    SINON SI (caseJoueur > plateau)
    DEBUT
        changementCase <- plateau - (caseJoueur - plateau)
        //Si on d�passe la taille du plateau, on revient en arri�re
    FINSI

    SI ((caseJoueur = caseMort) OU (changementCase = caseMort))
    DEBUT
        changementCase <- caseDepart
        //Si le joueur arrive � la case 58 on retourne 0 pour le remettre � la case de d�part
    FINSI

    verifCase <- changementCase
FINFONCTION

var resDe <- 0, caseJoueur <- 0 : ENTIER

DEBUT
    ECRIRE "Bienvenue au jeu de l'oie.
    FAIRE
    DEBUT
        ECRIRE "Vous �tes sur la case " + caseJoueur
        ECRIRE "Veuilez appuyer sur entrer pour continuer
        LIRE
        resDe <- lanceDe
        caseJoueur <- caseJoueur + resDe
        caseJoueur <- verifCase(caseJoueur, resDe)
    TANT QUE (caseJoueur <> plateau)
    ECRIRE "Bravo, vous avez gagn�"
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
    //il s'agit de la boucle principale. Elle r�p�te les actions jusqu'� ce que le joueur gagne
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

//Cette fonction retourne un nombre al�atoire
int nombreAlea(){
    return (rand() % intervalle) + 2;
}

//Cette fonction lance le d�
int lanceDe(){
    return nombreAlea();
}

//Cette fonction permet de v�rifier les bonus/malus de la case o� se trouve le joueur
int verifCase(int caseJoueur, int de){
    int changementCase = caseJoueur;


    if ((changementCase % caseOie == 0) && (changementCase != nonCaseOie) && (changementCase < plateau)){
        printf("Vous etes sur la case %d.", changementCase);
        changementCase = caseJoueur + de;
        printf("Il s'agit d'une case oie, votre resultat de de est double !\n");
        system("pause");
        //On v�rifie si la case est un multiple de 9 et non = � 63 et si c'est le cas, on ajoute � nouveau le r�sultat du d�
    }
    else if (caseJoueur > plateau){
        changementCase = plateau - (caseJoueur - plateau);
        printf("Vous depassez la taille du plateau, retour en arriere sur la case %d.\n", changementCase);
        system("pause");
        //Si on d�passe la taille du plateau, on revient en arri�re
    }

    if (changementCase == caseMort){
        changementCase = caseDepart;
        printf("Vous etes sur la case tete de mort. Vous vous retrouvez a la case de depart.\n");
        system("pause");
        //Si le joueur arrive � la case 58 on retourne 0 pour le remettre � la case de d�part
        //On le test � la fin pour prendre en compte d'autres �ventuels changement
    }
    return changementCase;
}


