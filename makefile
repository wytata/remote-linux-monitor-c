WX_INCLUDE = `wx-config --cxxflags --libs aui,core,base`

gui: gui.cpp sshConnect.o FileSystem.o Processes.o Resources.o System.o
	g++ -lssh gui.cpp sshConnect.o FileSystem.o Processes.o Resources.o System.o -o gui ${WX_INCLUDE} -std=c++17

Processes.o: Processes.cpp Processes.h
	g++ -c Processes.cpp -o Processes.o -std=c++17 ${WX_INCLUDE}

Resources.o: Resources.cpp Resources.h
	g++ -c Resources.cpp -o Resources.o -std=c++17 ${WX_INCLUDE}

System.o: System.cpp System.h
	g++ -c System.cpp -o System.o -std=c++17 ${WX_INCLUDE}

FileSystem.o: FileSystem.cpp FileSystem.h
	g++ -c FileSystem.cpp -o FileSystem.o -std=c++17 ${WX_INCLUDE}

sshConnect.o: sshConnect.cpp sshConnect.h
	g++ -c sshConnect.cpp -o sshConnect.o -std=c++17 ${WX_INCLUDE}

clean:
	rm -f gui *.o
