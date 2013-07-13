#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include "scanner.h"
#include "grammar.h"

class Parser : public PDDL_Parser {
    PDDL_Scanner scanner;

  public:
    Parser(PDDL_Parser::Type type, StringTable &t) : PDDL_Parser(t, type), scanner(t) { }
    virtual ~Parser() { }

    void read(char *name, bool trace) {
        yydebug = trace;
        scanner.open_file(name, trace);
        error_flag_ = false;
        int rv = yyparse();
        scanner.close_file();
        if( error_flag_ || (rv > 0) ) {
            //std::cerr << "error: rv = " << rv << std::endl;
            exit(255);
        }
    }

    virtual int next_token() { return scanner.next_token(yylval); }

    virtual void log_error(char *msg) {
        syntax_errors() << msg << std::endl;
        error_flag_ = true;
    }

    virtual std::ostream& syntax_errors() {
        std::cerr << "syntax error at ";
        if( scanner.current_file() )
            std::cerr << scanner.current_file() << ":";
        return std::cerr << scanner.current_line() << ": ";
    }
};

#endif

