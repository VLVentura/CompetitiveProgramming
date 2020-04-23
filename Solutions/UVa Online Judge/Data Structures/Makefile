MSG = add UVa solutions
PROG = 394\ -\ Mapmaker

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
	@rm -f ${PROG} in out;\
	git add .;\
	git commit -m "$(MSG)";\
	git push