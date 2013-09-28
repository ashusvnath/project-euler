MAX = 999999
MAX_BY_2 = MAX/2

l = [0]
i = 0
while true
  k = l[i]
  t = 5*k
  break if t > MAX_BY_2
  l += [t, t+1, t+2, t+3, t+4]
  i += 1
end
puts l.size
