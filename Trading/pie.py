#import matplotlib

#matplotlib.use('TkAgg')

import matplotlib.pylab as pylab


from pylab import *

#matplotlib.use('TkAgg')

f = open('portfolio.txt', 'r')
l = f.readlines()
ll = []
for i in l:
	ll.append(i.replace('\n','').split())

nameList = []

for i in ll[1:]:
	nameList.append(i[0])

values = []

for i in ll[1:]:
	values.append(float(i[1]) * int(i[2]))

#print tuple(nameList), tuple(values)

figure(1, figsize=(6,6))
ax = axes([0.1,0.1,0.8,0.8])

labels = tuple(nameList) 

summation = sum(values)

fractionsList = []

for i in values:
	fractionsList.append(i / summation)

fracs = fractionsList
#explode=(0,0,0,0)
pie(fracs, labels = labels, autopct='%1.1f%%', startangle=90)

title("Your Fucking Portfolio, Asshole", bbox={'facecolor':'0.8', 'pad':5})

show()

savefig('foo.png')
raw_input("fuck you")
