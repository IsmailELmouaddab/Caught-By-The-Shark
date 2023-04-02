CC = g++
FLAGS = -ggdb -Wall

ALLOBJ= ./obj/Couleur.o ./obj/Corail.o ./obj/TabCorail.o ./obj/Requin.o ./obj/TabRequin.o ./obj/Perso.o ./obj/Ocean.o ./obj/Jeu.o

CORE = ./src/core/Ocean.cpp ./src/core/Jeu.cpp ./src/core/Couleur.cpp ./src/core/Perso.cpp ./src/core/TabPerso.cpp ./src/core/Corail.cpp ./src/core/TabCorail.cpp ./src/core/Requin.cpp ./src/core/TabRequin.cpp

SRCS_TXT = $(CORE) ./src/txt/txtJeu.cpp ./src/txt/winTxt.cpp ./src/txt/main_txt.cpp

LIB = -Isrc -Isrc/core -Isrc/sdl2 -Itxt

ifeq ($(OS), Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/include/SDL2/ \
			-Iextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/include/SDL2/ \
			-Iextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2/ \
			-Iextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include/SDL2/

	LIBS_SDL = -Lextern \
			-Lextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll

else
INCLUDE_DIR_SDL = -I/usr/include/SDL2
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
endif

all: ./bin/Test ./bin/mainTXT ./bin/mainSDL

./bin/Test: ./obj/Test.o ./obj/Couleur.o ./obj/Corail.o ./obj/TabCorail.o ./obj/Requin.o ./obj/TabRequin.o ./obj/Perso.o ./obj/Ocean.o ./obj/TabPerso.o
	$(CC) $(FLAGS) ./obj/Test.o ./obj/Couleur.o ./obj/Corail.o ./obj/TabCorail.o ./obj/Requin.o ./obj/TabRequin.o ./obj/Perso.o ./obj/TabPerso.o ./obj/Ocean.o -o ./bin/Test

./obj/Test.o: ./src/core/Test.cpp ./src/core/Couleur.h ./src/core/Corail.h ./src/core/TabCorail.h ./src/core/Requin.h ./src/core/TabRequin.h  ./src/core/Perso.h ./src/core/TabPerso.h
	$(CC) $(FLAGS) $(LIB) -c ./src/core/Test.cpp -o ./obj/Test.o

./bin/mainSDL: ./obj/SDLjeu.o $(ALLOBJ) ./obj/ModeSDL.o
	$(CC) $(FLAGS) $(ALLOBJ) ./obj/ModeSDL.o ./obj/SDLjeu.o -o ./bin/SDLjeu $(LIBS_SDL)

./obj/ModeSDL.o: ./src/SDL2/ModeSDL.h ./src/SDL2/ModeSDL.cpp ./src/core/Jeu.cpp
	$(CC) $(FLAGS) -c ./src/SDL2/ModeSDL.cpp $(INCLUDE_DIR_SDL) $(LIB) -o ./obj/ModeSDL.o

./obj/SDLjeu.o: ./src/SDL2/SDLjeu.cpp ./src/SDL2/ModeSDL.h
	$(CC) $(FLAGS) -c ./src/SDL2/SDLjeu.cpp $(INCLUDE_DIR_SDL) $(LIB) -o ./obj/SDLjeu.o

# ----------------------------------------------------- #

./obj/Couleur.o: ./src/core/Couleur.cpp ./src/core/Couleur.h
	$(CC) $(FLAGS) -c ./src/core/Couleur.cpp -o ./obj/Couleur.o

./obj/Perso.o: ./src/core/Perso.cpp ./src/core/Perso.h ./src/core/Ocean.h ./src/core/TabRequin.h ./src/core/Couleur.h
	$(CC) $(FLAGS) -c ./src/core/Perso.cpp -o ./obj/Perso.o

./obj/TabPerso.o: ./src/core/TabPerso.cpp ./src/core/TabPerso.h ./src/core/Perso.h
	$(CC) $(FLAGS) -c ./src/core/TabPerso.cpp -o ./obj/TabPerso.o

./obj/Corail.o: ./src/core/Corail.cpp ./src/core/Corail.h ./src/core/Couleur.h
	$(CC) $(FLAGS) -c ./src/core/Corail.cpp -o ./obj/Corail.o

./obj/TabCorail.o: ./src/core/TabCorail.cpp ./src/core/TabCorail.h ./src/core/Corail.h
	$(CC) $(FLAGS) -c ./src/core/TabCorail.cpp -o ./obj/TabCorail.o

./obj/Requin.o: ./src/core/Requin.cpp ./src/core/Requin.h
	$(CC) $(FLAGS) -c ./src/core/Requin.cpp -o ./obj/Requin.o

./obj/TabRequin.o: ./src/core/TabRequin.cpp ./src/core/TabRequin.h ./src/core/Requin.h
	$(CC) $(FLAGS) -c ./src/core/TabRequin.cpp -o ./obj/TabRequin.o

./obj/Ocean.o: ./src/core/Ocean.cpp ./src/core/Ocean.h
	$(CC) $(FLAGS) -c ./src/core/Ocean.cpp -o ./obj/Ocean.o

# ----------------------------------------------------- #

./bin/mainTXT: ./obj/main_txt.o ./obj/winTxt.o ./obj/txtJeu.o $(ALLOBJ)
	$(CC) $(FLAGS) $(ALLOBJ) ./obj/main_txt.o ./obj/winTxt.o ./obj/txtJeu.o -o ./bin/mainTXT

./obj/main_txt.o: ./src/txt/main_txt.cpp ./src/txt/winTxt.h ./src/txt/txtJeu.h ./src/core/Jeu.h
	$(CC) $(FLAGS) -c ./src/txt/main_txt.cpp $(LIB) -o ./obj/main_txt.o

./obj/txtJeu.o: ./src/txt/txtJeu.cpp ./src/txt/txtJeu.h ./src/txt/winTxt.h ./src/core/Jeu.h
	$(CC) $(FLAGS) -c ./src/txt/txtJeu.cpp $(LIB) -o ./obj/txtJeu.o

./obj/winTxt.o: ./src/txt/winTxt.cpp ./src/txt/winTxt.h
	$(CC) $(FLAGS) -c ./src/txt/winTxt.cpp -o ./obj/winTxt.o

./obj/Jeu.o: ./src/core/Jeu.cpp ./src/core/Jeu.h ./src/core/Perso.h ./src/core/Ocean.h
	$(CC) $(FLAGS) -c ./src/core/Jeu.cpp -o ./obj/Jeu.o



doc:
	doxygen -g doc/image.doxy

clean:
ifeq ($(OS), Windows_NT)
	del .\obj\*.o
	del .\bin\*.exe
else
	rm ./obj/*.o ./bin/main*
endif
