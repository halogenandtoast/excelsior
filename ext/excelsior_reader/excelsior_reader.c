
#line 1 "excelsior_reader.rl"
#include <ruby.h>

static ID s_read;
VALUE arr;
int has_found = 0;
#define BUFSIZE 16384


#line 66 "excelsior_reader.rl"

 

#line 16 "excelsior_reader.c"
static const char _excelsior_scan_actions[] = {
	0, 1, 0, 1, 2, 1, 4, 1, 
	5, 1, 6, 1, 7, 1, 11, 1, 
	12, 1, 13, 1, 14, 1, 15, 1, 
	19, 1, 20, 1, 21, 1, 22, 1, 
	23, 1, 27, 1, 28, 1, 29, 1, 
	30, 1, 31, 1, 35, 1, 36, 1, 
	37, 1, 38, 1, 39, 2, 0, 1, 
	2, 3, 8, 2, 3, 9, 2, 3, 
	10, 2, 3, 16, 2, 3, 17, 2, 
	3, 18, 2, 3, 24, 2, 3, 25, 
	2, 3, 26, 2, 3, 32, 2, 3, 
	33, 2, 3, 34
};

static const char _excelsior_scan_key_offsets[] = {
	0, 0, 1, 2, 3, 4, 8, 15, 
	19, 20, 21, 28, 32, 33, 34, 41, 
	45, 46, 47, 54, 58, 59
};

static const char _excelsior_scan_trans_keys[] = {
	34, 34, 34, 34, 9, 44, 59, 124, 
	10, 13, 32, 34, 44, 9, 12, 10, 
	13, 34, 44, 10, 34, 9, 10, 13, 
	32, 34, 11, 12, 13, 34, 9, 10, 
	10, 34, 10, 13, 32, 34, 124, 9, 
	12, 10, 13, 34, 124, 10, 34, 10, 
	13, 32, 34, 59, 9, 12, 10, 13, 
	34, 59, 10, 34, 0
};

static const char _excelsior_scan_single_lengths[] = {
	0, 1, 1, 1, 1, 4, 5, 4, 
	1, 1, 5, 2, 1, 1, 5, 4, 
	1, 1, 5, 4, 1, 1
};

static const char _excelsior_scan_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 1, 1, 0, 0, 1, 0, 
	0, 0, 1, 0, 0, 0
};

static const char _excelsior_scan_index_offsets[] = {
	0, 0, 2, 4, 6, 8, 13, 20, 
	25, 27, 29, 36, 40, 42, 44, 51, 
	56, 58, 60, 67, 72, 74
};

static const char _excelsior_scan_trans_targs[] = {
	9, 1, 13, 2, 17, 3, 21, 4, 
	5, 5, 5, 5, 0, 6, 8, 7, 
	1, 6, 7, 7, 6, 6, 6, 6, 
	7, 6, 6, 1, 6, 10, 10, 12, 
	11, 2, 11, 11, 10, 10, 10, 11, 
	10, 10, 2, 10, 14, 16, 15, 3, 
	14, 15, 15, 14, 14, 14, 14, 15, 
	14, 14, 3, 14, 18, 20, 19, 4, 
	18, 19, 19, 18, 18, 18, 18, 19, 
	18, 18, 4, 18, 6, 10, 14, 18, 
	6, 6, 6, 10, 10, 10, 14, 14, 
	14, 18, 18, 18, 0
};

static const char _excelsior_scan_trans_actions[] = {
	62, 0, 71, 0, 80, 0, 89, 0, 
	7, 5, 11, 9, 0, 13, 0, 56, 
	0, 15, 56, 59, 21, 21, 21, 21, 
	59, 13, 17, 0, 19, 25, 23, 0, 
	65, 0, 65, 68, 31, 31, 31, 68, 
	23, 27, 0, 29, 33, 0, 74, 0, 
	35, 74, 77, 41, 41, 41, 41, 77, 
	33, 37, 0, 39, 43, 0, 83, 0, 
	45, 83, 86, 51, 51, 51, 51, 86, 
	43, 47, 0, 49, 21, 31, 41, 51, 
	21, 17, 19, 31, 27, 29, 41, 37, 
	39, 51, 47, 49, 0
};

static const char _excelsior_scan_to_state_actions[] = {
	0, 0, 0, 0, 0, 1, 53, 0, 
	0, 0, 53, 0, 0, 0, 53, 0, 
	0, 0, 53, 0, 0, 0
};

static const char _excelsior_scan_from_state_actions[] = {
	0, 0, 0, 0, 0, 3, 3, 0, 
	0, 0, 3, 0, 0, 0, 3, 0, 
	0, 0, 3, 0, 0, 0
};

