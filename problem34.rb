def fact(n)
	return case n
		when 0
		 1
		when 1
		 1
		when 2
		 2
		when 3
		 6
		when 4
		 24
		when 5
		 120
		when 6
		 720
		when 7
		 5040
		when 8
		 40320
		when 9
		 362880
		end
end

def sum_fact_digits(num)
	sum = 0
	num.to_s.each_char{|dig| sum += fact(dig.to_i)}
	sum
end

digits=0
n=0
while true
	n = n*10 + 1
	num = n * 9
	digits = digits + 1
	puts "#{num},#{digits*362880}" 
	break if(num > (digits*362880))
end
max = digits

sum_fact_sums = 0
(3..9999999).each{|num|
	if num == sum_fact_digits(num)
		sum_fact_sums += num
		puts "#{num},#{sum_fact_sums}"
	end
}
