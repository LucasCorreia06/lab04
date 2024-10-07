import stringdata
import time

def main():
    element = input("What are you searching for? ")
    data = stringdata.get_data()
    initial = time.time()
    print("Index:", linear_search(data, element))
    final = time.time()
    print("Linear time:", final - initial)
    initial = time.time()
    print("Index:", binary_search(data, element))
    final = time.time()
    print("Binary time:", final - initial)

def binary_search(container, element):
   start = 0
   end = len(container) - 1
   mid = (start + end) // 2
   final = -1
   while True:
       if container[mid] == element:
           final = mid
           break
       elif container[mid] > element:
           end = mid
           mid = (start + end) // 2
       else:
           start = mid
           mid = (start + end) // 2
       if start == mid or end == mid:
           if container[mid] == element:
               final = mid
               break
           else:
               break
   return final

def linear_search(container, element):
    final = -1
    for i in range(0, len(container)):
        if container[i] == element:
            final = i
            break
    return final

if __name__ == "__main__":
    main()