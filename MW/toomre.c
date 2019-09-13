
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "nrsrc/nr.h"
#include "nrsrc/nrutil.h"


#include "prototypes.h"
#include "globvars.h"





/* procedure not currently used - epicyclic frequency
   is calculated in force.c */
/*
double epicyclic_kappa2(double R)
{
  double dR,dphi,dphi_;

  if(R>0)
    {
      dR=R*0.02;

      dphi=comp_Dphi_R(R,0);
      dphi_=comp_Dphi_R(R+dR,0);

      return 3*dphi/R + (dphi_-dphi)/dR;
      
    }
  else return 0;
}
*/



int plot_toomre_stability(FILE *fd)
{
  int dummy;
  double *Q,*Q_all,*Temp,*Temp_all,*Soundspeed,*Kappa;
  double *Sigma_Hern,*Sigma_Hern_all;
  int i;
  double Sigma0_Disk, Sigma0_Gas;
  double Rd;
  int count;


  for(i=0,count=0;i<=RSIZE;i++)
    if(list_R[i]<=20*H)
      count++;
  
  switch(GasDistribution) {
        case 0:
          Rd= H;
          break;
        case 1:
          Rd= H*GasExpAlpha;
          break;
        case 2:
	  Rd= 1.0;
          break;
  }


  Sigma0_Disk=(M_DISK)/(2*PI*H*H);
  Sigma0_Gas=(M_GAS)/(2*PI*Rd*Rd);

  Q=dvector(0,RSIZE);
  Q_all=dvector(0,RSIZE);
  Sigma_Hern=dvector(0,RSIZE);
  Sigma_Hern_all=dvector(0,RSIZE);
  Temp=dvector(0,RSIZE);
  Temp_all=dvector(0,RSIZE);
  Soundspeed=dvector(0,RSIZE);
  Kappa=dvector(0,RSIZE);


  for(i=0;i<count;i++)
    {
      Kappa[i]= sqrt(epi_kappa2[i]);
      Q[i]=Qstabilizefactor*sqrt(VelDispRz_disk[i][0])*Kappa[i]/(3.36*G*Sigma0_Disk*exp(-list_R[i]/H));

      /* Disk + Gas */
      Q_all[i]= Qstabilizefactor*sqrt(VelDispRz_disk[i][0])*Kappa[i]/(3.36*G*(Sigma0_Disk*exp(-list_R[i]/H) + Sigma0_Gas*exp(-list_R[i]/Rd)));

      Sigma_Hern[i]= (3.36*G*Sigma0_Disk*exp(-list_R[i]/H))/Kappa[i];
      Sigma_Hern_all[i]= (3.36*G*(Sigma0_Disk*exp(-list_R[i]/H) + Sigma0_Gas*exp(-list_R[i]/Rd)))/Kappa[i];

      /* Figure out gas stability criteria, get c_s from toomre critera, convert to temp. */
      Soundspeed[i]=(1.0)*PI*G*Sigma0_Gas*exp(-list_R[i]/Rd)/Kappa[i];
      Temp[i]=(1.0/0.012381322)*Soundspeed[i]*Soundspeed[i]/(GAMMA*(GAMMA-1.0));

      /* Disk + Gas */
      Soundspeed[i]=(1.0)*PI*G*(Sigma0_Disk*exp(-list_R[i]/H) + Sigma0_Gas*exp(-list_R[i]/Rd))/Kappa[i];
      Temp_all[i]=(1.0/0.012381322)*Soundspeed[i]*Soundspeed[i]/(GAMMA*(GAMMA-1.0));
    }


  fprintf(fd,"\n%d\n",count);

  for(i=0;i<count;i++)
    fprintf(fd,"%g\n",list_R[i]);

  for(i=0;i<count;i++)
    fprintf(fd,"%g\n",Q[i]);

  for(i=0;i<count;i++)
    fprintf(fd,"%g\n",Q_all[i]);

  for(i=0;i<count;i++)
    fprintf(fd,"%g\n",Temp[i]);

  for(i=0;i<count;i++)
    fprintf(fd,"%g\n",Temp_all[i]);

  for(i=0;i<count;i++)
    fprintf(fd,"%g\n",Kappa[i]);

  for(i=0;i<count;i++)
    fprintf(fd,"%g\n",VelDispRz_disk[i][0]);

  for(i=0;i<count;i++)
    fprintf(fd,"%g\n",Sigma_Hern[i]);

  for(i=0;i<count;i++)
    fprintf(fd,"%g\n",Sigma_Hern_all[i]);

  for(i=0;i<count;i++)
    fprintf(fd,"%g\n",Sigma0_Disk*exp(-list_R[i]/H));

  for(i=0;i<count;i++)
    fprintf(fd,"%g\n",Sigma0_Gas*exp(-list_R[i]/Rd));

}







int plot_circular_speeds(FILE *fd)
{
  int i;
  double R;
  double RMAX;
  double vc2;

#define POINTS 1000



  RMAX=Rvir; 

  /*
    RMAX=10*H;
  */


  fprintf(fd,"%d\n",POINTS);

  for(i=1;i<=POINTS;i++)
    {
      R=(RMAX/POINTS)*i;
      fprintf(fd,"%f\n",R);
    }

  for(i=1;i<=POINTS;i++)
    {
      R=(RMAX/POINTS)*i;
      fprintf(fd,"%f\n",vc2=R*comp_Dphi_R_halo(R,0));
      /*
	printf("%g %g \n", R, vc2);
      */
    }

  for(i=1;i<=POINTS;i++)
    {
      R=(RMAX/POINTS)*i;
      fprintf(fd,"%f\n",vc2=R*comp_Dphi_R_disk_razorthin(R,0));
      /*
      printf("%g %g \n", R, vc2);
      */
    }

  for(i=1;i<=POINTS;i++)
    {
      R=(RMAX/POINTS)*i;
      fprintf(fd,"%f\n",vc2=R*comp_Dphi_R_gas_razorthin(R,0));
      /*
      printf("%g %g \n", R, vc2);
      */
    }

  for(i=1;i<=POINTS;i++)
    {
      R=(RMAX/POINTS)*i;
      fprintf(fd,"%f\n",vc2=R*comp_Dphi_R_bulge(R,0));
      /*
      printf("%g %g \n", R, vc2);
      */
    }

  
  for(i=1;i<=POINTS;i++)
    {
      /*
      R=(RMAX/POINTS)*i;
      fprintf(fd,"%f\n",vc2=R*comp_Dphi_R_disk(R,0));
      */
      /*
	printf("%g %g \n", R, vc2);
      */
    }
    

#undef POINTS 
}
