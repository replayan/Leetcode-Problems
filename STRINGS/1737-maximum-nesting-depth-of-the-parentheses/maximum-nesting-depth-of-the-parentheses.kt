class Solution {
    fun maxDepth(s: String): Int {
        var st = mutableListOf<Int>()
        var maxCounter = 0

        for (char in s) {
            if (char == '(') {
                st.add(1)
            } else if (char == ')') {
                st.removeAt(st.size - 1)
            }
            maxCounter = maxOf(maxCounter, st.size)
        }

        return maxCounter
    }
}
