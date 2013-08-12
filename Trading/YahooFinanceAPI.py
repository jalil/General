import urllib2 as urllib

class Y_Query(object):
	def __init__(self):
		self.yahoo_param_dict = {}
		
	def query(self, *params):
		pass
	
	def parse(self, lstLines):
		pass

                               

class Y_Stock_Query(Y_Query):
	def __init__(self):
		super(Y_Stock_Query, self).__init__()
		
		self.yahoo_param_dict = {
					'Symbol' : 's0',
					'RT Bid' : 'b3',
					'RT Ask' : 'b2',
					'RT Change' : 'c6',
					'RT Change Percent' : 'k2',
					'Change From 50D Mov Avg' : 'm7',
					'50D Mov Avg' : 'm3',
					'P/E' : 'r0',
					'Ex Dividend Date' : 'q0',
					'Market Cap' : 'j1',
					'Volume': 'v0',
					'Year High' : 'k0',
					'Year Low' : 'j0',
					'Year Change' : 'w0',
					'Exchange' : 'x0',
					'Revenue' : 's6',
					'EPS Est Curr': 'r6',
					'EPS Est Next': 'r7',
					'Price to Book': 'p6'
					}
	
	def generateURL(self, stockLst, paramLst):
		stockStr = reduce(lambda x,y: x + ',' + y, stockLst)
		paramStr = reduce(lambda x,y: x + y, [self.yahoo_param_dict[k] for k in paramLst])		
		
		s = "http://download.finance.yahoo.com/d/quotes.csv?s=" + stockStr + "&f=" + paramStr + "&e=.csv" #%40%5E
		#print s
		return s
	
	def query(self, stockLst = ['AAPL'], paramLst = ["Symbol", "RT Bid", "RT Ask", "RT Change", "50D Mov Avg", "P/E", "Market Cap"]):
		if paramLst == 'All':
			paramLst = self.yahoo_param_dict.keys()

		w = urllib.urlopen(self.generateURL(stockLst, paramLst))
		l = w.readlines()
		w.close()
		return self.parse(paramLst, l)
	
	def parse(self, paramLst, rowLst):
		paramLst = [paramLst]
		for r in rowLst:
			paramLst.append(r.replace('"', '').replace('\r\n', '').split(','))
		
		l = []
		for r in paramLst:
			if r != ['']:
				l.append(r)
				
		return l
		
	def queryToString(self, parsedRowLst):
		maxLenLst = [-9999999 for x in range(len(parsedRowLst[0]))]
		for c in range(len(parsedRowLst[0])):
			for r in parsedRowLst:
				if len(r[c]) > maxLenLst[c]:
					maxLenLst[c] = len(r[c])
					
		rowsToPrint = []
		for r in parsedRowLst:
			rowsToPrint.append( '|' + reduce(lambda x,y: x + ' |  ' + y, map(lambda x: x.ljust(maxLenLst[r.index(x)]), r)) + '|')
			
		header = len(rowsToPrint[0]) * '-'
		l = []
		for i in rowsToPrint:
			l.append(i)
			l.append(header)
		
		l.insert(0, header)
		rowsToPrint = l
		
		s = ''
		for row in rowsToPrint:
			s += row + '\n'
		
		return s
		
	def toTxt(self, sData):
		with open("Report.txt", 'w') as f:
			f.write(sData)
			