static const char _excelsior_scan_eof_trans[] = {
	0, 81, 84, 87, 90, 0, 0, 81, 
	82, 83, 0, 84, 85, 86, 0, 87, 
	88, 89, 0, 90, 91, 92
};

static const int excelsior_scan_start = 5;
static const int excelsior_scan_error = 0;

static const int excelsior_scan_en_main = 5;
static const int excelsior_scan_en_csv = 6;
static const int excelsior_scan_en_tsv = 10;
static const int excelsior_scan_en_psv = 14;
static const int excelsior_scan_en_ssv = 18;


#line 69 "excelsior_reader.rl"


VALUE e_rows(int argc, VALUE *argv, VALUE self) {
  
  int cs, act, have = 0, nread = 0, curline = 1, text = 0;
  char *ts = 0, *te = 0, *buf = NULL, *eof = NULL;
	char *p, *pe;
  int buffer_size = BUFSIZE;
  
  has_found = 0;
  VALUE io;
  VALUE format;
  int is_io = 0;
  int done = 0;
	int first_run = 1;
  arr = rb_ary_new();
  rb_scan_args(argc, argv, "11", &io, &format);
	if(NIL_P(format)) format = rb_str_new2("csv");
	
	
#line 146 "excelsior_reader.c"
	{
	cs = excelsior_scan_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 89 "excelsior_reader.rl"
  
  is_io = rb_respond_to(io, s_read);
  buf = (char *) malloc(buffer_size); //ALLOC_N(char, buffer_size); <= This caused problems
	  
  while(!done) {
  
    int len, space = buffer_size - have;
    VALUE str;
    p = buf + have;
  
    if(is_io) {
      str = rb_funcall(io, s_read, 1, INT2FIX(space));
      len = RSTRING_LEN(str);
      memcpy(p, StringValuePtr(str), len);
    } else { 
      // Going to assume it's a string and already in memory
      //str = io;
			io = rb_str_buf_append(format, io);
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
  
    
#line 190 "excelsior_reader.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_acts = _excelsior_scan_actions + _excelsior_scan_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 2:
#line 1 "excelsior_reader.rl"
	{ts = p;}
	break;
#line 211 "excelsior_reader.c"
		}
	}

	_keys = _excelsior_scan_trans_keys + _excelsior_scan_key_offsets[cs];
	_trans = _excelsior_scan_index_offsets[cs];

	_klen = _excelsior_scan_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _excelsior_scan_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
_eof_trans:
	cs = _excelsior_scan_trans_targs[_trans];

	if ( _excelsior_scan_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _excelsior_scan_actions + _excelsior_scan_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 3:
#line 1 "excelsior_reader.rl"
	{te = p+1;}
	break;
	case 4:
#line 31 "excelsior_reader.rl"
	{te = p+1;{ {cs = 6; goto _again;} }}
	break;
	case 5:
#line 32 "excelsior_reader.rl"
	{te = p+1;{ {cs = 10; goto _again;} }}
	break;
	case 6:
#line 33 "excelsior_reader.rl"
	{te = p+1;{ {cs = 14; goto _again;} }}
	break;
	case 7:
#line 34 "excelsior_reader.rl"
	{te = p+1;{ {cs = 18; goto _again;} }}
	break;
	case 8:
#line 39 "excelsior_reader.rl"
	{act = 6;}
	break;
	case 9:
#line 40 "excelsior_reader.rl"
	{act = 7;}
	break;
	case 10:
#line 41 "excelsior_reader.rl"
	{act = 8;}
	break;
	case 11:
#line 38 "excelsior_reader.rl"
	{te = p+1;{ if(has_found ==0) rb_ary_push(arr, Qnil); rb_yield(arr); arr = rb_ary_new(); has_found = 0; }}
	break;
	case 12:
#line 42 "excelsior_reader.rl"
	{te = p+1;{ if(has_found == 0) rb_ary_push(arr, Qnil); has_found = 0;}}
	break;
	case 13:
#line 38 "excelsior_reader.rl"
	{te = p;p--;{ if(has_found ==0) rb_ary_push(arr, Qnil); rb_yield(arr); arr = rb_ary_new(); has_found = 0; }}
	break;
	case 14:
#line 41 "excelsior_reader.rl"
	{te = p;p--;{ rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}}
	break;
	case 15:
#line 1 "excelsior_reader.rl"
	{	switch( act ) {
	case 0:
	{{cs = 0; goto _again;}}
	break;
	case 7:
	{{p = ((te))-1;} rb_ary_push(arr, rb_str_new(ts, te - ts)); has_found = 1;}
	break;
	case 8:
	{{p = ((te))-1;} rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}
	break;
	default:
	{{p = ((te))-1;}}
	break;
	}
	}
	break;
	case 16:
#line 46 "excelsior_reader.rl"
	{act = 11;}
	break;
	case 17:
#line 47 "excelsior_reader.rl"
	{act = 12;}
	break;
	case 18:
#line 48 "excelsior_reader.rl"
	{act = 13;}
	break;
	case 19:
#line 45 "excelsior_reader.rl"
	{te = p+1;{ if(has_found ==0) rb_ary_push(arr, Qnil); rb_yield(arr); arr = rb_ary_new(); has_found = 0; }}
	break;
	case 20:
#line 46 "excelsior_reader.rl"
	{te = p+1;}
	break;
	case 21:
#line 45 "excelsior_reader.rl"
	{te = p;p--;{ if(has_found ==0) rb_ary_push(arr, Qnil); rb_yield(arr); arr = rb_ary_new(); has_found = 0; }}
	break;
	case 22:
#line 48 "excelsior_reader.rl"
	{te = p;p--;{ rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}}
	break;
	case 23:
#line 1 "excelsior_reader.rl"
	{	switch( act ) {
	case 0:
	{{cs = 0; goto _again;}}
	break;
	case 12:
	{{p = ((te))-1;} rb_ary_push(arr, rb_str_new(ts, te - ts)); has_found = 1;}
	break;
	case 13:
	{{p = ((te))-1;} rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}
	break;
	default:
	{{p = ((te))-1;}}
	break;
	}
	}
	break;
	case 24:
#line 53 "excelsior_reader.rl"
	{act = 16;}
	break;
	case 25:
#line 54 "excelsior_reader.rl"
	{act = 17;}
	break;
	case 26:
#line 55 "excelsior_reader.rl"
	{act = 18;}
	break;
	case 27:
#line 52 "excelsior_reader.rl"
	{te = p+1;{ if(has_found ==0) rb_ary_push(arr, Qnil); rb_yield(arr); arr = rb_ary_new(); has_found = 0; }}
	break;
	case 28:
#line 56 "excelsior_reader.rl"
	{te = p+1;{ if(has_found == 0) rb_ary_push(arr, Qnil); has_found = 0;}}
	break;
	case 29:
#line 52 "excelsior_reader.rl"
	{te = p;p--;{ if(has_found ==0) rb_ary_push(arr, Qnil); rb_yield(arr); arr = rb_ary_new(); has_found = 0; }}
	break;
	case 30:
#line 55 "excelsior_reader.rl"
	{te = p;p--;{ rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}}
	break;
	case 31:
#line 1 "excelsior_reader.rl"
	{	switch( act ) {
	case 0:
	{{cs = 0; goto _again;}}
	break;
	case 17:
	{{p = ((te))-1;} rb_ary_push(arr, rb_str_new(ts, te - ts)); has_found = 1;}
	break;
	case 18:
	{{p = ((te))-1;} rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}
	break;
	default:
	{{p = ((te))-1;}}
	break;
	}
	}
	break;
	case 32:
#line 60 "excelsior_reader.rl"
	{act = 21;}
	break;
	case 33:
#line 61 "excelsior_reader.rl"
	{act = 22;}
	break;
	case 34:
#line 62 "excelsior_reader.rl"
	{act = 23;}
	break;
	case 35:
#line 59 "excelsior_reader.rl"
	{te = p+1;{ if(has_found ==0) rb_ary_push(arr, Qnil); rb_yield(arr); arr = rb_ary_new(); has_found = 0; }}
	break;
	case 36:
#line 63 "excelsior_reader.rl"
	{te = p+1;{ if(has_found == 0) rb_ary_push(arr, Qnil); has_found = 0;}}
	break;
	case 37:
#line 59 "excelsior_reader.rl"
	{te = p;p--;{ if(has_found ==0) rb_ary_push(arr, Qnil); rb_yield(arr); arr = rb_ary_new(); has_found = 0; }}
	break;
	case 38:
#line 62 "excelsior_reader.rl"
	{te = p;p--;{ rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}}
	break;
	case 39:
#line 1 "excelsior_reader.rl"
	{	switch( act ) {
	case 0:
	{{cs = 0; goto _again;}}
	break;
	case 22:
	{{p = ((te))-1;} rb_ary_push(arr, rb_str_new(ts, te - ts)); has_found = 1;}
	break;
	case 23:
	{{p = ((te))-1;} rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}
	break;
	default:
	{{p = ((te))-1;}}
	break;
	}
	}
	break;
#line 480 "excelsior_reader.c"
		}
	}

_again:
	_acts = _excelsior_scan_actions + _excelsior_scan_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 0:
#line 1 "excelsior_reader.rl"
	{ts = 0;}
	break;
	case 1:
#line 1 "excelsior_reader.rl"
	{act = 0;}
	break;
#line 497 "excelsior_reader.c"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _excelsior_scan_eof_trans[cs] > 0 ) {
		_trans = _excelsior_scan_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

#line 124 "excelsior_reader.rl"
    
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