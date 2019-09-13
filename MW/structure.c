#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "nrsrc/nr.h"
#include "nrsrc/nrutil.h"

#include "prototypes.h"
#include "globvars.h"




#define  N  400000   /* number of mass bins for halo */



/* a number of tables */

static double *rt,*mt,*m2r,*r2m;
static double *rfinal;  
static double *mfinal;
static double *rhofinal,*rho2r;  

static int III;   /* a dummy variable */



static double rvir_halo,a_halo,rho0_halo,rhot_halo,gam1_halo,p1_halo;






structure()
{
  double disk_angmomentum(void);
  double additional_mass_in_halo_cutoff(void);
  double darkmass_inside_ropt(void);
  double fc(double);
  double gc(double);
  int i,pass;
  double jhalo,jd;
  double dm=0;
  double x,ez, Omega_z, Delta_vir;
  double mass_dm;
 



  /*  new method  */

  ez = sqrt(Omega_Lambda 
		+ (1 - Omega_0 - Omega_Lambda) * (1+Z) * (1+Z)
		+ Omega_0 * (1+Z) * (1+Z) * (1+Z));
  printf("ez = %g\n",ez);
  Omega_z = Omega_0 * (1+Z) * (1+Z) * (1+Z) / (ez * ez);
  printf("Omega_z = %g\n",Omega_z);
  x = Omega_z - 1.0;

  Delta_vir = (18*PI*PI + 82*x -39*x*x) / Omega_z;
  printf("Delta_vir = %g\n",Delta_vir);



  printf("H= %g \n",H);
  Z0=DiskHeight*H;   /* sets disk thickness */
  A=BulgeSize*H;     /* sets bulge size */


  Z0=DiskHeight*H;   /* sets disk thickness */
  A=BulgeSize;       /* sets bulge size  -- now an absolute size */


  pass= 0;


  if(DARKMASS_IN_ROPT<0.0) 
    {
	/* setup NFW properties the old fashioned way -- no contraction */
	Mvir=Mvir+dm;
	Rvir=pow(2*G*Mvir/(Delta_vir*H0*H0*ez*ez*Omega_z),1.0/3.0);
	Vvir=sqrt(G*Mvir/Rvir);
	RS=Rvir/CC;
	M_TOTAL=Mvir + additional_mass_in_halo_cutoff();
	rho0_halo=Mvir/( 4*PI*(log(1+CC)-CC/(1+CC)) * RS*RS*RS);
	M_HALO=M_TOTAL;//-M_DISK-M_GAS-M_BULGE;
	jhalo=LAMBDA*sqrt(G)*pow(Mvir,1.5)*sqrt(2*Rvir/fc(CC));
	halo_spinfactor=1.5*LAMBDA*sqrt(2*CC/fc(CC))*pow(log(1+CC)-CC/(1+CC),1.5)/gc(CC);
	MD= (M_DISK+M_GAS)/Mvir;
	MB= M_BULGE/Mvir;
	setup_massprofile(0);  /* sets up NFW profile, with virial mass */
	mass_dm= darkmass_inside_ropt();   /*  dark matter mass inside optical radius */
	} 
	else
	{
  do
    {
	/* setup NFW properties */
	Mvir=Mvir+dm;
	Rvir=pow(2*G*Mvir/(Delta_vir*H0*H0*ez*ez*Omega_z),1.0/3.0);
	Vvir=sqrt(G*Mvir/Rvir);
	RS=Rvir/CC;
	M_TOTAL=Mvir + additional_mass_in_halo_cutoff();
	rho0_halo=Mvir/( 4*PI*(log(1+CC)-CC/(1+CC)) * RS*RS*RS);
	M_HALO=M_TOTAL;//-M_DISK-M_GAS-M_BULGE;
	jhalo=LAMBDA*sqrt(G)*pow(Mvir,1.5)*sqrt(2*Rvir/fc(CC));
	halo_spinfactor=1.5*LAMBDA*sqrt(2*CC/fc(CC))*pow(log(1+CC)-CC/(1+CC),1.5)/gc(CC);
	MD= (M_DISK+M_GAS)/Mvir;
	MB= M_BULGE/Mvir;
	
	if(pass==0)
	  {
		setup_massprofile(0);  /* sets up NFW profile, with virial mass */
		pass= 1;
	  }
	else
		setup_massprofile(1);

	solve_mass_shells();  /* adiabatic contraction */

	mass_dm= darkmass_inside_ropt();   /*  dark matter mass inside optical radius */

	dm= DARKMASS_IN_ROPT-mass_dm;

	if(fabs(dm)>0.1*DARKMASS_IN_ROPT)
	  {
	    dm= 5*dm;
	  }
	else
	  dm=dm*0.5;

     }
   while(fabs(2*dm) > 1e-3);
	}

  //RHO_0=M_GASHALO/(4*PI*qromb(halogas_profile_int,1e-6,Rvir));

  printf("\nRvir = %g\n",Rvir);
  printf("Vvir = %g\n",Vvir);
  printf("Mvir = %g     (c= %g)\n\n",Mvir,CC);
  printf("Mdisk  = %g\n",M_DISK);
  printf("Mgas   = %g\n",M_GAS);
  printf("Mbulge = %g\n\n",M_BULGE);
  printf("Dark Mass inside Ropt= %g   (DM_IN_ROPT=%g)\n\n",mass_dm,DARKMASS_IN_ROPT);
  printf("MD     = %g\n",MD);
  printf("MB     = %g\n",MB);
  printf("rho_s = %g\n", rho0_halo);
  printf("r_s = %g\n",RS);
  printf("E = %g\n",-G*M_TOTAL*M_TOTAL*fc(CC)/(2*Rvir));
  printf("J_halo = %g\n\n",jhalo);
  printf("\nTotal mass will be: %g\n",M_TOTAL);


  jd=disk_angmomentum(); /* computes disk momentum */
  JD= jd/jhalo;
  printf("JD=Jdisk/Jhalo= %g \n\n",JD);
      
  prepare_cumlative_profile();  /* prepare cumulative profile of dark mass */

}




