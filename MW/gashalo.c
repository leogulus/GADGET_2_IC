#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "nrsrc/nr.h"
#include "nrsrc/nrutil.h"

#include "prototypes.h"
#include "globvars.h"





compute_velocity_dispersions_gashalo()
{
  int i,j;
  double z,R;
  double rho;
 

  printf("gashalo gas velocity dispersion field...\n"); fflush(stdout);  

  for(i=0;i<=RSIZE;i++)
    {
      printf("gashalo gas A, %d\n",i);
      
      for(j=0;j<=ZSIZE;j++)
	{
	  xl[j+1]=list_z[j];
	  yl[j+1]=Dphi_z[i][j] * comp_rho_gashalo(list_R[i],list_z[j]);
	}

      spline(xl,yl,ZSIZE+1,1e40,1e40,D2yl);


      for(j=ZSIZE - 1, VelDispRz_halo[i][ZSIZE]=0  ;j>=0;j--)
	{

	  VelDispRz_halo[i][j] =  VelDispRz_halo[i][j+1];
	  if(fabs(yl[j+2])>1e-100 && fabs(yl[j+1])>1e-100)
	    VelDispRz_halo[i][j]+=
	      qromb(splint_xl_yl_D2yl,list_z[j],list_z[j+1]);
	}
    }

  for(i=0;i<=RSIZE;i++)
    {
      printf("gashalo gas B, %d\n",i);

      for(j=0;j<=ZSIZE;j++)
	{
	  xl[j+1]=list_z[j];
	  yl[j+1]=Dphi_z_dR[i][j] * comp_rho_gashalo(list_RplusdR[i],list_z[j]);

	}

      spline(xl,yl,ZSIZE+1,1e40,1e40,D2yl);
      
      for(j=ZSIZE - 1, VelDispRz_dR_halo[i][ZSIZE]=0  ;j>=0;j--)
	{
	  VelDispRz_dR_halo[i][j] =  VelDispRz_dR_halo[i][j+1];
	  if(fabs(yl[j+2])>1e-100 && fabs(yl[j+1])>1e-100)
	    VelDispRz_dR_halo[i][j]+=
	      qromb(splint_xl_yl_D2yl,list_z[j],list_z[j+1]);
	}
      
    }

  
  for(i=0;i<=RSIZE;i++)
    {
      for(j=0;j<=ZSIZE;j++)
	{
	  R=list_R[i];
	  z=list_z[j];
	  
	  rho = comp_rho_gashalo(R,z);

	  if(rho>0)
	    {
	      if(i>0)
		VelDispPhi_halo[i][j]=R/rho * (VelDispRz_dR_halo[i][j]-VelDispRz_halo[i][j])/(list_RplusdR[i]-list_R[i]);
	      else
		VelDispPhi_halo[i][j]=0;

	      VelDispRz_halo[i][j]/=rho;
	    }
	  else
	    VelDispRz_halo[i][j]=VelDispPhi_halo[i][j]=0;

	  
	  VelVc2_halo[i][j]=R*Dphi_R[i][j];
	  
	  VelDispPhi_halo[i][j]+=VelVc2_halo[i][j]+VelDispRz_halo[i][j];

	  VelStreamPhi_halo[i][j]=halo_spinfactor * sqrt(VelVc2_halo[i][j]);
  
	  VelDispPhi_halo[i][j]-=VelStreamPhi_halo[i][j]*VelStreamPhi_halo[i][j];


	  if(VelDispRz_halo[i][j]<0)
	    VelDispRz_halo[i][j]=0;

	  if(VelDispPhi_halo[i][j]<0)
	    VelDispPhi_halo[i][j]=0;
	}
    }

  
  printf("done.\n"); fflush(stdout);  
}




double comp_Dphi_z_gashalo(double R,double z)
{
  double r,M_r;

  r=sqrt(R*R+z*z);
  
  M_r=gashalo_mass(r);

  if(r>0)
    return G*z/(r*r*r)*M_r;
  else
    return 0;
}


double comp_Dphi_R_gashalo(double R,double z)
{
  double r,M_r;

  r=sqrt(R*R+z*z);

  M_r=gashalo_mass(r);

  if(r>0)
    return G*R/(r*r*r)*M_r;
  else
    return 0;
}


double comp_rho_gashalo(double R,double z)
{
  double r;

  r=sqrt(R*R+z*z);

  return gashalo_rho(r);
}

/*
double gashalo_m_lessthan_r(double r)
{
   return RHO_0*qromb(gashalo_profile_int,0,r);
}
*/


double gashalo_profile(double r)
{
  /* Beta Model */
  double RC=GasHalo_Rc_over_Rs*RS;
  return RHO_0*pow(1+(r/RC)*(r/RC),-1.5*GasHalo_Beta);

  /* Hydrostatic eq. - Isothermal 
  return pow(1+r, 1/r);
  */

  /* 
  Hydrostatic eq. - T function of r
  double alpha= 1.0;
  return exp(-(3.0/alpha)*r*(1-log(1+r)/r)/(log(1+r)-r/(1+r)));
  */

}


















