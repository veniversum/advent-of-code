import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Day 2: Corruption Checksum
 * http://adventofcode.com/2017/day/2
 */
class Solution {
    public static int partA(String s) {
        int accumulator = 0;
        for (String line : s.split("\n")) {
            int min = Integer.MAX_VALUE;
            int max = Integer.MIN_VALUE;
            for (String token : line.split("\t")) {
                int n = Integer.parseInt(token);
                if (n < min) {
                    min = n;
                }
                if (n > max) {
                    max = n;
                }
            }
            accumulator += max - min;
        }
        return accumulator;
    }

    public static int partB(String s) {
        int accumulator = 0;
        for (String line : s.split("\n")) {
            List<Integer> nums = Arrays.stream(line.split("\t")).mapToInt(Integer::parseInt).boxed().collect(Collectors.toList());
            for (int i = 0; i < nums.size(); i++) {
                for (int j = 0; j < i; j++) {
                    int a = nums.get(i);
                    int b = nums.get(j);
                    if (a < b) {
                        int tmp = a;
                        a = b;
                        b = tmp;
                    }
                    if (a % b == 0) accumulator += a / b;
                }
            }
        }
        return accumulator;
    }
}
