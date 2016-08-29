include makedefs

.SUFFIXES : .cc $(SUFFIXES)

.cc.o:
	$(C++) $(CFLAGS) -c $<

LIBSRCS = string_table.cc base.cc ptr_table.cc char_map.cc problem.cc kp_problem.cc clg_problem.cc mvv_problem.cc mvv2_problem.cc cp_problem.cc ks0_problem.cc name.cc preprocess.cc solver.cc classical_planner.cc
#LIBSRCS = string_table.cc base.cc ptr_table.cc char_map.cc problem.cc kp_problem.cc clg_problem.cc mvv_problem.cc ks0_problem.cc name.cc preprocess.cc solver.cc classical_planner.cc
LIBGENSRCS = grammar.cc scanner.cc
GENSRCS = ppddl.y ppddl.lex
TARGET1 = k-replanner
TARGET2 = cp2fsc

all: $(TARGET1) $(TARGET2)

grammar.h: ppddl.y base.h
	$(BISON) -v -d -o grammar_tmp.cc ppddl.y
	cat grammar_tmp.cc | sed "s/register //g" | sed "s/YY_PDDL_Parser_ERROR(char/YY_PDDL_Parser_ERROR(const char/" > grammar.cc
	cat grammar_tmp.h | sed "s/YY_PDDL_Parser_ERROR(char/YY_PDDL_Parser_ERROR(const char/" > grammar.h
	mv grammar_tmp.output grammar.output
	rm -f grammar_tmp.{cc,h}
	#touch grammar.cc grammar.h
grammar.cc: ppddl.y base.h
	$(BISON) -v -d -o grammar_tmp.cc ppddl.y
	cat grammar_tmp.cc | sed "s/register //g" | sed "s/YY_PDDL_Parser_ERROR(char/YY_PDDL_Parser_ERROR(const char/" > grammar.cc
	cat grammar_tmp.h | sed "s/YY_PDDL_Parser_ERROR(char/YY_PDDL_Parser_ERROR(const char/" > grammar.h
	mv grammar_tmp.output grammar.output
	rm -f grammar_tmp.{cc,h}
	#touch grammar.cc grammar.h
scanner.cc: ppddl.lex grammar.h
	$(FLEX) -i -hscanner.h -oscanner_tmp.cc ppddl.lex
	cat scanner_tmp.cc | sed "s/register //g" > scanner.cc
	rm -f scanner_tmp.cc
	#touch scanner.cc scanner.h
scanner.h: ppddl.lex grammar.h
	$(FLEX) -i -hscanner.h -oscanner_tmp.cc ppddl.lex
	cat scanner_tmp.cc | sed "s/register //g" > scanner.cc
	rm -f scanner_tmp.cc
	#touch scanner.cc scanner.h

include makedeps

libp.a: $(LIBSRCS:.cc=.o) $(LIBGENSRCS:.cc=.o)
	ar cr libp.a $(LIBSRCS:.cc=.o) $(LIBGENSRCS:.cc=.o)
	ranlib libp.a

$(TARGET1): $(TARGET1).o libp.a
	$(LINK) $(LFLAGS) $(TARGET1).o -lp -o $(TARGET1)

$(TARGET2): $(TARGET2).o libp.a
	$(LINK) $(LFLAGS) $(TARGET2).o -lp -o $(TARGET2)

deps:	$(TARGET1).cc $(TARGET2).cc $(LIBSRCS) $(LIBGENSRCS)
	rm -f makedeps
	$(C++) -MM $(TARGET1).cc $(TARGET2).cc $(LIBSRCS) $(LIBGENSRCS) > makedeps

clean:
	rm -f *~ *.o *.a core $(TARGET1) $(TARGET2) gen-[pd]*.pddl

remake: clean
	rm -f grammar.* scanner.*

