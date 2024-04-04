def max_depth(s)
    st = []
    max_counter = 0
    
    s.each_char do |char|
        if char == '('
            st.push(1)
        elsif char == ')'
            st.pop
        end
        max_counter = [max_counter, st.size].max
    end
    
    max_counter
end
