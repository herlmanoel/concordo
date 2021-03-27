concordo: usuario.o servidor.o sistema.o executor.o concordo.o
	g++ -o concordo -Wall -ansi -pedantic usuario.o servidor.o concordo.o sistema.o executor.o

usuario.o: Usuario.cpp Usuario.h
	g++  -c Usuario.cpp

servidor.o: Servidor.cpp Servidor.h
	g++ -c Servidor.cpp

concordo.o: concordo.cpp
	g++ -c concordo.cpp

sistema.o: sistema.cpp sistema.h
	g++ -c sistema.cpp 

executor.o: executor.cpp executor.h
	g++ -c executor.cpp 

clean:
	rm *.o concordo

run:
	concordo
	# ./concordo