prepare_cumlative_profile()
{
  double mass_cumulative_disk(double);
  double mass_cumulative_gas(double);
  double mass_cumulative_bulge(double);
  int i;



  for(i=2,mfinal[1]=0;i<=N;i++)
    {
      mfinal[i]= rt[i]/rfinal[i]* mt[i] ;//- mass_cumulative_disk(rfinal[i]) - mass_cumulative_bulge(rfinal[i]) - mass_cumulative_gas(rfinal[i]);
    }

  for(i=1;i<=(N-1);i++)
    {
      rhofinal[i]= (mfinal[i+1] - mfinal[i])/
	( 4.0*PI/3*( pow(rfinal[i+1],3) - pow(rfinal[i],3) ));


    }
  rhofinal[N]=0;

  spline(rfinal,mfinal,N,1e40,1e40,m2r);
  spline(mfinal,rfinal,N,1e40,1e40,r2m);
  spline(rfinal,rhofinal,N,1e40,1e40,rho2r);


  LL= rfinal[N];
}




double halo_mass(double r)
{
  double x;
  
  if(r>rfinal[N])
    x=mfinal[N];
  else
    splint(rfinal,mfinal,m2r,N,r,&x);
	//printf("from splint: rfinal0, mfinal0, m2r0, N, r, x=%g %g %g %d %g %g \n",rfinal[2],mfinal[2],m2r[2],N,r,x);
  return x;
}


double halo_q_to_r(double q)
{
  double m,x;

  m=mfinal[N]*q;

  splint(mfinal,rfinal,r2m,N,m,&x);

  return x;
}


double halo_rho(double r)
{
  double x;
  
  if(r>rfinal[N])
    x=0;
  else
    splint(rfinal,rhofinal,rho2r,N,r,&x);

  return x;
}









double disk_angmomentum(void)
{
  double jdisk_int(double);
  double jgas_int(double);
  double jbulge_int(double);
  double dmin(double a,double b);
  double j_disk= 0, j_gas= 0, j_bulge= 0;

/* j_diskplusgas= qromb(jdiskplusgas_int,0,dmin(40*H,Rvir)); */
/* j_bulge= M_BULGE*qromb(jbulge_int,0,dmin(30*H,Rvir));  if we want a rotating bulge */
  j_disk= qromb(jdisk_int,0,dmin(30*H,Rvir));
  printf("j_disk1= %g\n",j_disk);
  j_gas= qromb(jgas_int,0,dmin(100*H,Rvir));


  printf("j_disk= %g\n",j_disk);
  printf("j_gas=  %g\n",j_gas);
  printf("j_bulge=%g\n",j_bulge);


  return j_disk+j_gas+j_bulge;
}

