concordo: usuario.o servidor.o concordo.o sistema.o executor.o canal.o canalTexto.o canalVoz.o mensagem.o
	g++ -o concordo -Wall -ansi -pedantic usuario.o servidor.o concordo.o sistema.o executor.o canal.o canalTexto.o canalVoz.o mensagem.o

mensagem.o: Mensagem.cpp Mensagem.h
	g++  -c Mensagem.cpp

canalVoz.o: CanalVoz.cpp CanalVoz.h
	g++  -c CanalVoz.cpp

canalTexto.o: CanalTexto.cpp CanalTexto.h
	g++  -c CanalTexto.cpp

canal.o: Canal.cpp Canal.h
	g++  -c Canal.cpp

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