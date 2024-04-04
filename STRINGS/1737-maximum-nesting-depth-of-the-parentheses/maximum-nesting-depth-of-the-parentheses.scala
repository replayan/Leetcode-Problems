object Solution {
  def maxDepth(s: String): Int = {
    var st = List[Int]()
    var maxCounter = 0
    
    for (char <- s) {
      if (char == '(') {
        st = 1 :: st
      } else if (char == ')') {
        st = st.tail
      }
      maxCounter = math.max(maxCounter, st.length)
    }
    
    maxCounter
  }
}
