#ifndef PARSER_H
#define INPUT_H

#include <stdlib.h>
#include <stdio.h>
#include "scanner.h"
#include "grammar.h"

class Parser : public PDDL_Parser {
    PDDL_Scanner scanner;
  public:
    Parser(StringTable &t) : PDDL_Parser(t), scanner(t) { }
    virtual ~Parser() { }

    void read(char *name, bool trace) {
        yydebug = trace;
        scanner.open_file(name, trace);
        error_flag = false;
        int rv = yyparse();
        scanner.close_file();
        if( error_flag || (rv > 0) ) {
            std::cerr << "error: rv = " << rv << std::endl;
            exit(255);
        }
    }

    virtual int next_token() { return scanner.next_token(yylval); }

    virtual void log_error(char *msg) {
        syntax_errors() << msg << std::endl;
        error_flag = true;
    }

    virtual std::ostream& syntax_errors() {
        std::cerr << "syntax error at ";
        if( scanner.current_file() )
            std::cerr << scanner.current_file() << ":";
        return std::cerr << scanner.current_line() << ": ";
    }
};

#endif

