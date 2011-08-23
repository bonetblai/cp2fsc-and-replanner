#ifndef FLEX_HEADER_scanner_h
#define FLEX_HEADER_scanner_h
#define YY_PDDL_Scanner_CHAR char
#line 1 "/opt/sfw/lib/flexskel.h"
/* A lexical scanner header generated by flex */
/* MODIFIED FOR C++ CLASS BY Alain Coetmeur: coetmeur(at)icdc.fr */
/* Note that (at) mean the 'at' symbol that I cannot write */
/* because it is expanded to the class name */
/* made at Informatique-CDC, Research&development department */
/* company from the Caisse Des Depots et Consignations */


/*********************************************/
/* SYSTEM dependent declaration, includes... */
/*********************************************/
/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_PROTOS
#define YY_USE_PROTOS
#endif
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else	/* ! __cplusplus */
#ifdef __STDC__
#ifdef __GNUC__
#else
#endif	/* __GNUC__ */
#ifndef YY_USE_PROTOS
#define YY_USE_PROTOS
#endif
#endif	/* __STDC__ */
#endif	/* ! __cplusplus */
/*********************************************/
/* COMPILER DEPENDENT   MACROS               */
/*********************************************/
/* use prototypes in function declarations */
#ifndef YY_PROTO
#ifdef YY_USE_PROTOS
#define YY_PROTO(proto) proto
#else
#define YY_PROTO(proto) ()
#endif
#endif
#include <stdio.h>




/* % here is the declaration from section1 %header{  */ 
#line 2 "ppddl.lex"
#define YY_PDDL_Scanner_LEX  next_token
#line 3 "ppddl.lex"
#define YY_PDDL_Scanner_LEX_PARAM  YY_PDDL_Parser_STYPE& val
#line 4 "ppddl.lex"
#define YY_PDDL_Scanner_DEBUG  1
#line 6 "ppddl.lex"
#define YY_PDDL_Scanner_MEMBERS  \
  private: \
    StringTable& _tab; \
    bool  _reset; \
    char  *_filename; \
    int   _line_no; \
    bool  _trace_line; \
  public: \
    void  open_file(char *fname, bool trace); \
    void  close_file(); \
    char* current_file() const { return _filename; } \
    int   current_line() const { return _line_no; }
#line 19 "ppddl.lex"
#define YY_PDDL_Scanner_CONSTRUCTOR_PARAM  StringTable& t
#line 20 "ppddl.lex"
#define YY_PDDL_Scanner_CONSTRUCTOR_INIT  : _tab(t), _reset(false), _filename(0), _line_no(1), _trace_line(false)
#line 23 "ppddl.lex"
#include <strings.h>
#include "string_table.h"
#include "grammar.h"

using namespace std;

#line 40 "ppddl.lex"
#line 52 "/opt/sfw/lib/flexskel.h"

#ifdef YY_USE_CLASS
#ifdef YY_PDDL_Scanner_IOSTREAM
#include <iostream.h>
#define YY_PDDL_Scanner_IFILE  istream
#define YY_PDDL_Scanner_OFILE ostream 
#define YY_PDDL_Scanner_ERRFILE cerr

#ifndef YY_PDDL_Scanner_IFILE_DEFAULT
#define YY_PDDL_Scanner_IFILE_DEFAULT &cin
#endif

#ifndef YY_PDDL_Scanner_OFILE_DEFAULT
#define YY_PDDL_Scanner_OFILE_DEFAULT &cout
#endif

#endif
#endif

#ifndef YY_PDDL_Scanner_IFILE
#define YY_PDDL_Scanner_IFILE FILE 
#endif

#ifndef YY_PDDL_Scanner_OFILE
#define YY_PDDL_Scanner_OFILE FILE 
#endif

#ifndef YY_PDDL_Scanner_ERRFILE
#define YY_PDDL_Scanner_ERRFILE stderr
#endif

#ifndef YY_PDDL_Scanner_IFILE_DEFAULT
#define YY_PDDL_Scanner_IFILE_DEFAULT stdin
#endif

#ifndef YY_PDDL_Scanner_OFILE_DEFAULT
#define YY_PDDL_Scanner_OFILE_DEFAULT stdout
#endif




#ifndef YY_PDDL_Scanner_TEXT
#define YY_PDDL_Scanner_TEXT yytext
#endif
#ifndef YY_PDDL_Scanner_LENG
#define YY_PDDL_Scanner_LENG yyleng
#endif
#ifndef YY_PDDL_Scanner_IN
#define YY_PDDL_Scanner_IN yyin
#endif
#ifndef YY_PDDL_Scanner_OUT
#define YY_PDDL_Scanner_OUT yyout
#endif

