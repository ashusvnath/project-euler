class Fixnum
	def digits
		arr = []
		self.to_s.each_char{ |digit| arr << digit }
		arr.uniq
	end
	
	def has_uniq_digits
		self.to_s.length == self.digits.length
	end
end

i = 1
sum = 0
summed = []
while i <= 99
	if i.has_uniq_digits
		j,max = (i<10 ? [1000,9999] : [100,999])
		while j <= max
			if (j.has_uniq_digits) && (j.digits & i.digits == [])
				k = i * j
				pan_digits = i.digits + j.digits + k.digits
				if k.has_uniq_digits && pan_digits.sort == ["1", "2", "3", "4", "5", "6", "7", "8", "9"] 
					unless summed.include? k
						summed << k
						sum += k
						puts "#{i}x#{j}=#{k}"
					end
				end
			end
			j += 1
		end
	end
	i += 1
end

puts "Sum of all pandigital numbers is #{sum}"
