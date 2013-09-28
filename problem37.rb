@primes = [2, 3, 5, 7]

def is_prime(i)
  return false if i == 1
  unless @primes.take(Math.sqrt(i).floor).find{|p| i % p == 0}
    @primes << i
    return true
  end
  false
end

@both_ways_truncatable_primes = []
last_try = @primes.last + 2
while @both_ways_truncatable_primes.length < 11
  if is_prime(last_try)
    last_try_string_array = last_try.to_s.split('')
    len = last_try_string_array.length
    is_truncatable = nil
    for i in (1..len).to_a
      num = last_try_string_array.first(i).join('').to_i
      break unless (is_truncatable = is_prime(num))
      num = last_try_string_array.last(i).join('').to_i
      break unless (is_truncatable = is_prime(num))
    end
    if is_truncatable
      print " #{last_try} "
      @both_ways_truncatable_primes << last_try
    end
  end
  last_try += 2
end
puts "The both ways truncatable_primes : #{@both_ways_truncatable_primes.map(&:to_s).join(',')}"
puts "Sum : #{@both_ways_truncatable_primes.inject(0){|a, x| a + x}}"
