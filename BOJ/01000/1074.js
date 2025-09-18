const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, R, C] = input[0].split(" ").map((v) => +v);

const z = (n, y, x) => {
  if (n === 0) return 0;

  const half = Math.pow(2, n - 1);
  const squreOfHalf = half * half;

  if (y < half && x < half) return z(n - 1, y, x);
  if (y < half && x >= half) return squreOfHalf + z(n - 1, y, x - half);
  if (y >= half && x < half) return 2 * squreOfHalf + z(n - 1, y - half, x);
  return 3 * squreOfHalf + z(n - 1, y - half, x - half);
};

console.log(z(N, R, C));
