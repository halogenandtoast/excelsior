$:<< File.join(File.dirname(__FILE__), '..', 'ext', 'excelsior_reader')
 
require 'rubygems'
require 'excelsior'
require 'benchmark'
require 'fastercsv'

Benchmark.bm do |b|
  b.report("Excelsior") do
    Excelsior::Reader.rows(File.open("data/test.csv")) do |row|
    end
  end
  
  b.report("FasterCsv") do
    FasterCSV.parse(File.open("data/test.csv")) do |row|
    end
  end
end