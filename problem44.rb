PENTAGONAL_NUMBERS = [0]
def pentagonal_number(n)
  PENTAGONAL_NUMBERS[n] ||= (n*(3*n-1))/2
end

def populate_pentagonal_numbers_upto(n)
  # puts "Finding pentagonal numbers upto %d" % n
  k = PENTAGONAL_NUMBERS.length - 1
  begin
    k += 1
    last_num = pentagonal_number(k)
    print ','
  end while last_num < n
end

(1..90000).each{ |i|
  print "."
  pi = pentagonal_number(i)
  (1..(i-1)).each{ |j|
    pj = pentagonal_number(j)
    sum = pi + pj
    diff = pi - pj
    populate_pentagonal_numbers_upto(10*sum) if PENTAGONAL_NUMBERS.last < sum
    (puts("\ni:%d P_i:%d j:%d P_j:%d S:%d D:%d" % [i, pi, j, pj, sum, diff]) && exit!(0)) if PENTAGONAL_NUMBERS.include?(diff) && PENTAGONAL_NUMBERS.include?(sum)
  }
}
