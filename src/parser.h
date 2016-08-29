#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include "scanner.h"
#include "grammar.h"
#include "options.h"
#include "utils.h"

class Parser : public PDDL_Parser {
    PDDL_Scanner scanner;

  public:
    Parser(PDDL_Parser::Type type, StringTable &t, const Options::Mode &options)
      : PDDL_Parser(t, type, options), scanner(t) { }
    virtual ~Parser() { }

    void read(const char *name, bool trace) {
        yydebug = trace;
        scanner.open_file(const_cast<char*>(name), trace);
        error_flag_ = false;
        int rv = yyparse();
        scanner.close_file();
        if( error_flag_ || (rv > 0) ) {
            //std::cout << Utils::error() << "rv = " << rv << std::endl;
            exit(255);
        }
    }

    virtual int next_token() { return scanner.next_token(yylval); }

    virtual void log_error(const char *msg) {
        syntax_errors() << msg << std::endl;
        error_flag_ = true;
    }

    virtual std::ostream& syntax_errors() {
        std::cout << Utils::red() << "syntax error" << Utils::normal() << " at ";
        if( scanner.current_file() )
            std::cout << scanner.current_file() << ":";
        return std::cout << scanner.current_line() << ": ";
    }
};

#endif

