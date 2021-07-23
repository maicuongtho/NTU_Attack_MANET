#
# OMNeT++/OMNEST Makefile for NTUattack
#
# This file was generated with the command:
#  opp_makemake -f --deep -KINET_PROJ=../../inet -DINET_IMPORT -Iattacks/controlmessages/wormholeAttack -Iattacks/controlmessages/delayAttack -Iattacks/controlmessages/pathanBaitTimer -Ihackedmodules/routing/Pathan_Aodv -Ihackedmodules/routing/MDBM_Aodv -Ihackedmodules/routing/HHS_Aodv -Iattacks/controlmessages/blackholeAttack -Iattacks/controlmessages/grayholeAttack -I$$\(INET_PROJ\)/src/inet/networklayer/ipv4 -Iattacks/controlmessages/droppingAttack -Iattacks/controlmessages/floodingAttack -Iattacks -Iattacks/controlmessages/sinkholeAttack -Iattacks/controllers -Icommon/log -Ihackedmodules -I$$\(INET_PROJ\)/src/inet/routing/aodv -I$$\(INET_PROJ\)/src -L$$\(INET_PROJ\)/src -lINET$$\(D\)
#

# Name of target to be created (-o option)
TARGET = NTUattack$(D)$(EXE_SUFFIX)
TARGET_DIR = .

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(QTENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)
#USERIF_LIBS = $(QTENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -Iattacks/controlmessages/wormholeAttack \
    -Iattacks/controlmessages/delayAttack \
    -Iattacks/controlmessages/pathanBaitTimer \
    -Ihackedmodules/routing/Pathan_Aodv \
    -Ihackedmodules/routing/MDBM_Aodv \
    -Ihackedmodules/routing/HHS_Aodv \
    -Iattacks/controlmessages/blackholeAttack \
    -Iattacks/controlmessages/grayholeAttack \
    -I$(INET_PROJ)/src/inet/networklayer/ipv4 \
    -Iattacks/controlmessages/droppingAttack \
    -Iattacks/controlmessages/floodingAttack \
    -Iattacks \
    -Iattacks/controlmessages/sinkholeAttack \
    -Iattacks/controllers \
    -Icommon/log \
    -Ihackedmodules \
    -I$(INET_PROJ)/src/inet/routing/aodv \
    -I$(INET_PROJ)/src

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = $(LDFLAG_LIBPATH)$(INET_PROJ)/src  -lINET$(D)

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/attacks/controllers/NTU_Attack.o \
    $O/attacks/controllers/blackholeAttack/NTU_BlackholeAttack.o \
    $O/attacks/controllers/delayAttack/NTU_DelayingAttack.o \
    $O/attacks/controllers/droppingAttack/NTU_DroppingAttack.o \
    $O/attacks/controllers/floodingAttack/NTU_FloodingAttack.o \
    $O/attacks/controllers/grayholeAttack/NTU_GrayholeAttack.o \
    $O/attacks/controllers/pathanBaitTimer/PathanBaitTimer.o \
    $O/attacks/controllers/sinkholeAttack/NTU_SinkholeAttack.o \
    $O/attacks/controllers/wormholeAttack/NTU_WormholeAttack.o \
    $O/common/log/NA_NesgLog.o \
    $O/common/utils/NA_Utils.o \
    $O/hackedmodules/NTU_HackedModule.o \
    $O/hackedmodules/networklayer/ipv4/hacked_IPv4.o \
    $O/hackedmodules/networklayer/ipv4/hacked_IPv4NetworkLayer.o \
    $O/hackedmodules/routing/DebaratiAODV/DebaratiAODV.o \
    $O/hackedmodules/routing/DebaratiAODV_BH/DebaratiAODV_BH.o \
    $O/hackedmodules/routing/DokurerAodv_BH/BHdokurerAodv.o \
    $O/hackedmodules/routing/Dokurer_Aodv/dokurerAodv.o \
    $O/hackedmodules/routing/HHS_Aodv/hhsAodv.o \
    $O/hackedmodules/routing/MDBM_Aodv/MDBM_Aodv.o \
    $O/hackedmodules/routing/NiraliModi_AODV/niraAodv.o \
    $O/hackedmodules/routing/RrepAuth_AODV/RrepAuthAodv.o \
    $O/hackedmodules/routing/TnTaodv/TnTaodv.o \
    $O/hackedmodules/routing/TnTaodv_BH/TnTaodv_BH.o \
    $O/hackedmodules/routing/aodv/AodvControlPacketsSerializer.o \
    $O/hackedmodules/routing/aodv/AodvRouteData.o \
    $O/hackedmodules/routing/aodv/NTU_Aodv.o \
    $O/hackedmodules/routing/floodingAodv/floodNTU_Aodv.o \
    $O/nodes/NTU_delayerAodvRouter.o \
    $O/attacks/controlmessages/blackholeAttack/NTU_BlackholeMessage_m.o \
    $O/attacks/controlmessages/delayAttack/NTU_DelayMessage_m.o \
    $O/attacks/controlmessages/droppingAttack/NTU_DroppingMessage_m.o \
    $O/attacks/controlmessages/floodingAttack/NTU_FloodingM_m.o \
    $O/attacks/controlmessages/grayholeAttack/NTU_GrayholeMessage_m.o \
    $O/attacks/controlmessages/pathanBaitTimer/pathanBaitTimerMessage_m.o \
    $O/attacks/controlmessages/sinkholeAttack/NTU_SinkholeMessage_m.o \
    $O/attacks/controlmessages/wormholeAttack/NTU_WormholeMessage_m.o

