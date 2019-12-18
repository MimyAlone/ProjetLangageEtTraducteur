#line 3 "projet.acc"
 /* Code C */
   /* Inclusion de bibliotheques C */
   #include<stdio.h>
   #include<malloc.h>

   /* Action de fin d analyse */
   void fin_analyse(){
        printf("Fin de traitement \n") ;
        printf("Syntaxe correcte \n") ;
   }

# line 14 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 26: {
      Document();
      get_lexval();
      } break;
   }
}

Document ()
{
   switch(yyselect()) {
   case 1: {
      opts();
      DOC();
#line 21 "projet.acc"
fin_analyse();
# line 35 "yygrammar.c"
      } break;
   }
}

opts ()
{
   switch(yyselect()) {
   case 2: {
      opt();
      opts();
      } break;
   case 3: {
      } break;
   }
}

opt ()
{
   switch(yyselect()) {
   case 4: {
      get_lexval();
      TEXTE();
      get_lexval();
      } break;
   case 5: {
      get_lexval();
      TEXTE();
      get_lexval();
      } break;
   case 6: {
      get_lexval();
      TEXTE();
      get_lexval();
      } break;
   }
}

DOC ()
{
   switch(yyselect()) {
   case 7: {
      get_lexval();
      CONTENU();
      get_lexval();
      } break;
   }
}

TEXTE ()
{
   switch(yyselect()) {
   case 8: {
      get_lexval();
      TEXTE();
      } break;
   case 9: {
      EXP();
      TEXTE();
      } break;
   case 10: {
      get_lexval();
      TEXTE();
      } break;
   case 11: {
      get_lexval();
      TEXTE();
      } break;
   case 12: {
      liste();
      TEXTE();
      } break;
   case 13: {
      } break;
   }
}

EXP ()
{
   switch(yyselect()) {
   case 14: {
      get_lexval();
      TEXTE();
      get_lexval();
      TEXTE();
      } break;
   case 15: {
      get_lexval();
      TEXTE();
      get_lexval();
      TEXTE();
      } break;
   }
}

liste ()
{
   switch(yyselect()) {
   case 16: {
      get_lexval();
      liste_items();
      get_lexval();
      } break;
   case 17: {
      get_lexval();
      liste_items();
      get_lexval();
      } break;
   }
}

liste_items ()
{
   switch(yyselect()) {
   case 18: {
      get_lexval();
      TEXTE();
      liste_items();
      } break;
   case 19: {
      } break;
   }
}

CONTENU ()
{
   switch(yyselect()) {
   case 20: {
      get_lexval();
      CONTENU();
      } break;
   case 21: {
      SECTION();
      CONTENU();
      } break;
   case 22: {
      } break;
   }
}

SECTION ()
{
   switch(yyselect()) {
   case 23: {
      get_lexval();
      TEXTE();
      get_lexval();
      TEXTE();
      } break;
   case 24: {
      get_lexval();
      TEXTE();
      get_lexval();
      TEXTE();
      } break;
   case 25: {
      get_lexval();
      TEXTE();
      get_lexval();
      TEXTE();
      } break;
   }
}

extern YYSTYPE yylval;
YYSTYPE yylval;
extern long yypos;
long yypos = 1;
/* GentleFlag = no */

typedef struct LEXELEMSTRUCT {
   YYSTYPE val;
   long pos;
   long sym;
   char * text;
   struct LEXELEMSTRUCT *next;
} LEXELEM;
   
LEXELEM *first_lexelem, *cur_lexelem;

init_lexelem()
{
   cur_lexelem = first_lexelem;
}

first_lexval () {
   LEXELEM *p;
   p = (LEXELEM *)malloc(sizeof(LEXELEM));
   if (! p) yymallocerror();
   p->val = yylval;
   p->pos = yypos;
   p->next = 0;
   cur_lexelem = p;
   first_lexelem = p;
}

next_lexval() {
   LEXELEM *p;
   p = (LEXELEM *)malloc(sizeof(LEXELEM));
   if (! p) yymallocerror();
   cur_lexelem-> next = p;
   p->val = yylval;
   p->pos = yypos;
   p->next = 0;
   cur_lexelem = p;
}

