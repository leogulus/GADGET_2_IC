#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "nrsrc/nr.h"
#include "nrsrc/nrutil.h"
#include "prototypes.h"
#include "globvars.h"


#ifdef T3E
  typedef short int int4byte;   /* Note: int has 8 Bytes on the T3E ! */
#else
  typedef int int4byte;
#endif





struct io_header_1
{
  int4byte npart[6];
  double   mass[6];
  double   time;
  double   redshift;
  int4byte flag_sfr;
  int4byte flag_feedback;
  int4byte npartTotal[6];
  int4byte flag_cooling;
  int4byte num_files;
  double   BoxSize;
  double   Omega0;
  double   OmegaLambda;
  double   HubbleParam; 
  char     fill[256- 6*4- 6*8- 2*8- 2*4- 6*4- 2*4 - 4*8];  /* fills to 256 Bytes */
} header1;







void save_particles(char *fname)
{
  FILE *fd;
  int4byte i,d;
  float xyz[3];
  double t;
  int4byte blklen;
#define BLKLEN fwrite(&blklen, sizeof(blklen), 1, fd);

  
  if(!(fd=fopen(fname,"w")))
    {
      printf("error opening file %s\n",fname);
      exit(0);
    }

  printf("saveing initial conditions to file `%s'\n\n",fname);

  header1.npart[0]= header1.npartTotal[0]= N_GAS;
  header1.npart[1]= header1.npartTotal[1]= N_HALO;
  header1.npart[2]= header1.npartTotal[2]= N_DISK;
  header1.npart[3]= header1.npartTotal[3]= N_BULGE;
  header1.npart[4]= 0;
#ifdef ADDBH
  header1.npart[5]= 1;
#else
  header1.npart[5]= 0;
#endif

  header1.num_files= 0;

  for(i=0;i<6;i++)
    header1.mass[i]=0;

  if(N_GAS)
    header1.mass[0]=mp_gas[1];

  if(N_HALO)
    header1.mass[1]=mp_halo[1];

  if(N_DISK)
    header1.mass[2]=mp_disk[1];

  if(N_BULGE)
    header1.mass[3]=mp_bulge[1];

#ifdef ADDBH
  header1.mass[5]=M_BH;
#endif

  header1.flag_sfr=0;
  header1.flag_feedback=0;
  header1.flag_cooling=0;


  blklen=sizeof(header1);
  BLKLEN;
  fwrite(&header1, sizeof(header1), 1, fd);
  BLKLEN;


#ifdef ADDBH
  blklen=3*(N_GAS+N_HALO+N_DISK+N_BULGE+1)*sizeof(float);
#else
  blklen=3*(N_GAS+N_HALO+N_DISK+N_BULGE)*sizeof(float);
#endif
  BLKLEN;
  for(i=1;i<=N_GAS;i++)
    {
      xyz[0]=xp_gas[i];
      xyz[1]=yp_gas[i];
      xyz[2]=zp_gas[i];
      fwrite(xyz,sizeof(float),3,fd);
    }      
  for(i=1;i<=N_HALO;i++)
    {
      xyz[0]=xp_halo[i];
      xyz[1]=yp_halo[i];
      xyz[2]=zp_halo[i];
      fwrite(xyz,sizeof(float),3,fd);
    }      
  for(i=1;i<=N_DISK;i++)
    {
      xyz[0]=xp_disk[i];
      xyz[1]=yp_disk[i];
      xyz[2]=zp_disk[i];
      fwrite(xyz,sizeof(float),3,fd);
    }      
  for(i=1;i<=N_BULGE;i++)
    {
      xyz[0]=xp_bulge[i];
      xyz[1]=yp_bulge[i];
      xyz[2]=zp_bulge[i];
      fwrite(xyz,sizeof(float),3,fd);
    }
#ifdef ADDBH
  xyz[0]=xyz[1]=xyz[2]=0;
  fwrite(xyz,sizeof(float),3,fd);
#endif
  BLKLEN;



#ifdef ADDBH
  blklen=3*(N_GAS+N_HALO+N_DISK+N_BULGE+1)*sizeof(float);
#else
  blklen=3*(N_GAS+N_HALO+N_DISK+N_BULGE)*sizeof(float);
#endif
  BLKLEN;
  for(i=1;i<=N_GAS;i++)
    {
      xyz[0]=vxp_gas[i];
      xyz[1]=vyp_gas[i];
      xyz[2]=vzp_gas[i];
      fwrite(xyz,sizeof(float),3,fd);
    }    
  for(i=1;i<=N_HALO;i++)
    {
      xyz[0]=vxp_halo[i];
      xyz[1]=vyp_halo[i];
      xyz[2]=vzp_halo[i];
      fwrite(xyz,sizeof(float),3,fd);
    }      
  for(i=1;i<=N_DISK;i++)
    {
      xyz[0]=vxp_disk[i];
      xyz[1]=vyp_disk[i];
      xyz[2]=vzp_disk[i];
      fwrite(xyz,sizeof(float),3,fd);
    }      
  for(i=1;i<=N_BULGE;i++)
    {
      xyz[0]=vxp_bulge[i];
      xyz[1]=vyp_bulge[i];
      xyz[2]=vzp_bulge[i];
      fwrite(xyz,sizeof(float),3,fd);
    }
#ifdef ADDBH
  xyz[0]=xyz[1]=xyz[2]=0;
  fwrite(xyz,sizeof(float),3,fd);
#endif
  BLKLEN;


#ifdef ADDBH
  blklen=(N_GAS+N_HALO+N_DISK+N_BULGE+1)*sizeof(int4byte);
#else
  blklen=(N_GAS+N_HALO+N_DISK+N_BULGE)*sizeof(int4byte);
#endif
  BLKLEN;
#ifdef ADDBH
  for(i=1;i<=(N_GAS+N_HALO+N_DISK+N_BULGE+1);i++)
#else
  for(i=1;i<=(N_GAS+N_HALO+N_DISK+N_BULGE);i++)
#endif
    {
      fwrite(&i,sizeof(int4byte),1,fd);  /* ID */
    }
  BLKLEN;

  if(N_GAS)
    {
      blklen=(N_GAS)*sizeof(float);
      BLKLEN;
      for(i=1;i<=N_GAS;i++)
	{
	  xyz[0]= u_gas[i];
	  fwrite(xyz, sizeof(float), 1, fd);
	}
      BLKLEN;
    }

  fclose(fd);
}


