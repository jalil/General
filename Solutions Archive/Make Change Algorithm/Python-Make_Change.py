def makeChange(strChange):
	strChange = strChange.split('.')
	intDollars, intChange = strChange[0], strChange[1]
	intDollars, intChange = int(intDollars), int(intChange)
	lstChange = [0,0,0,0,0,0,0,0,0,0]
	lstDollarDenom, lstChangeDenom = subdivideDollars(intDollars), subdivideChange(intChange)
	for idx in range(0, 11):
		if idx < 6:
			lstChange[idx] = lstDollarDenom[idx]
		else:
			lstChange[idx] = lstChangeDenom[idx]
	return lstChange


def subdivideDollars(intDollars):
	intHundreds, intFifties, intTwenties, intTens, intFives, intSingles = 0,0,0,0,0,0
	while intDollars > 0:
		if intDollars - 100 >= 0:
			intHundreds += 1
		elif intDollars - 50 >= 0:
			intFifties += 1
		elif intDollars - 20 >= 0:
			intTwenties += 1
		elif intDollars - 10 >= 0:
			intTens += 1
		elif intDollars - 5 >= 0:
			intFives += 1
		elif intDollars - 1 >= 0:
			intSingles += 1
	lstDenominations = [intHundreds, intFifties, intTwenties, intTens, intFives, intSingles]
	return lstDenominations

def subdivideChange(intChange):
	intQuarters, intDimes, intNickels, intPennies = 0,0,0,0
	while intChange > 0:
		if intChange - 25 >= 0:
			intQuarters += 1
		elif intChange - 10 >= 0:
			intDimes += 1
		elif intChange - 5 >= 0:
			intNickels += 1
		elif intChange - 1>= 0:
			intPennies += 1
	lstDenominations = [intQuarters, intDimes, intNickels, intPennies]
	return lstDenominations

def main():
	dictIO = {1: "Welcome to the make change algorithm.\n",\
	2: "Please type in the amount of money you would like to make change for:\n", 3:"You will need:", \
	4: " one hundred dollar bill(s)", 5:" fifty dollar bill(s)", \
	6: " twenty dollar bill(s)", 7:" ten dollar bill(s)",\
	8:" five dollar bill(s)", 9:" one dollar bill(s)", \
	10: " quarter(s)", 11: " dime(s)", 12: " nickel(s)", 13: " pennie(s)" \
	,14: "There was an error in your submission:\n", 15: "Would you like to continue? [y/n]" \
	,16: "Goodbye!", 17: "The value provided was not an integer followed by a decimal fraction."}
	isLoop = True
	print dictIO[1]
	while isLoop == True:
		try:
			lstChange = makeChange(raw_input(dictIO[2]))
			print(dictIO[3])
			for idx in range(0, len(lstChange)):
				if lstChange[idx] != 0:
					print(dictIO[idx + 4])
		except ValueError:
			print(dictIO[17])
		except Exception as e:
			print(dictIO[14])
			print e
		finally:
			if raw_input(dictIO[15]) != 'y':
				print(dictIO[16])
				isLoop = False

main()
