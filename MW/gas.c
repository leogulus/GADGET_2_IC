#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "nrsrc/nr.h"
#include "nrsrc/nrutil.h"


#include "prototypes.h"
#include "globvars.h"






static double R,z;

/* ADD FUNCTIONS TO INCLUDE BH POTENTIAL IN CALCULATING INITIAL ORBITS */
/* -------------------------------------
     Compute:  dphi/dR
   ------------------------------------- */

double comp_Dphi_z_BH(double R,double z)
{
  double r,M_r;

  r=sqrt(R*R+z*z);
  M_r=M_BH;

  if(r>0)
    return G*z/(r*r*r)*M_r;
  else
    return 0;
}


double comp_Dphi_R_BH(double R,double z)
{
  double r,M_r;

  r=sqrt(R*R+z*z);
  M_r=M_BH;

  if(r>0)
    return G*R/(r*r*r)*M_r;
  else
    return 0;
}


compute_velocity_dispersions_gas()
{
  int i,j;
  double z,R;
  double rho;

  if(N_DISK==0) return;

  printf("gas velocity dispersion field...\n"); fflush(stdout);  

  for(i=0;i<=RSIZE;i++)
    {
      printf("gas A, %d\n",i);
      
      for(j=0;j<=ZSIZE;j++)
	{

	  xl[j+1]=list_z[j];
	  yl[j+1]=Dphi_z[i][j] * comp_rho_gas(list_R[i],list_z[j]);
	}

      spline(xl,yl,ZSIZE+1, 1e40, 1e40, D2yl);


      for(j=ZSIZE - 1, VelDispRz_gas[i][ZSIZE]=0  ;j>=0;j--)
	{
	  VelDispRz_gas[i][j] =  VelDispRz_gas[i][j+1];
	  if(fabs(yl[j+2])>1e-100 && fabs(yl[j+1])>1e-100)
	    VelDispRz_gas[i][j]+=
	      qromb(splint_xl_yl_D2yl,list_z[j],list_z[j+1]);
	}
    }

  for(i=0;i<=RSIZE;i++)
    {
      printf("gas B, %d\n",i);

      for(j=0;j<=ZSIZE;j++)
	{
	  xl[j+1]=list_z[j];
	  yl[j+1]=Dphi_z_dR[i][j] * comp_rho_gas(list_RplusdR[i],list_z[j]);

	}

      spline(xl,yl,ZSIZE+1, 1e40,1e40,D2yl);
      
      for(j=ZSIZE - 1, VelDispRz_dR_gas[i][ZSIZE]=0  ;j>=0;j--)
	{
	  VelDispRz_dR_gas[i][j] =  VelDispRz_dR_gas[i][j+1];
	  if(fabs(yl[j+2])>1e-100 && fabs(yl[j+1])>1e-100)
	    VelDispRz_dR_gas[i][j]+=
	      qromb(splint_xl_yl_D2yl,list_z[j],list_z[j+1]);
	}
      
    }

  
  for(i=0;i<=RSIZE;i++)
    {
      for(j=0;j<=ZSIZE;j++)
	{

	  R=list_R[i];
	  z=list_z[j];
	  
	  rho = comp_rho_gas(R,z);

	  if(rho>0)
	    {
	      if(i>0)
		VelDispPhi_gas[i][j]=R/rho * (VelDispRz_dR_gas[i][j]-VelDispRz_gas[i][j])/(list_RplusdR[i]-list_R[i]);
	      else
		VelDispPhi_gas[i][j]=0;

	      VelDispRz_gas[i][j]/=rho;
	    }
	  else
	    VelDispRz_gas[i][j]=VelDispPhi_gas[i][j]=0;

	  VelVc2_gas[i][j]=R*Dphi_R[i][j];
  
	  VelDispPhi_gas[i][j]+=VelVc2_gas[i][j]+VelDispRz_gas[i][j];
	  

	  if(VelDispPhi_gas[i][j]>VelDispRz_gas[i][j]/epi_gamma2[i])
	    {
	      VelStreamPhi_gas[i][j]=sqrt(VelDispPhi_gas[i][j]-VelDispRz_gas[i][j]/epi_gamma2[i]);
	      VelDispPhi_gas[i][j] = VelDispRz_gas[i][j]/epi_gamma2[i];
	    }
	  else
	    {
	      VelStreamPhi_gas[i][j]=0;
	      VelDispPhi_gas[i][j] = VelDispRz_gas[i][j]/epi_gamma2[i];
	    }



	  
	  /*** alternativ ******/

	  if(VelVc2_gas[i][j]>0)
	    VelStreamPhi_gas[i][j]=sqrt(VelVc2_gas[i][j]);
	  else
	    VelStreamPhi_gas[i][j]=0;

	  VelDispPhi_gas[i][j] = VelDispRz_gas[i][j]/epi_gamma2[i];

	  /************/



	  if(VelDispRz_gas[i][j]<0)
	    VelDispRz_gas[i][j]=0;
	  
	  if(VelDispPhi_gas[i][j]<0)
	    VelDispPhi_gas[i][j]=0;
	}
    }

  printf("done.\n"); fflush(stdout);  
  
  test();

}