double dmin(double a,double b)
{
  if(a<b)
    return a;
  else
    return b;
}




double jdisk_int(double x)
{
  double vc2,Sigma0,vc,y;
  double jint=0;
  double mass_total_dark(double radius);
  double mass_cumulative_bulge(double radius);
  double Rd;

  Rd=1.0;
  //printf("GasDistribution = %d \n",GasDistribution);
  switch(GasDistribution) {
        case 0:
          Rd*= H;
          break;
        case 1:
          Rd*= H*GasExpAlpha;
          break;
        case 2:
          Rd*= H;
          break;
        case 3:
          Rd*= 1.0*H;
          break;
    }

  if(x>1e-20)
    {
      vc2= G * (mass_total_dark(x) + mass_cumulative_bulge(x) + mass_cumulative_disk(x) + mass_cumulative_gas(x) + M_BH) /x;
/*  printf("checking vc2, x, mdm, mb= %g %g %g %g\n",vc2,x,mass_total_dark(x),mass_cumulative_bulge(x)); */
/*    vc2= G * (mass_total_dark(x) + mass_cumulative_bulge(x) + mass_cumulative_gas(x)) /x;  */
/*    vc2= G * (mass_total_dark(x) + mass_cumulative_bulge(x) + mass_cumulative_disk(x)) /x;  */
    }
  else
    vc2=0;


  if(vc2<0)
    {
      vc2=0;
      printf("wwww1\n");
      exit(0);
    }

  //printf("jdisk_int_1: vc2= %g\n",vc2);

/*  -----------------------------------------
 *    Get Disk Contribution to Vc
 *  ----------------------------------------- */

  Sigma0=(M_DISK)/(2*PI*H*H);
  y=x/(2*H);

  if(y>1e-4) 
    vc2+= 4*PI*G*Sigma0*H*y*y*(bessi0(y)*bessk0(y)-bessi1(y)*bessk1(y));    /* bt p. 78. eq.2-169 */
    	
  //printf("jdisk_int_2: vc2= %g\n",vc2);


/*  -----------------------------------------
 *    Get Gas Disk Contribution to Vc
 *  ----------------------------------------- */

 Sigma0=(M_GAS)/(2*PI*Rd*Rd);
 y=x/(2*Rd);

 if(y>1e-4)
   vc2+= 4*PI*G*Sigma0*Rd*y*y*(bessi0(y)*bessk0(y)-bessi1(y)*bessk1(y));


  vc=sqrt(vc2);

  //printf("jdisk_int_3: vc2= %g %g %g %g %g %g %g\n",vc2,x,y,Rd,Sigma0,M_GAS,H);
  //printf("jdisk_int_3.5: %g %g %g %g\n",bessi0(y),bessk0(y),bessi1(y),bessk1(y));


  /* disk angular momentum */
  jint= M_DISK*pow(x/H,2)*vc*exp(-x/H);

  //printf("jdisk_int_4: vc2= %g\n",jint);

  return jint;
}



double jgas_int(double x)
{
  double vc2,Sigma0,vc,y;
  double jint=0;
  double mass_total_dark(double radius);
  double mass_cumulative_bulge(double radius);
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
          Rd= 1.0*H;
          break;
    }

  if(x>1e-20)
    {
      vc2= G * (mass_total_dark(x) + mass_cumulative_bulge(x) + mass_cumulative_disk(x) + mass_cumulative_gas(x) + M_BH) /x;
/*    vc2= G * (mass_total_dark(x) + mass_cumulative_bulge(x) + mass_cumulative_gas(x)) /x;  */
/*    vc2= G * (mass_total_dark(x) + mass_cumulative_bulge(x) + mass_cumulative_disk(x)) /x;  */
    }
  else
    vc2=0;


  if(vc2<0)
    {
      vc2=0;
      printf("wwww2\n");
      exit(0);
    }

