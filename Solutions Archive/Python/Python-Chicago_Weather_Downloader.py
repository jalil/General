import urllib

f = urllib.urlopen('http://weather.noaa.gov//pub/data/forecasts/state/il/ilz013.txt')

lstILWeather = f.readlines()

lstRowsToPrint = []
	
print "Prepare for the weather:\n"
for idx in range(0,len(lstILWeather)):
	if lstILWeather[idx] == 'ROWS INCLUDE...\n':
		for ix in range(-3, 9):
			print lstILWeather[idx + ix]

	elif lstILWeather[idx] == '...NORTHEAST IL...\n':
		print lstILWeather[idx]
		for ix in range(5, 13):
			print lstILWeather[idx + ix]

for row in lstRowsToPrint:
	print row

f.close()

raw_input("Press enter to exit.")
print("Goodbye")

