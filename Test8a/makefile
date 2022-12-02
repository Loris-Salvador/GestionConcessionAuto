CC = g++
EXEC = Test8a
DEBUG = #-D DEBUG

Fichier.cpp = Classes/
Fichier.o = Classes/
Fichier.h = Classes/

SRC = $(wildcard $(Fichier.cpp)*.cpp)
TMP = $(SRC:$(Fichier.cpp)%=$(Fichier.o)%)
OBJ = $(TMP:.cpp=.o)


all : $(EXEC)

$(Fichier.o)%.o :	$(Fichier.cpp)%.cpp
	$(CC) -o $@ -c $< $(DEBUG) -I $(Fichier.h)


$(EXEC) :	$(OBJ) $(EXEC).cpp
	$(CC) -o $@ $(OBJ) $(EXEC).cpp $(DEBUG) -I $(Fichier.o) -I $(Fichier.h)


clean:
	rm $(Fichier.o)*.o