double mass_cumulative_gas(double R)
{
double Rdt,x,F1;

      switch(GasDistribution) {
          case 0:   /* Standard Exponential Distribution */
	        return M_GAS*(1-(1+R/H)*exp(-R/H));
                break;
          case 1:  /* exponential with Rd 4x the Disk one */
		return M_GAS*(1-(1+R/(GasExpAlpha*H))*exp(-R/(GasExpAlpha*H)));
                break;
          case 2:  /* Power-law distribution - gamma=1 is Mestel, or 1/R distribution */
		return M_GAS*pow((R/PowerLawCutOff), 2-PowerLawGamma);
                break;
          case 3:   /* Exponential with a central hole */
           Rdt=H*GasExpAlpha;
           F1=(2.+HoleGamma)/(2.+HoleGamma+HoleRadius*(2.+HoleRadius+HoleGamma));
	   if(R < HoleRadius*Rdt)
	     {
		x = F1*(HoleRadius*HoleRadius/(2.+HoleGamma)) * pow(R/(HoleRadius*Rdt),2.+HoleGamma);
	     }
	   else
	     { 
		x = 1.0 - F1 * (1.+R/Rdt)*exp(-R/Rdt+HoleRadius);
	     }
		return M_GAS*x;
		break;
	}
}






double comp_rho_gas(double R,double z)
{
  double x,Rdt,F1;

  if(fabs(z)>6*Z0)
    {
        x=0;
        return x;
    }


  switch(GasDistribution) {
	case 0:
	  x=(M_GAS)/(4*PI*H*H*Z0)*exp(-R/H)*pow(2/(exp(z/Z0)+exp(-z/Z0)),2);
	  break;
	case 1:
	  x=(M_GAS)/(4*PI*GasExpAlpha*H*GasExpAlpha*H*Z0)*exp(-R/(GasExpAlpha*H))*pow(2/(exp(z/Z0)+exp(-z/Z0)),2);
	  break;
	case 2:
	  x=(M_GAS)/(4*PI*Z0*PowerLawGamma*PowerLawGamma)*(2-PowerLawGamma)*pow((R/PowerLawCutOff),PowerLawGamma)*pow(2/(exp(z/Z0)+exp(-z/Z0)),2);
	  break;
	case 3:
	   Rdt=H*GasExpAlpha;
	   F1=(2.+HoleGamma)/(2.+HoleGamma+HoleRadius*(2.+HoleRadius+HoleGamma));
            if(R < HoleRadius*Rdt) 
              {
	  	x = F1*pow(R/(HoleRadius*Rdt),HoleGamma);	
              }
            else 
              {
		x = F1*exp(-R/Rdt+HoleRadius);
              }
	  	x *= (M_GAS)/(4*PI*Rdt*Rdt*Z0)*pow(2/(exp(z/Z0)+exp(-z/Z0)),2);
	  break;
    }

  return x;
}








/* -------------------------------------
 *    Bessel function integrads for
 *    calculating potential of a 
 *    sheet of mass (as a function of 
 *    surface density).
 *
 *    binney & tremaine, pp. 74-79
 *      equation 2-167, with derivatives
 *      taken with respect to z and R
 *
 * ------------------------------------- */


double intz_g(double k);
double intz_g_abs(double);

double intR_g(double k);
double intR_g_abs(double k);





/* -------------------------------------
     Compute:  dphi/dz
   ------------------------------------- */

double comp_Dphi_z_gas(double RR,double zz)
{
  double comp_Dphi_z_gas_sph(double RR,double zz);
  double comp_Dphi_z_gas_exact(double RR,double zz);
  double Rd;

  switch(GasDistribution) {
	case 0:
	  Rd= H;
	  break;
	case 1:
	  Rd= H*GasExpAlpha;
	  break;
	case 2:
	  break;
	case 3:
	  Rd= H*GasExpAlpha;
	  break;
  }

  if(sqrt(RR*RR+zz*zz)>10*Rd)
    return comp_Dphi_z_gas_sph(RR,zz);
  else
    return comp_Dphi_z_gas_exact(RR,zz);

}



