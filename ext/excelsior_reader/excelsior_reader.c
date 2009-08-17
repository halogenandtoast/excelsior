
#line 1 "excelsior_reader.rl"
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

 
#line 34 "excelsior_reader.rl"


 
#line 25 "excelsior_reader.c"
static const char _excelsior_scan_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 1, 8, 1, 9
};

static const char _excelsior_scan_key_offsets[] = {
	0, 6, 7, 8, 16, 22
};

static const char _excelsior_scan_trans_keys[] = {
	32, 34, 39, 44, 9, 13, 34, 39, 
	10, 13, 32, 34, 39, 44, 9, 12, 
	32, 34, 39, 44, 9, 13, 10, 0
};

static const char _excelsior_scan_single_lengths[] = {
	4, 1, 1, 6, 4, 1
};

static const char _excelsior_scan_range_lengths[] = {
	1, 0, 0, 1, 1, 0
};

static const char _excelsior_scan_index_offsets[] = {
	0, 6, 8, 10, 18, 24
};

static const char _excelsior_scan_indicies[] = {
	0, 0, 0, 0, 0, 1, 3, 2, 
	3, 4, 6, 7, 5, 2, 4, 8, 
	5, 1, 10, 9, 9, 9, 9, 1, 
	6, 11, 0
};

static const char _excelsior_scan_trans_targs[] = {
	3, 4, 1, 3, 2, 3, 3, 5, 
	3, 3, 0, 3
};

static const char _excelsior_scan_trans_actions[] = {
	19, 5, 0, 11, 0, 9, 7, 0, 
	13, 17, 0, 15
};

static const char _excelsior_scan_to_state_actions[] = {
	0, 0, 0, 1, 0, 0
};

static const char _excelsior_scan_from_state_actions[] = {
	0, 0, 0, 3, 0, 0
};

static const char _excelsior_scan_eof_trans[] = {
	1, 0, 0, 0, 10, 12
};

static const int excelsior_scan_start = 3;
static const int excelsior_scan_error = -1;

static const int excelsior_scan_en_main = 3;


#line 37 "excelsior_reader.rl"
 
#line 91 "excelsior_reader.c"
	{
	cs = excelsior_scan_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 38 "excelsior_reader.rl"
 
#line 101 "excelsior_reader.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
_resume:
	_acts = _excelsior_scan_actions + _excelsior_scan_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 1:
#line 1 "excelsior_reader.rl"
	{ts = p;}
	break;
#line 120 "excelsior_reader.c"
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
	_trans = _excelsior_scan_indicies[_trans];
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
	case 2:
#line 1 "excelsior_reader.rl"
	{te = p+1;}
	break;
	case 3:
#line 28 "excelsior_reader.rl"
	{te = p+1;{ rb_ary_push(rows, arr); arr = rb_ary_new(); }}
	break;
	case 4:
#line 29 "excelsior_reader.rl"
	{te = p+1;}
	break;
	case 5:
#line 31 "excelsior_reader.rl"
	{te = p+1;{ rb_ary_push(arr, rb_str_new(ts + 1, te - ts - 2)); has_found = 1;}}
	break;
	case 6:
#line 32 "excelsior_reader.rl"
	{te = p+1;{ if(has_found == 0) rb_ary_push(arr, Qnil); has_found = 0;}}
	break;
	case 7:
#line 28 "excelsior_reader.rl"
	{te = p;p--;{ rb_ary_push(rows, arr); arr = rb_ary_new(); }}
	break;
	case 8:
#line 30 "excelsior_reader.rl"
	{te = p;p--;{ rb_ary_push(arr, rb_str_new(ts, te - ts)); has_found = 1;}}
	break;
	case 9:
#line 30 "excelsior_reader.rl"
	{{p = ((te))-1;}{ rb_ary_push(arr, rb_str_new(ts, te - ts)); has_found = 1;}}
	break;
#line 218 "excelsior_reader.c"
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
#line 231 "excelsior_reader.c"
		}
	}

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

	}

#line 39 "excelsior_reader.rl"
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