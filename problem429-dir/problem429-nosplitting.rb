#!/usr/bin/env ruby
require 'mathn'

CONTRIB = []
MOD_CONST = 1000000009

max = 0

if ARGV.length == 0
  print "Enter value of n to find S(n!): "
  max = gets.to_i
else
  max = ARGV.first.to_i
end

product = 1
Prime.first(max).select{|x| x <= max}.each do |p|
      #index = calculate_index(p, max)
      index = (1..Math.log(max,p).floor).inject(0){|index, n| index + (max/(p**n)).floor}
      num = (1 + p**(2*index))
      product = (product * num) % MOD_CONST
end

puts "S(#{max}!) = #{product}"
# puts CONTRIB.inspect
