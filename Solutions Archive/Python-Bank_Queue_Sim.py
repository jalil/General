class Customer:
	def __init__(self,strCustomerName, intDeposit):
		self.name = strCustomerName
		self.deposit = intDeposit
	
def add_customer(name,deposit, queue):
	customer = Customer(name, deposit)
	queue.append(customer)

def serve_customers(lstQueue):
	x = lstQueue.pop(0)
	print "Customer " + x.name + " has been served."

def print_customers(queue):
	for customers in queue:
		print customers.name

def main():
	queue = []
	isLoop = True
	while isLoop == True:
		print("1 - Add a customer\n2 - Serve a customer\n3 - Print List\n4 - Quit")
		action = raw_input("Enter an action: ")
		if action == '1':
			strCustomer = raw_input("Enter a name followed by a comma and the amount of the deposit for this customer: ")
			strName, strDeposit = strCustomer.split(',')
			add_customer(strName, int(strDeposit), queue)
		elif action == '2':
			serve_customers(queue)
		elif action == '3':
			print_customers(queue)
		else:
			isLoop = False
			print "Goodbye!"

			

main()

