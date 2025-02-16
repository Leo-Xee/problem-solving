const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

class Node {
  constructor(value) {
    this.value = value;
    this.prev = null;
    this.next = null;
  }
}

class Deque {
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  getSize() {
    return this.size;
  }

  isEmtpy() {
    return this.size === 0;
  }

  front() {
    return this.head.value;
  }

  back() {
    return this.tail.value;
  }

  findIndex(value) {
    let curr = this.head;
    let idx = 0;
    while (curr !== null) {
      if (curr.value === value) {
        return idx;
      }
      curr = curr.next;
      idx++;
    }

    return -1;
  }

  pushFront(value) {
    const node = new Node(value);
    if (this.isEmtpy()) {
      this.head = node;
      this.tail = node;
    } else {
      node.next = this.head;
      this.head.prev = node;
      this.head = node;
    }
    this.size++;
  }

  pushBack(value) {
    const node = new Node(value);
    if (this.isEmtpy()) {
      this.head = node;
      this.tail = node;
    } else {
      this.tail.next = node;
      node.prev = this.tail;
      this.tail = node;
    }
    this.size++;
  }

  popFront() {
    if (this.isEmtpy()) {
      return null;
    }
    const value = this.head.value;
    this.head = this.head.next;
    this.size--;
    return value;
  }

  popBack() {
    if (this.isEmtpy()) {
      return null;
    }
    const value = this.tail.value;
    if (this.size === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.tail = this.tail.prev;
      this.tail.next = null;
    }
    this.size--;
    return value;
  }

  print() {
    let curr = this.head;
    let list = "";
    while (curr) {
      list += `${curr.value} `;
      curr = curr.next;
    }
    console.log(list);
  }
}

const solution = (n, _, arr) => {
  const dq = new Deque();
  let ret = 0;

  for (let i = 1; i <= n; i++) dq.pushBack(i);

  arr.forEach((v) => {
    const idx = dq.findIndex(v);

    while (v !== dq.front()) {
      if (idx <= Math.floor(dq.getSize() / 2)) {
        dq.pushBack(dq.popFront());
      } else {
        dq.pushFront(dq.popBack());
      }
      ret++;
    }

    dq.popFront();
  });

  return ret;
};

const [n, m] = input
  .shift()
  .split(" ")
  .map((v) => +v);

const arr = input[0].split(" ").map((v) => +v);

console.log(solution(n, m, arr));
