import YahooFinanceAPI

class ReportsToComplete(object):
	def __init__(self, fName):
		self.fname = fName	

	
	def getTickers(self):
		with open(self.fname, 'r') as f:
			l = f.readlines()
		
		tickerLst = []
		for r in l:
			tickerLst.append(r.split(',')[0].replace('"', ''))
		return tickerLst
		

def main():
	rtc = ReportsToComplete("companylist.csv")
	for ticker in rtc.getTickers()[1:]:
		try:
			print ticker
			t = YahooFinanceAPI.Y_Hist_Stock_Query()
			t.toTxt(t.queryToString(t.query(ticker, [7,13,2008], [7,13,2013], 'm')))
		except Exception as e:
			print e	
			print 'The ticker "' + ticker + '" is broken.'
		


if __name__ == '__main__':
	main()
