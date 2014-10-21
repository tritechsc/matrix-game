//inkey loop
//char to int type cast ascii and game control with numbers
#include <stdio.h>
#include <stdlib.h>
#include  <conio.h>
#include <time.h>
void Display(int h, int k, int nh, int nk);
int Modulo (int nb, int mod);

int main()
{
    int nh, nk,  h,k, jump = 0;
     srand (time(NULL));
     h = rand() % 10 ;   /* generate secret number between 0 and 10: */
      k = rand() % 10 ;   /* generate secret number between 0 and 10: */

        nh = rand() % 10 ;   /* generate secret number between 0 and 10: */
      nk = rand() % 10 ;   /* generate secret number between 0 and 10: */
       Display(h,k,nh,nk);
      //   printf( " USE THE ARROW KEYS AND SPACE TO JUMP (EXC TO QUIT) ");
	int asc;
	bool done = false;
    char input;

	// game loop
	while(!done){
			input = getch();
			asc = (int)input;
			//printf(" %d ",asc);


			if (asc == 75){
                    system ("CLS");
                    h = h -1;
                    h = Modulo(h,10);
                    Display(h,k,nh,nk);
                    printf(" LEFT \n");
            }
			if (asc == 77){
                system ("CLS");
                h = h + 1;
                  h = Modulo(h,10);
                     Display(h,k,nh,nk);
                 printf(" RIGHT \n");
            }
			if (asc == 72){
                system ("CLS");
                k = k - 1;
                k = Modulo(k,10);
                  Display(h,k,nh,nk);
                  printf(" UP \n");
            }
			if (asc == 80){
                system ("CLS");
                k = k + 1;
                  k = Modulo(k,10);
                Display(h,k,nh,nk);
                printf(" DOWN \n");
            }
			if (asc == 32 ) {
                     system ("CLS");
                  h = h + 3;
                k = k - 3;

                  k = Modulo(k,10);
                   h = Modulo(h,10);
                    Display(h,k,nh,nk);
                printf(" JUMP ");
                jump++;
            }
            if (asc == 27){
                done = true;
                printf( " CIAO ");
            }
	}
}

void Display(int h, int k, int nh, int nk) {
    system("COLOR 7F" );
    int x, y;
    for (y = 0; y < 10; y++){
        for (x = 0; x < 10; x++){
            //printf (" %d,%d ", x,y);
            if ((x == h )&&(y == k)){printf ("(%d,%d)",h,k);}
            else if ((x == nh )&&(y == nk)){printf ("  4  ");}
            else {
                printf ("  .  ");
            }

       //      if ((x == nh )&&(y == nk)){printf ("(%d,%d)",h,k);}
        //    else {
         //       printf ("  .  ");
         //   }
       }//end y

        printf("\n");
    }//end x
     printf( "USE THE ARROW KEYS AND SPACE TO JUMP (EXC TO QUIT) \n\n");
     printf ("                     ");
}


int Modulo (int nb, int mod){
if (nb < 0 )nb += mod;
//if (nb > mod )nb -= mod;
    return nb % mod;
}





