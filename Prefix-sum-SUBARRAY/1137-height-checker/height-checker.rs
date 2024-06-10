impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut cloned_heights = heights.clone();
        
        cloned_heights.sort();
        
        let mut count = 0;
        for i in 0..heights.len() {
            if heights[i] != cloned_heights[i] {
                count += 1;
            }
        }
        count
    }
}
