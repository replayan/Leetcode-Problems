class Solution {
  int maxDepth(String s) {
    List<int> st = [];
    int maxCounter = 0;

    for (int i = 0; i < s.length; i++) {
      if (s[i] == '(') {
        st.add(1);
      } else if (s[i] == ')') {
        st.removeLast();
      }
      maxCounter = maxCounter > st.length ? maxCounter : st.length;
    }

    return maxCounter;
  }
}
