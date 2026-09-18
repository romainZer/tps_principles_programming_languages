tp01-bonjour :
	mkdir -p ./tp01/out
	gcc -Wall -Wextra -o ./tp01/out/bonjour.out ./tp01/bonjour.c
	./tp01/out/bonjour.out

tp01-cercle: 
	mkdir -p ./tp01/out
	gcc -Wall -Wextra -o ./tp01/out/cercle.out ./tp01/cercle.c
	./tp01/out/cercle.out

tp01-sizeof_types: 
	mkdir -p ./tp01/out
	gcc -Wall -Wextra -o ./tp01/out/sizeof_types.out ./tp01/sizeof_types.c
	./tp01/out/sizeof_types.out

tp01-variables: 
	mkdir -p ./tp01/out
	gcc -Wall -Wextra -o ./tp01/out/variables.out ./tp01/variables.c
	./tp01/out/variables.out