get_lexval() {
   extern int FREE_LEXELEMS;
   LEXELEM *p;
   yylval = cur_lexelem->val;
   yypos = cur_lexelem->pos;
   p = cur_lexelem;
   cur_lexelem = cur_lexelem->next;
   free(p);
}

extern int c_length;
int c_length = 139;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 26,
/* 6 */ 0,
/* 7 */ 11,
/* 8 */ 37,
/* 9 */ -6,
/* 10 */ 1,
/* 11 */ 16,
/* 12 */ 19,
/* 13 */ 11,
/* 14 */ -11,
/* 15 */ 2,
/* 16 */ 0,
/* 17 */ -11,
/* 18 */ 3,
/* 19 */ 25,
/* 20 */ 50258,
/* 21 */ 43,
/* 22 */ 50261,
/* 23 */ -19,
/* 24 */ 4,
/* 25 */ 31,
/* 26 */ 50260,
/* 27 */ 43,
/* 28 */ 50261,
/* 29 */ -19,
/* 30 */ 5,
/* 31 */ 0,
/* 32 */ 50259,
/* 33 */ 43,
/* 34 */ 50261,
/* 35 */ -19,
/* 36 */ 6,
/* 37 */ 0,
/* 38 */ 50256,
/* 39 */ 106,
/* 40 */ 50257,
/* 41 */ -37,
/* 42 */ 7,
/* 43 */ 48,
/* 44 */ 50273,
/* 45 */ 43,
/* 46 */ -43,
/* 47 */ 8,
/* 48 */ 53,
/* 49 */ 71,
/* 50 */ 43,
/* 51 */ -43,
/* 52 */ 9,
/* 53 */ 58,
/* 54 */ 50274,
/* 55 */ 43,
/* 56 */ -43,
/* 57 */ 10,
/* 58 */ 63,
/* 59 */ 50275,
/* 60 */ 43,
/* 61 */ -43,
/* 62 */ 11,
/* 63 */ 68,
/* 64 */ 85,
/* 65 */ 43,
/* 66 */ -43,
/* 67 */ 12,
/* 68 */ 0,
/* 69 */ -43,
/* 70 */ 13,
/* 71 */ 78,
/* 72 */ 50267,
/* 73 */ 43,
/* 74 */ 50261,
/* 75 */ 43,
/* 76 */ -71,
/* 77 */ 14,
/* 78 */ 0,
/* 79 */ 50266,
/* 80 */ 43,
/* 81 */ 50261,
/* 82 */ 43,
/* 83 */ -71,
/* 84 */ 15,
/* 85 */ 91,
/* 86 */ 50268,
/* 87 */ 97,
/* 88 */ 50269,
/* 89 */ -85,
/* 90 */ 16,
/* 91 */ 0,
/* 92 */ 50270,
/* 93 */ 97,
/* 94 */ 50271,
/* 95 */ -85,
/* 96 */ 17,
/* 97 */ 103,
/* 98 */ 50272,
/* 99 */ 43,
/* 100 */ 97,
/* 101 */ -97,
/* 102 */ 18,
/* 103 */ 0,
/* 104 */ -97,
/* 105 */ 19,
/* 106 */ 111,
/* 107 */ 50262,
/* 108 */ 106,
/* 109 */ -106,
/* 110 */ 20,
/* 111 */ 116,
/* 112 */ 119,
/* 113 */ 106,
/* 114 */ -106,
/* 115 */ 21,
/* 116 */ 0,
/* 117 */ -106,
/* 118 */ 22,
/* 119 */ 126,
/* 120 */ 50263,
/* 121 */ 43,
/* 122 */ 50261,
/* 123 */ 43,
/* 124 */ -119,
/* 125 */ 23,
/* 126 */ 133,
/* 127 */ 50264,
/* 128 */ 43,
/* 129 */ 50261,
/* 130 */ 43,
/* 131 */ -119,
/* 132 */ 24,
/* 133 */ 0,
/* 134 */ 50265,
/* 135 */ 43,
/* 136 */ 50261,
/* 137 */ 43,
/* 138 */ -119,
/* 139 */ 25,
0
};
extern int yyannotation[];
int yyannotation[] = {
0,
/* 1 */ 0,
/* 2 */ 0,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 0,
/* 6 */ 0,
/* 7 */ 1,
/* 8 */ 1,
/* 9 */ -6,
/* 10 */ 1,
/* 11 */ 16,
/* 12 */ 1,
/* 13 */ 1,
/* 14 */ -11,
/* 15 */ 1,
/* 16 */ 0,
/* 17 */ -11,
/* 18 */ 2,
/* 19 */ 25,
/* 20 */ 50258,
/* 21 */ 1,
/* 22 */ 50261,
/* 23 */ -19,
/* 24 */ 1,
/* 25 */ 31,
/* 26 */ 50260,
/* 27 */ 1,
/* 28 */ 50261,
/* 29 */ -19,
/* 30 */ 2,
/* 31 */ 0,
/* 32 */ 50259,
/* 33 */ 1,
/* 34 */ 50261,
/* 35 */ -19,
/* 36 */ 3,
/* 37 */ 0,
/* 38 */ 50256,
/* 39 */ 1,
/* 40 */ 50257,
/* 41 */ -37,
/* 42 */ 1,
/* 43 */ 48,
/* 44 */ 50273,
/* 45 */ 1,
/* 46 */ -43,
/* 47 */ 1,
/* 48 */ 53,
/* 49 */ 1,
/* 50 */ 1,
/* 51 */ -43,
/* 52 */ 2,
/* 53 */ 58,
/* 54 */ 50274,
/* 55 */ 1,
/* 56 */ -43,
/* 57 */ 3,
/* 58 */ 63,
/* 59 */ 50275,
/* 60 */ 1,
/* 61 */ -43,
/* 62 */ 4,
/* 63 */ 68,
/* 64 */ 1,
/* 65 */ 1,
/* 66 */ -43,
/* 67 */ 5,
/* 68 */ 0,
/* 69 */ -43,
/* 70 */ 6,
/* 71 */ 78,
/* 72 */ 50267,
/* 73 */ 1,
/* 74 */ 50261,
/* 75 */ 1,
/* 76 */ -71,
/* 77 */ 1,
/* 78 */ 0,
/* 79 */ 50266,
/* 80 */ 1,
/* 81 */ 50261,
/* 82 */ 1,
/* 83 */ -71,
/* 84 */ 2,
/* 85 */ 91,
/* 86 */ 50268,
/* 87 */ 1,
/* 88 */ 50269,
/* 89 */ -85,
/* 90 */ 1,
/* 91 */ 0,
/* 92 */ 50270,
/* 93 */ 1,
/* 94 */ 50271,
/* 95 */ -85,
/* 96 */ 2,
/* 97 */ 103,
/* 98 */ 50272,
/* 99 */ 1,
/* 100 */ 1,
/* 101 */ -97,
/* 102 */ 1,
/* 103 */ 0,
/* 104 */ -97,
/* 105 */ 2,
/* 106 */ 111,
/* 107 */ 50262,
/* 108 */ 1,
/* 109 */ -106,
/* 110 */ 1,
/* 111 */ 116,
/* 112 */ 1,
/* 113 */ 1,
/* 114 */ -106,
/* 115 */ 2,
/* 116 */ 0,
/* 117 */ -106,
/* 118 */ 3,
/* 119 */ 126,
/* 120 */ 50263,
/* 121 */ 1,
/* 122 */ 50261,
/* 123 */ 1,
/* 124 */ -119,
/* 125 */ 1,
/* 126 */ 133,
/* 127 */ 50264,
/* 128 */ 1,
/* 129 */ 50261,
/* 130 */ 1,
/* 131 */ -119,
/* 132 */ 2,
/* 133 */ 0,
/* 134 */ 50265,
/* 135 */ 1,
/* 136 */ 50261,
/* 137 */ 1,
/* 138 */ -119,
/* 139 */ 3,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 21010,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 21010,
/* 6 */ 9999,
/* 7 */ 21012,
/* 8 */ 21017,
/* 9 */ 9999,
/* 10 */ 21015,
/* 11 */ 9999,
/* 12 */ 24008,
/* 13 */ 24012,
/* 14 */ 9999,
/* 15 */ 24010,
/* 16 */ 9999,
/* 17 */ 9999,
/* 18 */ 26006,
/* 19 */ 9999,
/* 20 */ 9999,
/* 21 */ 28020,
/* 22 */ 9999,
/* 23 */ 9999,
/* 24 */ 28018,
/* 25 */ 9999,
/* 26 */ 9999,
/* 27 */ 29027,
/* 28 */ 9999,
/* 29 */ 9999,
/* 30 */ 29025,
/* 31 */ 9999,
/* 32 */ 9999,
/* 33 */ 30029,
/* 34 */ 9999,
/* 35 */ 9999,
/* 36 */ 30027,
/* 37 */ 9999,
/* 38 */ 9999,
/* 39 */ 33016,
/* 40 */ 9999,
/* 41 */ 9999,
/* 42 */ 33014,
/* 43 */ 9999,
/* 44 */ 9999,
/* 45 */ 35019,
/* 46 */ 9999,
/* 47 */ 35017,
/* 48 */ 9999,
/* 49 */ 36011,
/* 50 */ 36015,
/* 51 */ 9999,
/* 52 */ 36013,
/* 53 */ 9999,
/* 54 */ 9999,
/* 55 */ 37022,
/* 56 */ 9999,
/* 57 */ 37020,
/* 58 */ 9999,
/* 59 */ 9999,
/* 60 */ 38015,
/* 61 */ 9999,
/* 62 */ 38013,
/* 63 */ 9999,
/* 64 */ 39011,
/* 65 */ 39017,
/* 66 */ 9999,
/* 67 */ 39015,
/* 68 */ 9999,
/* 69 */ 9999,
/* 70 */ 41001,
/* 71 */ 9999,
/* 72 */ 9999,
/* 73 */ 43016,
/* 74 */ 9999,
/* 75 */ 43029,
/* 76 */ 9999,
/* 77 */ 43014,
/* 78 */ 9999,
/* 79 */ 9999,
/* 80 */ 44016,
/* 81 */ 9999,
/* 82 */ 44029,
/* 83 */ 9999,
/* 84 */ 44014,
/* 85 */ 9999,
/* 86 */ 9999,
/* 87 */ 47025,
/* 88 */ 9999,
/* 89 */ 9999,
/* 90 */ 47023,
/* 91 */ 9999,
/* 92 */ 9999,
/* 93 */ 48024,
/* 94 */ 9999,
/* 95 */ 9999,
/* 96 */ 48022,
/* 97 */ 9999,
/* 98 */ 9999,
/* 99 */ 51020,
/* 100 */ 51026,
/* 101 */ 9999,
/* 102 */ 51018,
/* 103 */ 9999,
/* 104 */ 9999,
/* 105 */ 53001,
/* 106 */ 9999,
/* 107 */ 9999,
/* 108 */ 55017,
/* 109 */ 9999,
/* 110 */ 55015,
/* 111 */ 9999,
/* 112 */ 56011,
/* 113 */ 56019,
/* 114 */ 9999,
/* 115 */ 56017,
/* 116 */ 9999,
/* 117 */ 9999,
/* 118 */ 58001,
/* 119 */ 9999,
/* 120 */ 9999,
/* 121 */ 60022,
/* 122 */ 9999,
/* 123 */ 60035,
/* 124 */ 9999,
/* 125 */ 60020,
/* 126 */ 9999,
/* 127 */ 9999,
/* 128 */ 61022,
/* 129 */ 9999,
/* 130 */ 61035,
/* 131 */ 9999,
/* 132 */ 61020,
/* 133 */ 9999,
/* 134 */ 9999,
/* 135 */ 62022,
/* 136 */ 9999,
/* 137 */ 62035,
/* 138 */ 9999,
/* 139 */ 62020,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[141];
*/
int TABLE[27][277];
init_dirsets() {
TABLE[26][0] = 1;
TABLE[26][256] = 1;
TABLE[26][258] = 1;
TABLE[26][260] = 1;
TABLE[26][259] = 1;
TABLE[1][256] = 1;
TABLE[1][259] = 1;
TABLE[1][260] = 1;
TABLE[1][258] = 1;
TABLE[2][258] = 1;
TABLE[2][260] = 1;
TABLE[2][259] = 1;
TABLE[3][256] = 1;
TABLE[4][258] = 1;
TABLE[5][260] = 1;
TABLE[6][259] = 1;
TABLE[7][256] = 1;
TABLE[8][273] = 1;
TABLE[9][267] = 1;
TABLE[9][266] = 1;
TABLE[10][274] = 1;
TABLE[11][275] = 1;
TABLE[12][268] = 1;
TABLE[12][270] = 1;
TABLE[13][261] = 1;
TABLE[13][273] = 1;
TABLE[13][274] = 1;
TABLE[13][275] = 1;
TABLE[13][266] = 1;
TABLE[13][267] = 1;
TABLE[13][270] = 1;
TABLE[13][268] = 1;
TABLE[13][272] = 1;
TABLE[13][269] = 1;
TABLE[13][271] = 1;
TABLE[13][262] = 1;
TABLE[13][265] = 1;
TABLE[13][264] = 1;
TABLE[13][263] = 1;
TABLE[13][257] = 1;
TABLE[14][267] = 1;
TABLE[15][266] = 1;
TABLE[16][268] = 1;
TABLE[17][270] = 1;
TABLE[18][272] = 1;
TABLE[19][269] = 1;
TABLE[19][271] = 1;
TABLE[20][262] = 1;
TABLE[21][263] = 1;
TABLE[21][264] = 1;
TABLE[21][265] = 1;
TABLE[22][257] = 1;
TABLE[23][263] = 1;
TABLE[24][264] = 1;
TABLE[25][265] = 1;
}

extern int yydirset();
int yydirset(i,j)
   int i,j;
{
   return TABLE[i][j];
}
int yytransparent(n)
   int n;
{
   switch(n) {
      case 1: return 1; break;
      case 6: return 1; break;
      case 11: return 1; break;
      case 19: return 0; break;
      case 37: return 0; break;
      case 43: return 1; break;
      case 71: return 0; break;
      case 85: return 0; break;
      case 97: return 1; break;
      case 106: return 1; break;
      case 119: return 0; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "Document"; break;
         case 11: return "opts"; break;
         case 19: return "opt"; break;
         case 37: return "DOC"; break;
         case 43: return "TEXTE"; break;
         case 71: return "EXP"; break;
         case 85: return "liste"; break;
         case 97: return "liste_items"; break;
         case 106: return "CONTENU"; break;
         case 119: return "SECTION"; break;
   }
   else 
      switch(n-50000) {
         case 276: return "SEPARATEUR"; break;
         case 275: return "mot"; break;
         case 274: return "SUSPENSION"; break;
         case 273: return "ANTISLASH"; break;
         case 272: return "ITEM"; break;
         case 271: return "LISTENUM_FIN"; break;
         case 270: return "LISTENUM_DEB"; break;
         case 269: return "LISTENONNUM_FIN"; break;
         case 268: return "LISTENONNUM_DEB"; break;
         case 267: return "ITALIQUE"; break;
         case 266: return "GRAS"; break;
         case 265: return "TITRE3_DEB"; break;
         case 264: return "TITRE2_DEB"; break;
         case 263: return "TITRE1_DEB"; break;
         case 262: return "TITRE"; break;
         case 261: return "PARFER"; break;
         case 260: return "DATEDOC_DEB"; break;
         case 259: return "AUTEURDOC_DEB"; break;
         case 258: return "TITREDOC_DEB"; break;
         case 257: return "FINDOC"; break;
         case 256: return "DEBUTDOC"; break;
      }
   return "special_character";
}
