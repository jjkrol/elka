def licz_n(path, b, avg_n = 0, avg_miu = 0)
file = File.open(path)
n_sum = miu_sum = rh_sum =0
e = 1.602176487 *10 **(-19) 
d = 2 * 10 **(-7) 
c = 150 * 10 **(-6)
while line = file.gets do
line.gsub!(/\/\//) #wywal koncow \\
line.gsub!(/,/,".") # zamien przecnki na kropki (zeby traktowalo jako liczby)
arr = line.split(/\s&\s/) # rozdziel po &
uh = arr[1].to_f # to_f - to float
u = arr[2].to_f
is = arr[3].to_f/1000 # przez 1000 bo podawane w mA
no = arr[0].to_i

cur_n = is*b/e/d/uh
cur_miu = (uh*is)/(u*c*b)
if avg_n == 0 then
	n_sum +=cur_n
	miu_sum += cur_miu
else
	n_sum += (cur_n - avg_n) ** 2
	miu_sum += (cur_miu - avg_miu) ** 2
end
rh_sum += is/(cur_n*e*cur_miu*c*d) 
#	u/uw * 100
end
file.close
return [n_sum,miu_sum,rh_sum]
end


wynik = File.open("wynik.txt", "w")
all_n = all_miu = all_rh = all_ux_n = all_ux_miu = 0.0

files = [["1.txt",0.0125],["2.txt",0.025],["3.txt",0.04],["4.txt", 0.05]]
files.each{|set|
puts "licze dla " + set[0]+ " z b = "+set[1].to_s
ret = licz_n(set[0],set[1])
all_n += ret[0]
all_miu += ret[1]
all_rh += ret[2]

}

n = all_n/120.0
miu = all_miu/120.0
rh = all_rh/120.0

files.each{|set|
puts "licze niepewnosc dla " + set[0]+ " z b = "+set[1].to_s
ret = licz_n(set[0],set[1], n, miu)
all_ux_n += ret[0]
all_ux_miu += ret[1]
}

ux_n = Math.sqrt(all_ux_n/(120*119))
ux_miu = Math.sqrt(all_ux_miu/(120*119))

wynik.puts "obliczone n = " + n.to_s + " : "+((n.to_s.length) - 2).to_s
wynik.puts "obliczone miu = " + miu.to_s
wynik.puts "obliczone rh = " + rh.to_s
wynik.puts "obliczone ux_n = " + ux_n.to_s + " = " + (ux_n/n*100).to_s + "%"
wynik.puts "obliczone ux_miu = " + ux_miu.to_s + " = " + (ux_miu/miu*100).to_s + "%"





