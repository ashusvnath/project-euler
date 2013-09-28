#!/usr/bin/env ruby
require 'mathn'

CONTRIB = []
MAX = 100000000
MOD_CONST = 1000000009

def calculate_index(p, max)
end

max = 0

if ARGV.length == 0
  print "Enter value of n to find S(n!): "
  max = gets.to_i
else
  max = ARGV.first.to_i
end
slice_size = (max > 100) ? (max/100).floor : max
puts "Slicing every #{slice_size} primes"
sleep(10)
asdf = gets

Prime.first(max).each_slice(slice_size) do |prime_list|
  pid = fork do
    product = 1
    prime_list.collect do |p|
      #index = calculate_index(p, max)
      index = (1..Math.log(max,p).floor).inject(0){|index, n| index + (max/(p**n)).floor}
      num = (1 + p**(2*index))
      product = (product * num) % MOD_CONST
    end
    File.open("problem429-#{Process.pid}.txt", "w") do |file|
      file.puts product
    end
    exit
  end
  CONTRIB << pid
end

puts "Forked children #{CONTRIB.inspect} .. waiting"
Process.waitall
puts "Done waiting"

values = CONTRIB.each.collect{|pid| val = File.read("problem429-#{pid}.txt").chomp.to_i}

puts "values : #{values.inspect}"

puts "S(#{max}!) = #{values.inject(1){|p, v| (p*v) % MOD_CONST}}"
# puts CONTRIB.inspect
