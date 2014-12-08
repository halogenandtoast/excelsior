
#line 1 "excelsior_reader.rl"
#include <ruby.h>

#define EXCELSIOR_BUFSIZE 16384

static ID s_read;
static VALUE arr;
static VALUE header_row;
static int row_index = 0;
static int header = 0;
static int is_header_row = 0;
static int has_found = 0;


#line 45 "excelsior_reader.rl"



#line 21 "excelsior_reader.c"
static const int excelsior_scan_start = 2;
static const int excelsior_scan_error = 0;

static const int excelsior_scan_en_main = 2;


#line 48 "excelsior_reader.rl"


VALUE e_rows(int argc, VALUE *argv, VALUE self) {

  int cs, act, have = 0, nread = 0, curline = 1, text = 0;
  char *ts = 0, *te = 0, *buf = NULL, *eof = NULL;
  int buffer_size = EXCELSIOR_BUFSIZE;

  header = 0;
  has_found = 0;
  VALUE io;
  VALUE options;
  int is_io = 0;
  int done = 0;

  arr = rb_ary_new();
  rb_scan_args(argc, argv, "11", &io, &options);
  if(options != Qnil) {
    header = rb_hash_aref(options, ID2SYM(rb_intern("header"))) == Qtrue;
  }
  if(header == 1) {
    is_header_row = 1;
    header_row = rb_ary_new();
  }
  is_io = rb_respond_to(io, s_read);
  buf = (char *) malloc(buffer_size); //ALLOC_N(char, buffer_size); <= This caused problems

  
#line 57 "excelsior_reader.c"
	{
	cs = excelsior_scan_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 76 "excelsior_reader.rl"

  while(!done) {

    int len, space = buffer_size - have;
    VALUE str;
    char *p, *pe;
    p = buf + have;

    if(is_io) {
      str = rb_funcall(io, s_read, 1, INT2FIX(space));
      if(str == Qnil) {
        return rb_hash_new();
      }
      len = RSTRING_LEN(str);
      memcpy(p, StringValuePtr(str), len);
    } else {
      // Going to assume it's a string and already in memory
      //str = io;
      p = RSTRING_PTR(io);
      len = RSTRING_LEN(io);
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

    
#line 101 "excelsior_reader.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 1 "NONE"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 3:
	{{p = ((te))-1;} rb_ary_push((is_header_row ? header_row : arr), rb_str_new(ts, te - ts)); has_found = 1;}
	break;
	case 4:
	{{p = ((te))-1;} rb_ary_push((is_header_row ? header_row : arr), rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}
	break;
	default:
	{{p = ((te))-1;}}
	break;
	}
	}
	goto st2;
tr5:
#line 23 "excelsior_reader.rl"
	{te = p+1;{
      if(!is_header_row) {
        if(header == 1) {
          VALUE hash = rb_hash_new();
          int i = 0;
          for(i = 0; i < RARRAY_LEN(header_row); i++) {
            rb_hash_aset(hash, rb_ary_entry(header_row, i), rb_ary_entry(arr, i));
          }
          rb_yield(hash);
        } else {
          rb_yield(arr);
        }
      }
      arr = rb_ary_new();
      has_found = 0;
      is_header_row = 0;
    }}
	goto st2;
tr7:
#line 43 "excelsior_reader.rl"
	{te = p+1;{ if(has_found == 0) rb_ary_push((is_header_row ? header_row : arr), Qnil); has_found = 0;}}
	goto st2;
tr8:
#line 23 "excelsior_reader.rl"
	{te = p;p--;{
      if(!is_header_row) {
        if(header == 1) {
          VALUE hash = rb_hash_new();
          int i = 0;
          for(i = 0; i < RARRAY_LEN(header_row); i++) {
            rb_hash_aset(hash, rb_ary_entry(header_row, i), rb_ary_entry(arr, i));
          }
          rb_yield(hash);
        } else {
          rb_yield(arr);
        }
      }
      arr = rb_ary_new();
      has_found = 0;
      is_header_row = 0;
    }}
	goto st2;
tr9:
#line 42 "excelsior_reader.rl"
	{te = p;p--;{ rb_ary_push((is_header_row ? header_row : arr), rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}}
	goto st2;
st2:
#line 1 "NONE"
	{ts = 0;}
#line 1 "NONE"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 1 "NONE"
	{ts = p;}
#line 183 "excelsior_reader.c"
	switch( (*p) ) {
		case 10: goto tr5;
		case 13: goto st4;
		case 32: goto tr4;
		case 34: goto st1;
		case 44: goto tr7;
	}
	if ( 9 <= (*p) && (*p) <= 12 )
		goto tr4;
	goto tr3;
tr3:
#line 1 "NONE"
	{te = p+1;}
#line 41 "excelsior_reader.rl"
	{act = 3;}
	goto st3;
tr4:
#line 1 "NONE"
	{te = p+1;}
#line 40 "excelsior_reader.rl"
	{act = 2;}
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 210 "excelsior_reader.c"
	switch( (*p) ) {
		case 10: goto tr0;
		case 13: goto tr0;
		case 34: goto tr0;
		case 44: goto tr0;
	}
	goto tr3;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 10 )
		goto tr5;
	goto tr8;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	if ( (*p) == 34 )
		goto tr2;
	goto st1;
tr2:
#line 1 "NONE"
	{te = p+1;}
#line 42 "excelsior_reader.rl"
	{act = 4;}
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 242 "excelsior_reader.c"
	if ( (*p) == 34 )
		goto st1;
	goto tr9;
st0:
cs = 0;
	goto _out;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 3: goto tr0;
	case 4: goto tr8;
	case 1: goto tr0;
	case 5: goto tr9;
	}
	}

	_out: {}
	}

#line 111 "excelsior_reader.rl"

    if(ts != 0) { // we are not at the end
      have = pe - ts; //so copy stuff back in
      memmove(buf, ts, have);
      te = buf + (te - ts);
      ts = buf;
    }

  }

  if(RARRAY_LEN(arr) > 0) { // have a last array to yield
    if(!is_header_row) {
      if(header == 1) {
        VALUE hash = rb_hash_new();
        int i = 0;
        for(i = 0; i < RARRAY_LEN(header_row); i++) {
          rb_hash_aset(hash, rb_ary_entry(header_row, i), rb_ary_entry(arr, i));
        }
        rb_yield(hash);
      } else {
        rb_yield(arr);
      }
    }
  }

  free(buf);

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
