
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "nrsrc/nr.h"
#include "nrsrc/nrutil.h"


#include "prototypes.h"
#include "globvars.h"


#include "forcetree.h"






double SofteningTable[6];



struct particle_data 
{
  double Pos[3], 
         Mass, 
         Acc[3],
         Potential;
  int    Type;
} **P;





compute_local_escape_speed()
{
  //int i,j,N,n;
  long int i,j,N,n;

  void allocate_memory(int NumPart);


  SofteningTable[1]=0.05*RS;  /* halo */
  SofteningTable[0]=SofteningTable[2]=  0.1*H;  /* gas & disk */
  SofteningTable[3]=0.4*A;  /* bulge */
  SofteningTable[5]=1;



  printf("Start computing local escape speed...  ");  fflush(stdout);


  N=N_HALO+N_DISK+N_BULGE+N_GAS+1;


  allocate_memory(N);
  printf("check 0 N=%d \n",N); fflush(stdout);
  force_setpointers(SofteningTable);
  printf("check 1 \n"); fflush(stdout);
  force_treeallocate(2*N);
  printf("check 2 2*N=%d \n",2*N); fflush(stdout);



  n=1;
  
  if(N_HALO>0)
    {
      for(i=1;i<=N_HALO;i++)
	{
	  P[n]->Pos[0]=xp_halo[i];
	  P[n]->Pos[1]=yp_halo[i];
	  P[n]->Pos[2]=zp_halo[i];
	  P[n]->Mass=mp_halo[i];
	  P[n]->Type=1;

	  n++;
	}
    }




  if(N_DISK>0)
    {
      for(i=1;i<=N_DISK;i++)
	{
	  P[n]->Pos[0]=xp_disk[i];
	  P[n]->Pos[1]=yp_disk[i];
	  P[n]->Pos[2]=zp_disk[i];
	  P[n]->Mass=mp_disk[i];
	  P[n]->Type=2;

	  n++;
	}
    }

      
  if(N_BULGE>0)
    {
      for(i=1;i<=N_BULGE;i++)
	{

	  P[n]->Pos[0]=xp_bulge[i];
	  P[n]->Pos[1]=yp_bulge[i];
	  P[n]->Pos[2]=zp_bulge[i];
	  P[n]->Mass=mp_bulge[i];
	  P[n]->Type=3;

	  n++;
	}
    }


  if(N_GAS>0)
    {
      for(i=1;i<=N_GAS;i++)
	{
	  P[n]->Pos[0]=xp_gas[i];
	  P[n]->Pos[1]=yp_gas[i];
	  P[n]->Pos[2]=zp_gas[i];
	  P[n]->Mass=mp_gas[i];
	  P[n]->Type=0;

	  n++;
	}
    }


  if(M_BH>0)
    {
	  P[n]->Pos[0]=0;
	  P[n]->Pos[1]=0;
	  P[n]->Pos[2]=0;
	  P[n]->Mass=M_BH;
	  P[n]->Type=5;
	  n++;
    }



  printf("positions input \n"); fflush(stdout);

  force_treebuild((void **)P+1, N,  1.0 , 1);

  printf("treebuild_forced, N=%d \n",N); fflush(stdout);

  for(i=1;i<=N;i++)
    {
      if((i%10000)==0)
	printf("...%d\n",i); fflush(stdout);
      P[i]->Potential=0;
      force_treeevaluate_potential(i-1);    
    }
  
  printf("potentials grabbed \n"); fflush(stdout);


  for(i=1;i<=N;i++)
    {
      printf("i/N=%ld/%ld t=%d P[i]->Potential=%g  self-pot=%g  m=%g G=%g vmax2=%g \n",i, N,
        P[i]->Type,P[i]->Potential,P[i]->Mass/SofteningTable[P[i]->Type],
        P[i]->Mass,G,-2.0*G*(P[i]->Potential+P[i]->Mass/SofteningTable[P[i]->Type])); fflush(stdout);

      P[i]->Potential += P[i]->Mass/SofteningTable[P[i]->Type];  /* removes self energy */
      P[i]->Potential *= G;
    }






  n=1;

  if(N_HALO>0)
    {
      for(i=1;i<=N_HALO;i++)
	{
	  vmax2_halo[i]=-2*P[n]->Potential;
	  n++;
	}
    }



  if(N_DISK>0)
    {
      for(i=1;i<=N_DISK;i++)
	{
	  vmax2_disk[i]=-2*P[n]->Potential;
	  n++;
	}
    }

      
  if(N_BULGE>0)
    {
      for(i=1;i<=N_BULGE;i++)
	{
	  vmax2_bulge[i]=-2*P[n]->Potential;
	  n++;
	}
    }


  if(N_GAS>0)
    {
      for(i=1;i<=N_GAS;i++)
	{
	  vmax2_gas[i]=-2*P[n]->Potential;
	  n++;
	}
    }




  printf("done.\n"); 
}







void allocate_memory(int NumPart)
{
  int i;

  fprintf(stdout,"allocating memory...\n");


  if(NumPart>0)
    {

      if(!(P=malloc((NumPart)*sizeof(struct particle_data *))))
	{
	  fprintf(stdout,"failed to allocate memory. (A)\n");
	  exit(0);
	}

      P--;   /* start with offset 1 */
      
      if(!(P[1]=malloc((NumPart)*sizeof(struct particle_data))))
	{
	  fprintf(stdout,"failed to allocate memory. (B)\n");
	  exit(0);
	}

      for(i=2;i<=(NumPart);i++)   /* initiliaze pointer table */
	P[i]=P[i-1]+1;

    }

  fprintf(stdout,"allocating memory...done\n");
}
