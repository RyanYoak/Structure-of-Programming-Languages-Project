class Node:
    # Here one can see Python's pass by reference vs pass by value methods, if data is a basic data type it will be
    # pass by value, however if it is a more complex data type then it will be pass by reference.
    def __init__(self, data, next = None):
        self.data = data
        self.next = next

    def __str__(self):
        return str(self.data)

class LinkedList:
    def __init__(self, data=None):
        if data == None:
            self.firstNode = None
        else:
            node = Node(data)
            self.firstNode = node

    def __str__(self):
        if self.firstNode == None:
            return "[ ]"
        Lstr = "[ " + str(self.firstNode.data)
        currentNode = self.firstNode.next
        while currentNode != None:
            Lstr = Lstr + ", " + str(currentNode.data)
            currentNode = currentNode.next
        Lstr = Lstr + " ]"
        return Lstr

    # Here you can see how Python is dynamically typed, here the type of node is not known at
    # compile time and only known at run time (not quite how Python works), a block of memory
    # is allocated in the heap and assigned a value once the code runs.
    def add(self, data, position = None):
        node = Node(data)
        currentNode = self.firstNode
        if position == None:
            while currentNode.next != None:
                currentNode = currentNode.next
            currentNode.next = node
        else:
            if position == 0:
                node.next = self.firstNode
                self.firstNode = node
                return
            counter = 1
            while counter != position:
                if currentNode.next == None:
                    currentNode.next = node
                    return
                currentNode = currentNode.next
                counter = counter + 1
            temp = currentNode.next
            node.next = temp
            currentNode.next = node

    # Here you can see Python's garbage collection at work, instead of having to manually delete
    # data on the heap, Python's data collection will be able to detect when the references to an
    # object are no longer used and be able to delete the object for the programmer.
    def remove(self, data):
        if self.firstNode.data == data:
            self.firstNode = self.firstNode.next
            return

        previousNode = self.firstNode
        currentNode = self.firstNode.next
        while currentNode.data != data:
            if currentNode.next == None:
                return
            currentNode = currentNode.next
            previousNode = previousNode.next
        nextNode = currentNode.next
        previousNode.next = nextNode

ll = LinkedList(1)
ll.add(2)
ll.add(2.5)
ll.add(2.75)
ll.add(3,1)

print(ll)

ll.remove(3)

print(ll)
