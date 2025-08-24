const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

input
  .shift()
  .split(" ")
  .map((v) => +v);

const nums = input
  .shift()
  .split(" ")
  .map((v) => +v);

const mp = new Map(); // 숫자:빈도
const omp = new Map(); // 숫자:순서
const ret = []; // [숫자, 빈도]

nums.forEach((num, idx) => {
  if (mp.has(num)) {
    mp.set(num, mp.get(num) + 1);
  } else {
    mp.set(num, 1);
    if (!omp.has(num)) omp.set(num, idx + 1);
  }
});

for (let [num, freq] of mp) {
  ret.push([num, freq]);
}

// 음수면 a가 앞에 위치, 양수면 b가 앞에 위치
ret.sort((a, b) => {
  if (a[1] === b[1]) {
    return omp.get(a[0]) - omp.get(b[0]);
  }
  return b[1] - a[1];
});

console.log(
  ret
    .map(([num, freq]) => `${num} `.repeat(freq))
    .join("")
    .trim()
);
