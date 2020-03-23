MSG = add UVa solutions
SRC = 11942\ -\ Lumberjack\ Sequencing.cpp

prog: $(SRC)
	g++ -std=c++11 -Wall -O2 $(SRC) -o a -g

teste:
	@./a < in > out

in:
	@> in;\
	nano in

run:
	@./a

clean:
	@rm -f a

delete:
	@rm -f a in out;\
	ls

git:
	@git add .;\
	git commit -m "$(MSG)";\
	git push

debug:
	@gdb ./a
