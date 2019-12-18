## -*- Makefile -*-
##
## User: bill
## Time: Feb 28, 2017 6:07:22 PM
## Makefile created by Oracle Developer Studio.
##
## This file is generated automatically.
##


#### Compiler and tool definitions shared by all build targets #####
CCC = g++
CXX = g++
BASICOPTS = -std=c++11
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# Define the target directories.
TARGETDIR_executable=.
TARGETDIR_testSem=build
SOURCEDIR=src


all: $(TARGETDIR_executable)/comp

## Target: testSem
OBJS_testSem =  \
	$(TARGETDIR_testSem)/inputHandler.o \
	$(TARGETDIR_testSem)/parser.o \
	$(TARGETDIR_testSem)/scanner.o \
	$(TARGETDIR_testSem)/token.o \
	$(TARGETDIR_testSem)/tokenSymbol.o \
	$(TARGETDIR_testSem)/parseTree.o \
	$(TARGETDIR_testSem)/staticSemantics.o \
	$(TARGETDIR_testSem)/codeGen.o \
	$(TARGETDIR_testSem)/scope.o \
	$(TARGETDIR_testSem)/main.o
USERLIBS_testSem = $(SYSLIBS_testSem) 
DEPLIBS_testSem =  
LDLIBS_testSem = $(USERLIBS_testSem)


# Link or archive
$(TARGETDIR_executable)/comp: $(TARGETDIR_testSem) $(OBJS_testSem) $(DEPLIBS_testSem)
	$(LINK.cc) $(CCFLAGS_testSem) $(CPPFLAGS_testSem) -o $@ $(OBJS_testSem) $(LDLIBS_testSem)


# Compile source files into .o files

$(TARGETDIR_testSem)/inputHandler.o: $(TARGETDIR_testSem) $(SOURCEDIR)/inputHandler.cpp
	$(COMPILE.cc) $(CCFLAGS_testSem) $(CPPFLAGS_testSem) -o $@ $(SOURCEDIR)/inputHandler.cpp
	
$(TARGETDIR_testSem)/parser.o: $(TARGETDIR_testSem) $(SOURCEDIR)/parser.cpp
	$(COMPILE.cc) $(CCFLAGS_testSem) $(CPPFLAGS_testSem) -o $@ $(SOURCEDIR)/parser.cpp
	
$(TARGETDIR_testSem)/scanner.o: $(TARGETDIR_testSem) $(SOURCEDIR)/scanner.cpp
	$(COMPILE.cc) $(CCFLAGS_testSem) $(CPPFLAGS_testSem) -o $@ $(SOURCEDIR)/scanner.cpp
	
$(TARGETDIR_testSem)/token.o: $(TARGETDIR_testSem) $(SOURCEDIR)/token.cpp
	$(COMPILE.cc) $(CCFLAGS_testSem) $(CPPFLAGS_testSem) -o $@ $(SOURCEDIR)/token.cpp
	
$(TARGETDIR_testSem)/tokenSymbol.o: $(TARGETDIR_testSem) $(SOURCEDIR)/tokenSymbol.cpp
	$(COMPILE.cc) $(CCFLAGS_testSem) $(CPPFLAGS_testSem) -o $@ $(SOURCEDIR)/tokenSymbol.cpp
	
$(TARGETDIR_testSem)/parseTree.o: $(TARGETDIR_testSem) $(SOURCEDIR)/parseTree.cpp
	$(COMPILE.cc) $(CCFLAGS_testSem) $(CPPFLAGS_testSem) -o $@ $(SOURCEDIR)/parseTree.cpp
	
$(TARGETDIR_testSem)/staticSemantics.o: $(TARGETDIR_testSem) $(SOURCEDIR)/staticSemantics.cpp
	$(COMPILE.cc) $(CCFLAGS_testSem) $(CPPFLAGS_testSem) -o $@ $(SOURCEDIR)/staticSemantics.cpp
	
$(TARGETDIR_testSem)/codeGen.o: $(TARGETDIR_testSem) $(SOURCEDIR)/codeGen.cpp
	$(COMPILE.cc) $(CCFLAGS_testSem) $(CPPFLAGS_testSem) -o $@ $(SOURCEDIR)/codeGen.cpp
	
$(TARGETDIR_testSem)/scope.o: $(TARGETDIR_testSem) $(SOURCEDIR)/scope.cpp
	$(COMPILE.cc) $(CCFLAGS_testSem) $(CPPFLAGS_testSem) -o $@ $(SOURCEDIR)/scope.cpp
	
$(TARGETDIR_testSem)/main.o: $(TARGETDIR_testSem) $(SOURCEDIR)/main.cpp
	$(COMPILE.cc) $(CCFLAGS_testSem) $(CPPFLAGS_testSem) -o $@ $(SOURCEDIR)/main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_testSem)/* \
		$(TARGETDIR_executable)/comp
	$(CCADMIN)
	rm -f -r $(TARGETDIR_testSem)


# Create the target directory (if needed)
$(TARGETDIR_testSem):
	mkdir -p $(TARGETDIR_testSem)


# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-x86_64-Linux


