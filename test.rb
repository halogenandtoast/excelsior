$:<< File.join(File.dirname(__FILE__), 'ext', 'excelsior_reader')

require 'excelsior_reader'

Excelsior::Reader.rows("1|2|3\n4|5|6", "|") do |row|
  puts row.inspect
end