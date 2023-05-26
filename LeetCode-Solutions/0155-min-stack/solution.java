class MinStack {
    private Stack<Integer>stack;
    private PriorityQueue<Integer> pQueue;
    public MinStack() {
        stack  = new Stack<Integer>();
        pQueue = new PriorityQueue<Integer>();
    }
    
    public void push(int val) {
        stack.push(val);
        pQueue.add(val);
    }
    
    public void pop() {
        pQueue.remove(stack.pop());
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
       return pQueue.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
