# CSCI_313 HW2 Question 3
### Author: James Deciutiis
## The Question: 
3) Test a stack's speed (with millions of operations) as to which is faster: an array based
stack or a linked list based stack.
## Methodology:
- I first created a node class and a linked list class as the backend for the linked stack. 
<br></br>
- Next I created the array based stack which was essentially just an array that only allows access from the top 
(last array element)
<br></br>
- Finally I created a class that would take in a linked list based stack and an array based stack and would perform millions of pushes and pops. These trials were measured in milliseconds and were the basis for the judgement to determine which stack implementation performs operations faster.

Reasoning: I felt that separating the problem into classes would reduce the clutter in main.cpp,
improve readability. It also allowed me to have an easier time to write trials for each of the stack implementations.

## Timing 
I used the chrono library which measures true time elapsed. In the timeTrial class, each test is ran multiple times to ensure the accuracy of the test.

## Compile 

```
g++ main.cpp -std=c++11 -o <desired_name_of_output>
```

## Closing thoughts
I think this question really demonstrated the strengths and weaknesses of each of the two stack implementations. All operations were faster on the array implementation, however the linked list implementation could have various other advantages in different applications. 
