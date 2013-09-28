db_palindromes = []
sum = 0
for i in (1..1000000).to_a
  if(i == i.to_s.reverse.to_i && i.to_s(2) == i.to_s(2).reverse)
    print "#{i}, "
    db_palindromes << i
    sum += i
  end
end
puts "\nSum is #{sum}"
