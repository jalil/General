import matplotlib
import pylab
import matplotlib.pyplot as p
import ReportsToComplete_Hist, os, gc

class Historical_Plot(object):
	def __init__(self, ticker):
		self.ticker = ticker
		self.days, self.adj_closes = self.get_data_from_report(self.get_report_from_ticker())
		#self.ls = os.listdir('./HistData/DailyLastFiveYears/')

	def get_report_from_ticker(self):
		ls = os.listdir('./HistData/MonthlyLastFiveYears/')
		for report in ls:
			if '%s_Report.txt' %self.ticker == report:
				return report
		else:
			return None

	def get_data_from_report(self,report):
		with open('./HistData/MonthlyLastFiveYears/' + report, 'r') as f:
			l = [x.replace('\n','').split() for x in f.readlines()]

		return  [x + 1 for x in range(len(l[1:]))], [float(x[6]) for x in l[1:]]		

	def plot_hist_data(self, x, y):
		if self.days is None or self.adj_closes is None:
			raise Exception
		
		self.adj_closes.reverse()
		
		pylab.xlim([0,self.days[-1]])
		fig = matplotlib.pyplot.figure()
		ax = fig.add_subplot(111)
		ax.plot(self.days, self.adj_closes)
		
		matplotlib.pyplot.ylabel('%s %s' %(self.ticker, y))
		matplotlib.pyplot.xlabel('%s' %x)
		matplotlib.pyplot.suptitle('%s %s over %s' %(self.ticker, y, x ))
		
		fig.savefig('./Charts/MonthlyLastFiveYears/%s_Chart.png' %self.ticker)
		pylab.close()

if __name__ == '__main__':
	ptc = ReportsToComplete_Hist.ReportsToComplete("companylist.csv")
	for ticker in ptc.getTickers()[1:]:
		try:
			
			hp = Historical_Plot(ticker)
			hp.plot_hist_data('Months', 'Adjusted Close (USD)')
			del hp
			print "It seems like %s finished okay" %ticker
		except Exception as e:
			print e, "Fuck! The historical data for %s wasn't found! Trying again..." %ticker
			if e is MemoryError:
				gc.collect()
				hp = Historical_Plot(ticker)
				hp.plot_hist_data('Months', 'Adjusted Close (USD)')
				del hp
