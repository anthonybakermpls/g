WORKDIR = `pwd`

CC = gcc
CXX = clang++ 
AR = ar
LD = clang++ 
WINDRES = windres

INC = -Iinclude -Ilib -Ilib/glm/glm
CFLAGS = -std=c++11 -Wall -pthread
RESINC = 
LIBDIR = -L./lib
LIB=
#USERLIBS = lib/tinyxml2-master/tinyxml2/tinyxml2-cbp/bin/Release/libtinyxml2.a
USERLIBS = $(WORKDIR)/lib/tinyxml2-master/libtinyxml2.so
LDFLAGS = -pthread

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = 
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = g 
#bin/Debug/g

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = 
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = g
#bin/Release/g

OBJ_DEBUG = $(OBJDIR_DEBUG)/src/character.o $(OBJDIR_DEBUG)/src/character_manager.o $(OBJDIR_DEBUG)/src/command_line.o $(OBJDIR_DEBUG)/src/game.o $(OBJDIR_DEBUG)/src/item.o $(OBJDIR_DEBUG)/src/level.o $(OBJDIR_DEBUG)/src/main.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/src/character.o $(OBJDIR_RELEASE)/src/character_manager.o $(OBJDIR_RELEASE)/src/command_line.o $(OBJDIR_RELEASE)/src/game.o $(OBJDIR_RELEASE)/src/item.o $(OBJDIR_RELEASE)/src/level.o $(OBJDIR_RELEASE)/src/main.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG)/src || mkdir -p $(OBJDIR_DEBUG)/src

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG) 
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG) $(LDFLAGS_DEBUG) $(LIB_DEBUG) $(USERLIBS)

$(OBJDIR_DEBUG)/src/character.o: src/character.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/character.cpp -o $(OBJDIR_DEBUG)/src/character.o

$(OBJDIR_DEBUG)/src/character_manager.o: src/character_manager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/character_manager.cpp -o $(OBJDIR_DEBUG)/src/character_manager.o

$(OBJDIR_DEBUG)/src/command_line.o: src/command_line.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/command_line.cpp -o $(OBJDIR_DEBUG)/src/command_line.o

$(OBJDIR_DEBUG)/src/game.o: src/game.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/game.cpp -o $(OBJDIR_DEBUG)/src/game.o

$(OBJDIR_DEBUG)/src/item.o: src/item.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/item.cpp -o $(OBJDIR_DEBUG)/src/item.o

$(OBJDIR_DEBUG)/src/level.o: src/level.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/level.cpp -o $(OBJDIR_DEBUG)/src/level.o

$(OBJDIR_DEBUG)/src/main.o: src/main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/main.cpp -o $(OBJDIR_DEBUG)/src/main.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)/src

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE)/src || mkdir -p $(OBJDIR_RELEASE)/src

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE) $(USERLIBS)

$(OBJDIR_RELEASE)/src/character.o: src/character.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/character.cpp -o $(OBJDIR_RELEASE)/src/character.o

$(OBJDIR_RELEASE)/src/character_manager.o: src/character_manager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/character_manager.cpp -o $(OBJDIR_RELEASE)/src/character_manager.o

$(OBJDIR_RELEASE)/src/command_line.o: src/command_line.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/command_line.cpp -o $(OBJDIR_RELEASE)/src/command_line.o

$(OBJDIR_RELEASE)/src/game.o: src/game.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/game.cpp -o $(OBJDIR_RELEASE)/src/game.o

$(OBJDIR_RELEASE)/src/item.o: src/item.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/item.cpp -o $(OBJDIR_RELEASE)/src/item.o

$(OBJDIR_RELEASE)/src/level.o: src/level.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/level.cpp -o $(OBJDIR_RELEASE)/src/level.o

$(OBJDIR_RELEASE)/src/main.o: src/main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/main.cpp -o $(OBJDIR_RELEASE)/src/main.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)/src

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

