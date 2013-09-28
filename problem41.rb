require 'gsl'

def is_prime(n)
  return false if n % 2 == 0
  divisor = 3
  lim = Math.sqrt(n).floor
  begin
    return false if n % divisor == 0
    divisor += 2
  end while divisor <= lim
  return true
end

max = 0
for n in (3..9)
  p = GSL::Permutation.alloc(n)
  begin
    n = p.to_a.map{|i| i+1}.join.gsub(/[\] \[]/, "").to_i
    if is_prime(n)
      max = max < n ? n : max
    end
  end while p.next == 0
end
puts max
