/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    RETURN = 260,
    DO = 261,
    WHILE = 262,
    FOR = 263,
    SWITCH = 264,
    BREAK = 265,
    CONTINUE = 266,
    EQ = 267,
    EOL = 268,
    EXTERN = 269,
    STRUCT = 270,
    CASE = 271,
    DEFAULT = 272,
    INT = 273,
    LONG = 274,
    SHORT = 275,
    FLOAT = 276,
    DOUBLE = 277,
    CHAR = 278,
    VOID = 279,
    STRING = 280,
    SIZE_OF = 281,
    LESS_OR_EQUAL = 282,
    GREATER_OR_EQUAL = 283,
    EQUAL = 284,
    NOT_EQUAL = 285,
    INC_OP = 286,
    DEC_OP = 287,
    AND_OP = 288,
    OR_OP = 289,
    THREE_WAY_OP = 290,
    PRINTF = 291,
    ARROW = 292,
    FORMAT_SPEC = 293,
    ID = 294,
    INT_NUMBER = 295,
    HEX = 296
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define RETURN 260
#define DO 261
#define WHILE 262
#define FOR 263
#define SWITCH 264
#define BREAK 265
#define CONTINUE 266
#define EQ 267
#define EOL 268
#define EXTERN 269
#define STRUCT 270
#define CASE 271
#define DEFAULT 272
#define INT 273
#define LONG 274
#define SHORT 275
#define FLOAT 276
#define DOUBLE 277
#define CHAR 278
#define VOID 279
#define STRING 280
#define SIZE_OF 281
#define LESS_OR_EQUAL 282
#define GREATER_OR_EQUAL 283
#define EQUAL 284
#define NOT_EQUAL 285
#define INC_OP 286
#define DEC_OP 287
#define AND_OP 288
#define OR_OP 289
#define THREE_WAY_OP 290
#define PRINTF 291
#define ARROW 292
#define FORMAT_SPEC 293
#define ID 294
#define INT_NUMBER 295
#define HEX 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
