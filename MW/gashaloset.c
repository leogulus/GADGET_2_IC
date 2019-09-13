#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "nrsrc/nr.h"
#include "nrsrc/nrutil.h"

#include "prototypes.h"
#include "globvars.h"





void set_gashalo_velocities(void)
{
  int   i;
  double R,z;
  double vx,vy,vz;


  if(N_GASHALO==0) return;


  printf("set gashalo velocities...\t"); fflush(stdout);  
  
  for(i=1;i<=N_GASHALO;i++)
    {

      R=sqrt(xp_gashalo[i]*xp_gashalo[i] + yp_gashalo[i]*yp_gashalo[i]);
      z=zp_gashalo[i];

/*
      vr=0;
      vz=0;
      vphi=vstream_phi;
      vx=vr*xp_gashalo[i]/R - vphi*yp_gashalo[i]/R;
      vy=vr*yp_gashalo[i]/R + vphi*xp_gashalo[i]/R;
*/

      vx=0.0;
      vy=0.0;
      vz=0.0;
      vxp_gashalo[i]=vx;
      vyp_gashalo[i]=vy;
      vzp_gashalo[i]=vz;

      /* hydrostatic equilibrium */
      u_gashalo[i]=vdisp_rz/(GAMMA-1);
      
      /* all at Tvir */
      //u_gashalo[i]= 1.27e4*Mvir/Rvir;      /* had this multiplied by 15 at one point */
    }

  printf("done.\n"); fflush(stdout);
}




void set_gashalo_positions(void)
{
  int   i,countr,countz;
  double q,R,phi,theta;
  double AVOIDANCE_ZONE = 5.0;

  if(N_GASHALO==0) return;

  srand48(73);

  printf("set gashalo positions...\t"); fflush(stdout);

  for(i=1,countr=countz=0;i<=N_GASHALO;)
    {
      do
	{
	  q=drand48();
	  R=gashalo_q_to_r(q);
	}
      while(R > Rvir);

      phi=drand48()*PI*2;
      theta=acos(drand48()*2-1);
	  
      xp_gashalo[i]=R*sin(theta)*cos(phi);
      yp_gashalo[i]=R*sin(theta)*sin(phi);
      zp_gashalo[i]=R*cos(theta);

      /* avoid the central disk, since it screws things up and the contribution 
	   to the mass there is negligible anyways */
      if((R < AVOIDANCE_ZONE*H) && (fabs(zp_gashalo[i]) < AVOIDANCE_ZONE*Z0))
	{
	  printf("\nrejected i=%d R=%g  z=%g .... ",i,R,zp_gashalo[i]); fflush(stdout);
	  continue;
	}

      i++;
    }


  for(i=1;i<=N_GASHALO;i++)
    mp_gashalo[i]=M_GASHALO/N_GASHALO;

  printf("done\n"); fflush(stdout);

}




