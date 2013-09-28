require 'set'
#@count
def gcd a,b
	return 1 if a==1 || b==1
	return a if(b%a==0) 
	#@count = @count+1
	#print "%d,%d"%[a,b] if @count%100==0
	gcd(b%a,a)
end

def simplest_form a,b
	#@count=0
	return true if a==1
	return false if b%a==0
	return false if gcd(a,b) != 1
	true
end


def get_hidden_count max
primes = [2,3,5,7]
count = (max-1)
return count*6 if max<4
(4..max).each{ |den|
	print "." if den%100000 == 0
	next if(primes.include?(den) || den==1)
	#puts "%d:%s:%s"%[den, primes.join(','), primes.map{|p| den%p}.join(',')]
	unless primes.map{|p| den%p}.include?(0)
		primes += [den]
		#print "p#{den} "
		next
	end
	(1..(den-1)).each{ |num|
		#(print "%d,%d are not in the simplest form"%[num,den])
		count = count + 1 unless simplest_form(num,den)
	}

}
return count*6
end
print "Enter number of rows in hexagonal orchard: "
max = gets.to_i
puts "\n#{get_hidden_count(max)} points are hidden from the center"
