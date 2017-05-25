ifndef CC
CC=gcc
endif

-include config_laird

ifeq ($(PKG_CONFIG),)
ifneq ($(CC),gcc)
# use cross-compile pkg-config
BINDIR=$(dir $(shell which $(CC)))
ifneq ($(BINDIR),)
PKG_CONFIG=$(BINDIR)pkg-config
MFLAGS += PKG_CONFIG=$(PKG_CONFIG)
endif
endif
endif

ifeq ($(OBJCOPY),)
ifneq ($(CC),gcc)
OBJCOPY=$(patsubst %-gcc,%-objcopy,$(CC))
else
OBJCOPY=objcopy
endif
endif

# check for typical errors before invoking wpa_supplicant Makefile
ifeq ($(shell which $(CC)),)
ERRORS += error-cc
endif

ifneq ($(PKG_CONFIG),)
ifeq ($(shell which $(PKG_CONFIG)),)
ERRORS += error-pkg-config
endif
endif

ifneq ($(OBJCOPY),)
ifeq ($(shell which $(OBJCOPY)),)
ERRORS += error-objcopy
endif
endif

ifeq ($(ERRORS),)
# invoke the wpa_supplicant Makefile
.DEFAULT:
	cp config_laird ../wpa_supplicant/.config
	make -C ../wpa_supplicant clean
	make -C ../wpa_supplicant $(MFLAGS) $(MAKECMDGOALS)
	@if [ -e ../wpa_supplicant/wpa_supplicant ]; \
	then \
		$(OBJCOPY) -S ../wpa_supplicant/wpa_supplicant wpa_supplicant; \
		echo "Output file ./wpa_supplicant with symbols stripped"; \
	fi
	@echo "Output files are in ../wpa_supplicant."
endif

target: .DEFAULT

help:
	@echo "Use this Makefile for building wpa_supplicant."
	@echo "For cross compiler builds, use:"
	@echo "    make CC=cross-compiler-prefix-gcc"
	@echo "Note: pkg-config and objcopy must also be available."

show-options:
	@echo "Using the following settings:"
	@echo "CC=$(CC)"
	@echo "PKG_CONFIG=$(PKG_CONFIG)"
	@echo "OBJCOPY=$(OBJCOPY)"

# Report common errors
error-cc:
	@echo "ERROR: cannot find compiler: $(CC)"

error-pkg-config:
	@echo "ERROR: cannot find pkg-config: $(PKG_CONFIG)"

error-objcopy:
	@echo "ERROR: cannot find objcopy: $(OBJCOPY)"

error-report: $(ERRORS)
	@echo "ERROR: there were errors preventing running the Makefile"

ifneq ($(ERRORS),)
# if errors occurred, report the errors
.DEFAULT:
	@make error-report
endif
