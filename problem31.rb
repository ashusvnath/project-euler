DENOMINATIONS||=[200,100,50,20,10,5,2,1]
@start = 0
@num = 0
@returned_ones=false
def get_reps(num,incoming_denominations=DENOMINATIONS)
	@num = num if @num==0
	all_reps = []
	rep_start = []
	return [[]] if(num==0)
	#puts "Getting reps of #{num} in terms of #{incoming_denominations.join(',')}" 
	denominations = incoming_denominations.clone
	while denominations.any?
		highest = denominations.shift
		if(highest==1 && !@returned_ones)
			if @start==0 && num==@num
				@start=1
			end
			@returned_ones=true
			all_reps+=[[1]*num]
		else
			num_times = num/highest
			(@flag..num_times).each{|multiple|
				rep_start = [highest]*multiple
				lower_reps = get_reps(num-multiple*highest, denominations)
				all_reps += lower_reps.map{|rep| rep_start+rep}
			}
			@returned_ones=false
		end
	end
	all_reps
end
puts "Total number of representations in of 200 in terms of #{DENOMINATIONS.join(',')} is: #{get_reps(200).count}"
