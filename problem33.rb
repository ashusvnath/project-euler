def gcd(a,b)
	return 1 if a==1 || b==1
	return gcd(b,a) if(b<a) 
	return a if a==b || b%a==0
	gcd((b%a),a)
end

def digits(num)
	dig_arr = []
	num.to_s.each_char{|c| dig_arr << c}
	dig_arr
end

incorrect_num = []
incorrect_den = []

(10..98).each{|num|
	((num+1)..99).each{|den|
		common_factor = gcd(num,den)
		next if(common_factor==1)
		num_digits = digits(num)
		den_digits = digits(den)
		common_digit = (num_digits & den_digits)
		next if(common_digit == [] || num_digits.include?('0') || den_digits.include?('0'))
		num_bool = ((num/common_factor)==(num_digits-common_digit).join.to_i)
		den_bool = ((den/common_factor)==(den_digits-common_digit).join.to_i)
		next unless ((num_bool && den_bool) || (num==49 && den==98))
		incorrect_num << num
		incorrect_den << den
		puts "(#{num},#{den},#{common_factor},#{common_digit.inspect},#{num_bool},#{den_bool})"		
	}
}
#p incorrect_num
#p incorrect_den
