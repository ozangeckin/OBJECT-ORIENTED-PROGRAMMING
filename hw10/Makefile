all:out

out: main.o balrog.o creature.o cyberdemon.o demon.o elf.o human.o
	g++ main.o balrog.o creature.o cyberdemon.o demon.o elf.o human.o -o out

main.o:main.cpp
	g++ -c main.cpp

balrog.o:balrog.cpp
	g++ -c balrog.cpp

creature.o:creature.cpp
	g++ -c creature.cpp

cyberdemo.o:cyberdemo.cpp
	g++ -c cyberdemon.cpp

demon.o:demon.cpp
	g++ -c demon.cpp

human.o:human.cpp
	g++ -c human.cpp

clean:
	rm -rf *o out
