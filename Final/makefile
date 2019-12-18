##This is the makefile for project 4 which is the last project
##Dara Lim
##cs4280

#### Compiler and tool definitions shared by all build targets #####
CCC = g++
CXX = g++
BASICOPTS = -std=c++11
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# Define the target directories.
TARGETDIR_executable=.
TARGETDIR_statSem=build
SOURCEDIR=src


all: $(TARGETDIR_executable)/comp

## Target: statSem
OBJS_statSem =  \
	$(TARGETDIR_statSem)/handleInput.o \
	$(TARGETDIR_statSem)/parser.o \
	$(TARGETDIR_statSem)/scanner.o \
	$(TARGETDIR_statSem)/token.o \
	$(TARGETDIR_statSem)/symToken.o \
	$(TARGETDIR_statSem)/scope.o \
	$(TARGETDIR_statSem)/codeGen.o \
	$(TARGETDIR_statSem)/testTree.o \
	$(TARGETDIR_statSem)/staticSemantics.o \
	$(TARGETDIR_statSem)/main.o
USERLIBS_statSem = $(SYSLIBS_statSem) 
DEPLIBS_statSem =  
LDLIBS_statSem = $(USERLIBS_statSem)


# Link or archive
$(TARGETDIR_executable)/comp: $(TARGETDIR_statSem) $(OBJS_statSem) $(DEPLIBS_statSem)
	$(LINK.cc) $(CCFLAGS_statSem) $(CPPFLAGS_statSem) -o $@ $(OBJS_statSem) $(LDLIBS_statSem)


#start to compile source to object files

$(TARGETDIR_statSem)/handleInput.o: $(TARGETDIR_statSem) $(SOURCEDIR)/handleInput.cpp
	$(COMPILE.cc) $(CCFLAGS_statSem) $(CPPFLAGS_statSem) -o $@ $(SOURCEDIR)/handleInput.cpp
	
$(TARGETDIR_statSem)/parser.o: $(TARGETDIR_statSem) $(SOURCEDIR)/parser.cpp
	$(COMPILE.cc) $(CCFLAGS_statSem) $(CPPFLAGS_statSem) -o $@ $(SOURCEDIR)/parser.cpp
	
$(TARGETDIR_statSem)/scanner.o: $(TARGETDIR_statSem) $(SOURCEDIR)/scanner.cpp
	$(COMPILE.cc) $(CCFLAGS_statSem) $(CPPFLAGS_statSem) -o $@ $(SOURCEDIR)/scanner.cpp
	
$(TARGETDIR_statSem)/token.o: $(TARGETDIR_statSem) $(SOURCEDIR)/token.cpp
	$(COMPILE.cc) $(CCFLAGS_statSem) $(CPPFLAGS_statSem) -o $@ $(SOURCEDIR)/token.cpp
	
$(TARGETDIR_statSem)/symToken.o: $(TARGETDIR_statSem) $(SOURCEDIR)/symToken.cpp
	$(COMPILE.cc) $(CCFLAGS_statSem) $(CPPFLAGS_statSem) -o $@ $(SOURCEDIR)/symToken.cpp
	
$(TARGETDIR_statSem)/testTree.o: $(TARGETDIR_statSem) $(SOURCEDIR)/testTree.cpp
	$(COMPILE.cc) $(CCFLAGS_statSem) $(CPPFLAGS_statSem) -o $@ $(SOURCEDIR)/testTree.cpp
	
$(TARGETDIR_statSem)/staticSemantics.o: $(TARGETDIR_statSem) $(SOURCEDIR)/staticSemantics.cpp
	$(COMPILE.cc) $(CCFLAGS_statSem) $(CPPFLAGS_statSem) -o $@ $(SOURCEDIR)/staticSemantics.cpp

$(TARGETDIR_statSem)/scope.o: $(TARGETDIR_statSem) $(SOURCEDIR)/scope.cpp
	$(COMPILE.cc) $(CCFLAGS_statSem) $(CPPFLAGS_statSem) -o $@ $(SOURCEDIR)/scope.cpp

$(TARGETDIR_statSem)/codeGen.o: $(TARGETDIR_statSem) $(SOURCEDIR)/codeGen.cpp
	$(COMPILE.cc) $(CCFLAGS_statSem) $(CPPFLAGS_statSem) -o $@ $(SOURCEDIR)/codeGen.cpp
	
$(TARGETDIR_statSem)/main.o: $(TARGETDIR_statSem) $(SOURCEDIR)/main.cpp
	$(COMPILE.cc) $(CCFLAGS_statSem) $(CPPFLAGS_statSem) -o $@ $(SOURCEDIR)/main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_statSem)/* \
		$(TARGETDIR_executable)/comp
	$(CCADMIN)
	rm -f -r $(TARGETDIR_statSem)


# Create the target directory (if needed)
$(TARGETDIR_statSem):
	mkdir -p $(TARGETDIR_statSem)


# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-x86_64-Linux


