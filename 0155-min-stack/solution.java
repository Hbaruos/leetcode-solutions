class MinStack {
  private Deque<Integer> mainStack;
  private Deque<Integer> minStack;

  public MinStack() {
    mainStack = new ArrayDeque<>();
    minStack = new ArrayDeque<>();
  }

  public void push(int val) {
    mainStack.push(val);

    // If minStack is empty, the first element is the minimum
    if (minStack.isEmpty()) {
      minStack.push(val);
    } else {
      // Push the smaller value between current val and current minimum
      minStack.push(Math.min(val, minStack.peek()));
    }
  }

  public void pop() {
    // Keep both stacks synchronized
    mainStack.pop();
    minStack.pop();
  }

  public int top() {
    return mainStack.peek();
  }

  public int getMin() {
    return minStack.peek();
  }
}
