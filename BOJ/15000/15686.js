const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input
  .shift()
  .split(" ")
  .map((v) => +v);
const map = input.map((row) => row.split(" ").map((v) => +v));

const houses = [];
const chickens = [];
const selectedChickensList = [];
let ret = Infinity;

const combi = (start, arr) => {
  if (arr.length === M) {
    selectedChickensList.push([...arr]);
    return;
  }

  for (let i = start + 1; i < chickens.length; i++) {
    arr.push(i);
    combi(i, arr);
    arr.pop();
  }
  return;
};

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    if (map[i][j] === 1) houses.push([i, j]);
    if (map[i][j] === 2) chickens.push([i, j]);
  }
}

combi(-1, []);

for (let selectedChickens of selectedChickensList) {
  let cityDist = 0;

  for (let house of houses) {
    let minDist = Infinity;

    for (let idx of selectedChickens) {
      const distY = Math.abs(house[0] - chickens[idx][0]);
      const distX = Math.abs(house[1] - chickens[idx][1]);
      minDist = Math.min(minDist, distY + distX);
    }
    cityDist += minDist;
  }
  ret = Math.min(ret, cityDist);
}

console.log(ret);
