#!/usr/bin/env ruby
require 'mathn'

CONTRIB = []
MOD_CONST = 1000000009
SLICE_LENGTH = 1000000

if ARGV.length > 0
  max = ARGV.first.to_i
else
  print "Enter the number whose factorial's sum of squares of unitary divisors you want to calculate: "
  max = gets.to_i
end

def pow_modn(num,exponent)
  product = 1
  while exponent > 0
    product = (product * num) % MOD_CONST
    exponent -= 1
  end
  product
end

product = 1
count = 0
Prime.each do |p|
  break if p > max
  count += 1
  print "." if count%100000 == 0
  index = (1..Math.log(max,p).floor).inject(0){|index, n| index + (max/(p**n)).floor}
  num = (1 + pow_modn(p, 2*index))
  product = (product * num) % MOD_CONST
end

puts "S(#{max}!) = #{product}"
