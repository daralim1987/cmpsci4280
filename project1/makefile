CCC = g++
CXX = g++
BASICOPTS = -std=c++11
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


TARGETDIR_testScanner=build


all: $(TARGETDIR_testScanner)/scanner

OBJS_testScanner =  \
	$(TARGETDIR_testScanner)/handleInput.o \
	$(TARGETDIR_testScanner)/main.o \
	$(TARGETDIR_testScanner)/scanner.o \
	$(TARGETDIR_testScanner)/testScanner.o \
	$(TARGETDIR_testScanner)/token.o \
	$(TARGETDIR_testScanner)/symToken.o
USERLIBS_testScanner = $(SYSLIBS_testScanner) 
DEPLIBS_testScanner =  
LDLIBS_testScanner = $(USERLIBS_testScanner)



$(TARGETDIR_testScanner)/scanner: $(TARGETDIR_testScanner) $(OBJS_testScanner) $(DEPLIBS_testScanner)
	$(LINK.cc) $(CCFLAGS_testScanner) $(CPPFLAGS_testScanner) -o $@ $(OBJS_testScanner) $(LDLIBS_testScanner)



$(TARGETDIR_testScanner)/handleInput.o: $(TARGETDIR_testScanner) handleInput.cpp
	$(COMPILE.cc) $(CCFLAGS_testScanner) $(CPPFLAGS_testScanner) -o $@ handleInput.cpp

$(TARGETDIR_testScanner)/main.o: $(TARGETDIR_testScanner) main.cpp
	$(COMPILE.cc) $(CCFLAGS_testScanner) $(CPPFLAGS_testScanner) -o $@ main.cpp

$(TARGETDIR_testScanner)/scanner.o: $(TARGETDIR_testScanner) scanner.cpp
	$(COMPILE.cc) $(CCFLAGS_testScanner) $(CPPFLAGS_testScanner) -o $@ scanner.cpp

$(TARGETDIR_testScanner)/testScanner.o: $(TARGETDIR_testScanner) testScanner.cpp
	$(COMPILE.cc) $(CCFLAGS_testScanner) $(CPPFLAGS_testScanner) -o $@ testScanner.cpp

$(TARGETDIR_testScanner)/token.o: $(TARGETDIR_testScanner) token.cpp
	$(COMPILE.cc) $(CCFLAGS_testScanner) $(CPPFLAGS_testScanner) -o $@ token.cpp

$(TARGETDIR_testScanner)/symToken.o: $(TARGETDIR_testScanner) symToken.cpp
	$(COMPILE.cc) $(CCFLAGS_testScanner) $(CPPFLAGS_testScanner) -o $@ symToken.cpp



clean:
	rm -f \
		$(TARGETDIR_testScanner)/testScanner \
		$(TARGETDIR_testScanner)/handleInput.o \
		$(TARGETDIR_testScanner)/main.o \
		$(TARGETDIR_testScanner)/scanner.o \
		$(TARGETDIR_testScanner)/testScanner.o \
		$(TARGETDIR_testScanner)/token.o \
		$(TARGETDIR_testScanner)/symToken.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_testScanner)


$(TARGETDIR_testScanner):
	mkdir -p $(TARGETDIR_testScanner)

.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-x86_64-Linux



