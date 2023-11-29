class Node:
    def __init__(self, value):
        self.value = value 
        self.sons = []

    def add_son(self, value):
        self.sons.append(Node(value))

    
class Tree:
    def __init__(self):
        self.root= None
    

root = Node(3)
root.add_son(5)
root.add_son(4)
root.add_son(3)