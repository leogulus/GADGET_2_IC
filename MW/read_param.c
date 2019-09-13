#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globvars.h"
#include "prototypes.h"


void read_parameterfile(char *fname)
{
#define FLOAT 1
#define STRING 2
#define INT 3
#define MAXTAGS 300

  FILE *fd;
  char buf[200], buf1[200], buf2[200], buf3[200];
  int i, j, nt;
  int id[MAXTAGS];
  void *addr[MAXTAGS];
  char tag[MAXTAGS][50];
  int errorFlag = 0;

  /* read parameter file on all processes for simplicty */

  nt = 0;

  strcpy(tag[nt], "CC");
  addr[nt] = &CC;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "Mvir");
  addr[nt] = &Mvir;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "LAMBDA");
  addr[nt] = &LAMBDA;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "M_DISK");
  addr[nt] = &M_DISK;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "M_GAS");
  addr[nt] = &M_GAS;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "M_BULGE");
  addr[nt] = &M_BULGE;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "DARKMASS_IN_ROPT");
  addr[nt] = &DARKMASS_IN_ROPT;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "H");
  addr[nt] = &H;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "DiskHeight");
  addr[nt] = &DiskHeight;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "BulgeSize");
  addr[nt] = &BulgeSize;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "BulgeDistribution");
  addr[nt] = &BulgeDistribution;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "N_HALO");
  addr[nt] = &N_HALO;
  id[nt++] = INT;

  strcpy(tag[nt], "N_DISK");
  addr[nt] = &N_DISK;
  id[nt++] = INT;

  strcpy(tag[nt], "N_GAS");
  addr[nt] = &N_GAS;
  id[nt++] = INT;

  strcpy(tag[nt], "N_BULGE");
  addr[nt] = &N_BULGE;
  id[nt++] = INT;


  strcpy(tag[nt], "GasDistribution");
  addr[nt] = &GasDistribution;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "GasExpAlpha");
  addr[nt] = &GasExpAlpha;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "PowerLawGamma");
  addr[nt] = &PowerLawGamma;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "PowerLawCutOff");
  addr[nt] = &PowerLawCutOff;
  id[nt++] = FLOAT;


  strcpy(tag[nt], "HI_GasMassFraction");
  addr[nt] = &HI_GasMassFraction;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "HI_GasDiskScaleLength");
  addr[nt] = &HI_GasDiskScaleLength;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "Qstabilizefactor");
  addr[nt] = &Qstabilizefactor;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "HUBBLE");
  addr[nt] = &HUBBLE;
  id[nt++] = FLOAT;

  strcpy(tag[nt], "Z");
  addr[nt] = &Z;
  id[nt++] = FLOAT;


  strcpy(tag[nt], "OutputDir");
  addr[nt] = OutputDir;
  id[nt++] = STRING;

  strcpy(tag[nt], "OutputFile");
  addr[nt] = OutputFile;
  id[nt++] = STRING;



  if((fd = fopen(fname, "r")))
    {
      while(!feof(fd))
	{
	  buf[0] = 0;
	  fgets(buf, 200, fd);

	  if(sscanf(buf, "%s%s%s", buf1, buf2, buf3) < 2)
	    continue;

	  if(buf1[0] == '%')
	    continue;

	  for(i = 0, j = -1; i < nt; i++)
	    if(strcmp(buf1, tag[i]) == 0)
	      {
		j = i;
		tag[i][0] = 0;
		break;
	      }

	  if(j >= 0)
	    {
	      switch (id[j])
		{
		case FLOAT:
		  *((double *) addr[j]) = atof(buf2);
		  break;
		case STRING:
		  strcpy(addr[j], buf2);
		  break;
		case INT:
		  *((int *) addr[j]) = atoi(buf2);
		  break;
		}
	    }
	  else
	    {
	      fprintf(stdout, "Error in file %s:   Tag '%s' not allowed or multiple defined.\n", fname, buf1);
	      errorFlag = 1;
	    }
	}
      fclose(fd);

    }
  else
    {
      fprintf(stdout, "Parameter file %s not found.\n", fname);
      errorFlag = 1;
    }


  for(i = 0; i < nt; i++)
    {
      if(*tag[i])
	{
	  fprintf(stdout, "Error. I miss a value for tag '%s' in parameter file '%s'.\n", tag[i], fname);
	  errorFlag = 1;
	}
    }

  if(errorFlag)
    {
      exit(1);
    }



#undef FLOAT
#undef STRING
#undef INT
#undef MAXTAGS
}
