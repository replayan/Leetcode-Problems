impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let mut st = Vec::new();
        let mut max_counter = 0;

        for c in s.chars() {
            if c == '(' {
                st.push(1);
            } else if c == ')' {
                st.pop();
            }
            max_counter = max_counter.max(st.len() as i32);
        }

        max_counter
    }
}
