# invoke SourceDir generated makefile for main.pe430
main.pe430: .libraries,main.pe430
.libraries,main.pe430: package/cfg/main_pe430.xdl
	$(MAKE) -f C:\Users\Ryan\CSS_workspace_v6_0\SM/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\Ryan\CSS_workspace_v6_0\SM/src/makefile.libs clean

