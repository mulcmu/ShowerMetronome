#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/grace_3_00_02_64/packages;C:/ti/msp430/driverlib_1_95_00_49/packages;C:/ti/msp430/driverlib_1_95_00_49;C:/ti/ccsv6/ccs_base
override XDCROOT = c:/ti/xdctools_3_30_05_60_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/grace_3_00_02_64/packages;C:/ti/msp430/driverlib_1_95_00_49/packages;C:/ti/msp430/driverlib_1_95_00_49;C:/ti/ccsv6/ccs_base;c:/ti/xdctools_3_30_05_60_core/packages;..
HOSTOS = Windows
endif
