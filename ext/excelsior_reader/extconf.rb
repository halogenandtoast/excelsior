require 'mkmf'

dir_config('excelsior')
have_library("c", "main")
create_makefile('excelsior_reader')