#ifndef YY_PDDL_Scanner_LEX_RETURN
#define YY_PDDL_Scanner_LEX_RETURN int
#else
#ifndef YY_PDDL_Scanner_LEX_DEFINED
#define YY_PDDL_Scanner_LEX_DEFINED 
#endif
#endif

#ifndef YY_PDDL_Scanner_LEX
#define YY_PDDL_Scanner_LEX yylex
#else
#ifndef YY_PDDL_Scanner_LEX_DEFINED
#define YY_PDDL_Scanner_LEX_DEFINED 
#endif
#endif

#ifndef YY_PDDL_Scanner_LEX_PARAM
#ifndef YY_USE_PROTOS
#define YY_PDDL_Scanner_LEX_PARAM 
#else
#define YY_PDDL_Scanner_LEX_PARAM void
#endif
#else
#ifndef YY_PDDL_Scanner_LEX_DEFINED
#define YY_PDDL_Scanner_LEX_DEFINED 
#endif
#endif

#ifndef YY_PDDL_Scanner_LEX_PARAM_DEF
#define YY_PDDL_Scanner_LEX_PARAM_DEF
#else
#ifndef YY_PDDL_Scanner_LEX_DEFINED
#define YY_PDDL_Scanner_LEX_DEFINED 
#endif
#endif

#ifndef YY_PDDL_Scanner_RESTART
#define YY_PDDL_Scanner_RESTART yyrestart
#endif
#ifndef YY_PDDL_Scanner_SWITCH_TO_BUFFER
#define YY_PDDL_Scanner_SWITCH_TO_BUFFER yy_switch_to_buffer
#endif
#ifndef YY_PDDL_Scanner_LOAD_BUFFER_STATE
#define YY_PDDL_Scanner_LOAD_BUFFER_STATE yy_load_buffer_state
#endif

#ifndef YY_PDDL_Scanner_CREATE_BUFFER
#define YY_PDDL_Scanner_CREATE_BUFFER yy_create_buffer
#ifndef YY_USE_CLASS
#ifndef yy_new_buffer
#define yy_new_buffer yy_create_buffer
#endif
#endif
#endif
#ifndef YY_PDDL_Scanner_DELETE_BUFFER
#define YY_PDDL_Scanner_DELETE_BUFFER yy_delete_buffer
#endif
#ifndef YY_PDDL_Scanner_INIT_BUFFER
#define YY_PDDL_Scanner_INIT_BUFFER yy_init_buffer
#endif



#ifdef YY_PDDL_Scanner_FLEX_DEBUG
#ifndef YY_PDDL_Scanner_DEBUG
#define YY_PDDL_Scanner_DEBUG 1
#endif
#else
#ifndef YY_PDDL_Scanner_DEBUG
#define YY_PDDL_Scanner_DEBUG 0
#endif
#endif

#if YY_PDDL_Scanner_DEBUG != 0
#ifndef YY_PDDL_Scanner_DEBUG_FLAG
#define YY_PDDL_Scanner_DEBUG_FLAG yy_flex_debug
#endif
#ifndef YY_PDDL_Scanner_DEBUG_INIT
#define YY_PDDL_Scanner_DEBUG_INIT 1
#endif
#endif




#ifndef YY_USE_CLASS
#ifndef YY_PDDL_Scanner_CURRENT_BUFFER
#define YY_PDDL_Scanner_CURRENT_BUFFER yy_current_buffer
#endif
typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern void YY_PDDL_Scanner_RESTART YY_PROTO(( YY_PDDL_Scanner_IFILE *input_file ));
extern void YY_PDDL_Scanner_SWITCH_TO_BUFFER YY_PROTO(( YY_BUFFER_STATE new_buffer ));
extern void YY_PDDL_Scanner_LOAD_BUFFER_STATE YY_PROTO(( void ));
extern YY_BUFFER_STATE YY_PDDL_Scanner_CREATE_BUFFER YY_PROTO(( YY_PDDL_Scanner_IFILE *file, int size ));
extern void YY_PDDL_Scanner_DELETE_BUFFER YY_PROTO(( YY_BUFFER_STATE b ));
extern void YY_PDDL_Scanner_INIT_BUFFER YY_PROTO(( YY_BUFFER_STATE b, YY_PDDL_Scanner_IFILE *file ));

