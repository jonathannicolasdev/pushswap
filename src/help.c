

def A_to_B()
	//choose proper pivot from stack A elements
	for r elements
		if top of stack A > pivot
			ra
		else
			pb

//How can I choose the right pivot?
//Our goal is to look inside this stack and 
//find the optimal instruction set. So it might be 
//a good idea to sort the numbers separately and find the best pivot there.

//However, there may be parts of Stack A that you do not want to touch. For example, 
//if you have already sorted parts, you may want to divide only a certain range into two groups.
//So, what if you want to divide only a certain part of stack A?

def A_to_B(size of range r)
	//choose proper pivot from stack A elements
	for r elements
		if ((top of stack A) > pivot
			ra
			ra_call_count++
		else
			pb
            pb_call_count++	
    for ra_number of calls
		rra //Rewind elements moved to #ra back to the top of the stack


//This leaves only values ​​greater than the pivot in stack A, and only values ​​less than the pivot in stack B.
//The algorithm that sends a certain part of stack B to A wouldn't be any different, right?!

def B_to_A(size of range r)
    //Choose the "proper" pivot from r elements of stack B	
    for r elements
		if (top of stack B) > pivot
			rb
			rb_call_count++
		else
			pa
			pa_call_count++
	for ra_호출 횟수
		rra #ra로 넘어간 원소들을 다시 스택 상단으로 되감기



//If you combine these two functions and call them recursively, you can finish sorting with $O(n\log n)$.
//To do this, add a condition to each of the two functions you just created and a condition to call each other.

def A_to_B(범위의 크기r)
	if r == 1
		return
	Choose the "proper" pivot from r elements of stack A
	for r
		if (top of stack A) > pivot
			ra
			ra_call_count++
		else
			pb
			pb_call_count++
	for ra_number of calls
		rra Rewinds elements moved to #ra back to the top of the stack
	A_to_B(ra_call_count) //Make A as light as possible
	B_to_A(pb_call_count) //When #A is sorted, the things that went to B are put into A.

def B_to_A(size of range r)
	if r == 1
		pa call
		return
	//Choose the "proper" pivot from r elements of stack B
	for r
		if (top of stack B) > pivot
			rb
			rb_call_count++
		else
			pa
			pa_call_count++
	for ra_number of calls
		rra Rewinds elements moved to #ra back to the top of the stack
	A_to_B(pa_호출_횟수) //The group that went to #A
	B_to_A(pb_호출_횟수) //B's remaining group

//The algorithm described so far is too simplistic.
//This algorithm has a lot of room for optimization.

//When splitting groups, sometimes the size of the range is 2 or 3. This algorithm is generally good when the size of the range is large, 
//but there are shorter solutions than this algorithm for smaller sizes of the range. In such a case, you can provide a solution directly 
//and escape the recursive statement.
//When the number of things to be sorted is small, the number of cases is small, so there is a way to directly 
//instruct the instruction in each case, or to search the number of cases using a BFS or other method to select the shortest instruction set. . 
//However, DFS doesn't seem like a good solution.
//I've only dealt with the case of range 3, and especially case of size 3.
//And if the range is 2, you can call sa, sb, ss conditionally.
//In this way, the number of commands is reduced by a constant multiple.

//If there are only values ​​greater than the pivot since a certain index, there is no need to call ra. 
//If you don't call ra, you call rra less often.
//And there may be cases where calling rra is faster than calling ra. 
//You can get a better instruction set by handling such cases separately.


//In the case of stack A, if the alignment is well done, there is no need to rearrange the group by splitting it. 
//Each group divided in the process of solving by this algorithm is a group of consecutive elements. 
//If it's sorted, that's it. Just call the following function:

//Only when implementing #3,
//If the next value before ra/rb is the last element to be pushed to the other side of the stack, you can call sa/sb and then pb/pa.

//I knew that the expected value of the number of commands fell short of the target, but I realized that the results could be improved 
//if the optimization was done well, so I implemented it first.
//But it didn't work out, and another algorithm came up, so this algorithm was discarded.
//(Based on 100 commands, sometimes the number of commands is less than 700, and sometimes it exceeds.


//When passing from stack A to B, it can be divided once again based on a specific value. 
//For example, the pivot is selected among the values ​​to be passed, and the value larger than the pivot is left as it is, 
//and the smaller value is passed backward by calling rb.
//Pick 2 pivots, move the value less than the largest pivot to B, leave the value greater than the smallest pivot, 
//and call rb to pass the smaller value back!
//It is divided into 3 groups.

//It's a bit complicated this time around. This is because the order in which the two groups are moved to A and sorted is also important, 
//since there are two groups that are pushed onto the opposite stack.

//[3], [2], [1], from the largest group to the smallest group. Of course, the three groups are initially mixed.
//We classify it in the same way as in Section 4.1, but this time with a slightly different part. It is to pass 
//[2], not [1], backwards with the rb command. This way you can sort [2] immediately after sorting [3].

```python
def A_to_B(r)
Pick 2 "appropriate" pivots from stack A elements
tmp = top of stack A # target to be operated on
for for r elements
if tmp >= pivot[larger]
rewind with the ra command
number of ra calls++
else
send to b with the pb command
number of pb calls++
if tmp >= pivot [small]
Skip backwards with the rb command
number of rb calls++
for ra calls, rb calls
rrr calls #[3] and [2] are brought to the front of the stack
```
