class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int student_0 = 0; // students preferring circular sandwiches
        int student_1 = 0; // students preferring square sandwiches

        // Count the number of students for each preference
        for (int student : students) {
            if (student == 1)
                student_1++;
            else
                student_0++;
        }

        // Iterate through sandwiches and check if any students are unable to eat
        for (int sandwich : sandwiches) {
            if ((sandwich == 0 && student_0 == 0) || (sandwich == 1 && student_1 == 0))
                break; // No more students can eat this type of sandwich
            else if (sandwich == 0)
                student_0--; // Reduce the count of available circular sandwiches
            else
                student_1--; // Reduce the count of available square sandwiches
        }

        // Sum up the remaining students who couldn't eat
        return student_0 + student_1;
    }
}
