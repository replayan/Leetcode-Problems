var reverseString = function (s) {
    left = 0
    right = s.length - 1
    while (left < right) {
        if (s[left] !== s[right]) {
            [s[left], s[right]] = [s[right], s[left]];
        }
        left++;
        right--;
    }
};