/*  -----------------------------------------
 *    Get Disk Contribution to Vc
 *  ----------------------------------------- */

  Sigma0=(M_DISK)/(2*PI*H*H);
  y=x/(2*H);

  if(y>1e-4)
    vc2+= 4*PI*G*Sigma0*H*y*y*(bessi0(y)*bessk0(y)-bessi1(y)*bessk1(y));    /* bt p. 78. eq.2-169 */



/*  -----------------------------------------
 *    Get Gas Disk Contribution to Vc
 *  ----------------------------------------- */

 Sigma0=(M_GAS)/(2*PI*Rd*Rd);
 y=x/(2*Rd);

 if(y>1e-4)
   vc2+= 4*PI*G*Sigma0*Rd*y*y*(bessi0(y)*bessk0(y)-bessi1(y)*bessk1(y));


  vc=sqrt(vc2);


  /* gas angular momentum */
  jint= M_GAS*pow(x/Rd,2)*vc*exp(-x/Rd);

  return jint;
}








solve_mass_shells()
{
  int i;
  double zriddr(double (*func)(double), double x1, double x2, double xacc);
  double masszero(double);


  for(i=2;i<=(N-1);i++)
    {
      III=i;
      rfinal[i]=zriddr(masszero,0,rt[N],1e-6*rt[2]);
    }


  for(i=2,mfinal[1]=0;i<=N;i++)
    {
      mfinal[i]= rt[i]/rfinal[i]* mt[i] - mass_cumulative_disk(rfinal[i]) - mass_cumulative_bulge(rfinal[i]) - mass_cumulative_gas(rfinal[i]);
    }

  spline(rfinal,mfinal,N,1e40,1e40,m2r);
  spline(mfinal,rfinal,N,1e40,1e40,r2m);

}


double masszero(double rf)
{
  double mi,ri;
  double mass_cumulative_gas(double r);
  double mass_cumulative_disk(double r);
  double mass_cumulative_bulge(double r);  
  
  mi=mt[III];
  ri=rt[III];

  return mi*ri-rf*( (1- Mvir/mt[N]*(MD+MB))*mi + mass_cumulative_disk(rf) + mass_cumulative_bulge(rf) + mass_cumulative_gas(rf));
}









double darkmass_inside_ropt(void)
{
  double ropt;
  double mass_total_dark(double radius);

  ropt= 3.2*H;
/*
  do
    {
	i++;
    }
  while(rfinal[i]<(3.2*H));

  double mass_total_dark(double radius);

  return mfinal[i-1];
*/

  return mass_total_dark(ropt);
}











double mass_total_dark(double radius)
{
  double x;

  if(radius>rfinal[N])
{
    x=mfinal[N];
    /*  printf("dumping on inner if clause in mass_total_dark, x, r, rf, N= %g %g %g %g\n",x,radius,rfinal[N],N); */
}
  else
{
 //printf(" R2 = %g %g %g \n",radius,mfinal[N],rfinal[N]);
splint(rfinal,mfinal,m2r,N,radius,&x);
/*      printf("dumping on outer if clause in mass_total_dark, x, r, rf, mf= %g %g %g %g\n",x,radius,rfinal[N],mfinal); */
}
  return x;
}




