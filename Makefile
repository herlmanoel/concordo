concordo: usuario.o servidor.o concordo.o sistema.o executor.o canal.o canalTexto.o canalVoz.o mensagem.o
	g++ -o concordo -Wall -ansi -pedantic usuario.o servidor.o concordo.o sistema.o executor.o canal.o canalTexto.o canalVoz.o mensagem.o

mensagem.o: src/Mensagem.cpp src/Mensagem.h
	g++  -c src/Mensagem.cpp

canalVoz.o: src/CanalVoz.cpp src/CanalVoz.h
	g++  -c src/CanalVoz.cpp

canalTexto.o: src/CanalTexto.cpp src/CanalTexto.h
	g++  -c src/CanalTexto.cpp

canal.o: src/Canal.cpp src/Canal.h
	g++  -c src/Canal.cpp

usuario.o: src/Usuario.cpp src/Usuario.h
	g++  -c src/Usuario.cpp

servidor.o: src/Servidor.cpp src/Servidor.h
	g++ -c src/Servidor.cpp

concordo.o: src/concordo.cpp
	g++ -c src/concordo.cpp

sistema.o: src/sistema.cpp src/sistema.h
	g++ -c src/sistema.cpp 

executor.o: src/executor.cpp src/executor.h
	g++ -c src/executor.cpp 

clean:
	rm *.o concordo

run:
	concordo
	# ./concordo