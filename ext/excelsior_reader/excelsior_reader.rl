#include <ruby.h>

static ID s_read;
VALUE arr;
int has_found = 0;
#define BUFSIZE 16384

%%{
   machine excelsior_scan;
   delimiter = ",";
   newline = "\r"? "\n" | "\r";
   string_character = any - '"';
   letter = string_character - delimiter - newline;
   string = '"' (string_character | '""')* '"' ;
   value = letter+;
   main := |*
		 newline { if(has_found ==0) rb_ary_push(arr, Qnil); rb_yield(arr); arr = rb_ary_new(); has_found = 0; };
     space;
     value { rb_ary_push(arr, rb_str_new(ts, te - ts)); has_found = 1;};
     string { rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;};
     delimiter { if(has_found == 0) rb_ary_push(arr, Qnil); has_found = 0;};
   *|;
}%%
 
%% write data nofinal; 


VALUE e_rows(int argc, VALUE *argv, VALUE self) {
  
  int cs, act, have = 0, nread = 0, curline = 1, text = 0;
  char *ts = 0, *te = 0, *buf = NULL, *eof = NULL;
  int buffer_size = BUFSIZE;
  
  has_found = 0;
  VALUE io;
  int is_io = 0;
  int done = 0;
  
  arr = rb_ary_new();
  rb_scan_args(argc, argv, "1", &io);
  
  is_io = rb_respond_to(io, s_read);
  buf = (char *) malloc(buffer_size); //ALLOC_N(char, buffer_size); <= This caused problems
  
  %% write init;
  
  while(!done) {
  
    int len, space = buffer_size - have;
    VALUE str;
    char *p, *pe;
    p = buf + have;
  
    if(is_io) {
      str = rb_funcall(io, s_read, 1, INT2FIX(space));
      len = RSTRING_LEN(str);
      memcpy(p, StringValuePtr(str), len);
    } else { 
      // Going to assume it's a string and already in memory
      //str = io;
	  p = RSTRING_PTR(io);
      len = RSTRING_LEN(io) + 1;
      pe = p + len;
	  eof = pe;
	  done = 1;
    }
  
    if(len < space) {
      done = 1;
      //p[len++] = 0; can't seem to get it to work with this
      pe = p + len;
      eof = pe;
    } else {
      pe = p + len; 
    }
  
    %% write exec;
    
    if(ts != 0) { // we are not at the end
      have = pe - ts; //so copy stuff back in
      memmove(buf, ts, have);
      te = buf + (te - ts);
      ts = buf;
    }   
    
  }
  
  if(RARRAY_LEN(arr) > 0) { // have a last array to yield
    rb_yield(arr);
  }
  
  return Qnil;
}

VALUE mExcelsior;
VALUE cReader;

void Init_excelsior_reader() {
  s_read = rb_intern("read");
  mExcelsior = rb_define_module("Excelsior");
  cReader = rb_define_class_under(mExcelsior, "Reader", rb_cObject);
  rb_define_singleton_method(cReader, "rows", e_rows, -1);
}