/* assume spherical mass density */
double comp_Dphi_z_gas_sph(double RR,double zz)
{
  double m;
  double r;


  r=sqrt(RR*RR+zz*zz);
  m=mass_cumulative_gas(r);

    if (m<=0.) printf("dingle 1 RR zz r m = %g %g %g %g \n",RR,zz,r,m);
  
  return G*zz/(r*r*r)*m;
}



/* This is only for the exponential distributions at the moment,
   we will prepare this for the power law one later  */
double comp_Dphi_z_gas_exact(double RR,double zz)
{
  int i;
  double dphiz,dphiz2,e2;
  double Sigma0;
  double in1,in2,in3,bb;
  double deltaz,zpos;
  double Rd;


  if(N_GAS==0) return 0;


  switch(GasDistribution) {
        case 0:
          Rd= H;
          break;
        case 1:
          Rd= H*GasExpAlpha;
          break;
        case 2:
	  	  return comp_Dphi_z_gas_sph(RR,zz);
          break;
        case 3:
	  		/*return comp_Dphi_z_gas_sph(RR,zz);*/
	  		Rd=H*GasExpAlpha;
          break;
    }

  if(fabs(zz)<4*Z0)
    {
      deltaz=(6.0*Z0)/NSHEETS;

      dphiz=0;

      for(i=0;i<NSHEETS;i++)
        {
          zpos=-3.0*Z0 + (i+0.5)*Z0*6.0/NSHEETS;

          R=RR;
          z=zz-zpos;

          Sigma0=(M_GAS)/(2*PI*Rd*Rd) * deltaz/(2*Z0) * pow(2/(exp(zpos/Z0)+exp(-zpos/Z0)),2);

          in1=qromb(intz_g,0,2/Rd);

          bb=2;
          do
            {
              in2=qromb(intz_g,bb/Rd,(bb+2)/Rd);
              in3=qromb(intz_g_abs,bb/Rd,(bb+2)/Rd);
              in1+=in2;
              bb+=2;
            }
          while(fabs(in3/in1)>1e-2);

          dphiz += 2*PI*G*Sigma0*Rd*Rd*( in1 );
        }
      return dphiz;
    }
  else
    {
      R=RR;
      z=zz;
      Sigma0=(M_GAS)/(2*PI*Rd*Rd);

      in1=qromb(intz_g,0,2/Rd);

      bb=2;
      do
        {
          in2=qromb(intz_g,bb/Rd,(bb+2)/Rd);
          in3=qromb(intz_g_abs,bb/Rd,(bb+2)/Rd);
          in1+=in2;
          bb+=2;
        }
      while(fabs(in3/in1)>1e-2);

      dphiz = 2*PI*G*Sigma0*Rd*Rd*( in1 );

      return dphiz;

    }
}




double intz_g(double k)
{ 
  double Rd;

  switch(GasDistribution) {
        case 0:
          Rd= H;
          break;
        case 1:
          Rd= H*GasExpAlpha;
          break;
        case 2:
          Rd= H;
          break;
        case 3:
          Rd= H*GasExpAlpha;
          break;
    }

  if(z>0)
    return ( bessj0(k*R)*k*exp(-z*k)/pow(1+k*k*Rd*Rd,1.5));
  else
    return (-bessj0(k*R)*k*exp(z*k)/pow(1+k*k*Rd*Rd,1.5));
}


double intz_g_abs(double k)
{ 
  double Rd;

  switch(GasDistribution) {
        case 0:
          Rd= H;
          break;
        case 1:
          Rd= H*GasExpAlpha;
          break;
        case 2:
          Rd= H;
          break;
        case 3:
          Rd= H*GasExpAlpha;
          break;
    }

  if(z>0)
    return fabs( bessj0(k*R)*k*exp(-z*k)/pow(1+k*k*Rd*Rd,1.5));
  else
    return fabs(-bessj0(k*R)*k*exp(z*k)/pow(1+k*k*Rd*Rd,1.5));
}








/* -------------------------------------
     Compute:  dphi/dR
   ------------------------------------- */

double comp_Dphi_R_gas(double RR,double zz)
{
  double comp_Dphi_R_gas_sph(double RR,double zz);
  double comp_Dphi_R_gas_exact(double RR,double zz);

  if(RR>0)
    {
      if(sqrt(RR*RR+zz*zz)>10*H*GasExpAlpha)
        return comp_Dphi_R_gas_sph(RR,zz);
      else
        return comp_Dphi_R_gas_exact(RR,zz);
    }
  else
    return 0;
}




double comp_Dphi_R_gas_sph(double RR,double zz)
{
  double m;
  double r;

  r=sqrt(RR*RR+zz*zz);

  m=mass_cumulative_gas(r);

  if (m<=0.) printf("dingle 2 RR zz r m = %g %g %g %g \n",RR,zz,r,m);

  return G*RR/(r*r*r)*m;
}








