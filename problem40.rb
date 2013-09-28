str=""
i=1
while str.length <= 1000000
  str += i.to_s
  i += 1
  print "." if i % 100 == 0
end
ans = 1
(0..6).each{|i| indx = 10**i ; num = str[indx-1].chr.to_i; ans = ans * num; puts "i:%d digit:%d ans:%d" % [indx, num, ans] }
