require 'rake'
require 'rake/extensiontask'
require 'rspec/core/rake_task'

RSpec::Core::RakeTask.new(:spec)
Rake::ExtensionTask.new "excelsior_reader" do |ext|
  ext.lib_dir = 'lib/excelsior'
end

desc "Compile the ragel state machines"
task :ragel do
  Dir.chdir "ext/excelsior_reader" do
    target = "excelsior_reader.c"
    sh "ragel excelsior_reader.rl -G2 -o #{target}"
    raise "Failed to compile Ragel state machine" unless File.exist? target
  end
end

task default: [:ragel, :clobber, :compile, :spec]
