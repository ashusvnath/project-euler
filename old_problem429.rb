#!/usr/bin/env ruby -w

require 'benchmark' 

class Integer    
   def prime?         # cf. http://snippets.dzone.com/posts/show/4636
     n = self.abs()
     return true if n == 2
     return false if n == 1 || n & 1 == 0
     d = n-1
     d >>= 1 while d & 1 == 0
     20.times do                               # 20 = k from above
       a = rand(n-2) + 1
       t = d
       y = ModMath.pow(a,t,n)                  # implemented below
       while t != n-1 && y != 1 && y != n-1
         y = (y * y) % n
         t <<= 1
       end
       return false if y != n-1 && t & 1 == 0
     end
     return true
   end
end
 
module ModMath
   def ModMath.pow(base, power, mod)
     result = 1
     while power > 0
       result = (result * base) % mod if power & 1 == 1
       base = (base * base) % mod
       power >>= 1;
     end
     result
   end
end



class Integer

   def primes   # cf. http://snippets.dzone.com/posts/show/3734

      sieve = []
      3.step(self, 2) { |i| sieve[i] = i }
      sieve[1] = nil
      sieve[2] = 2

      3.step(Math.sqrt(self).floor, 2) do |i| 
         next unless sieve[i]
         (i*i).step(self, i) do |j|
            sieve[j] = nil
         end
      end

      sieve.compact!

   end 


   def primes2       # cf. http://snippets.dzone.com/posts/show/3734

      primes = [nil, nil].concat((2..self).to_a)

      (2 .. Math.sqrt(self)).each do |i|
         next unless primes[i]
            (i*i).step(self, i) do |j|
               primes[j] = nil
            end
      end
	
      primes.compact!

   end

end



class Integer

   @primes_cache ||= 100.primes
   #@primes_cache ||= [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
   class << self; attr_accessor :primes_cache; end

   @nthprime_limit ||= 5_000_000
   class << self; attr_reader :nthprime_limit; end
   #class << self; attr_accessor :nthprime_limit; end


   def sieve_size
      num = self.to_i.abs
      logn = Math.log(num)
      if num < 15985     # cf. http://primes.utm.edu/howmany.shtml
         ( num * (logn + Math.log(logn) - 1 + 1.8 * Math.log(logn) / logn) ).floor
      else
         ( num * (logn + Math.log(logn) - 0.9427) ).floor
      end
   end


   def nthprime

      num = self.to_i.abs

      # set a limit; cf. http://primes.utm.edu/nthprime/: The 5,000,000th prime is 86,028,121.
      raise "#{num}: number too big for Integer#nthprime" if num > Integer.nthprime_limit      

      primes_cache_size = Integer.primes_cache.size

      if num > primes_cache_size

         # optional; cf. Integer#nthprime_add and Integer#nthprime_add_mr below
         if num >= 50_000 && num < 100_000 && (num - primes_cache_size) < 5000 then return num.nthprime_add end
         if num >= 100_000 && num < 200_000 && (num - primes_cache_size) < 15000 then return num.nthprime_add end
         if num >= 200_000 && (num - primes_cache_size) < 35000 then return num.nthprime_add end
         
         logn = Math.log(num)

         if num < 15985       # cf. http://primes.utm.edu/howmany.shtml
            limit = ( num * (logn + Math.log(logn) - 1 + 1.8 * Math.log(logn) / logn) ).floor
            Integer.primes_cache = limit.primes
         else
            limit = ( num * (logn + Math.log(logn) - 0.9427) ).floor
            Integer.primes_cache = limit.primes
         end

=begin
         elsif num >= 15985 && num <= 1_000_000
            limit = ( num * (logn + Math.log(logn) - 0.9427) ).floor
            Integer.primes_cache = limit.primes
         elsif num > 1_000_000
            Integer.primes_cache = 20_000_000.primes
         end
=end

      else
         return Integer.primes_cache.at(num-1)
      end


      if num <= Integer.primes_cache.size
         return Integer.primes_cache.at(num-1)
      end

      if Integer.primes_cache.size > 2_500_000
         num.nthprime_add_mr 
      else
         num.nthprime_add   # faster for a (relatively) small prime cache
      end

   end


   def nthprime_add       #  add primes to Integer.primes_cache up to the nth prime

      num = self.to_i.abs

      if num <= Integer.primes_cache.size
         return Integer.primes_cache.at(num-1)
      end

      last_prime = Integer.primes_cache.last
      last_prime_divmod = last_prime.divmod(6)

      if last_prime_divmod.last == 1
         i = last_prime_divmod.first
         Integer.primes_cache.pop      # avoid a duplicate prime
      else
         i = last_prime_divmod.first + 1
      end


      while Integer.primes_cache.size < num

         n1 = 6*i+1       # cf. http://betterexplained.com/articles/another-look-at-prime-numbers/ and
         n2 = n1+4        # http://everything2.com/index.pl?node_id=1176369
         i += 1

         [n1, n2].each do |p| 

            next if p % 5 == 0 || p % 7 == 0

            next_num_sqrt = Math.sqrt(p).floor

            Integer.primes_cache.each do |d| 
               if d > next_num_sqrt 
                  Integer.primes_cache << p
                  #print "\r\e[0K#{Integer.primes_cache.size}"
                  #$stdout.flush
                  break
               elsif p % d == 0
                  break
               end  
            end
         end   # each  

      end  # while

      return Integer.primes_cache.at(num-1)

   end


   def nthprime_add_mr       #  add Miller-Rabin primes to Integer.primes_cache up to the nth prime

      num = self.to_i.abs

      if num <= Integer.primes_cache.size
         return Integer.primes_cache.at(num-1)
      end

      last_prime = Integer.primes_cache.last
      last_prime_divmod = last_prime.divmod(6)

      if last_prime_divmod.last == 1
         i = last_prime_divmod.first
         Integer.primes_cache.pop
      else
         i = last_prime_divmod.first + 1
      end


      while Integer.primes_cache.size < num

         search_next_prime = true

         while search_next_prime

            n1 = 6*i+1       
            n2 = n1+4        
            i += 1

            [n1, n2].each do |p| 

               next if p % 5 == 0 || p % 7 == 0

               if p.prime?
                  Integer.primes_cache << p
                  search_next_prime = false
                  #print "\r\e[0K#{Integer.primes_cache.size}"
                  #$stdout.flush
               end
            end
         end

      end  #  first while loop

      return Integer.primes_cache.at(num-1)

   end


