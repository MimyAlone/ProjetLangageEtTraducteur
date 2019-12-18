%{
/* Fichier projet.lex */
/* Section en C : Declarations de constantes et de variables
                  Insertions de bibliotheques */
#include "yystype.h"
#include "yygrammar.h"
char err[40];

%}

/* Definition de macros */
lettre [0-9a-zA-Z:;,.\-'\(\)éèàùîê]
separateur [ \t]

%%
\}                          {
/*                                 printf("Fin"); */
                                return PARFER ;
                            }
"\\begin\{document\}"       {
/*                                 printf("Début de document"); */
                                return DEBUTDOC;
                            } /* Début du document */
"\\end\{document\}"         {
/*                                 printf("Fin de document"); */
                                return FINDOC;
                            } /* Fin du document */
"\\title\{"                 {
/*                                 printf("Définition de titre\n"); */
                                return TITREDOC_DEB;
                            } /*Définition du titre */
"\\author\{"                 {
/*                                 printf("Définition de l'auteur\n"); */
                                return AUTEURDOC_DEB;
                            } /* Définit l'auteur du document */
"\\date\{"                  {
/*                                 printf("Définition de la date\n"); */
                                return DATEDOC_DEB;
                            } /* Définit la date du document */
"\\maketitle"               {
/*                                 printf("Nouveau TITRE0\n"); */
                                return TITRE;
                            } /* Génère un titre */
"\\section\{"               {
/*                                 printf("Nouvelle section\n"); */
                                return TITRE1_DEB;
                            } /* Définit un titre de niveau 1 */
"\\subsection\{"            {
/*                                 printf("Nouvelle sous section\n"); */
                                return TITRE2_DEB;
                            } /* Définit un titre de niveau 2 */
"\\subsubsection\{"         {
/*                                 printf("Nouvelle sous sous section\n"); */
                                return TITRE3_DEB;
                            } /* Définit un titre de niveau 3 */
"\\textbf\{"                {
/*                                 printf("Début gras\n"); */
                                return GRAS;
                            } /* Définit une zone de gras */
"\\textit\{"                {
/*                                 printf("Début italique\n"); */
                                return ITALIQUE;
                            } /* Définit une zone en italique */
"\\begin\{itemize\}"        {
/*                                 printf("Début liste non numéroté\n"); */
                                return LISTENONNUM_DEB;
                            } /* Définit une zone de liste non numéroté */
"\\end\{itemize\}"          {
/*                                 printf("Fin liste non numerote\n"); */
                                return LISTENONNUM_FIN;
                            } /*  Finit une zone de liste non numéroté */
"\\begin\{enumerate\}"      {
/*                                 printf("Début liste numerote\n"); */
                                return LISTENUM_DEB;
                            } /* Définit une zone de liste numéroté */
"\\end\{enumerate\}"        {
/*                                 printf("Fin liste numerote\n"); */
                                return LISTENUM_FIN;
                            } /*  Finit une zone de liste numéroté */
"\\item"                    {
/*                                 printf("nouvel élément liste\n"); */
                                return ITEM;
                            } /* Définit un élement d'une liste */
"\\"                        {
/*                                 printf("Retour à la ligne\n"); */
                                return ANTISLASH;
                            } /* Passage à une nouvelle ligne */
"\\ldots"                   {
/*                                 printf("Suspension\n"); */
                                return SUSPENSION;
                            } /* Point de suspension */
{lettre}+                 {  yylval.texte= (char *) malloc(strlen(yytext+1)) ; strcpy(yylval.texte,yytext) ;
                                return mot;
                            }
{separateur}+               ;
\n                          yypos++ ;
                            
.                           {sprintf(err,"Mauvais caractere %c",yytext[0]);
                            yyerror(err);
                            }
%%

/* Section des fonctions auxiliaires C */
