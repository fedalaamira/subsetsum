#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#define SET_SIZE 7
int E[7];
int Sol[7]={0, 0, 0, 0, 0, 0, 0};
int T[7]={0,0,0,0,0,0,0};
int Result[100];
int Mat[7];
int j=0;
const tab_taille=7;
//-----------------if the array E contains a subset F such that the sum of its elements = somme -------------------------

int subsetsum_exist(int n,int s){

    if(s==0){
        return 1;

    }
    else{
        if(s<0){
            return 0;
        }
    }
    if(n<0 && s>0){
        return 0;
    }


    return (subsetsum_exist(n-1,s)||subsetsum_exist(n-1,s-E[n]));
}
//-------------------------- giving one solution (one subset)----------------------------------
int subsetsum(int n,int s){
    int a=0,b=0;
    if(s==0){
        return 1;

    }
    else{
        if(s<0){
            return 0;
        }
    }
    if(n<0 && s>0){
        return 0;
    }

    if(subsetsum(n-1,s-T[n])){
         a=1;
         Sol[n]=1;

    }
    else if(subsetsum(n-1,s) ){
        Sol[n]=0;
        b=1;

    }
    return b||a;
}

/*-------------------copy the table -----------------------------------------*/
void CopierTab()
{

int cmp;
for (cmp=0; cmp < 7; ++cmp)
{
    T[cmp]=E[cmp];
}
return 0;

}

/*-------------------check if a small array (size b)  is included in a big array (size a) -----------------------------------------*/
int verif( int a, int b)
{
    int j=0, t=0 , l=0;
    int cpt=0;
    int p;


                for(p=0;p<b;p++)
                {

                    while((Result[j]!= Mat[p])&&j<a)
                    {
                        j++;


                    }
                    if(Result[j]== Mat[p])
                    {
                        cpt++;
                        j=0;

                    }
                }
                if(cpt==b){
                    return 1;
                }
                else{
                    j=l+1;
                }




        return 0;

}

//-------------------------main-------------------------------
int main()
{

//---------------------sol3---------------------------------

    int s=1,i,a,f,b,it=0,somme,indice=0,choix;
    int sum=0;
    int n=tab_taille-1,taille=tab_taille-1,iteration=0,sauv;

    for(b=0;b<tab_taille;b++)
    {
        printf("introduce the element %d of the array ",b);
        scanf("%d",&E[b]);
    }
    printf("introduce the sum S");
    scanf("%d",&somme);
    CopierTab();


     menu:

    system("cls");
    printf("\n\n Menu \n\n ");

    printf("\n  1 Test whether a subset F belongs to E such that the sum of its elements = S \n");
    printf("\n  2 Display a subset of E such that the sum of its elements = S \n ");
    printf("\n  3 Show all subsets of E such that the sum of its elements = S\n ");
    printf("\n\n your choice :");
    scanf("%d",&choix);
    system("cls");


    switch(choix)
    {
    case 1:
        if(subsetsum_exist(7,somme)==1){
            printf("\n\n  the array E contains a subset F such that the sum of its elements = %d",somme);
        }
        else{
             printf("\n\n the array E does not contain a subset F such that the sum of its elements = %d",somme);
        }
        printf("\n");
        system("pause");
        goto menu;
        break;

    case 2:
        if(subsetsum(7,somme)==1){
            printf("\n\n the array E contains a subset F such that the sum of its elements =  %d \n\n\n",somme);
            for(j=0;j<7;j++){
            if (Sol[j]==1){
                printf("%d \n",E[j]);
            }
        }
        }
        else{
             printf("\n\n  the array E does not contain a subset F such that the sum of its elements = %d",somme);
        }
        printf("\n");
        system("pause");
    goto menu;
        break;

    case 3:
  while(s==1)
    {
  if (iteration>=1)
     {
     T[n]=sauv;
     }

     subsetsum(tab_taille-1,somme);
        for(f=0;f<7;f++)
    { if (T[f]==0)
      Sol[f]=0;
    }

       for(a=0;a<7;a++)
     {
         if (Sol[a]==1)
         {
         Mat[it]=E[a];
         it++;
         }
          Sol[a]=0;
     }
if (verif(indice,it)==0)
     {
for (i=0;i<it;i++)
{
    Result[indice]= Mat[i];
    indice++;
}
for (i=0;i<it;i++)
{
    Mat[i]=0;
}

 Result[indice]=-1;
 indice++;

     }
it=0;
iteration++;
   sauv=T[n-1];
     T[n-1]=0;

     n--;

     if (n==-1)
     {
         T[taille]=0;
         taille--;
         n=taille;
         iteration=0;
     }

     for(i=0;i<7;i++)

     {
         sum+= T[i];
     }

    if(sum==0)
      {
          s=0;
      }
     sum=0;



    }

for(i=0;i<indice-1;i++)
    {
        if (Result[i]==-1)
        {i++;
            printf("\n");

        }
   printf("%d |",Result[i]);
    }

        printf("\n");
        system("pause");
        goto menu;
        break;

    default:
        if(subsetsum(7,s)==1){
            printf("\n\n  the array E contains a subset F such that the sum of its elements =  %d",somme);
        }
        else{
             printf("\n\n the array E does not contain a subset F such that the sum of its elements =%d",somme);
        }
        printf("\n");
        system("pause");
        goto menu;
        break;

    }


    return 0;


}


