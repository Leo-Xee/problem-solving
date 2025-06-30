# JavaScript 입출력

```js
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
```

# C++ 컴파일 명령어

```sh
g++ -std=c++14 -Wall test.cpp -o test.out
```

# 문제 메타 정보 예시

```cpp
/**
 * 문제 이름: 일곱 난쟁이
 *
 * 시간 복잡도: O(N)
 * 공간 복잡도: O(N)
 *
 * 문제 풀이
 * 1. HELLO
 * 2. WORLD
 */
```