# Message files
MSGFILES = \
    attacks/controlmessages/blackholeAttack/NTU_BlackholeMessage.msg \
    attacks/controlmessages/delayAttack/NTU_DelayMessage.msg \
    attacks/controlmessages/droppingAttack/NTU_DroppingMessage.msg \
    attacks/controlmessages/floodingAttack/NTU_FloodingM.msg \
    attacks/controlmessages/grayholeAttack/NTU_GrayholeMessage.msg \
    attacks/controlmessages/pathanBaitTimer/pathanBaitTimerMessage.msg \
    attacks/controlmessages/sinkholeAttack/NTU_SinkholeMessage.msg \
    attacks/controlmessages/wormholeAttack/NTU_WormholeMessage.msg

# SM files
SMFILES =

# Other makefile variables (-K)
INET_PROJ=../../inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIBS = $(OPPMAIN_LIB) $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)
ifneq ($(TOOLCHAIN_NAME),clangc2)
LIBS += -Wl,-rpath,$(abspath $(INET_PROJ)/src)
endif

COPTS = $(CFLAGS) $(IMPORT_DEFINES) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $(TARGET_DIR)/$(TARGET)

$(TARGET_DIR)/% :: $O/%
	@mkdir -p $(TARGET_DIR)
	$(Q)$(LN) $< $@
ifeq ($(TOOLCHAIN_NAME),clangc2)
	$(Q)-$(LN) $(<:%.dll=%.lib) $(@:%.dll=%.lib)
endif

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile $(CONFIGFILE)
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET) $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders smheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE) | msgheaders smheaders
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc -MD -MP -MF $O/$(basename $<)_m.h.d $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning $(TARGET)
	$(Q)-rm -rf $O
	$(Q)-rm -f $(TARGET_DIR)/$(TARGET)
	$(Q)-rm -f $(TARGET_DIR)/$(TARGET:%.dll=%.lib)
	$(Q)-rm -f $(call opp_rwildcard, . , *_m.cc *_m.h *_sm.cc *_sm.h)

cleanall:
	$(Q)$(MAKE) -s clean MODE=release
	$(Q)$(MAKE) -s clean MODE=debug
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

# include all dependencies
-include $(OBJS:%=%.d) $(MSGFILES:%.msg=$O/%_m.h.d)
