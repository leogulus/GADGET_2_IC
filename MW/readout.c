#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define RSIZE 50
#define ZSIZE 50


int  main()
{
  int i,j;
  FILE *fd,*fout;
  double VelDispRz_disk[RSIZE+1][ZSIZE+1];


  if(fd=fopen("out.dat","r"))
    {

      fread(&VelDispRz_disk[0][0], (RSIZE+1)*(ZSIZE+1),  sizeof(double), fd);

      if(!(fout=fopen("VelDisp.txt","w")))
        {
	  fprintf(stderr, "Can't open file 'VelDisp.txt'.\n");
	  exit(0);
        }

      for(i=0; i<=RSIZE; i++)
	for(j=0; j<=ZSIZE; j++)
	   fprintf(fout,"VelDispRz_disk,%3d,%3d=%13g\n",i,j,VelDispRz_disk[i][j]);  


      fclose(fd);
      fclose(fout);
    }
  else
    {
      fprintf(stderr,"Can't open file 'out.dat'.\n");
      exit(0);
    }
  printf("done.\n");

  return(0);

}
