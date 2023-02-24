all:compile connect run
compile:
	g++ -c -I "./include" ./src/BinaryTree.cpp -o ./lib/BinaryTree.o
	g++ -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -c -I "./include" ./src/Kontrol.cpp -o ./lib/Kontrol.o
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o
	g++ -c -I "./include" ./src/Sistem.cpp -o ./lib/Sistem.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
connect:
	g++ ./lib/BinaryTree.o ./lib/Doku.o ./lib/Hucre.o ./lib/Kontrol.o ./lib/Organ.o ./lib/Organizma.o ./lib/Queue.o ./lib/Radix.o ./lib/Sistem.o ./lib/main.o -o ./bin/program
run:
	./bin/program