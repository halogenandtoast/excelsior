require 'spec_helper'
FIXTURE_PATH = File.expand_path("../fixtures", __FILE__)

describe Excelsior::Reader do
  it "parses an io object" do
    data = ""
    Excelsior::Reader.rows(StringIO.new("a")) do |row|
      data << row.flatten.join(",")
    end

    expect(data).to eq("a")
  end

  it "handles blank objects" do
    data =  ""
    Excelsior::Reader.rows(StringIO.new("")) do |row|
      data << row.flatten.join(",")
    end

    expect(data).to eq("")
  end

  it "handles a csv file" do
    data = []
    Excelsior::Reader.rows(File.open(File.join(FIXTURE_PATH, "basic.csv"), "r")) do |row|
      data << row.flatten.join(",")
    end
    expect(data.join("\n")).to eq("a,b,c\n1,2,3")
  end

  it "handles csv headers" do
    data = ""
    Excelsior::Reader.rows(File.open(File.join(FIXTURE_PATH, "basic.csv"), "r"), header: true) do |row|
      data << row.to_a.map { |key, value| "#{key}=>#{value}" }.join(",")
    end
    expect(data).to eq("a=>1,b=>2,c=>3")
  end
end