#------------------------------------------- some additional prime methods


   def next_primes_in_cache    # next primes in Integer.primes_cache

      search_next_primes = self.to_i.abs

      last_prime = Integer.primes_cache.last
      last_prime_divmod = last_prime.divmod(6)

      if last_prime_divmod.last == 1
         i = last_prime_divmod.first
         Integer.primes_cache.pop
      else
         i = last_prime_divmod.first + 1
      end

      while search_next_primes > 0

         n1 = 6*i+1       
         n2 = n1+4        
         i += 1

         [n1, n2].each do |p| 

            next if p % 5 == 0 || p % 7 == 0
            next_num_sqrt = Math.sqrt(p).floor

            Integer.primes_cache.each do |d| 
               if d > next_num_sqrt 
                  Integer.primes_cache << p
                  search_next_primes -= 1
                  #print "\r\e[0K#{Integer.primes_cache.size}"
                  #$stdout.flush
                  break
               elsif p % d == 0
                  break
               end  
            end
         end 
      end   # while

      Integer.primes_cache.last(self.to_i.abs)

   end


   def next_mr_prime     # next Miller-Rabin prime
     
      last_num = self.to_i.abs
      last_num_divmod = last_num.divmod(6)

      if last_num_divmod.last == 1
         i = last_num_divmod.first
      else
         i = last_num_divmod.first + 1
      end

      next_prime = nil
      search_next_prime = true

      while search_next_prime

         n1 = 6*i+1       
         n2 = n1+4        
         i += 1

         [n1, n2].each do |p| 

            next if p % 5 == 0 || p % 7 == 0

            if p > last_num && p.prime?
               next_prime = p
               search_next_prime = false 
               break
            end
         end
      end

         next_prime

   end



   def next_mr_primes(n)     # next Miller-Rabin primes

      last_num = self.to_i.abs
      last_num_divmod = last_num.divmod(6)

      if last_num_divmod.last == 1
         i = last_num_divmod.first
      else
         i = last_num_divmod.first + 1
      end

      next_primes = []
      search_next_primes = n.to_i.abs

      while search_next_primes > 0

         n1 = 6*i+1      
         n2 = n1+4       
         i += 1

         [n1, n2].each do |p| 

            next if p % 5 == 0 || p % 7 == 0

            if p > last_num && p.prime?
               next_primes << p
               search_next_primes -= 1 
            end
         end
      end

      next_primes

   end

end



num1 = 10_000
num1 = 1_000
num1 = 5_000

num2 = 210_349
num2 = 100_125
num2 = 55_000

ret1 = nil
ret2 = nil
ret3 = nil
ret4 = nil


Benchmark.bm(16) do |t| 

   t.report("first #{num1} primes: ") do
      ret1 = num1.nthprime_add
   end 

   Integer.primes_cache.clear
   Integer.primes_cache.concat(100.primes)

   t.report("first #{num1} primes: ") do
      ret2 = num1.nthprime_add_mr
   end 

   Integer.primes_cache.clear
   Integer.primes_cache.concat(100.primes)

   t.report("first #{num1} primes: ") do
      ret3 = num1.nthprime
   end 

   Integer.primes_cache.clear
   Integer.primes_cache.concat(100.primes)

   t.report("first #{num2} primes: ") do
      ret4 = num2.nthprime
   end 

end


puts
puts "the #{num1}th prime number: #{ret1}"
puts "the #{num1}th prime number: #{ret2}"
puts "the #{num1}th prime number: #{ret3}"
puts "the #{num2}th prime number: #{ret4}"
puts
puts "the #{num1}th prime: #{Integer.primes_cache.at(num1-1)}"
puts "the #{num2}th prime: #{Integer.primes_cache.at(num2-1)}"
puts
p Integer.primes_cache.first(10)
p Integer.primes_cache.last(10)
p Integer.primes_cache.size
puts


p 15.next_primes_in_cache

puts 594_213.next_mr_prime

p 149_137.next_mr_primes(5)

puts
p 1_000.sieve_size
p 1_000_000.sieve_size
p 2_500_000.sieve_size
p 5_000_000.sieve_size
p 10_000_000.sieve_size
p 100_000_000.sieve_size


=begin

# check with primegen.c, http://cr.yp.to/primegen.html
primes 2 48611 | nl | tail -n 1
primes 2 104729 | nl | tail -n 1
primes 2 679277 | nl | tail -n 1
primes 2 1301423 | nl | tail -n 1
primes 2 2903603 | nl | tail -n 1
primes 1303129 1303283 | nl
primes 594213 $((594213 + 500)) | head -n 1
primes 149137 $((149137 + 1000)) | head -n 5

# further prime tools from http://libtom.org
- LibTomMath
   bn_mp_prime_is_prime.c
   bn_mp_prime_miller_rabin.c
- TomsFastMath
   fp_isprime.c
   fp_prime_miller_rabin.c

=end