#if YY_PDDL_Scanner_DEBUG != 0
extern int YY_PDDL_Scanner_DEBUG_FLAG ;
#endif
extern YY_PDDL_Scanner_CHAR  *YY_PDDL_Scanner_TEXT;
extern int YY_PDDL_Scanner_LENG;
extern YY_PDDL_Scanner_IFILE *YY_PDDL_Scanner_IN;
extern YY_PDDL_Scanner_OFILE *YY_PDDL_Scanner_OUT;
#ifdef YY_PDDL_Scanner_LEX_DEFINED
extern YY_PDDL_Scanner_LEX_RETURN YY_PDDL_Scanner_LEX ( YY_PDDL_Scanner_LEX_PARAM )
YY_PDDL_Scanner_LEX_PARAM_DEF
#else
#ifndef YY_DECL
extern YY_PDDL_Scanner_LEX_RETURN YY_PDDL_Scanner_LEX ( YY_PDDL_Scanner_LEX_PARAM )
YY_PDDL_Scanner_LEX_PARAM_DEF
#else
/* no declaration if oldstyle flex */
#endif
#endif
#else

#ifndef YY_PDDL_Scanner_CURRENT_BUFFER
#define YY_PDDL_Scanner_CURRENT_BUFFER YY_CURRENT_BUFFER
#endif
#ifndef YY_PDDL_Scanner_CLASS
#define YY_PDDL_Scanner_CLASS PDDL_Scanner
#endif
#ifndef YY_PDDL_Scanner_ECHO
#define YY_PDDL_Scanner_ECHO yy_echo
#endif
#ifdef YY_PDDL_Scanner_ECHO_PURE
#define YY_PDDL_Scanner_ECHO_NOCODE
#endif

#ifndef YY_PDDL_Scanner_ECHO_CODE
#ifndef YY_PDDL_Scanner_IOSTREAM
#define YY_PDDL_Scanner_ECHO_CODE fwrite( (char *) YY_PDDL_Scanner_TEXT, YY_PDDL_Scanner_LENG, 1, YY_PDDL_Scanner_OUT );
#else
#define YY_PDDL_Scanner_ECHO_CODE (YY_PDDL_Scanner_OUT->write( (char *) YY_PDDL_Scanner_TEXT, YY_PDDL_Scanner_LENG));
#endif
#endif

#ifndef YY_PDDL_Scanner_INPUT
#define YY_PDDL_Scanner_INPUT yy_input
#endif
#ifdef YY_PDDL_Scanner_INPUT_PURE
#define YY_PDDL_Scanner_INPUT_NOCODE
#endif

#ifndef YY_PDDL_Scanner_INPUT_CODE
#ifndef YY_PDDL_Scanner_IOSTREAM
#define YY_PDDL_Scanner_INPUT_CODE return result= fread(  buffer, 1,max_size,YY_PDDL_Scanner_IN );
#else
#define YY_PDDL_Scanner_INPUT_CODE if(YY_PDDL_Scanner_IN->eof())  result=0;else {YY_PDDL_Scanner_IN->read(buffer,max_size);result=YY_PDDL_Scanner_IN->gcount();YY_PDDL_Scanner_IN->clear(YY_PDDL_Scanner_IN->rdstate()&(~ios::failbit));if(YY_PDDL_Scanner_IN->bad()) result= -1;} return result;
#endif
#endif

#ifdef YY_PDDL_Scanner_FATAL_ERROR_PURE
#define YY_PDDL_Scanner_FATAL_ERRO_NOCODE
#endif
#ifndef YY_PDDL_Scanner_FATAL_ERROR
#define YY_PDDL_Scanner_FATAL_ERROR yy_fatal_error
#endif

#ifndef YY_PDDL_Scanner_FATAL_ERROR_CODE
#ifndef YY_PDDL_Scanner_IOSTREAM
#define YY_PDDL_Scanner_FATAL_ERROR_CODE fputs( msg, YY_PDDL_Scanner_ERRFILE );putc( '\n', YY_PDDL_Scanner_ERRFILE );exit( 1 );
#else
#define YY_PDDL_Scanner_FATAL_ERROR_CODE YY_PDDL_Scanner_ERRFILE<< msg <<endl;exit( 1 );
#endif
#endif

#ifndef YY_PDDL_Scanner_WRAP
#define YY_PDDL_Scanner_WRAP yy_wrap
#endif
#ifdef YY_PDDL_Scanner_WRAP_PURE
#define YY_PDDL_Scanner_WRAP_NOCODE
#endif
#ifndef YY_PDDL_Scanner_WRAP_CODE
#define YY_PDDL_Scanner_WRAP_CODE return 1;
#endif