class Y_Hist_Stock_Query(Y_Query):
	def __init__(self):
		super(Y_Hist_Stock_Query, self).__init__()
		self.query_dict = {
			'Ticker' : '',
			'From Date' : {
				'Month' : 0,
				'Day' : 0,
				'Year' : 0
			},
			'To Date' : {
				'Month' : 0,
				'Day' : 0,
				'Year': 0
			},
			'Interval' : 'd'

		}
	def generateURL(self):
		fd = self.query_dict['From Date']
		td = self.query_dict['To Date']
		
		params = (self.query_dict['Ticker'], fd['Month'] - 1, fd['Day'], fd['Year'], td['Month'] - 1, td['Day'], td['Year'], self.query_dict['Interval'])
		
		s = "http://ichart.yahoo.com/table.csv?s=%s&a=%i&b=%i&c=%i&d=%i&e=%i&f=%i&g=%s&ignore=.csv" %params                        
		#print s
		return s
	
	def _getDateFormat(self):
		a = self.query_dict['From Date']
		b = self.query_dict['To Date']
		
		return [str(a['Month']) + '-' + str(a['Day']) + '-' + str(a['Year']), str(b['Month']) + '-' + str(b['Day']) + '-' + str(b['Year'])]
		
	def query(self, ticker, fromLst, toLst, interval):
		self.query_dict['Ticker'] = ticker
		self.query_dict['From Date']['Month'] = fromLst[0]
		self.query_dict['From Date']['Day'] = fromLst[1]
		self.query_dict['From Date']['Year'] = fromLst[2]
		self.query_dict['To Date']['Month'] = toLst[0]
		self.query_dict['To Date']['Day'] = toLst[1]
		self.query_dict['To Date']['Year'] = toLst[2]
		self.query_dict['Interval'] = interval
		
		w = urllib.urlopen(self.generateURL())
		l = w.readlines()
		w.close()
		
		return self.parse(l)
		
	def parse(self, rowLst):
		paramLst = []
		
		for r in rowLst:
			paramLst.append(r.replace('"', '').replace('\n', '').split(','))
		
		l = []
		for r in paramLst:
			if r != ['']:
				l.append(r)
				
		#print l
		return l
		
	def queryToString(self, parsedRowLst):
		#Instantiate max column element lengths list
		maxLenLst = [-9999999 for x in range(len(parsedRowLst[0]))]
		#Get longest element in each column
		for c in range(len(parsedRowLst[0])):
			for r in parsedRowLst:
				if len(r[c]) > maxLenLst[c]:
					maxLenLst[c] = len(r[c])
					
		#print maxLenLst
		rowsToPrint = []
		for r in parsedRowLst:
			s = ''
			for c in range(len(r)):
				s += r[c].ljust(maxLenLst[c]) + ' '
			
			rowsToPrint.append(s)
			
		s = ''
		for row in rowsToPrint:
			s += row + '\n'
		
		
		return s
		
	def toTxt(self, sData):
		with open(self.query_dict["Ticker"] + '_' + "Report.txt", 'w') as f:
			f.write(sData)

def main():
	q = Y_Stock_Query()
#	dChoice = raw_input("Finance Data Terminal:\n 1 - Stock Quotes\n 2 - Historical Quotes\n  --> ")
#	if dChoice == '1':
	#i = raw_input("Choose a quote input format:\n1 - DJI\n2 - List of Tickers\n --> ")
	p = 'All'#["Symbol", "Currency","RT Bid", "RT Ask", "RT Change", "50D Mov Avg", "P/E", "Market Cap", "Volume", "EPS-Curr", "EPS-Next", "Revenue", "Stock Exchange"]

		#if i == '1':
			#q.toTxt(q.queryToString(q.query(stockLst = ['DJI'],paramLst = p )))
		#else:
	l = raw_input("What are the tickers?\n --> ")
	print (q.query(stockLst = l.split(), paramLst = p))

	#else:
	#	pass       

def other():
	q = Y_Hist_Stock_Query()
	t = raw_input("Give me a ticker: ")
	sd = raw_input("Give me a start date (ex: 5.3.2013): ")
	fd = raw_input("Give me an end date (ex: 5.5.2013): ")
	inter = raw_input("Give me an interval: ")
	
	q.toTxt(q.queryToString(q.query( t, [int(x) for x in sd.split('.')], [int(x) for x in fd.split('.')], inter)))


if __name__ == '__main__':
	main()
	#other()
