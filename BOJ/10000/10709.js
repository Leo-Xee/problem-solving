const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [H, W] = input.shift().split(" ").map(Number);

const map = Array.from({ length: H }, () => Array.from({ length: W }));

for (let i = 0; i < H; i++) {
  for (let j = 0; j < W; j++) {
    if (input[i][j] === "c") {
      map[i][j] = 0;
    } else {
      map[i][j] = -1;
    }
  }
}

for (let i = 0; i < H; i++) {
  for (let j = 0; j < W; j++) {
    if (map[i][j] === 0) {
      let cnt = 1;

      // 다음 칸이 구름이 아닐때까지 칸 수를 증가시키며 구름까지의 거리를 계산
      while (map[i][j + 1] === -1) {
        map[i][j + 1] = cnt++;
        j++;
      }
    }
  }
}

for (let row of map) {
  console.log(row.join(" "));
}
