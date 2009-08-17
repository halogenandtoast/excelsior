#include "ruby.h"

VALUE e_parse(VALUE self, VALUE data) {
 int cs, act, curline = 1, len = 0;
 char *ts = 0, *te = 0, *buf = NULL, *eof = NULL;
 char *p, *pe;
 VALUE rows;
 VALUE arr;
 rows = rb_ary_new();
 arr = rb_ary_new();
 len = RSTRING(data)->len;
 p = RSTRING(data)->ptr;
 pe = p + len;
 eof = pe;
 int has_found = 0;

 %%{
   machine excelsior_scan;
   delimeter = ",";
   newline = "\r"? "\n" | "\r" | "\n";
   schar1 = any - '"';
   schar2 = any - "'";
   letter = any - delimeter - space - '"' - "'";
   string = '"' schar1* '"' | "'" schar2* "'";
   word = letter+;
   value = word (" " word)*;
   main := |*
     newline { rb_ary_push(rows, arr); arr = rb_ary_new(); };
     space;
     value { rb_ary_push(arr, rb_str_new(ts, te - ts)); has_found = 1;};
     string { rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;};
     delimeter { if(has_found == 0) rb_ary_push(arr, Qnil); has_found = 0;};
   *|;
 }%%

 %% write data nofinal;
 %% write init;
 %% write exec;
 if(RARRAY_LEN(arr) > 0) {
   rb_ary_push(rows, arr);
 }
 return rows;
}

VALUE mExcelsior;
VALUE cReader;

void Init_excelsior_reader() {
 mExcelsior = rb_define_module("Excelsior");
 cReader = rb_define_class_under(mExcelsior, "Reader", rb_cObject);
 rb_define_singleton_method(cReader, "parse", e_parse, 1);
}