MSG = add UVa solutions
SRC = 278\ -\ Chess.cpp

prog: $(SRC)
	g++ -std=c++11 -Wall -O2 $(SRC) -o a -g

tout:
	@./a < in > out

t:
	@./a < in 

in:
	@> in;\
	subl in

r:
	@./a

clean:
	@rm -f a

delete:
	@rm -f a in out;\
	ls

git:
	@rm -f a in out;\
	git add .;\
	git commit -m "$(MSG)";\
	git push

debug:
	@gdb ./a
