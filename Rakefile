require 'rake'
require 'rake/testtask'
 
PKG_FILES = %w(Rakefile) +
      Dir.glob("{lib}/**/*") +
      Dir.glob("ext/**/*.{c,rb,rl}") +
      %w[ext/excelsior_reader/excelsior_reader.c] # needed because they are generated later
 
gem_spec = Gem::Specification.new do |gem_spec|
  gem_spec.name = 'excelsior'
  gem_spec.version = '0.0.1'
  gem_spec.summary = 'A Ruby gem that uses C bindings to read CSV files superfast. I\'m totally serial!'
  gem_spec.description = 'A Ruby gem that uses C bindings to read CSV files superfast. I\'m totally serial!'
  gem_spec.email = 'matt@toastyapps.com'
  gem_spec.homepage = 'http://github.com/toastyapps/excelsior'
  gem_spec.authors = ["Matthew Mongeau"]
  gem_spec.files = PKG_FILES
  gem_spec.extensions = FileList["ext/**/extconf.rb"].to_a
end
 
desc "Generate a gemspec file"
task :gemspec do
  File.open("#{gem_spec.name}.gemspec", "w") do |f|
    f.write gem_spec.to_yaml
  end
end