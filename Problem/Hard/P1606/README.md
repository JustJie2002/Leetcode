View this problem as a simulation problem in following steps:
1. Suppose all servers are free
2. For each request, free up any servers that are done at or before current time
3. Find the first server that is available
4. Assign the current request to that server and put it in our queue

Answer will just be the servers that have maximum assignments

Let's work through each simulation steps one at a time
1. We can have some data structure that stores all free servers
2. Since we want to check for the "end time" of each request assignment to those servers, we can use a min priority queue to have the requests that end first at the top. Pop the top of the priority queue whenever we passed that time and free up that server by putting back in the list of free servers.
3. We should not be iterating all the way through or else that will take too long. First we can check whether our list of free server is empty or not. Then, consider finding i, i + 1, ... as finding the "first element that is >= i" then if there's none then we can just choose "first element that is >= 0" since it loops back. Now that should sound familiar enough. Yes. We can achieve this through binary search but in order to use binary search we need to make the data structure constantly sorted. Therefore, we can either use SortedList or TreeSet to store free servers.
4. We can just put it in our min priority queue and remove the free server from the data structure holding free servers.

After that we're completely done with the simulation

Time Complexity: O(N log K) \
Space Complexity: O(K)