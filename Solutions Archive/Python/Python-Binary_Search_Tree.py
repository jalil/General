
class Node:
    def __init__(self, val, k):
        self.key = k
        self.value = val
        self.left = None
        self.right = None	
	
def lookup(node, key):
    if node == None:
        return None
    elif node.key == key:
        return node.value
    elif node.key < key:
        return lookup(node.right, key)
    else: # node.key > key
        return lookup(node.left, key)

def insert(node, key, val):
    if node.key == key:
        node.value = val

    elif node.key < key and node.right == None:
        # There is no right child so add a new node
        node.right = Node(key, val)
    elif node.key < key: # and node.right != None
        # There is a right child, so insert the new element into that subtree
        insert(node.right, key, val)

    # We now do the same with right replaced with left
    elif node.key > key and node.left == None:
        node.left = Node(key, val)
    elif node.key > key: # and node.left != None
        insert(node.left, key, val)

def tree_max(node):
        if node.right != None and node.left != None:
                return max(node.value, tree_max(node.left), tree_max(node.right))
        elif node.right != None:
                return max(node.value, tree_max(node.right))
        elif node.left != None:
                return max(node.value, tree_max(node.left))
        else:
                return node.value

#def alter_output(input):
#	if  

def verify(node):	
	if node.right != None and node.left != None:
                if tree_max(node.left) > node.value or tree_max(node.right) < node.value:
                        return False
                else:
                        return verify(node.right) and verify(node.left)
	elif node.right != None:
		if tree_max(node.right) > node.value:
			return verify(node.right)
		else:
			return False
	elif node.left != None:
		if tree_max(node.left) < node.value:
			return verify(node.left)
		else:
			return False
	else:
		return True

root = Node(10, "Hello")
root.left = Node(15, "Fifteen")

print verify(root)


root = Node(10, "Ten")
root.right = Node(20, "Twenty")
root.left = Node(5, "Five")
root.left.right = Node(15, "Fifteen")

print verify(root)

root = Node(10, "Ten")
root.right = Node(15, "Eleven")
root.left = Node(5, "Five")
root.right.right = Node(16, "Sixteen")
root.right.left = Node(13, "Thirteen")
root.left.right = Node(7, "Seven")
root.left.left = Node(3, "three")

print verify(root)
