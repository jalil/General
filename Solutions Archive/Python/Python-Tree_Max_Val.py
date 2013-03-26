class Node:
	def __init__(self, value):
		self.value = value
		self.left = None
		self.right = None
def tree_max(node):
	if node.right != None and node.left != None:
		return max(node.value, tree_max(node.left), tree_max(node.right))
	elif node.right != None:
		return max(node.value, tree_max(node.right))
	elif node.left != None:
		return max(node.value, tree_max(node.left))
	else:
		return node.value
	



root = Node(5)
root.left = Node(15)
root.right = Node(22)
root.left.left = Node(4)
root.left.right = Node(2)
root.right.right = Node(33)
print tree_max(root)

root = Node(5)
root.left = Node(15)
root.right = Node(23)
root.right.right = Node(3)
root.right.left = Node(2)
root.left.right = Node(423)
root.left.right.right = Node(23)
print tree_max(root)