double comp_Dphi_R_gas_exact(double RR,double zz)
{
  int i;
  double dphiR,e2;
  double Sigma0;
  double in1,in2,in3,bb;
  double deltaz,zpos;
  double Rd;


  if(N_GAS==0) return 0;

  switch(GasDistribution) {
        case 0:
          Rd= H;
          break;
        case 1:
          Rd= H*GasExpAlpha;
          break;
        case 2:
          Rd= H;
	  	  return comp_Dphi_R_gas_sph(RR,zz);
          break;
        case 3:
	      /*return comp_Dphi_R_gas_sph(RR,zz);*/
          Rd=H*GasExpAlpha;
          break;
    }
										      

  if(fabs(zz)<4*Z0)
    {
      deltaz=(6.0*Z0)/NSHEETS;
      dphiR=0;

      for(i=0;i<NSHEETS;i++)
	{
	  zpos=-3.0*Z0 + (i+0.5)*Z0*6.0/NSHEETS;
	  R=RR;
	  z=zz-zpos;

	  Sigma0=(M_GAS)/(2*PI*Rd*Rd) * deltaz/(2*Z0) * pow(2/(exp(zpos/Z0)+exp(-zpos/Z0)),2);

	  in1=qromb(intR_g,0,2/Rd);
	  bb=2;

	  do
	  {
	    in2=qromb(intR_g,bb/Rd,(bb+2)/Rd);
	    in3=qromb(intR_g_abs,bb/Rd,(bb+2)/Rd);
	    in1+=in2;
	    bb+=2;
	  }
	  while(fabs(in3/in1)>1e-2);

	  dphiR += 2*PI*G*Sigma0*Rd*Rd*( in1 );
	}

      return dphiR;
    }
  else
    {
      R=RR;
      z=zz;

      Sigma0=(M_GAS)/(2*PI*Rd*Rd);

      in1=qromb(intR_g,0,2/Rd);
      bb=2;

      do
      {

	in2=qromb(intR_g,bb/Rd,(bb+2)/Rd);
	in3=qromb(intR_g_abs,bb/Rd,(bb+2)/Rd);
	in1+=in2;
	bb+=2;
       }
       while(fabs(in3/in1)>1e-2);

       dphiR = 2*PI*G*Sigma0*Rd*Rd*( in1 );

       return dphiR;
  }
}





double comp_Dphi_R_gas_razorthin(double RR,double zz)
{
  double Sigma0,y;
  double dphidR;
  double Rd=0;

  if(N_GAS==0) return 0;

  switch(GasDistribution) {
        case 0:
          Rd= H;
          break;
        case 1:
          Rd= H*GasExpAlpha;
          break;
        case 2:
          Rd= H;
          return comp_Dphi_R_gas_sph(RR,zz);
          break;
        case 3:
          /*return comp_Dphi_R_gas_sph(RR,zz);*/
          Rd=H*GasExpAlpha;
          break;
    }


  if(RR>0)
    {

      Sigma0=(M_GAS)/(2*PI*Rd*Rd);
      y=RR/(2*Rd);

      if(y>1e-4) 
        dphidR = 2*PI*G*Sigma0*y*(bessi0(y)*bessk0(y)-bessi1(y)*bessk1(y));
      else
        dphidR =0;
  
      return dphidR;
    }
  else
    return 0;
} 






double intR_g(double k)
{
  double Rd;

  switch(GasDistribution) {
	case 0:
	  Rd= H;
	  break;
	case 1:
	  Rd= H*GasExpAlpha;
	  break;
	case 2:
	  Rd= H; 
	  break;
	case 3:
	  Rd= H*GasExpAlpha;
	  break;
  }

  if(z>=0)
    return bessj1(k*R)*k*exp(-z*k)/pow(1+k*k*Rd*Rd,1.5);
  else
    return bessj1(k*R)*k*exp( z*k)/pow(1+k*k*Rd*Rd,1.5);
}

double intR_g_abs(double k)
{
  double Rd;

  switch(GasDistribution) {
	case 0:
	  Rd= H;
	  break;
	case 1:
	  Rd= H*GasExpAlpha;
	  break;
	case 2:
	  Rd= H;
	  break;
	case 3:
      Rd= H*GasExpAlpha;
	  break;
  }

  if(z>=0)
    return fabs(bessj1(k*R)*k*exp(-z*k)/pow(1+k*k*Rd*Rd,1.5));
  else
    return fabs(bessj1(k*R)*k*exp( z*k)/pow(1+k*k*Rd*Rd,1.5));
}














