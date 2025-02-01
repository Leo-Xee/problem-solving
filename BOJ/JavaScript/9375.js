const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let t = Number(input.shift());

while (t--) {
  const n = Number(input.shift());

  const mp = new Map();
  let ret = 1;

  for (let i = 0; i < n; i++) {
    const [_, b] = input.shift().split(" ");

    if (mp.has(b)) {
      mp.set(b, mp.get(b) + 1);
    } else {
      mp.set(b, 1);
    }
  }

  for (v of mp.values()) {
    ret *= v + 1;
  }
  ret--;

  console.log(ret);
}
