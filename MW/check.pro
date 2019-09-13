pro check, name
setup_plot
f=fload_initial_conditions(name)
rg=fload_gas_xyz('r') & mg=fload_gas_mass(1) & sg=sort(rg) & rg=rg[sg] & mg=mg[sg] & mgt=total(mg,/cumulative)
rd=fload_disk_xyz('r') & md=fload_disk_mass(1) & sd=sort(rd) & rd=rd[sd] & md=md[sd] & mdt=total(md,/cumulative)
rb=fload_bulge_xyz('r') & mb=fload_bulge_mass(1) & sb=sort(rb) & rb=rb[sb] & mb=mb[sb] & mbt=total(mb,/cumulative)
rh=fload_halo_xyz('r') & mh=fload_halo_mass(1) & sh=sort(rh) & rh=rh[sh] & mh=mh[sh] & mht=total(mh,/cumulative)

!p.multi=[0,2,0,0,0]

  plot,rg,mgt,/xlog,/ylog
 oplot,rd,mdt,color=80
 oplot,rb,mbt,color=250
 oplot,rh,mht,color=150

 print, max(mgt), max(mdt), max(mbt), max(mht)
 
 
 plot,rh,mht,/xlog,/ylog
 rv=70.2786 & c=15. & rs=rv/c & n=(1.+c)/((1.+c)*alog(1.+c)-c) & x=rh/rs 
 f=(-1.+alog(1.+x)+1./(1.+x))*1.
 oplot,rh,max(mht)*f,color=250
 print, max(x), max(f), n
 
 
 vx=fload_gas_v('x') & vy=fload_gas_v('y') & vz=fload_gas_v('z')
 vv=sqrt(vx*vx+vy*vy+vz*vz) & vs=vv[sg]
 ;plot,rg,vs,/xlog,/ylog,psym=3


 vx=fload_halo_v('x') & vy=fload_halo_v('y') & vz=fload_halo_v('z')
 vv=sqrt(vx*vx+vy*vy+vz*vz) & vs=vv[sh]
 ;plot,rh,vs,/xlog,/ylog,psym=3
 
 ;plot,rh,mht/(rh*rh*rh),/xlog,/ylog
end