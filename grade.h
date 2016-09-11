# ifndef GUARD_grade
# define GUARD_grade

// Compute a student's overall grade from midterm and final exam and homework grades
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}