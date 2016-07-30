
#OBJS specifies which files to compile as part of the project
OBJS = fighters.cpp game.cpp main.cpp

#CC specifies which compiler we're using
#CC = g++
CC = x86_64-w64-mingw32-g++ 

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -Wall

#LINKER_FLAGS specifies the libraries we're linking against
#LINKER_FLAGS = -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = adventures_of_linus_version_1.0_beta.exe

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
