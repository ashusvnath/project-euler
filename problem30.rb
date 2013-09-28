max = (1..100).collect{|num_digits| 
						biggest_num=("9"*num_digits);
						biggest_sum=0; 
						biggest_num.each_char{|c| biggest_sum+=(c.to_i**5)}; 
						[biggest_num.to_i,biggest_sum]
					  }.select{|list| list[0].to_s.length<=list[1].to_s.length}.last[0]
puts "Highest number that may be less than or equal to sum of its digits^5 :: #{max}" 
numbers_equal_to_sum_digits_power_5 = 
	(2..max).select{|num| 
					sum_digits_pow_5=0;
					num.to_s.each_char{|c| sum_digits_pow_5+=c.to_i**5};
					sum_digits_pow_5 == num
					}
puts "The numbers between 2 and #{max} such that num = sum_of_its_digits_power_5 :: #{numbers_equal_to_sum_digits_power_5.join(',')}"
required_sum = numbers_equal_to_sum_digits_power_5.inject(0){|acc, num| acc+num}
puts "Their sum is :: #{required_sum}"

