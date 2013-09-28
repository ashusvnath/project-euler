class Integer
  def factors
    (2..self).select{|n| (self%n).zero?}
  end
end

sums = []
(1..32).each{ |n|
  ((n+1)..33).each{ |m|
    sum = 2*m*(m+n)
    sums << sum unless sums.any?{|s| (((s%sum) == 0)||((sum%s) == 0))}
  }
}

sums = sums.sort.uniq

puts "triplet_sums: [#{sums.join(', ')}]"
max = 0
max_triplets = 0
(12..1000).each{|num|
  factors_that_are_triplet_sums = num.factors.select{|factor| sums.any?{|us|(factor==us)}}
  num_triplets = factors_that_are_triplet_sums.count
  if (max_triplets < num_triplets)
    max_triplets = num_triplets
    max = num
    puts "Change!!: #{max}, #{max_triplets}, [#{factors_that_are_triplet_sums.join(',')}]"
  end
}

puts "Final!!: #{max}, #{max_triplets}"
