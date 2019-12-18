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
TARGETDIR_parser=build
SOURCEDIR=src


all: $(TARGETDIR_executable)/parser

## Target: parser
OBJS_parser =  \
	$(TARGETDIR_parser)/inputHandler.o \
	$(TARGETDIR_parser)/parser.o \
	$(TARGETDIR_parser)/scanner.o \
	$(TARGETDIR_parser)/token.o \
	$(TARGETDIR_parser)/tokenSymbol.o \
	$(TARGETDIR_parser)/parseTree.o \
	$(TARGETDIR_parser)/main.o
USERLIBS_parser = $(SYSLIBS_parser) 
DEPLIBS_parser =  
LDLIBS_parser = $(USERLIBS_parser)


# Link or archive
$(TARGETDIR_executable)/parser: $(TARGETDIR_parser) $(OBJS_parser) $(DEPLIBS_parser)
	$(LINK.cc) $(CCFLAGS_parser) $(CPPFLAGS_parser) -o $@ $(OBJS_parser) $(LDLIBS_parser)


# Compile source files into .o files

$(TARGETDIR_parser)/inputHandler.o: $(TARGETDIR_parser) $(SOURCEDIR)/inputHandler.cpp
	$(COMPILE.cc) $(CCFLAGS_parser) $(CPPFLAGS_parser) -o $@ $(SOURCEDIR)/inputHandler.cpp
	
$(TARGETDIR_parser)/parser.o: $(TARGETDIR_parser) $(SOURCEDIR)/parser.cpp
	$(COMPILE.cc) $(CCFLAGS_parser) $(CPPFLAGS_parser) -o $@ $(SOURCEDIR)/parser.cpp
	
$(TARGETDIR_parser)/scanner.o: $(TARGETDIR_parser) $(SOURCEDIR)/scanner.cpp
	$(COMPILE.cc) $(CCFLAGS_parser) $(CPPFLAGS_parser) -o $@ $(SOURCEDIR)/scanner.cpp
	
$(TARGETDIR_parser)/token.o: $(TARGETDIR_parser) $(SOURCEDIR)/token.cpp
	$(COMPILE.cc) $(CCFLAGS_parser) $(CPPFLAGS_parser) -o $@ $(SOURCEDIR)/token.cpp
	
$(TARGETDIR_parser)/tokenSymbol.o: $(TARGETDIR_parser) $(SOURCEDIR)/tokenSymbol.cpp
	$(COMPILE.cc) $(CCFLAGS_parser) $(CPPFLAGS_parser) -o $@ $(SOURCEDIR)/tokenSymbol.cpp
	
$(TARGETDIR_parser)/parseTree.o: $(TARGETDIR_parser) $(SOURCEDIR)/parseTree.cpp
	$(COMPILE.cc) $(CCFLAGS_parser) $(CPPFLAGS_parser) -o $@ $(SOURCEDIR)/parseTree.cpp
	
$(TARGETDIR_parser)/main.o: $(TARGETDIR_parser) $(SOURCEDIR)/main.cpp
	$(COMPILE.cc) $(CCFLAGS_parser) $(CPPFLAGS_parser) -o $@ $(SOURCEDIR)/main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_parser)/* \
		$(TARGETDIR_executable)/parser
	$(CCADMIN)
	rm -f -r $(TARGETDIR_parser)


# Create the target directory (if needed)
$(TARGETDIR_parser):
	mkdir -p $(TARGETDIR_parser)


# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-x86_64-Linux


