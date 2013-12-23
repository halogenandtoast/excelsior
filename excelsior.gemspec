# -*- encoding: utf-8 -*-
lib = File.expand_path("../lib", __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)

require 'excelsior/version'


Gem::Specification.new do |gem|
  gem.name = "excelsior"
  gem.version = Excelsior::VERSION
  gem.authors = ["Matthew Mongeau"]
  gem.email = "halogenandtoast@gmail.com"
  gem.description = "A Ruby gem that uses C bindings to read CSV files superfast. I'm totally serial!"
  gem.files = ["lib/excelsior.rb"]
  gem.extensions << 'ext/excelsior_reader/extconf.rb'
  gem.homepage = "https://github.com/halogenandtoast/excelsior"
  gem.license = "MIT"
  gem.summary = "A Ruby gem that uses C bindings to read CSV files superfast. I'm totally serial!"
  gem.require_paths = ["lib"]

  gem.add_development_dependency 'rake'
  gem.add_development_dependency 'rspec'
  gem.add_development_dependency 'simplecov'
  gem.add_development_dependency 'rake-compiler'
end
