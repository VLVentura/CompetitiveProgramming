MSG = add UVa solutions
SRC = 11586\ -\ Train\ Tracks.cpp

prog: $(SRC)
	g++ -std=c++11 -Wall -O2 $(SRC) -o a -g

test:
	@./a < in > out

in:
	@> in;\
	subl in

run:
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
