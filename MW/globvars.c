


/***********  INPUT PARAMETERS *********/

 char    OutputDir[500], OutputFile[500];


 double  CC;      /* halo concentration */
 double  Vvir;    /* circular velocity v_vir */
 double  LAMBDA;    /* spin parameter  */
 double  MD;        /* disk mass fraction */
 double  JD;        /* disk spin fraction */
 double  MB;        /* bulge mass fraction */
 double  GasFraction;  
 double  DiskHeight; 
 double  BulgeSize;
 double  HI_GasMassFraction;    /* in terms of the total gas mass */
 double  HI_GasDiskScaleLength;  /* in terms of scale length of the disk */ 

 double  Qstabilizefactor;

 double  HUBBLE;	/* allow Hubble parameter to be set in main.c */

 double  Z;		/* redshift of galaxy */

 int     GasDistribution;   /* 0 = exp. (normail), 1 = Mestel  */
 double  GasExpAlpha;       /* gas is exp. with Rd*Alpha scale length */
 double  PowerLawGamma;     /* power-law index, sigma ~ r^-gamma   (gamma=1 is mestel) */
 double  PowerLawCutOff;    /* in units of Rd, when gas disk is terminated */
 double  HoleRadius;        /* in units of Rd, when inner gas disk is cut off */
 double  HoleGamma;         /* speed with which that cutoff occurs (should be << HoleRadius) */
 double  SetInitModeAmp;    /* amplitude of 'seed' modes (m=1-4) in initial gas */
 double  SetInitModeCut;    /* cutoff radius of 'seed' modes (m=1-4) in initial gas */
 double  SetInitModeM; 	 	/* modenumber m for 'seed' mode in initial gas */

 int     BulgeDistribution; /* 0 = Hernquist, 1 = Spherical Exp. */

 int     N_HALO;    /* desired number of particles in halo */
 int     N_DISK;    /* desired number of collsionless particles in disk */
 int     N_GAS;     /* number of gas particles in stellar disk */ 
 int     N_BULGE;   /* number of gas particles in stellar disk */ 

 double  ColdFlowExtraMgas; /* cold flow parameters */
 double  ColdFlowMdot;
 double  ColdFlowTheta;
 double  ColdFlowPhi;
 double  ColdFlowRinner;
 double  ColdFlowRadius;

 int     N_GAS_DISK; 		/* number of gas particles in disk */
 int     N_GAS_FLOW; 		/* number of gas particles in cold flow */
 int     N_GASHALO;		/* number of gas particles in hot halo */

/*********************************************/





 double  EZ;	   /* as in H(z)=H0*E(z) */

 double  Mvir;     /* virial mass */
 double  M_TOTAL;  /* total mass */

 double  RS;       /* scale radius for halo */
 double  Rvir;     /* virial radius */ 
 double  H;        /* disk scale length */
 double  Z0;       /* disk thickness */
 double  A;        /* bulge scale radius */


 double  M_HALO;   /* total dark mass */
 double  M_DISK;   /* mass of stellar disk (collisionless part) */
 double  M_GAS;    /* gas mass in disk */
 double  M_GASHALO;/* gas mass in extended halo */
 double  M_BULGE;  /* mass of bulge */
 double  M_BH;     /* mass of seed BH */

 double  DARKMASS_IN_ROPT;  /* dark mass inside optical radius (3.2H) */

 double  halo_spinfactor;  /* computed streamin of dark matter */


 double RHO_0; /* normalization of halo density profile */
 double GasHalo_Beta; /* beta of halo gas beta profile */
 double GasHalo_Rc_over_Rs; /* ratio Rc/Rs for halo gas beta profile */


 double G;            /* gravitational constant */
 double H0;           /* Hubble constant */
 double UnitTime_in_s;
 double UnitMass_in_g;
 double UnitLength_in_cm;
 double UnitVelocity_in_cm_per_s;
 double UnitTime_in_Megayears;



/* particle data */

 double    *vmax2_halo,*vmax2_disk,*vmax2_bulge,*vmax2_gas,*vmax2_gashalo;

 double    *xp_halo,*yp_halo,*zp_halo,*mp_halo;
 double    *xp_disk,*yp_disk,*zp_disk,*mp_disk;
 double    *xp_bulge,*yp_bulge,*zp_bulge,*mp_bulge;
 double    *xp_gas,*yp_gas,*zp_gas,*mp_gas,*u_gas; 
 double    *xp_gashalo,*yp_gashalo,*zp_gashalo,*mp_gashalo,*u_gashalo;

 double    *vxp_halo,*vyp_halo,*vzp_halo;
 double    *vxp_disk,*vyp_disk,*vzp_disk;
 double    *vxp_bulge,*vyp_bulge,*vzp_bulge;
 double    *vxp_gas,*vyp_gas,*vzp_gas;
 double    *vxp_gashalo,*vyp_gashalo,*vzp_gashalo;





double  LL,HR; /* LL = extension of fields in R and z.
		  HR = extension of high resolution region in z */
double  dR;    /* delta R */





 double **Dphi_z,**Dphi_R,**Dphi_z_dR;  /* derivatives of total potential */
 double *epi_gamma2,*epi_kappa2;   /* epicycle gamma^2  */ 



/* halo velocity fields */

 double **VelDispRz_halo;
 double **VelDispPhi_halo;
 double **VelVc2_halo;
 double **VelStreamPhi_halo;
 double **VelDispRz_dR_halo;


/* bulge velocity fields */

 double **VelDispRz_bulge;
 double **VelDispPhi_bulge;
 double **VelVc2_bulge;
 double **VelStreamPhi_bulge;
 double **VelDispRz_dR_bulge;


/* disk velocity fields */

 double **VelDispRz_disk;
 double **VelDispPhi_disk;
 double **VelVc2_disk;
 double **VelStreamPhi_disk;
 double **VelDispRz_dR_disk;


/* gas velocity fields */

 double **VelDispRz_gas;
 double **VelDispPhi_gas;
 double **VelVc2_gas;
 double **VelStreamPhi_gas;
 double **VelDispRz_dR_gas;




/* auxiliary field */

 double *xl,*yl,*D2yl;
 double *list_z,*list_R,*list_RplusdR;






