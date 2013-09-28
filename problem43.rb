require 'gsl'

p = GSL::Permutation.alloc(10)
primes = [0, 2, 3, 5, 7, 11, 13, 17]
sum = 0
begin
  arr = p.to_a
  next if arr[0] == 0
  if val = (1..7).map{|i| arr[i..(i+2)].join.to_i % primes[i] == 0}.all?
    n = arr.join.to_i
    sum += n
    puts "#{n} #{sum}"
  end
end while p.next
puts "sum #{sum}"
