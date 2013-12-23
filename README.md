# Excelsior

Ruby gem that uses C bindings to read CSV files superfast. I'm totally serial!

## Usage

### Parsing an IO Object

    require 'rubygems'
    require 'excelsior'
    rows = []
    Excelsior::Reader.rows(File.open('a_csv_file.csv', 'rb')) do |row|
     rows << row
    end

### Parsing a text stream

    require 'rubygems'
    require 'excelsior'
    rows = []
    Excelsior::Reader.rows("first,second,third\n1,2,3") do |row|
     rows << row
    end