setup_massprofile(int mode)
{
  int i,icount;
  double q,s,qq,f,f_,ds,r;


  if(mode==0)
    {
	rt=dvector(1,N);
	mt=dvector(1,N);
	mfinal=dvector(1,N);
	r2m=dvector(1,N);
	m2r=dvector(1,N);
	rfinal=dvector(1,N);
	rhofinal=dvector(1,N);
	rho2r=dvector(1,N);  
    }

  if(mode==1)
    {
	for(i=1;i<=N;i++)
	  {
	    rt[i]= 0;
	    mt[i]= 0;
	    mfinal[i]= 0;
	    r2m[i]= 0;
	    m2r[i]= 0;
	    rfinal[i]= 0;
	    rhofinal[i]= 0;
	    rho2r[i]= 0;
	  }
    }



  for(i=2, mt[1]=rt[1]=0 ;i<=N;i++)
    {
      mt[i]=(i-1.01)*(M_TOTAL/(N-1));

      q=mt[i]/M_TOTAL;

      if(q< (10.*Mvir/M_TOTAL))
	{
	  s=10.*q;
	  qq=q*M_TOTAL/(4*PI*rho0_halo*RS*RS*RS);
	  qq=q;
	  /*
	  //printf(" Mvir, M_TOTAL = %g %g \n",Mvir,M_TOTAL);
	  //printf(" i, q = %d %g \n",i,q);
	  icount=1;
	  */
	  do
	    {
	      f=log(1+s)-s/(1+s)-qq;
	      f_=s/(1+s)/(1+s);
	      ds=-0.1*f/f_;
	      /*
	      //printf("s ds q icount = %g %g %g %d \n",s,ds,qq,icount);
		  //if(s>0 && s<0.1) {
		   //ds=qq*(1+s)*(1+s)/s - s*(1/2+s/3-s*s/12+s*s*s/30-s*s*s*s/60);
		   //printf(" mod ds = %g \n",ds);
		   /* The problem is that the 'log' expansion gets inaccurate 
		        at low s, which screws up everything at small R in the halo */
		   //}*/
	      if(fabs(ds)/s > 0.01)
		   ds=s*0.01*ds/fabs(ds);
	      s+=ds;
	      /*
	      //icount++;
	      //if (icount%1000 == 0) {
	        //s=2.*drand48()*s;
	        //printf("icount = %d \n",icount);
	        //}*/
	    }
	    /* ARGH! After all that, its really just 
	         an under-resolution problem from using too 
	         few bins in the stepping routine: instead of 4000, 
	         want something much more like >N_particles, say 400,000+ */
	  while(fabs(ds/s)>1e-10);
	}
      else
	{
printf("i=%d  q=%g\n",i,q); fflush(stdout);
	  s=Rvir/RS;
	  do
	    {
	      f=gam1_halo*gammp(3+a_halo,s)-p1_halo-q*M_TOTAL+Mvir;
	      f_=gam1_halo*exp((a_halo+2)*log(s)-s-gammln(a_halo+3));
	      ds=-f/f_;
	      s+=ds;
	    }
	  while(fabs(ds/s)>1e-8);
	}
	
      r=s*RS;
      rt[i]=r;
    }

  for(i=1;i<=N;i++)
    rfinal[i]=rt[i];

  spline(rfinal,mt,N,1e40,1e40,m2r);
  spline(mt,rfinal,N,1e40,1e40,r2m);
  /* OK, rt here ultimately controls rfinal and so LL, the outer limit 
      to which integration is carried. Also, the initial setup here 
      is what leads to the 'excess' of stuff in the center of the halo 
      at the end of the computation */
}








double additional_mass_in_halo_cutoff(void)
{
  return 0;

  a_halo=CC-(1+3*CC)/(1+CC);
  rho0_halo=Mvir/( 4*PI*(log(1+CC)-CC/(1+CC)) * RS*RS*RS);
  rhot_halo=rho0_halo/(CC*(1+CC)*(1+CC));
  gam1_halo=4*PI*rhot_halo*Rvir*Rvir*Rvir*exp(CC+gammln(3+a_halo)-(3+a_halo)*log(CC));
  p1_halo=gam1_halo*gammp(3+a_halo,CC);
  
  return gam1_halo-p1_halo;
}





double fc(double c)
{
  return c*(0.5-0.5/pow(1+c,2)-log(1+c)/(1+c))/pow(log(1+c)-c/(1+c),2);
}

double gc(double c)
{
  double gc_int(double);
  return qromb(gc_int,0,c);
}

double gc_int(double x)
{
  return pow(log(1+x)-x/(1+x),0.5)*pow(x,1.5)/pow(1+x,2);
}





















write_cumulative_mass()
{
  FILE *fd;
  int i;

  fd=fopen("cummass.txt","w");

  for(i=1;i<=N;i++)
    {
      fprintf(fd,"%g %g %g %g %g \n", rt[i]/Rvir, rfinal[i]/Rvir, mt[i]/Mvir, 
	      mass_cumulative_disk(rfinal[i])/Mvir , mt[i]/Mvir  );
    }
  fclose(fd);
}



