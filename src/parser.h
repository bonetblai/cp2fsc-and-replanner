/*
 *  Copyright (C) 2011 - <date> Blai Bonet, Universidad Simon Bolivar
 * 
 *  Permission is hereby granted to distribute this software for
 *  non-commercial research purposes, provided that this copyright
 *  notice is included with any such distribution.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 *  EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
 *  SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
 *  ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
 *
 *  Blai Bonet, bonet@ldc.usb.ve, bonetblai@gmail.com
 *
 */

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
        if( strcmp(name, "-") == 0 )
            scanner.open_file(trace);
        else
            scanner.open_file(const_cast<char*>(name), trace);
        error_flag_ = false;
        int rv = yyparse();
        if( strcmp(name, "-") != 0 )
            scanner.close_file();
        if( error_flag_ || (rv > 0) ) {
            std::cout << Utils::internal_error()
                      << "parser error (rv = " << rv << "); terminating..."
                      << std::endl;
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

