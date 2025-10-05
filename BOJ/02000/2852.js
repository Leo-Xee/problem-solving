const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

input.shift();
const goals = input.map((v) => v.split(" ")).map((v) => [+v[0], v[1]]);

let a = 0,
  b = 0,
  prev;
const sumA = { value: 0 };
const sumB = { value: 0 };

const print = (obj) => {
  const min = "00" + Math.floor(obj.value / 60);
  const sec = "00" + Math.floor(obj.value % 60);

  return min.substring(min.length - 2) + ":" + sec.substring(sec.length - 2);
};

const changeToTime = (s) => {
  const [min, sec] = s.split(":").map(Number);
  return min * 60 + sec;
};

const calc = (obj, s) => {
  obj.value += changeToTime(s) - changeToTime(prev);
};

for (let [team, time] of goals) {
  if (a > b) calc(sumA, time);
  if (b > a) calc(sumB, time);

  team === 1 ? a++ : b++;
  prev = time;
}

if (a > b) calc(sumA, "48:00");
if (b > a) calc(sumB, "48:00");

console.log([print(sumA), print(sumB)].join("\n"));
