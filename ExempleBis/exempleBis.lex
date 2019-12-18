%{
/* Fichier exemple.lex */
/* Section en C : Declarations de constantes et de variables
                  Insertions de bibliotheques */

/* Declaration de l action d affichage des entiers */
void afficher_entier(char *ent);

/* Declaration de l action d affichage des reels */
void afficher_reel(char *reel);

/* Declaration de l action d affichage des identificateurs */
void afficher_id(char *id);

%}

/* Definition de macros */
separateur [ \t\n]
chiffre [0-9]
lettre [a-zA-Z]

%%
"+"                     { printf ("Addition\n"); }
"-"                     { printf ("Soustraction\n"); }
":="                    { printf ("Affectation\n"); }
{chiffre}+              { afficher_entier(yytext); }
{chiffre}*\.{chiffre}+  {   afficher_reel(yytext); }
{lettre}+		{ afficher_id(yytext); }
id                      { printf ("Mot id trouve\n"); }
{separateur}+           ;
.                       printf("Mauvais caractere : %c\n",yytext[0]);
%%

/* Section des fonctions auxiliaires C */

void afficher_entier(char *ent){
   /* La chaine de caracteres ent contient une suite de chiffres
      L'instruction atoi convertit cette chaine en un entier */
   printf ("Entier : %d\n",atoi(ent));
}

void afficher_reel(char *reel){
   /* La chaine de caracteres reel contient une suite de chiffres suivie d un point et d une suite de chiffres
      L'instruction atof convertit cette chaine en un reel */
   printf ("Reel : %.2f\n",atof(reel));
}

void afficher_id(char *id){
   /* La chaine de caracteres id contient une suite de lettres */
   printf ("Identificateur : %s\n",id);
}
