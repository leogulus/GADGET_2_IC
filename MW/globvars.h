
#define  GAMMA (5.0/3)
#define  PI  3.1415926


#define  GRAVITY     6.672e-8
#define  SOLAR_MASS  1.989e33
#define  CM_PER_MPC  3.085678e24
#define  SEC_PER_MEGAYEAR   3.155e13

#define  Omega_Lambda  0.7
#define  Omega_0   0.3

/*** random number generators ***/

#define BRAND	2255
#define DRAND	2435
#define GRAND	227
#define HRAND	449






/*** integration parameters ***/

#define FR 1.5
#define FZ 1.5

#define dRfac 0.1     /* delta R factor*/

#define  RSIZE 50  /* 40 */   /* size of force field array */
#define  ZSIZE 50  /* 50 */

#define NSHEETS 100  /* 100 */





/***********  INPUT PARAMETERS *********/

extern char    OutputDir[500], OutputFile[500];

extern double  CC;      /* halo concentration */
extern double  Vvir;    /* circular velocity v_vir */
extern double  LAMBDA;    /* spin parameter  */
extern double  MD;        /* disk mass fraction */
extern double  JD;        /* disk spin fraction */
extern double  MB;        /* bulge mass fraction */
extern double  GasFraction;  
extern double  DiskHeight; 
extern double  BulgeSize;
extern double  HI_GasMassFraction;    /* in terms of the total gas mass */
extern double  HI_GasDiskScaleLength;  /* in terms of scale length of the disk */ 

extern double  Qstabilizefactor;

extern double HUBBLE;
extern double Z;

extern int     GasDistribution;   /* 0 = exp. (normal), 1 = Power Law */
extern double  GasExpAlpha;       /* gas is exp. with Rd*Alpha scale length */
extern double  PowerLawGamma;     /* power-law index, sigma ~ r^-gamma   (gamma=1 is mestel) */
extern double  PowerLawCutOff;    /* in units of Rd, when gas disk is terminated */
extern double  HoleRadius;        /* in units of Rd, when inner gas disk is cut off */
extern double  HoleGamma;         /* speed with which that cutoff occurs (should be << HoleRadius) */
extern double  SetInitModeAmp;    /* amplitude of 'seed' modes (m=1-4) in initial gas */
extern double  SetInitModeCut;    /* cutoff radius of 'seed' modes (m=1-4) in initial gas */
extern double  SetInitModeM; 	  /* modenumber m for 'seed' mode in initial gas */

extern int     BulgeDistribution; /* 0= Hernquist, 1= Spherical Exp */

extern int     N_HALO;    /* desired number of particles in halo */
extern int     N_DISK;    /* desired number of collsionless particles in disk */
extern int     N_GAS;     /* number of gas particles in stellar disk */ 
extern int     N_BULGE;   /* number of particles in stellar bulge */ 


extern double  ColdFlowExtraMgas; /* cold flow parameters */
extern double  ColdFlowMdot;
extern double  ColdFlowTheta;
extern double  ColdFlowPhi;
extern double  ColdFlowRinner;
extern double  ColdFlowRadius;

extern int     N_GAS_DISK; 		/* number of gas particles in disk */
extern int     N_GAS_FLOW; 		/* number of gas particles in cold flow */

/*********************************************/


extern double EZ;	 /* E(z) as in H(z)=H0*E(z) */

extern double  Mvir;     /* virial mass */
extern double  M_TOTAL;  /* total mass */

extern double  RS;       /* scale radius for halo */
extern double  Rvir;     /* virial radius */
extern double  H;        /* disk scale length */
extern double  Z0;       /* disk thickness */
extern double  A;        /* bulge scale radius */


extern double  M_HALO;   /* total dark mass */
extern double  M_DISK;   /* mass of stellar disk (collisionless part) */
extern double  M_GAS;    /* gas mass in disk */
extern double  M_BULGE;  /* mass of bulge */
extern double  M_BH;     /* mass of seed BH */

extern double  DARKMASS_IN_ROPT;   /* dark mass inside optical radius (3.2H) */

extern double  halo_spinfactor;  /* computed streamin of dark matter */






extern double G;            /* gravitational constant */
extern double H0;           /* Hubble constant */
extern double UnitTime_in_s;
extern double UnitMass_in_g;
extern double UnitLength_in_cm;
extern double UnitVelocity_in_cm_per_s;
extern double UnitTime_in_Megayears;



/* particle data */

extern double    *vmax2_halo,*vmax2_disk,*vmax2_bulge,*vmax2_gas;

extern double    *xp_halo,*yp_halo,*zp_halo,*mp_halo;
extern double    *xp_disk,*yp_disk,*zp_disk,*mp_disk;
extern double    *xp_bulge,*yp_bulge,*zp_bulge,*mp_bulge;
extern double    *xp_gas,*yp_gas,*zp_gas,*mp_gas,*u_gas;

extern double    *vxp_halo,*vyp_halo,*vzp_halo;
extern double    *vxp_disk,*vyp_disk,*vzp_disk;
extern double    *vxp_bulge,*vyp_bulge,*vzp_bulge;
extern double    *vxp_gas,*vyp_gas,*vzp_gas;











double  LL;       /* LL = extension of fields in R and z. */






extern double **Dphi_z,**Dphi_R,**Dphi_z_dR;  /* derivatives of total potential */

extern double *epi_gamma2,*epi_kappa2;  /* epicycle gamma^2  */ 



/* halo velocity fields */

extern double **VelDispRz_halo;
extern double **VelDispPhi_halo;
extern double **VelVc2_halo;
extern double **VelStreamPhi_halo;
extern double **VelDispRz_dR_halo;


/* bulge velocity fields */

extern double **VelDispRz_bulge;
extern double **VelDispPhi_bulge;
extern double **VelVc2_bulge;
extern double **VelStreamPhi_bulge;
extern double **VelDispRz_dR_bulge;


/* disk velocity fields */

extern double **VelDispRz_disk;
extern double **VelDispPhi_disk;
extern double **VelVc2_disk;
extern double **VelStreamPhi_disk;
extern double **VelDispRz_dR_disk;



/* gas velocity fields */

extern double **VelDispRz_gas;
extern double **VelDispPhi_gas;
extern double **VelVc2_gas;
extern double **VelStreamPhi_gas;
extern double **VelDispRz_dR_gas;





/* auxiliary field */

extern double *xl,*yl,*D2yl;
extern double *list_z,*list_R,*list_RplusdR;






