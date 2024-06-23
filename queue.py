size = 5
queue = []
front = rear = -1
def enqueue():
    global front, rear
    if rear == size - 1:
        print("Overflow! Queue is full.")
    else:
        x = int(input("Enter the value to enqueue: "))
        if front == -1:
            front = 0
        rear += 1
        queue.append(x)
def dequeue():
    global front, rear
    if front == -1 or front > rear:
        print("Underflow! Queue is empty.")
    else:
        print("Dequeued element:", queue[front])
        front += 1
def display():
    global front, rear
    if front == -1 or front > rear:
        print("Queue is empty.")
    else:
        print("Elements in queue:")
        for i in range(front, rear + 1):
            print(queue[i])
if __name__ == "__main__":
    print("\nMenu:")
    print("1. Enqueue")
    print("2. Dequeue")
    print("3. Display")
    print("4. Exit")
    choice = int(input("Enter your choice: "))
    while True:
        if choice == 1:
            enqueue()
        elif choice == 2:
            dequeue()
        elif choice == 3:
            display()
        elif choice == 4:
            print("Exiting the program.")
            break
        else:
            print("Invalid choice!")