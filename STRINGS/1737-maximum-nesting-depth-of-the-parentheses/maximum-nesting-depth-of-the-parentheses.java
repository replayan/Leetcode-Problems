class Solution {
    public int maxDepth(String s) {
        Stack<Integer> st = new Stack<>();
        int maxCounter = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                st.push(i);
            } else if (s.charAt(i) == ')') {
                st.pop();
            }
            maxCounter = Math.max(maxCounter, st.size());
        }
        return maxCounter;
    }
}