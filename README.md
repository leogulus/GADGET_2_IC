# GADGET_2_IC README

These two codes are required to generate new initial condition (IC) code for GADGET-2.

1. MW: To create a single Milky Way-liked galaxy with dark matter halo, gas, disk, and bulge particles.
2. CombineGalaxies: To combine two galaxies together to create merging scenario


## Installation
- Change 'Makefile' in MW/ and 'makefile' in CombineGalaxies/ to be suitable for your machine.


## Usage
### MW
- `make clean` :To clear previous complied files
- `make`: To compile the code. The code is needed to be compiled everytime the parameters are changed in `main.c`.
- `./MakeHubbleType galaxy.dat`: To run with code with <output_name> (galaxy.dat).

All important parameters are in `main.c`. The important parameters to be changed include 
```
N_HALO=   10000;        /* desired number of particles in dark halo */
N_DISK=   5000;        /* desired number of collisionless particles in disk */
N_GAS=    10000;        /* number of gas particles in disk */ 
N_BULGE=  0;        /* number of bulge particles */ 
```

### CombineGalaxies
- `make clean` and then `make` to compile the code.
- `./CombineGalaxies galaxy.dat 0 45 galaxy.dat 90 0 50 300 0.2 combine_gal.dat`

```
./CombineGalaxies <fname_gal1> <theta1> <phi1> <fname_gal2> <theta2> <phi2> <rmin> <rstart> <eccentricity> <fname_galout>
(angles in degrees.)
```
- <iso_galaxy_1/2>: the isolated galaxy ICs
- <theta1/2>: the spherical ‘theta’ values that the angular momentum of galaxy 1/2 is offset from the angular momentum vector of the orbit
- <phi1/2>: the spherical ‘phi’ values that the angular momentum of galaxy 1/2
- <r_min>: the (keplarian calculated) pericenter passage distance
- <r_start>: the initial offset of the two galaxies
- <eccentricity>: eccentricity of the orbit
- <fname_galout>: output name "name.dat"


