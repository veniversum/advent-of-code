/**
* Day 1: Inverse Captcha in JS
* http://adventofcode.com/2017/day/1
*/

function partA(s) {
    return captcha(s, 1);
}

function partB(s) {
    const offset = s.length / 2;
    captcha(s, offset);
}

function captcha(s, offset) {
  return s.split("").map((x) => x | 0).filter((x, i, a) => x == a[(i + offset) % a.length]).reduce((a, b) => a + b, 0);
}
