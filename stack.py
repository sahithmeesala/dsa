size = 5
arr = [0] * size
top = -1

def push():
    global top
    if top == size - 1:
        print("Overflow! Stack is full.")
    else:
        x = int(input("Enter the value to push: "))
        top += 1
        arr[top] = x

def pop():
    global top
    if top == -1:
        print("Underflow! Stack is empty.")
    else:
        print("Popped element:", arr[top])
        top -= 1

def show():
    if top == -1:
        print("Stack is empty.")
    else:
        print("Elements in stack:")
        for i in range(top + 1):
            print(arr[i])

if __name__ == "__main__":
    print("\nMenu:")
    print("1. Push")
    print("2. Pop")
    print("3. Show")
    print("4. Exit")
    choice = int(input("Enter your choice:"))
        
    while True:
        if choice == 1:
            push()
        elif choice == 2:
            pop()
        elif choice == 3:
            show()
        elif choice == 4:
            print("Exiting the program.")
            break
        else:
            print("Invalid choice!")
