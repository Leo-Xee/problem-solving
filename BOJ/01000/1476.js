const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [E, S, M] = input.shift().split(" ").map(Number);

let ee = 1,
  ss = 1,
  mm = 1;
let year = 1;

while (true) {
  if (E === ee && S == ss && M === mm) {
    console.log(year);
    break;
  }

  ee = (ee % 15) + 1;
  ss = (ss % 28) + 1;
  mm = (mm % 19) + 1;

  year++;
}
