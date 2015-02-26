include makedefs

.SUFFIXES : .cc $(SUFFIXES)

.cc.o:
	$(C++) $(CFLAGS) -c $<

LIBSRCS = string_table.cc base.cc ptr_table.cc char_map.cc problem.cc kp_problem.cc clg_problem.cc lw1_problem.cc cp_problem.cc ks0_problem.cc name.cc preprocess.cc solver.cc classical_planner.cc
#LIBSRCS = string_table.cc base.cc ptr_table.cc char_map.cc problem.cc kp_problem.cc clg_problem.cc lw1_problem.cc ks0_problem.cc name.cc preprocess.cc solver.cc classical_planner.cc
LIBGENSRCS = grammar.cc scanner.cc
GENSRCS = ppddl.y ppddl.lex
TARGET1 = k-replanner
TARGET2 = cp2fsc
TARGET3 = lw1

all: $(TARGET1) $(TARGET2) $(TARGET3)

grammar.h: ppddl.y base.h
	$(BISON) -v -d -o grammar.cc ppddl.y
	#touch grammar.cc grammar.h
grammar.cc: ppddl.y base.h
	$(BISON) -v -d -o grammar.cc ppddl.y
	#touch grammar.cc grammar.h
scanner.cc: ppddl.lex grammar.h
	$(FLEX) -i -hscanner.h -oscanner.cc ppddl.lex
	#touch scanner.cc scanner.h
scanner.h: ppddl.lex grammar.h
	$(FLEX) -i -hscanner.h -oscanner.cc ppddl.lex
	#touch scanner.cc scanner.h

include makedeps

libp.a: $(LIBSRCS:.cc=.o) $(LIBGENSRCS:.cc=.o)
	ar cr libp.a $(LIBSRCS:.cc=.o) $(LIBGENSRCS:.cc=.o)
	ranlib libp.a

$(TARGET1): $(TARGET1).o libp.a
	$(LINK) $(LFLAGS) $(TARGET1).o -lp -o $(TARGET1)

$(TARGET2): $(TARGET2).o libp.a
	$(LINK) $(LFLAGS) $(TARGET2).o -lp -o $(TARGET2)

$(TARGET3): $(TARGET3).o libp.a
	$(LINK) $(LFLAGS) $(TARGET3).o -lp -o $(TARGET3)

deps:	$(TARGET1).cc $(TARGET2).cc $(TARGET3).cc $(LIBSRCS) $(LIBGENSRCS)
	rm -f makedeps
	$(C++) -MM $(TARGET1).cc $(TARGET2).cc $(TARGET3).cc $(LIBSRCS) $(LIBGENSRCS) > makedeps

clean:
	rm -f *~ *.o *.a core $(TARGET1) $(TARGET2) $(TARGET3) gen-[pd].*.pddl

remake: clean
	rm -f grammar.* scanner.*

