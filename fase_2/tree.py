class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        
    def __str__(self):
        return str(self.data)


class BinaryTree:
    
    def __init__(self, data=None, node=None):
        if node:
            self.root = node
        elif data:
            node = Node(data)
            self.root = node
        else:
            self.root = None

    def inorder_traversal(self, node=None): #Simetric Traversal
        if node is None:
            node = self.root
        if node.left:
            print('(', end="")
            self.inorder_traversal(node.left)
        print(node, end="")
        if node.right:
            self.inorder_traversal(node.right)
            print(')', end="")
            
    def posorder_traversal(self, node=None):
        if node is None:
            node = self.root
        if node.left:
            self.posorder_traversal(node.left)
        if node.right:
            self.posorder_traversal(node.right)
        print(node, end=" ")
        
    def height(self, node=None):
        if node is None:
            node = self.root
        hleft = 0
        hright = 0
        if node.left:
            hleft = self.height(node.left)
        if node.right:
            hright = self.height(node.right)
        if hright > hleft:
            return hright + 1
        return hleft + 1
    
    def simetric_traversal(self, node=None): #Simetric Traversal for ordering
        if node is None:
            node = self.root
        if node.left:
            self.simetric_traversal(node.left)
        print(node, end=" ")
        if node.right:
            self.simetric_traversal(node.right)
            
    def levelorder_traversal(self, node=None):
        if node is None:
            node = self.root
        
        queue = deque()
        queue.append(node)
        while len(queue):
            node = queue.pop()
            if node.left :
                queue.appendleft(node.left)
            if node.right :
                queue.appendleft(node.right)
            print(node.data, end=' ')

class BinarySearchTree(BinaryTree):
    def insert(self, value):
        parent = None
        x = self.root
        while(x):
            parent = x
            if value < x.data:
                x = x.left
            else:
                x = x.right
        if parent is None:
            self.root = Node(value)
        elif value < parent.data:
            parent.left = Node(value)
        else:
            parent.right = Node(value)
            
    def search(self,value):
        return self._search(value, self.root)
            
    def _search(self, value, node):
        if node is None :
            return node
        if node.data == value:
            return BinarySearchTree(node)
        if value < node.data:
            return self._search(value, node.left)
        return self._search(value, node.right)
    
    def minimun(self, node= None):
        if node is None:
            node = self.root
        while node.left:
            node = node.left
        return node.data
    
    def maximun(self, node= None):
        if node is None:
            node = self.root
        while node.right:
            node = node.right
        return node.data
    
    def remove(self, value, node=None): #O(H)
        if node == None:
            node = self.root
        if node is None:
            return None
        
        if value < node.data:
            node.left = self.remove(value, node.left)
        elif value > node.data:
            node.right = self.remove(value, node.right)
        else:
#             if node.left is None and node.right is None:
#                 return None
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            else:
                substitute = self.minimun(node.right)
                node.data = substitute
                node.right = slef.removeove(substitute, node.right)
        return node