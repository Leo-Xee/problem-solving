const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

class Stack {
  constructor() {
    this.items = [];
  }

  push(el) {
    this.items.push(el);
  }

  pop() {
    if (!this.empty()) {
      return this.items.pop();
    }
  }

  empty() {
    return this.items.length === 0;
  }

  size() {
    return this.items.length;
  }

  top() {
    return this.items[this.items.length - 1];
  }
}

input.shift();
const arr = input.map((v) => +v);
const stack = new Stack();
let ret = 0;

arr.forEach((v) => (v ? stack.push(v) : !stack.empty() && stack.pop()));

while (!stack.empty()) {
  ret += stack.top();
  stack.pop();
}

console.log(ret);
