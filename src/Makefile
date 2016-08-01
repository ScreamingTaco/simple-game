
#OBJS specifies which files to compile as part of the project
OBJS = fighters.cpp game.cpp main.cpp

#CC specifies which compiler we're using
#for linux
CC = g++ 

#for windows 64bit
#CC = x86_64-w64-mingw32-g++ 

#for windows 32bit
#CC = i686-w64-mingw32-g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -Wall

#LINKER_FLAGS specifies the libraries we're linking against
#for sdl programs
#LINKER_FLAGS = -lSDL2

#for windows
#LINKER_FLAGS = -static
#LINKER_FLAGS = -static-libgcc -static-libstdc++ -lpthread -L libwinpthread-1.dll

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = adventures_of_linus_version_1.1_beta

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
