
#line 1 "excelsior_reader.rl"
#include <ruby.h>

static ID s_read;
VALUE arr;
int has_found = 0;
#define BUFSIZE 16384


#line 23 "excelsior_reader.rl"

 

#line 16 "excelsior_reader.c"
static const char _excelsior_scan_actions[] = {
	0, 1, 2, 1, 7, 1, 8, 1, 
	9, 1, 10, 1, 11, 2, 0, 1, 
	2, 3, 4, 2, 3, 5, 2, 3, 
	6
};

static const char _excelsior_scan_key_offsets[] = {
	0, 0, 1, 8, 12, 13
};

static const char _excelsior_scan_trans_keys[] = {
	34, 10, 13, 32, 34, 44, 9, 12, 
	10, 13, 34, 44, 10, 34, 0
};

static const char _excelsior_scan_single_lengths[] = {
	0, 1, 5, 4, 1, 1
};

static const char _excelsior_scan_range_lengths[] = {
	0, 0, 1, 0, 0, 0
};

static const char _excelsior_scan_index_offsets[] = {
	0, 0, 2, 9, 14, 16
};

static const char _excelsior_scan_trans_targs[] = {
	5, 1, 2, 4, 3, 1, 2, 3, 
	3, 2, 2, 2, 2, 3, 2, 2, 
	1, 2, 2, 2, 2, 2, 0
};

static const char _excelsior_scan_trans_actions[] = {
	22, 0, 3, 0, 16, 0, 5, 16, 
	19, 11, 11, 11, 11, 19, 3, 7, 
	0, 9, 11, 11, 7, 9, 0
};

static const char _excelsior_scan_to_state_actions[] = {
	0, 0, 13, 0, 0, 0
};

static const char _excelsior_scan_from_state_actions[] = {
	0, 0, 1, 0, 0, 0
};

static const char _excelsior_scan_eof_trans[] = {
	0, 20, 0, 20, 21, 22
};

static const int excelsior_scan_start = 2;
static const int excelsior_scan_error = 0;

static const int excelsior_scan_en_main = 2;


#line 26 "excelsior_reader.rl"


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
  
  
#line 96 "excelsior_reader.c"
	{
	cs = excelsior_scan_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 46 "excelsior_reader.rl"
  
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
      len = buffer_size = RSTRING_LEN(io);
      memcpy(p, StringValuePtr(io), len);
      space = buffer_size - have;
      pe = p + buffer_size;
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
  
    
#line 138 "excelsior_reader.c"
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
#line 159 "excelsior_reader.c"
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
#line 18 "excelsior_reader.rl"
	{act = 2;}
	break;
	case 5:
#line 19 "excelsior_reader.rl"
	{act = 3;}
	break;
	case 6:
#line 20 "excelsior_reader.rl"
	{act = 4;}
	break;
	case 7:
#line 17 "excelsior_reader.rl"
	{te = p+1;{ rb_yield(arr); arr = rb_ary_new(); has_found = 0; }}
	break;
	case 8:
#line 21 "excelsior_reader.rl"
	{te = p+1;{ if(has_found == 0) rb_ary_push(arr, Qnil); has_found = 0;}}
	break;
	case 9:
#line 17 "excelsior_reader.rl"
	{te = p;p--;{ rb_yield(arr); arr = rb_ary_new(); has_found = 0; }}
	break;
	case 10:
#line 20 "excelsior_reader.rl"
	{te = p;p--;{ rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}}
	break;
	case 11:
#line 1 "excelsior_reader.rl"
	{	switch( act ) {
	case 0:
	{{cs = 0; goto _again;}}
	break;
	case 3:
	{{p = ((te))-1;} rb_ary_push(arr, rb_str_new(ts, te - ts)); has_found = 1;}
	break;
	case 4:
	{{p = ((te))-1;} rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}
	break;
	default:
	{{p = ((te))-1;}}
	break;
	}
	}
	break;
#line 274 "excelsior_reader.c"
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
#line 291 "excelsior_reader.c"
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

#line 79 "excelsior_reader.rl"
    
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