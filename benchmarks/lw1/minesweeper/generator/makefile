all:			gen-domain gen-problem gen-hidden

gen-domain: 	gen-domain.cc
				g++ -O3 -o gen-domain gen-domain.cc

gen-problem:	gen-problem.cc
				g++ -O3 -o gen-problem gen-problem.cc

gen-hidden:		gen-hidden.cc
				g++ -O3 -o gen-hidden gen-hidden.cc

clean:
				rm -f gen-domain gen-problem gen-hidden
