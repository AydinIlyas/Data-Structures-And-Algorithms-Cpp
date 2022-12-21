all:compile connect run
compile:
	g++ -c -I "./include" ./src/Node.cpp -o ./lib/Node.o
	g++ -c -I "./include" ./src/ListNode.cpp -o ./lib/ListNode.o
	g++ -c -I "./include" ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -c -I "./include" ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
connect:
	g++ ./lib/Node.o ./lib/ListNode.o ./lib/SatirListesi.o ./lib/YoneticiListesi.o ./lib/main.o -o ./bin/program
run:
	./bin/program