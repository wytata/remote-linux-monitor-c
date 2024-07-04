WX_INCLUDE = `wx-config --cxxflags --libs`

gui: gui.cpp sshConnect.o
	g++ -lssh gui.cpp sshConnect.o -o gui ${WX_INCLUDE} -std=c++17

sshConnect.o: sshConnect.cpp sshConnect.h
	g++ -c sshConnect.cpp -o sshConnect.o -std=c++17 ${WX_INCLUDE}

clean:
	rm -f gui *.o
