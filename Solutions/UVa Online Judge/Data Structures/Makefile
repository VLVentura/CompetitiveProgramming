MSG = add UVa solutions
PROG = 12356\ -\ Army\ Buddies

tout:
	@./${PROG} < in > out

t:
	@./${PROG} < in 

in:
	@> in;\
	subl in

r:
	@./${PROG}

clean:
	@rm -f ${PROG}

delete:
	@rm -f ${PROG} in out;\
	ls

git:
	@rm -f ${PROG} in out Makefile;\
	git add .;\
	git commit -m "$(MSG)";\
	git push