#ifndef YY_PDDL_Scanner_INHERIT
#define YY_PDDL_Scanner_INHERIT
#endif
#ifndef YY_PDDL_Scanner_MEMBERS
#define YY_PDDL_Scanner_MEMBERS 
#endif
#ifndef YY_PDDL_Scanner_CONSTRUCTOR_PARAM
#define YY_PDDL_Scanner_CONSTRUCTOR_PARAM
#endif
#ifndef YY_PDDL_Scanner_CONSTRUCTOR_CODE
#define YY_PDDL_Scanner_CONSTRUCTOR_CODE
#endif
#ifndef YY_PDDL_Scanner_CONSTRUCTOR_INIT
#define YY_PDDL_Scanner_CONSTRUCTOR_INIT
#endif
#ifndef YY_PDDL_Scanner_DESTRUCTOR_CODE
#define YY_PDDL_Scanner_DESTRUCTOR_CODE
#endif
typedef struct yy_buffer_state *YY_BUFFER_STATE;

class YY_PDDL_Scanner_CLASS YY_PDDL_Scanner_INHERIT
{
 private:/* data */
 YY_PDDL_Scanner_CHAR  *yy_c_buf_p;
 YY_PDDL_Scanner_CHAR  yy_hold_char;
 int yy_n_chars;
 int yy_init;
 int yy_start;
 int yy_did_buffer_switch_on_eof;
 private: /* functions */
 void yy_initialize();
 int input();
 int yyinput() {return input();};
 int yy_get_next_buffer();
 void yyunput( YY_PDDL_Scanner_CHAR  c, YY_PDDL_Scanner_CHAR  *buf_ptr );
 /* use long instead of yy_state_type because it is undef */
 long yy_get_previous_state_ ( void );
 long yy_try_NUL_trans_  ( long current_state_ );
 protected:/* non virtual */
 YY_BUFFER_STATE YY_PDDL_Scanner_CURRENT_BUFFER;
 void YY_PDDL_Scanner_RESTART ( YY_PDDL_Scanner_IFILE *input_file );
 void YY_PDDL_Scanner_SWITCH_TO_BUFFER( YY_BUFFER_STATE new_buffer );
 void YY_PDDL_Scanner_LOAD_BUFFER_STATE( void );
 YY_BUFFER_STATE YY_PDDL_Scanner_CREATE_BUFFER( YY_PDDL_Scanner_IFILE *file, int size );
 void YY_PDDL_Scanner_DELETE_BUFFER( YY_BUFFER_STATE b );
 void YY_PDDL_Scanner_INIT_BUFFER( YY_BUFFER_STATE b, YY_PDDL_Scanner_IFILE *file );
 protected: /* virtual */
 virtual void YY_PDDL_Scanner_ECHO()
#ifdef YY_PDDL_Scanner_ECHO_PURE
  =0
#endif
  ;
 virtual int  YY_PDDL_Scanner_INPUT(char  *buf,int &result,int max_size)
#ifdef YY_PDDL_Scanner_INPUT_PURE
  =0
#endif
  ;
 virtual void  YY_PDDL_Scanner_FATAL_ERROR(char *msg)
#ifdef YY_PDDL_Scanner_FATAL_ERROR_PURE
  =0
#endif
  ;
 virtual int  YY_PDDL_Scanner_WRAP()
#ifdef YY_PDDL_Scanner_WRAP_PURE
  =0
#endif
  ;
 public:
 YY_PDDL_Scanner_CHAR  *YY_PDDL_Scanner_TEXT;
 int YY_PDDL_Scanner_LENG;
 YY_PDDL_Scanner_IFILE *YY_PDDL_Scanner_IN;
 YY_PDDL_Scanner_OFILE *YY_PDDL_Scanner_OUT;
 YY_PDDL_Scanner_LEX_RETURN YY_PDDL_Scanner_LEX ( YY_PDDL_Scanner_LEX_PARAM);
 YY_PDDL_Scanner_CLASS(YY_PDDL_Scanner_CONSTRUCTOR_PARAM) ;
 virtual ~YY_PDDL_Scanner_CLASS() ;
#if YY_PDDL_Scanner_DEBUG != 0
 int YY_PDDL_Scanner_DEBUG_FLAG;
#endif
 public: /* added members */
 YY_PDDL_Scanner_MEMBERS 
};
#endif



/* declaration of externs for public use of yylex scanner */

/* % here is the declaration from section2 %header{ */ 
#line 130 "ppddl.lex"
#endif
#line 375 "/opt/sfw/lib/flexskel.h"

/* end of generated header */
