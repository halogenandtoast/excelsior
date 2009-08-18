--- !ruby/object:Gem::Specification 
name: excelsior
version: !ruby/object:Gem::Version 
  version: 0.0.3
platform: ruby
authors: 
- Matthew Mongeau
autorequire: 
bindir: bin
cert_chain: []

date: 2009-08-18 00:00:00 -04:00
default_executable: 
dependencies: []

description: A Ruby gem that uses C bindings to read CSV files superfast. I'm totally serial!
email: matt@toastyapps.com
executables: []

extensions: 
- ext/excelsior_reader/extconf.rb
extra_rdoc_files: []

files: 
- Rakefile
- lib/excelsior.rb
- ext/excelsior_reader/excelsior_reader.c
- ext/excelsior_reader/extconf.rb
- ext/excelsior_reader/excelsior_reader.rl
- ext/excelsior_reader/excelsior_reader.c
has_rdoc: true
homepage: http://github.com/toastyapps/excelsior
licenses: []

post_install_message: 
rdoc_options: []

require_paths: 
- lib
required_ruby_version: !ruby/object:Gem::Requirement 
  requirements: 
  - - ">="
    - !ruby/object:Gem::Version 
      version: "0"
  version: 
required_rubygems_version: !ruby/object:Gem::Requirement 
  requirements: 
  - - ">="
    - !ruby/object:Gem::Version 
      version: "0"
  version: 
requirements: []

rubyforge_project: 
rubygems_version: 1.3.4
signing_key: 
specification_version: 3
summary: A Ruby gem that uses C bindings to read CSV files superfast. I'm totally serial!
test_files: []

